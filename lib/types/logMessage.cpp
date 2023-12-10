#include <wlsp/types/logMessage.hpp>

namespace wlsp
{

using namespace std;

const String LogMessageParams::typeKey    = "type";
const String LogMessageParams::messageKey = "message";

LogMessageParams::LogMessageParams(MessageType type, String message):
	type(type),
	message(message)
{};

LogMessageParams::LogMessageParams(){};
LogMessageParams::~LogMessageParams(){};

void LogMessageParams::partialWrite(JsonWriter &writer)
{
	// type
	writer.Key(typeKey);
	writer.Int((int)type);

	// message
	writer.Key(messageKey);
	writer.String(message);
}

}
