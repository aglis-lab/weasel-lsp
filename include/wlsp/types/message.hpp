#pragma once

#include <string>

#include <wlsp/json/jsonValue.hpp>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{
	struct Message : public ObjectT
	{
	public:
		friend class Builder;

	public:
		String jsonrpc;

		Message(String jsonrpc) : jsonrpc(jsonrpc) {}

	protected:
		static constexpr NativeString jsonrpcKey = "jsonrpc";
	};
}
