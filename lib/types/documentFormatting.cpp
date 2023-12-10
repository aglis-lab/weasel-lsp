#include <wlsp/types/documentFormatting.hpp>

namespace wlsp
{

	using namespace std;

	const String DocumentFormattingClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	DocumentFormattingClientCapabilities::
		DocumentFormattingClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	DocumentFormattingClientCapabilities::DocumentFormattingClientCapabilities(){};
	DocumentFormattingClientCapabilities::~DocumentFormattingClientCapabilities(){};

	DocumentFormattingRegistrationOptions::DocumentFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
											  DocumentFormattingOptions(workDoneProgress){};

	DocumentFormattingRegistrationOptions::DocumentFormattingRegistrationOptions(){};
	DocumentFormattingRegistrationOptions::~DocumentFormattingRegistrationOptions(){};

	void DocumentFormattingRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		DocumentFormattingOptions::partialWrite(writer);
	}

	const String FormattingOptions::
		tabSizeKey = "tabSize";

	const String FormattingOptions::
		insertSpacesKey = "insertSpaces";

	const String FormattingOptions::
		trimTrailingWhitespaceKey = "trimTrailingWhitespace";

	const String FormattingOptions::
		insertFinalNewlineKey = "insertFinalNewline";

	const String FormattingOptions::
		trimFinalNewlinesKey = "trimFinalNewlines";

	FormattingOptions::FormattingOptions(Number tabSize,
										 Boolean insertSpaces,
										 optional<Boolean> trimTrailingWhitespace,
										 optional<Boolean> insertFinalNewline,
										 optional<Boolean> trimFinalNewlines,
										 map<String, variant<Boolean, Number, String>> extras) : tabSize(tabSize),
																								 insertSpaces(insertSpaces),
																								 trimTrailingWhitespace(trimTrailingWhitespace),
																								 insertFinalNewline(insertFinalNewline),
																								 trimFinalNewlines(trimFinalNewlines),
																								 extras(extras){};

	FormattingOptions::FormattingOptions(){};
	FormattingOptions::~FormattingOptions(){};

	const String DocumentFormattingParams::textDocumentKey = "textDocument";
	const String DocumentFormattingParams::optionsKey = "options";

	DocumentFormattingParams::DocumentFormattingParams(
		optional<ProgressToken> workDoneToken,
		TextDocumentIdentifier textDocument,
		FormattingOptions options) : WorkDoneProgressParams(workDoneToken),
									 textDocument(textDocument),
									 options(options){};

	DocumentFormattingParams::DocumentFormattingParams(){};
	DocumentFormattingParams::~DocumentFormattingParams(){};
}
