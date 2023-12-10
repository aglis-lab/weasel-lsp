// TODO: CHECK IT
#include <iostream>

#include <wlsp/types/responseMessage.hpp>

#define JSON_RPC_KEY "jsonrpc"
#define JSON_RPC_VERSION "2.0"

namespace wlsp
{
	using namespace std;

	ResponseMessage::~ResponseMessage(){};

	void ResponseMessage::partialWrite(JsonWriter &writer)
	{
		writer.Key(JSON_RPC_KEY);
		writer.String(JSON_RPC_VERSION);

		writer.Key(this->idKey);
		if (this->id.has_value())
		{
			writer.Int(this->id.value());
		}
		else
		{
			writer.Null();
		}

		writer.Key(this->resultKey);
		if (result)
		{
			writer.Object(*result);
		}
		else
		{
			writer.Null();
		}

		// error?
		writer.Key(errorKey);
		if (error.has_value())
		{
			// writer.Object(*error);
		}
		else
		{
			writer.Null();
		}

		// // result?
		// if (result.has_value() && !holds_alternative<Null>(id))
		// {
		// 	// Completes the request send from the client.
		// 	String method = server.completeRequest(methodId, RequestKind::fromClient);

		// 	optional<Capability> capability = server.getCapability(method);
		// 	if (capability.has_value())
		// 	{
		// 		writer.Key(resultKey);
		// 		capability->result->writer.value()(writer, *result);
		// 	}
		// }
	}

	const String ResponseError::codeKey = "code";
	const String ResponseError::messageKey = "message";
	const String ResponseError::dataKey = "data";

	ResponseError::ResponseError(ErrorCodes code, String message,
								 optional<variant<String, Number, Boolean, Array, Object, Null>> data) : code(code),
																										 message(message),
																										 data(data){};

	ResponseError::ResponseError(){};
	ResponseError::~ResponseError(){};

	void ResponseError::partialWrite(JsonWriter &writer)
	{
		// code
		writer.Key(codeKey);
		writer.Int((int)code);

		// message
		writer.Key(messageKey);
		writer.String(message);

		// data?
		writeData(writer);
	}

	void ResponseError::writeData(JsonWriter &writer)
	{
		if (data.has_value())
		{
			writer.Key(dataKey);
			visit(overload(
					  [&writer](String &str)
					  {
						  writer.String(str);
					  },
					  [&writer](Number n)
					  {
						  writer.Number(n);
					  },
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](Array &a)
					  {
						  writer.Array(a);
					  },
					  [&writer](Object obj)
					  {
						  writer.Object(*obj);
					  },
					  [&writer](Null)
					  {
						  writer.Null();
					  }),
				  data.value());
		}
	}
}
