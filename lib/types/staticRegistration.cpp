#include <wlsp/types/staticRegistration.hpp>

namespace wlsp
{

using namespace std;

const String StaticRegistrationOptions::idKey = "id";

StaticRegistrationOptions::StaticRegistrationOptions(optional<String> id):
	id(id)
{};

StaticRegistrationOptions::StaticRegistrationOptions(){};
StaticRegistrationOptions::~StaticRegistrationOptions(){};

void StaticRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// id?
	if(id.has_value())
	{
		writer.Key(idKey);
		writer.String(*id);
	}
}

}
