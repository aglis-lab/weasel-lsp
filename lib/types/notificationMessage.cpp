#include <wlsp/constant.hpp>
#include <wlsp/types/notificationMessage.hpp>

namespace wlsp
{
	using namespace std;

	NotificationMessage::NotificationMessage(String method, unique_ptr<ObjectT> params) : Message(JSON_RPC_VERSION), method(method)
	{
		this->params = std::move(params);
	}

	NotificationMessage::~NotificationMessage(){};

	void NotificationMessage::partialWrite(JsonWriter &writer)
	{
		// Json RPC
		writer.Key(jsonrpcKey);
		writer.String(jsonrpc);

		// method
		writer.Key(methodKey);
		writer.String(method);

		// params?
		if (params)
		{
			// optional<Capability> capability = server.getCapability(method);
			// if (capability.has_value())
			// {
			// 	writer.Key(paramsKey);

			// 	// TODO: Capability Params
			// 	// Find a way to cover this hole!
			// 	capability->params.writer.value()(writer, *params);
			// }
		}
	}
}
