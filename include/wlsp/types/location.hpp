#pragma once

#include <variant>
#include <optional>

#include <wlsp/types/range.hpp>

namespace wlsp
{

using namespace std;

/// Represents a location inside a resource, such as a line inside a text file.
///
/// uri: DocumentUri
///
/// range: Range
///
struct Location: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String uriKey;
	const static String rangeKey;

public:
	DocumentUri uri;

	Range range;

	//=======================================================================//


	Location(DocumentUri uri, Range range);

	Location();

	virtual ~Location();
};

}
