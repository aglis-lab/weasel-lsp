#include <wlsp/json/jsonWriter.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{
	JsonWriter::JsonWriter() : Writer<StringBuffer>(buffer){};

	bool JsonWriter::Object(ObjectT &obj)
	{
		obj.write(*this);

		return true;
	}

	bool JsonWriter::Number(wlsp::Number n)
	{
		bool result;

		visit(overload(
				  [this, &result](int n)
				  {
					  result = Int(n);
				  },
				  [this, &result](double n)
				  {
					  result = Double(n);
				  }),
			  n);

		return result;
	}

	bool JsonWriter::Array(wlsp::Array &a)
	{
		bool result = true;

		StartArray();
		for (const auto &ii : a)
		{
			visit(overload(
					  [this, &result](wlsp::String str)
					  {
						  result &= String(str.c_str());
					  },
					  [this, &result](wlsp::Number n)
					  {
						  result &= Number(n);
					  },
					  [this, &result](Boolean b)
					  {
						  result &= Bool(b);
					  },
					  [this, &result](wlsp::Null)
					  {
						  result &= Null();
					  },
					  [this, &result](wlsp::Object obj)
					  {
						  result &= Object(*obj);
					  }),
				  ii);
		}
		EndArray();

		return result;
	}

	bool JsonWriter::Any(wlsp::Any &a)
	{
		bool result;

		visit(overload(
				  [this, &result](wlsp::String str)
				  {
					  result = String(str.c_str());
				  },
				  [this, &result](wlsp::Number n)
				  {
					  result = Number(n);
				  },
				  [this, &result](Boolean b)
				  {
					  result = Bool(b);
				  },
				  [this, &result](wlsp::Null)
				  {
					  result = Null();
				  },
				  [this, &result](wlsp::Object obj)
				  {
					  result = Object(*obj);
				  },
				  [this, &result](wlsp::Array &a)
				  {
					  result = Array(a);
				  }),
			  a);

		return result;
	}

}
