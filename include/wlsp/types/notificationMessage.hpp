#pragma once

#include <variant>
#include <optional>

#include <wlsp/server/server.hpp>

#include <wlsp/types/message.hpp>

namespace wlsp
{

	using namespace std;

	/// A notification message.
	/// A processed notification message must not send a response back.
	///
	/// method: String
	///
	/// params?: any
	///
	struct NotificationMessage : public MessageServer
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String methodKey;
		const static String paramsKey;

	public:
		/// The method to be invoked.
		String method;

		/// The notification's params.
		optional<any> params;

		NotificationMessage(Server &server,
							String method,
							optional<any> params);

		NotificationMessage(Server &server);

		virtual ~NotificationMessage();
	};
}
