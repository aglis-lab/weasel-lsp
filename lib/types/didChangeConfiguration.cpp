#include <wlsp/types/didChangeConfiguration.hpp>
#include <wlsp/types/genericObject.hpp>

namespace wlsp
{

	using namespace std;

	const String DidChangeConfigurationClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	DidChangeConfigurationClientCapabilities::
		DidChangeConfigurationClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	DidChangeConfigurationClientCapabilities::
		DidChangeConfigurationClientCapabilities(){};

	DidChangeConfigurationClientCapabilities::
		~DidChangeConfigurationClientCapabilities(){};

	const String DidChangeConfigurationParams::settingsKey = "settings";

	DidChangeConfigurationParams::DidChangeConfigurationParams(Any settings) : settings(settings){};

	DidChangeConfigurationParams::DidChangeConfigurationParams(){};
	DidChangeConfigurationParams::~DidChangeConfigurationParams(){};
}
