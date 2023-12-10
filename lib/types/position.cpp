#include <wlsp/types/position.hpp>

namespace wlsp
{
	using namespace std;

	Position::Position(Uint line, Uint character) : line(line),
													character(character){};

	Position::Position(){};
	Position::~Position(){};

	void Position::partialWrite(JsonWriter &writer)
	{
		// line
		writer.Key(lineKey);
		writer.Uint(line);

		// character
		writer.Key(characterKey);
		writer.Uint(character);
	}
}
