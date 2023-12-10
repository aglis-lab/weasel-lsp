#include <wlsp/types/didSaveTextDocument.hpp>

namespace wlsp
{

	using namespace std;

	const String SaveOptions::includeTextKey = "includeText";

	SaveOptions::SaveOptions(optional<Boolean> includeText) : includeText(includeText){};

	SaveOptions::SaveOptions(){};
	SaveOptions::~SaveOptions(){};

	void SaveOptions::partialWrite(JsonWriter &writer)
	{
		// includeText?
		if (includeText.has_value())
		{
			writer.Key(includeTextKey);
			writer.Bool(*includeText);
		}
	}

	const String TextDocumentSaveRegistrationOptions::includeTextKey = "includeText";

	TextDocumentSaveRegistrationOptions::TextDocumentSaveRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> includeText) : TextDocumentRegistrationOptions(documentSelector),
										 includeText(includeText){};

	TextDocumentSaveRegistrationOptions::TextDocumentSaveRegistrationOptions(){};
	TextDocumentSaveRegistrationOptions::~TextDocumentSaveRegistrationOptions(){};

	void TextDocumentSaveRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		TextDocumentRegistrationOptions::partialWrite(writer);

		// includeText?
		if (includeText.has_value())
		{
			writer.Key(includeTextKey);
			writer.Bool(*includeText);
		}
	}

	const String DidSaveTextDocumentParams::textDocumentKey = "textDocument";
	const String DidSaveTextDocumentParams::textKey = "text";

	DidSaveTextDocumentParams::
		DidSaveTextDocumentParams(TextDocumentIdentifier textDocument,
								  optional<String> text) : textDocument(textDocument),
														   text(text){};

	DidSaveTextDocumentParams::DidSaveTextDocumentParams(){};
	DidSaveTextDocumentParams::~DidSaveTextDocumentParams(){};
}
