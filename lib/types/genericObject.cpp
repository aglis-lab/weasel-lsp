#include <wlsp/types/genericObject.hpp>

namespace wlsp
{

	using namespace std;

	GenericObject::GenericObject(map<String, Any> children) : children(children){};

	GenericObject::GenericObject(){};
	GenericObject::~GenericObject(){};

	ArrayMaker::ArrayMaker(Array &parentArray) : parentArray(parentArray){};

	ArrayMaker::~ArrayMaker(){};

	void GenericObject::partialWrite(JsonWriter &writer)
	{
		for (auto &i : children)
		{
			writer.Key(i.first);
			writer.Any(i.second);
		}
	}

	void GenericObject::reParse(JsonHandler &handler)
	{
		auto reString = [&handler](String &str)
		{
			handler.String(str.c_str(), str.length(), false);
		};

		auto reNumber = [&handler](Number n)
		{
			handler.Number(n);
		};

		auto reBoolean = [&handler](Boolean b)
		{
			handler.Bool(b);
		};

		auto reNull = [&handler](Null)
		{
			handler.Null();
		};

		auto reObject = [&handler](Object obj)
		{
			if (auto gObj = dynamic_pointer_cast<GenericObject>(obj))
			{
				handler.StartObject();

				gObj->reParse(handler);

				handler.EndObject(gObj->children.size());
			}
			else
			{

				// This is why its called reparse

				// First the object is transformed to json

				JsonWriter writer;

				obj->write(writer);

				// Then a new object is made from that json

				GenericObject newObj;

				JsonHandler handler;

				handler.objectStack.emplace().extraSetter =
					{
						nullopt,
						nullopt,
						nullopt,
						nullopt,
						nullopt,
						[&handler, &newObj]()
						{
							handler.pushInitializer();
						}};

				Reader r;

				StringStream s(writer.GetString());

				r.Parse(s, handler);

				// And finally from its children the json its reparsed

				handler.StartObject();

				newObj.reParse(handler);

				handler.EndObject(newObj.children.size());
			}
		};

		for (auto &i : children)
		{
			handler.Key(i.first.c_str(), i.first.length(), false);
			visit(overload(
					  reString,
					  reNumber,
					  reBoolean,
					  reNull,
					  reObject,
					  [&](Array &a)
					  {
						  handler.StartArray();
						  for (auto &i : a)
						  {
							  visit(overload(
										reString,
										reNumber,
										reBoolean,
										reNull,
										reObject),
									i);
						  }
						  handler.EndArray(a.size());
					  }),
				  i.second);
		}
	}

}
