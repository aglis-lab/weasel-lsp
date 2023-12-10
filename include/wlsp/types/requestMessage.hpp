#pragma once

#include <any>
#include <functional>
#include <optional>
#include <variant>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/message.hpp>

namespace wlsp
{
	using namespace std;

	/// A request message to describe a request between the client and the server.
	///
	/// id: Number | String
	///
	/// method: String
	///
	/// params?: any
	///
	struct RequestMessage : public Message
	{
		static constexpr NativeString idKey = "id";
		static constexpr NativeString methodKey = "method";
		static constexpr NativeString paramsKey = "params";

		/// The request id.
		/// The id of the message should be int not string
		optional<int> id;

		/// The method to be invoked.
		String method;

		/// The method's params.
		optional<any> params;

		optional<function<void(any &, Writer<StringBuffer> &)>> paramsWriter;

		RequestMessage(String jsonrpc, optional<int> id, String method) : Message(jsonrpc), id(id), method(method) {}

		~RequestMessage();
	};
}
