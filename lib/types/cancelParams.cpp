#include <wlsp/types/cancelParams.hpp>

namespace wlsp
{

	using namespace std;

	const String CancelParams::idKey = "id";

	CancelParams::CancelParams(variant<Number, String> id) : id(id){};

	CancelParams::CancelParams(){};
	CancelParams::~CancelParams(){};

	void CancelParams::partialWrite(JsonWriter &writer)
	{
		// id:
		writer.Key(idKey);
		visit(
			overload(
				[&writer](Number n)
				{
					writer.Number(n);
				},
				[&writer](String &str)
				{
					writer.String(str.c_str());
				}),
			id);
	}
}
