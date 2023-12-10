#include <wlsp/types/location.hpp>

namespace wlsp
{

	using namespace std;

	const String Location::uriKey = "uri";
	const String Location::rangeKey = "range";

	Location::Location(DocumentUri uri, Range range) : uri(uri),
													   range(range){};

	Location::Location(){};
	Location::~Location(){};

	void Location::partialWrite(JsonWriter &writer)
	{
		// uri
		writer.Key(uriKey);
		writer.String(uri);

		// range
		writer.Key(rangeKey);
		writer.Object(range);
	}

}
