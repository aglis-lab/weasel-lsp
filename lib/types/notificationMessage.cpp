#include <wlsp/types/notificationMessage.hpp>

namespace wlsp
{

	using namespace std;

	const String NotificationMessage::methodKey = "method";
	const String NotificationMessage::paramsKey = "params";

	NotificationMessage::NotificationMessage(Server &server,
											 String method,
											 optional<any> params) : MessageServer(server),
																	 method(method),
																	 params(params){};

	NotificationMessage::NotificationMessage(Server &server) : MessageServer(server){};

	NotificationMessage::~NotificationMessage(){};

	void NotificationMessage::partialWrite(JsonWriter &writer)
	{
		// Parent
		MessageServer::partialWrite(writer);

		// method
		writer.Key(methodKey);
		writer.String(method);

		// params?
		if (params.has_value())
		{
			optional<Capability> capability = server.getCapability(method);
			if (capability.has_value())
			{
				writer.Key(paramsKey);
				capability->params.writer.value()(writer, *params);
			}
		}
	}
}
