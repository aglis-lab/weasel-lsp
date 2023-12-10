#pragma once

#include <optional>

#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

/// A document filter denotes a document through properties
/// like language, scheme or pattern
///
/// language?: String
///
/// scheme?: String
///
/// pattern?: String
///
struct DocumentFilter: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String languageKey;
	const static String schemeKey;
	const static String patternKey;

public:
	/// A language id, like `typescript`.
	optional<String> language;

	/// A Uri [scheme](#Uri.scheme), like `file` or `untitled`.
	optional<String> scheme;

	/// A glob pattern, like `*.{ts,js}`.
	///
	/// Glob patterns can have the following syntax:
	/// - `*` to match one or more characters in a path segment
	/// - `?` to match on one character in a path segment
	/// - `**` to match any number of path segments, including none
	/// - `{}` to group conditions
	/// - `[]` to declare a range of characters to match in a path segment
	/// - `[!...]` to negate a range of characters to match in a path segment
	optional<String> pattern;

	// No parsing

	DocumentFilter(optional<String> language,
		optional<String> scheme,
		optional<String> pattern);

	DocumentFilter();

	virtual ~DocumentFilter();
};

/// A document selector is the combination of one or more document filters.
using DocumentSelector = vector<DocumentFilter>;

}
