#include <wlsp/types/executeCommand.hpp>

namespace wlsp
{

	using namespace std;

	const String ExecuteCommandClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	ExecuteCommandClientCapabilities::
		ExecuteCommandClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	ExecuteCommandClientCapabilities::ExecuteCommandClientCapabilities(){};
	ExecuteCommandClientCapabilities::~ExecuteCommandClientCapabilities(){};

	const String ExecuteCommandOptions::commandsKey = "commands";

	ExecuteCommandOptions::ExecuteCommandOptions(optional<Boolean> workDoneProgress,
												 vector<String> commands) : WorkDoneProgressOptions(workDoneProgress),
																			commands(commands){};

	ExecuteCommandOptions::ExecuteCommandOptions(){};
	ExecuteCommandOptions::~ExecuteCommandOptions(){};

	void ExecuteCommandOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		WorkDoneProgressOptions::partialWrite(writer);

		// commands
		writer.Key(commandsKey);
		writer.StartArray();
		for (auto &i : commands)
		{
			writer.String(i);
		}
		writer.EndArray();
	}

	const String ExecuteCommandParams::commandKey = "command";
	const String ExecuteCommandParams::argumentsKey = "arguments";

	ExecuteCommandParams::ExecuteCommandParams(optional<ProgressToken> workDoneToken,
											   String command,
											   optional<Array> arguments) : WorkDoneProgressParams(workDoneToken),
																			command(command),
																			arguments(arguments){};

	ExecuteCommandParams::ExecuteCommandParams(){};
	ExecuteCommandParams::~ExecuteCommandParams(){};
}
