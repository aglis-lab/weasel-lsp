#pragma once

#include <optional>

#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

using namespace std;

/// workspace/executeCommand client capabilities
///
/// dynamicRegistration?: Boolean
///
struct ExecuteCommandClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Execute command supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	//=======================================================================//

	// No writing

	ExecuteCommandClientCapabilities(optional<Boolean> dynamicRegistration);

	ExecuteCommandClientCapabilities();

	virtual ~ExecuteCommandClientCapabilities();
};

/// workspace/executeCommand options
///
/// commands: String[]
///
struct ExecuteCommandOptions: public WorkDoneProgressOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String commandsKey;

public:
	/// The commands to be executed on the server
	vector<String> commands;

	// No parsing

	ExecuteCommandOptions(optional<Boolean> workDoneProgress,
		vector<String> commands);

	ExecuteCommandOptions();

	virtual ~ExecuteCommandOptions();
};

/// Execute command registration options.
using ExecuteCommandRegistrationOptions = ExecuteCommandOptions; // No parsing

/// workspace/executeCommand params
///
/// command: String
///
/// arguments?: Array
///
struct ExecuteCommandParams: public WorkDoneProgressParams
{
private:
	const static String commandKey;
	const static String argumentsKey;

public:
	/// The identifier of the actual command handler.
	String command;

	/// Arguments that the command should be invoked with.
	optional<Array> arguments;

	//=======================================================================//

	// No writing

	ExecuteCommandParams(optional<ProgressToken> workDoneToken,
		String command,
		optional<Array> arguments);

	ExecuteCommandParams();

	virtual ~ExecuteCommandParams();
};

}
