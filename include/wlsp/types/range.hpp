#pragma once

#include <variant>
#include <optional>

#include <wlsp/types/position.hpp>

namespace wlsp
{

using namespace std;

/// Comparable to a selection in the editor
///
/// start: Position
///
/// end: Position
///
struct Range: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String startKey;
	const static String endKey;

public:
	/// The range's start position.
	Position start;


	/// The range's end position.
	Position end;

	//=======================================================================//


	Range(Position start, Position end);

	Range();

	virtual ~Range();
};

}
