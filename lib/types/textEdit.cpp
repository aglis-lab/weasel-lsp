#include <wlsp/types/textEdit.hpp>

namespace wlsp
{

	using namespace std;

	const String TextEdit::rangeKey = "range";
	const String TextEdit::newTextKey = "newText";

	TextEdit::TextEdit(Range range, String newText) : range(range),
													  newText(newText){};

	TextEdit::TextEdit(){};
	TextEdit::~TextEdit(){};

	void TextEdit::partialWrite(JsonWriter &writer)
	{
		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// newText
		writer.Key(newTextKey);
		writer.String(newText);
	}

	const String TextDocumentEdit::textDocumentKey = "textDocument";
	const String TextDocumentEdit::editsKey = "edits";

	TextDocumentEdit::TextDocumentEdit(VersionedTextDocumentIdentifier textDocument,
									   vector<TextEdit> edits) : textDocument(textDocument),
																 edits(edits){};

	TextDocumentEdit::TextDocumentEdit(){};
	TextDocumentEdit::~TextDocumentEdit(){};

	void TextDocumentEdit::partialWrite(JsonWriter &writer)
	{
		// textDocument
		writer.Key(textDocumentKey);
		writer.Object(textDocument);

		// edits
		writer.Key(editsKey);
		writer.StartArray();
		for (auto &i : edits)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}
}
