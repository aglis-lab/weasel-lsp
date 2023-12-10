#pragma once

#include <wlsp/json/jsonValue.hpp>
#include <wlsp/json/jsonWriter.hpp>

namespace wlsp
{

	using namespace std;
	using namespace rapidjson;

	struct JsonHandler;

	class ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &){};

	public:
		/// This is for writing the json
		void write(JsonWriter &writer);

		ObjectT() {}
		virtual ~ObjectT() {}
	};
}
