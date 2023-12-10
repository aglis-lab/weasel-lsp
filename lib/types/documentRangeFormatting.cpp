#include <wlsp/types/documentRangeFormatting.hpp>

namespace wlsp
{

	using namespace std;

	const String DocumentRangeFormattingClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	DocumentRangeFormattingClientCapabilities::
		DocumentRangeFormattingClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	DocumentRangeFormattingClientCapabilities::
		DocumentRangeFormattingClientCapabilities(){};

	DocumentRangeFormattingClientCapabilities::
		~DocumentRangeFormattingClientCapabilities(){};

	DocumentRangeFormattingRegistrationOptions::DocumentRangeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
											  DocumentRangeFormattingOptions(workDoneProgress){};

	DocumentRangeFormattingRegistrationOptions::
		DocumentRangeFormattingRegistrationOptions(){};

	DocumentRangeFormattingRegistrationOptions::
		~DocumentRangeFormattingRegistrationOptions(){};

	void DocumentRangeFormattingRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		DocumentRangeFormattingOptions::partialWrite(writer);
	}

	const String DocumentRangeFormattingParams::textDocumentKey = "textDocument";
	const String DocumentRangeFormattingParams::rangeKey = "range";
	const String DocumentRangeFormattingParams::optionsKey = "options";

	DocumentRangeFormattingParams::DocumentRangeFormattingParams(
		optional<ProgressToken> workDoneToken,
		TextDocumentIdentifier textDocument,
		Range range,
		FormattingOptions options) : WorkDoneProgressParams(workDoneToken),
									 textDocument(textDocument),
									 range(range),
									 options(options){};

	DocumentRangeFormattingParams::DocumentRangeFormattingParams(){};
	DocumentRangeFormattingParams::~DocumentRangeFormattingParams(){};
}
