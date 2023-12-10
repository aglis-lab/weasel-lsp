#pragma once

#include <map>

#include <wlsp/types/range.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

using namespace std;

/// DocumentFormatting request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentFormattingClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	//=======================================================================//

	// No writing

	DocumentFormattingClientCapabilities(optional<Boolean> dynamicRegistration);

	DocumentFormattingClientCapabilities();

	virtual ~DocumentFormattingClientCapabilities();
};

using DocumentFormattingOptions = WorkDoneProgressOptions; // No parsing

struct DocumentFormattingRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentFormattingOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	DocumentFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	DocumentFormattingRegistrationOptions();

	virtual ~DocumentFormattingRegistrationOptions();
};

/// Value-object describing what options formatting should use.
///
/// tabSize: Number
///
/// insertSpaces: Boolean
///
/// trimTrailingWhitespace?: Boolean
///
/// insertFinalNewline?: Boolean
///
/// trimFinalNewlines?: Boolean
///
/// [key: String]: Boolean | Number | String
///
struct FormattingOptions: public ObjectT
{
private:
	const static String tabSizeKey;
	const static String insertSpacesKey;
	const static String trimTrailingWhitespaceKey;
	const static String insertFinalNewlineKey;
	const static String trimFinalNewlinesKey;

public:
	/// Size of a tab in spaces.
	Number tabSize;

	/// Prefer spaces over tabs.
	Boolean insertSpaces;

	/// Trim trailing whitespace on a line.
	///
	/// @since 3.15.0
	optional<Boolean> trimTrailingWhitespace;

	/// Insert a newline character at the end of the file if one does not
	/// exist.
	///
	/// @since 3.15.0
	optional<Boolean> insertFinalNewline;

	/// Trim all newlines after the final newline at the end of the file.
	///
	/// @since 3.15.0
	optional<Boolean> trimFinalNewlines;

	/// Signature for further properties.
	map<String, variant<Boolean, Number, String>> extras;

	//=======================================================================//

	// No writing

	FormattingOptions(Number tabSize,
		Boolean insertSpaces,
		optional<Boolean> trimTrailingWhitespace,
		optional<Boolean> insertFinalNewline,
		optional<Boolean> trimFinalNewlines,
		map<String, variant<Boolean, Number, String>> extras);

	FormattingOptions();

	virtual ~FormattingOptions();
};

/// Document formatting request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// options: FormattingOptions
///
struct DocumentFormattingParams: public WorkDoneProgressParams
{
private:
	const static String textDocumentKey;
	const static String optionsKey;

public:
	/// The document to format.
	TextDocumentIdentifier textDocument;

	/// The format options.
	FormattingOptions options;

	//=======================================================================//

	// No writing

	DocumentFormattingParams(optional<ProgressToken> workDoneToken,
		TextDocumentIdentifier textDocument,
		FormattingOptions options);

	DocumentFormattingParams();

	virtual ~DocumentFormattingParams();
};

}
