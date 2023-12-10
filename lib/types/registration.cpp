#include <wlsp/types/registration.hpp>

namespace wlsp
{

using namespace std;

const String Registration::idKey              = "id";
const String Registration::methodKey          = "method";
const String Registration::registerOptionsKey = "registerOptions";

Registration::Registration(String id, String method, optional<Any> registerOptions):
	id(id),
	method(method),
	registerOptions(registerOptions)
{};

Registration::Registration(){};
Registration::~Registration(){};

void Registration::partialWrite(JsonWriter &writer)
{
	// id
	writer.Key(idKey);
	writer.String(id);

	// method
	writer.Key(methodKey);
	writer.String(method);

	// registerOptions?
	if(registerOptions.has_value())
	{
		writer.Key(registerOptionsKey);
		writer.Any(*registerOptions);
	}
}


const String RegistrationParams::registrationsKey = "registrations";

RegistrationParams::RegistrationParams(vector<Registration> registrations):
	registrations(registrations)
{};

RegistrationParams::RegistrationParams(){};
RegistrationParams::~RegistrationParams(){};

void RegistrationParams::partialWrite(JsonWriter &writer)
{
	// registrations
	writer.Key(registrationsKey);
	writer.StartArray();
	for(auto& i: registrations)
	{
		writer.Object(i);
	}
	writer.EndArray();
}


const String Unregistration::idKey              = "id";
const String Unregistration::methodKey          = "method";

Unregistration::Unregistration(String id, String method):
	id(id),
	method(method)
{};

Unregistration::Unregistration(){};
Unregistration::~Unregistration(){};

void Unregistration::partialWrite(JsonWriter &writer)
{
	// id
	writer.Key(idKey);
	writer.String(id);

	// method
	writer.Key(methodKey);
	writer.String(method);
}


const String UnregistrationParams::unregisterationsKey = "unregisterations";

UnregistrationParams::UnregistrationParams(vector<Unregistration> unregisterations):
	unregisterations(unregisterations)
{};

UnregistrationParams::UnregistrationParams(){};
UnregistrationParams::~UnregistrationParams(){};

void UnregistrationParams::partialWrite(JsonWriter &writer)
{
	// registrations
	writer.Key(unregisterationsKey);
	writer.StartArray();
	for(auto& i: unregisterations)
	{
		writer.Object(i);
	}
	writer.EndArray();
}

}
