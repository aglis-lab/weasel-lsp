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

	enum class ErrorCodes
	{
		// Json-rpc error codes
		ParseError = -32700,
		InvalidRequest = -32600,
		MethodNotFound = -32601,
		InvalidParams = -32602,
		InternalError = -32603,
		jsonrpcReservedErrorRangeStart = -32099,
		jsonrpcReservedErrorRangeEnd = -32000,
		ServerNotInitialized = -32002,
		UnknownErrorCode = -32001,

		// LSP error codes
		RequestCancelled = -32800,
		ContentModified = -32801
	};

	/// An object with the data of the error that ocurred
	///
	/// code: ErrorCodes
	///
	/// message: String
	///
	/// data?: String | Number | Boolean | Array | Object | Null
	///
	struct ResponseError : public ObjectT
	{
		const static String codeKey;
		const static String messageKey;
		const static String dataKey;

		/// A number indicating the error type that occurred.
		ErrorCodes code;

		/// A string providing a short description of the error.
		String message;

		/// A Primitive or Structured value that contains additional
		/// information about the error. Can be omitted.
		optional<variant<String, Number, Boolean, Array, Object, Null>> data;

		// Initialize variables outside the constructor.
		// The variant constructor is not very clever.
		ResponseError(ErrorCodes code, String message,
					  optional<variant<String, Number, Boolean, Array, Object, Null>> data);

		ResponseError();

		virtual ~ResponseError();

	private:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

		/// Writer for the data pair
		void writeData(JsonWriter &writer);
	};

	/// A Response MessageServer sent as a result of a request.
	///
	/// id: Number
	///
	///
	///
	/// result?: any
	///
	/// error?: ResponseError
	///
	struct ResponseMessage : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		static constexpr NativeString idKey = "id";
		static constexpr NativeString resultKey = "result";
		static constexpr NativeString errorKey = "error";

	public:
		/// The request id.
		optional<int> id;

		/// The result of a request. This member is REQUIRED on success.
		/// This member MUST NOT exist if there was an error invoking the method.
		ObjectT *result;

		/// The error object in case a request fails.
		optional<ResponseError> error;

		ResponseMessage(optional<int> id, ObjectT *result, optional<ResponseError> error) : id(id), result(result), error(error) {}

		virtual ~ResponseMessage();
	};
}
