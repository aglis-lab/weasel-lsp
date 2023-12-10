#include <wlsp/types/didChangeTextDocument.hpp>

namespace wlsp
{

	using namespace std;

	const String TextDocumentChangeRegistrationOptions::syncKindKey = "syncKind";

	TextDocumentChangeRegistrationOptions::TextDocumentChangeRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		TextDocumentSyncKind syncKind) : TextDocumentRegistrationOptions(documentSelector),
										 syncKind(syncKind){};

	TextDocumentChangeRegistrationOptions::TextDocumentChangeRegistrationOptions(){};

	TextDocumentChangeRegistrationOptions::
		~TextDocumentChangeRegistrationOptions(){};

	void TextDocumentChangeRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		TextDocumentRegistrationOptions::partialWrite(writer);

		// syncKind
		writer.Key(syncKindKey);
		writer.Int((int)syncKind);
	}

	const String TextDocumentContentChangeEvent::rangeKey = "range";
	const String TextDocumentContentChangeEvent::rangeLengthKey = "rangeLength";
	const String TextDocumentContentChangeEvent::textKey = "text";

	TextDocumentContentChangeEvent::
		TextDocumentContentChangeEvent(Range range, String text) : range(range),
																   text(text){};

	TextDocumentContentChangeEvent::
		TextDocumentContentChangeEvent(String text) : text(text){};

	TextDocumentContentChangeEvent::TextDocumentContentChangeEvent(){};
	TextDocumentContentChangeEvent::~TextDocumentContentChangeEvent(){};

	const String DidChangeTextDocumentParams::textDocumentKey = "textDocument";
	const String DidChangeTextDocumentParams::contentChangesKey = "contentChanges";

	DidChangeTextDocumentParams::
		DidChangeTextDocumentParams(VersionedTextDocumentIdentifier textDocument,
									vector<TextDocumentContentChangeEvent> contentChanges) : textDocument(textDocument),
																							 contentChanges(contentChanges){};

	DidChangeTextDocumentParams::DidChangeTextDocumentParams(){};
	DidChangeTextDocumentParams::~DidChangeTextDocumentParams(){};

	DidChangeTextDocumentParams::ContentChangesMaker::ContentChangesMaker(vector<TextDocumentContentChangeEvent> &parentArray) : parentArray(parentArray){};

	DidChangeTextDocumentParams::ContentChangesMaker::~ContentChangesMaker(){};
}
