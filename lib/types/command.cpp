#include <wlsp/types/command.hpp>
#include <wlsp/types/genericObject.hpp>

namespace wlsp
{

	using namespace std;

	const String Command::titleKey = "title";
	const String Command::commandKey = "command";
	const String Command::argumentsKey = "arguments";

	Command::Command(String title, String command, optional<Array> arguments) : title(title),
																				command(command),
																				arguments(arguments){};

	Command::Command(){};
	Command::~Command(){};

	void Command::partialWrite(JsonWriter &writer)
	{
		// title
		writer.Key(titleKey);
		writer.String(title.c_str());

		// command
		writer.Key(commandKey);
		writer.String(command);

		// arguments?
		if (arguments.has_value())
		{
			writer.Key(argumentsKey);
			writer.Array(*arguments);
		}
	}
}
