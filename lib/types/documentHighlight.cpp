#include <wlsp/types/documentHighlight.hpp>

namespace wlsp
{

	using namespace std;

	const String DocumentHighlightClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	DocumentHighlightClientCapabilities::
		DocumentHighlightClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	DocumentHighlightClientCapabilities::DocumentHighlightClientCapabilities(){};
	DocumentHighlightClientCapabilities::~DocumentHighlightClientCapabilities(){};

	DocumentHighlightRegistrationOptions::DocumentHighlightRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
											  DocumentHighlightOptions(workDoneProgress){};

	DocumentHighlightRegistrationOptions::DocumentHighlightRegistrationOptions(){};
	DocumentHighlightRegistrationOptions::~DocumentHighlightRegistrationOptions(){};

	void DocumentHighlightRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		DocumentHighlightOptions::partialWrite(writer);
	}

	DocumentHighlightParams::DocumentHighlightParams(TextDocumentIdentifier textDocument,
													 Position position,
													 optional<ProgressToken> workDoneToken,
													 optional<ProgressToken> partialResultToken) : TextDocumentPositionParams(textDocument, position),
																								   WorkDoneProgressParams(workDoneToken),
																								   PartialResultParams(partialResultToken){};

	DocumentHighlightParams::DocumentHighlightParams(){};
	DocumentHighlightParams::~DocumentHighlightParams(){};

	const String DocumentHighlight::rangeKey = "range";
	const String DocumentHighlight::kindKey = "kind";

	DocumentHighlight::DocumentHighlight(Range range,
										 optional<DocumentHighlightKind> kind) : range(range),
																				 kind(kind){};

	DocumentHighlight::DocumentHighlight(){};
	DocumentHighlight::~DocumentHighlight(){};

	void DocumentHighlight::partialWrite(JsonWriter &writer)
	{
		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// kind?
		if (kind.has_value())
		{
			writer.Key(kindKey);
			writer.Int((int)(*kind));
		}
	}

}
