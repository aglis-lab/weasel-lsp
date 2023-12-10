#include <wlsp/types/objectT.hpp>

namespace wlsp
{
	void ObjectT::write(JsonWriter &writer)
	{
		writer.StartObject();

		partialWrite(writer);

		writer.EndObject();
	}
}
