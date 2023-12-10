#pragma once

#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

enum class MessageType
{
	/// An error message.
	Error = 1,

	/// A warning message.
	Warning = 2,

	/// An information message.
	Info = 3,

	/// A log message.
	Log = 4
};

/// The show message notification is sent from a server to a client to ask
/// the client to display a particular message in the user interface.
///
/// type: MessageType
///
/// message: String
///
struct ShowMessageParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String typeKey;
	const static String messageKey;

public:
	/// The message type. See {@link MessageType}.
	MessageType type;

	/// The actual message.
	String message;


	// No parsing


	ShowMessageParams(MessageType type, String message);

	ShowMessageParams();

	virtual ~ShowMessageParams();
};

/// The message action items to present.
///
/// title: String
///
struct MessageActionItem: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String titleKey;

public:
	/// A short title like 'Retry', 'Open Log' etc.
	String title;

	//=======================================================================//


	MessageActionItem(String title);

	MessageActionItem();

	virtual ~MessageActionItem();
};

struct ShowMessageRequestParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String typeKey;
	const static String messageKey;
	const static String actionsKey;

public:
	/// The message type. See {@link MessageType}.
	MessageType type;

	/// The actual message.
	String message;

	/// The message action items to present.
	optional<vector<MessageActionItem>> actions;

	// No parsing

	ShowMessageRequestParams(MessageType type,
		String message,
		optional<vector<MessageActionItem>> actions);

	ShowMessageRequestParams();

	virtual ~ShowMessageRequestParams();
};

}
