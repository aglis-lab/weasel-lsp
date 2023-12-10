#pragma once

#include <variant>
#include <optional>

#include <wlsp/types/range.hpp>

namespace wlsp
{

using namespace std;

/// Represents a link between a source and a target location.
///
/// originSelectionRange?: Range
///
/// targetUri: DocumentUri
///
/// targetRange: Range
///
/// targetSelectionRange: Range
///
struct LocationLink: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String originSelectionRangeKey;
	const static String targetUriKey;
	const static String targetRangeKey;
	const static String targetSelectionRangeKey;

public:
	/// Span of the origin of this link.
	///
	/// Used as the underlined span for mouse interaction.
	/// Defaults to the word range at the mouse position.
	optional<Range> originSelectionRange;

	/// The target resource identifier of this link.
	DocumentUri targetUri;

	/// The full target range of this link. If the target for example is a symbol
	/// then target range is the range enclosing this symbol not including
	/// leading/trailing whitespace but everything else like comments.
	/// This information is typically used to highlight the range in the editor.
	Range targetRange;

	/// The range that should be selected and revealed when this link is being followed,
	/// e.g the name of a function.  Must be contained by the the `targetRange`.
	/// See also `DocumentSymbol#range`
	Range targetSelectionRange;

	//=======================================================================//


	LocationLink(optional<Range> originSelectionRange,
		DocumentUri targetUri,
		Range targetRange,
		Range targetSelectionRange);

	LocationLink();

	virtual ~LocationLink();
};

}
