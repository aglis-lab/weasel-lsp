#pragma once

#include <optional>

#include <wlsp/types/range.hpp>
#include <wlsp/types/textDocumentIdentifier.hpp>

namespace wlsp
{

	using namespace std;

	/// A textual edit applicable to a text document.
	///
	/// range: Range
	///
	/// newText: String
	///
	struct TextEdit : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String rangeKey;
		const static String newTextKey;

	public:
		/// The range of the text document to be manipulated. To insert
		/// text into a document create a range where start == end.
		Range range;

		/// The string to be inserted. For delete operations use an
		/// empty string.
		String newText;

		//=======================================================================//

		TextEdit(Range range, String newText);

		TextEdit();

		virtual ~TextEdit();
	};

	/// Describes textual changes on a single text document.
	///
	/// textDocument: VersionedTextDocumentIdentifier
	///
	/// edits: TextEdit[]
	///
	struct TextDocumentEdit : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String textDocumentKey;
		const static String editsKey;

		struct EditsMaker : public ObjectT
		{
			// The object where the array is build
			TextDocumentEdit *parent;
		};

	public:
		/// The text document to change.
		VersionedTextDocumentIdentifier textDocument;

		/// The edits to be applied.
		vector<TextEdit> edits;

		//=======================================================================//

		TextDocumentEdit(VersionedTextDocumentIdentifier textDocument,
						 vector<TextEdit> edits);

		TextDocumentEdit();

		virtual ~TextDocumentEdit();
	};

}
