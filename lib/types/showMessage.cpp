#include <wlsp/types/showMessage.hpp>

namespace wlsp
{

	using namespace std;

	const String ShowMessageParams::typeKey = "type";
	const String ShowMessageParams::messageKey = "message";

	ShowMessageParams::ShowMessageParams(MessageType type, String message) : type(type),
																			 message(message){};

	ShowMessageParams::ShowMessageParams(){};
	ShowMessageParams::~ShowMessageParams(){};

	void ShowMessageParams::partialWrite(JsonWriter &writer)
	{
		// type
		writer.Key(typeKey);
		writer.Int((int)type);

		// message
		writer.Key(messageKey);
		writer.String(message);
	}

	const String MessageActionItem::titleKey = "title";

	MessageActionItem::MessageActionItem(String title) : title(title){};

	MessageActionItem::MessageActionItem(){};
	MessageActionItem::~MessageActionItem(){};

	void MessageActionItem::partialWrite(JsonWriter &writer)
	{
		// title
		writer.Key(titleKey);
		writer.String(title);
	}

	const String ShowMessageRequestParams::typeKey = "type";
	const String ShowMessageRequestParams::messageKey = "message";
	const String ShowMessageRequestParams::actionsKey = "actions";

	ShowMessageRequestParams::ShowMessageRequestParams(MessageType type,
													   String message,
													   optional<vector<MessageActionItem>> actions) : type(type),
																									  message(message),
																									  actions(actions){};

	ShowMessageRequestParams::ShowMessageRequestParams(){};
	ShowMessageRequestParams::~ShowMessageRequestParams(){};

	void ShowMessageRequestParams::partialWrite(JsonWriter &writer)
	{
		// type
		writer.Key(typeKey);
		writer.Int((int)type);

		// message
		writer.Key(messageKey);
		writer.String(message);

		// actions?
		if (actions.has_value())
		{
			writer.Key(actionsKey);
			writer.StartArray();
			for (auto &i : *actions)
			{
				writer.Object(i);
			}
			writer.EndArray();
		}
	}

}
