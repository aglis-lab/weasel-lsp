#include <wlsp/types/partialResult.hpp>

namespace wlsp
{

	using namespace std;

	const String PartialResultParams::partialResultTokenKey = "partialResultToken";

	PartialResultParams::
		PartialResultParams(optional<ProgressToken> partialResultToken) : partialResultToken(partialResultToken){};

	PartialResultParams::PartialResultParams(){};
	PartialResultParams::~PartialResultParams(){};

	void PartialResultParams::partialWrite(JsonWriter &writer)
	{
		// partialResultToken?
		if (partialResultToken.has_value())
		{
			writer.Key(partialResultTokenKey);
			visit(overload(
					  [&writer](String &str)
					  {
						  writer.String(str);
					  },
					  [&writer](Number n)
					  {
						  writer.Number(n);
					  }),
				  *partialResultToken);
		}
	}

}
