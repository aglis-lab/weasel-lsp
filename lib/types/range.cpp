#include <wlsp/types/range.hpp>

namespace wlsp
{

	using namespace std;

	const String Range::startKey = "start";
	const String Range::endKey = "end";

	Range::Range(Position start, Position end) : start(start),
												 end(end){};

	Range::Range(){};
	Range::~Range(){};

	void Range::partialWrite(JsonWriter &writer)
	{
		// start
		writer.Key(startKey);
		writer.Object(start);

		// end
		writer.Key(endKey);
		writer.Object(end);
	}
}
