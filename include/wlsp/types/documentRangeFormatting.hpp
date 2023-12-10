#pragma once

#include <wlsp/types/documentFormatting.hpp>

namespace wlsp
{

using namespace std;

/// DocumentRangeFormatting request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentRangeFormattingClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	//=======================================================================//

	// No writing

	DocumentRangeFormattingClientCapabilities(optional<Boolean> dynamicRegistration);

	DocumentRangeFormattingClientCapabilities();

	virtual ~DocumentRangeFormattingClientCapabilities();
};

using DocumentRangeFormattingOptions = WorkDoneProgressOptions; // No parsing

struct DocumentRangeFormattingRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentRangeFormattingOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:

	// No parsing

	DocumentRangeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	DocumentRangeFormattingRegistrationOptions();

	virtual ~DocumentRangeFormattingRegistrationOptions();
};

/// Document range formatting request parameters
///
/// textDocument: TextDocumentIdentifier
///
/// range: Range
///
/// options: FormattingOptions
///
struct DocumentRangeFormattingParams: public WorkDoneProgressParams
{
private:
	const static String textDocumentKey;
	const static String rangeKey;
	const static String optionsKey;

public:
	/// The document to format.
	TextDocumentIdentifier textDocument;

	/// The range to format
	Range range;

	/// The format options.
	FormattingOptions options;

	//=======================================================================//

	// No writing

	DocumentRangeFormattingParams(optional<ProgressToken> workDoneToken,
		TextDocumentIdentifier textDocument,
		Range range,
		FormattingOptions options);

	DocumentRangeFormattingParams();

	virtual ~DocumentRangeFormattingParams();
};

}
