#pragma once

#include <string>

#include <wlsp/json/jsonValue.hpp>
#include <wlsp/server/server.hpp>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{
	struct MessageServer : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

		/// A reference to the lsp server
		Server &server;

	public:
		const static std::pair<String, String> jsonrpc;

		MessageServer(Server &server);
		virtual ~MessageServer();
	};

	struct Message : public ObjectT
	{
	public:
		friend class Builder;

	public:
		String jsonrpc;

		Message(String jsonrpc) : jsonrpc(jsonrpc) {}

	private:
		static constexpr NativeString jsonrpcKey = "jsonrpc";
	};
}
