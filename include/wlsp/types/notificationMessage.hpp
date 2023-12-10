#pragma once

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
	struct NotificationMessage : public Message
	{
	public:
		friend class Builder;

	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		static constexpr NativeString methodKey = "method";
		static constexpr NativeString paramsKey = "params";

	public:
		/// The method to be invoked.
		String method;

		/// The notification's params.
		unique_ptr<ObjectT> params;

		NotificationMessage(String method, unique_ptr<ObjectT> params);

		virtual ~NotificationMessage();
	};
}
