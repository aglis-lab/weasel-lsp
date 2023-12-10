#pragma once

#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

/// An item to transfer a text document from the client to the server.
///
/// uri: DocumentUri
///
/// languageId: String
///
/// version: Number
///
/// text: String
///
struct TextDocumentItem: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String uriKey;
	const static String languageIdKey;
	const static String versionKey;
	const static String textKey;

public:

	/// The text document's URI.
	DocumentUri uri;

	/// The text document's language identifier.
	String languageId;

	/// The version number of this document (it will increase after each
	/// change, including undo/redo).
	Number version;

	/// The content of the opened text document.
	String text;

	//=======================================================================//


	TextDocumentItem(DocumentUri uri,
		String languageId,
		Number version,
		String text);

	TextDocumentItem();

	virtual ~TextDocumentItem();
};

}
