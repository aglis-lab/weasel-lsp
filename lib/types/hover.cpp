#include <wlsp/types/hover.hpp>

namespace wlsp
{
	using namespace std;

	HoverClientCapabilities::HoverClientCapabilities(
		optional<Boolean> dynamicRegistration,
		optional<vector<MarkupKind>> contentFormat) : dynamicRegistration(dynamicRegistration),
													  contentFormat(contentFormat){};

	HoverRegistrationOptions::
		HoverRegistrationOptions(variant<DocumentSelector, Null> documentSelector,
								 optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
																	   HoverOptions(workDoneProgress){};

	void HoverRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		HoverOptions::partialWrite(writer);
	}

	HoverParams::HoverParams(TextDocumentIdentifier textDocument,
							 Position position,
							 optional<ProgressToken> workDoneToken) : TextDocumentPositionParams(textDocument, position),
																	  WorkDoneProgressParams(workDoneToken){};

	void Hover::partialWrite(JsonWriter &writer)
	{
		// contents
		writer.Key(contentsKey);
		writer.Object(contents);

		// range?
		if (range.has_value())
		{
			writer.Key(rangeKey);
			writer.Object(range.value());
		}
	}
}
