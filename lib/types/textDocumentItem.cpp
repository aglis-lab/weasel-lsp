#include <wlsp/types/textDocumentItem.hpp>

namespace wlsp
{

	using namespace std;

	const String TextDocumentItem::uriKey = "uri";
	const String TextDocumentItem::languageIdKey = "languageId";
	const String TextDocumentItem::versionKey = "version";
	const String TextDocumentItem::textKey = "text";

	TextDocumentItem::TextDocumentItem(DocumentUri uri,
									   String languageId,
									   Number version,
									   String text) : uri(uri),
													  languageId(languageId),
													  version(version),
													  text(text){};

	TextDocumentItem::TextDocumentItem(){};
	TextDocumentItem::~TextDocumentItem(){};

	void TextDocumentItem::partialWrite(JsonWriter &writer)
	{
		// uri
		writer.Key(uriKey);
		writer.String(uri);

		// languageId
		writer.Key(languageIdKey);
		writer.String(languageId);

		// version
		writer.Key(versionKey);
		writer.Number(version);

		// text
		writer.Key(textKey);
		writer.String(text);
	}

}
