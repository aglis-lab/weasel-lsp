#include <wlsp/types/message.hpp>

namespace wlsp
{

	using namespace std;

	const pair<String, String> MessageServer::jsonrpc = {"jsonrpc", "2.0"};

	MessageServer::MessageServer(Server &server) : server(server){};

	MessageServer::~MessageServer(){};

	void MessageServer::partialWrite(JsonWriter &writer)
	{
		writer.Key(jsonrpc.first);
		writer.String(jsonrpc.second);
	}
}
