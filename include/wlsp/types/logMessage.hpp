#pragma once

#include <wlsp/types/showMessage.hpp>

namespace wlsp
{

using namespace std;

/// The log message notification is sent from the server to the client to
/// ask the client to log a particular message.
///
/// type: MessageType
///
/// message: String
///
struct LogMessageParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String typeKey;
	const static String messageKey;

public:
	/// The message type. See {@link MessageType}
	MessageType type;

	/// The actual message
	String message;

	// No parsing

	LogMessageParams(MessageType type, String message);

	LogMessageParams();

	virtual ~LogMessageParams();
};

}
