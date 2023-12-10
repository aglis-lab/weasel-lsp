#pragma once

#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	/// Server capability for DidChangeConfiguration
	///
	/// dynamicRegistration?: Boolean
	///
	struct DidChangeConfigurationClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;

	public:
		/// Did change configuration notification supports dynamic registration.
		optional<Boolean> dynamicRegistration;

		//=======================================================================//

		// No writing

		DidChangeConfigurationClientCapabilities(optional<Boolean> dynamicRegistration);

		DidChangeConfigurationClientCapabilities();

		virtual ~DidChangeConfigurationClientCapabilities();
	};

	/// DidChangeConfiguration params
	///
	/// settings: Any
	///
	struct DidChangeConfigurationParams : public ObjectT
	{
	private:
		const static String settingsKey;

	public:
		/// The actual changed settings
		Any settings;

		//=======================================================================//

		// No writing

		DidChangeConfigurationParams(Any settings);

		DidChangeConfigurationParams();

		virtual ~DidChangeConfigurationParams();
	};
}
