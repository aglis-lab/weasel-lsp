#pragma once

#include <wlsp/types/documentColor.hpp>
#include <wlsp/types/textEdit.hpp>

namespace wlsp
{

	using namespace std;

	/// ColorPresentation request parameters
	///
	/// textDocument: TextDocumentIdentifier
	///
	/// color: Color
	///
	/// range: Range
	///
	struct ColorPresentationParams : public WorkDoneProgressParams,
									 public PartialResultParams
	{
	private:
		const static String textDocumentKey;
		const static String colorKey;
		const static String rangeKey;

	public:
		/// The text document.
		TextDocumentIdentifier textDocument;

		/// The color information to request presentations for.
		Color color;

		/// The range where the color would be inserted. Serves as a context.
		Range range;

		//=======================================================================//

		// No writing

		ColorPresentationParams(optional<ProgressToken> workDoneToken,
								optional<ProgressToken> partialResultToken,
								TextDocumentIdentifier textDocument,
								Color color,
								Range range);

		ColorPresentationParams();

		virtual ~ColorPresentationParams();
	};

	/// Color presentation response result.
	///
	/// label: String
	///
	/// textEdit?: TextEdit
	///
	/// additionalTextEdits?: TextEdit[]
	///
	struct ColorPresentation : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String labelKey;
		const static String textEditKey;
		const static String additionalTextEditsKey;

	public:
		/// The label of this color presentation. It will be shown on the color
		/// picker header. By default this is also the text that is inserted when
		/// selecting this color presentation.
		String label;

		/// An edit which is applied to a document when selecting
		/// this presentation for the color.  When `falsy` the label
		/// is used.
		optional<TextEdit> textEdit;

		/// An optional array of additional text edits that are applied when
		/// selecting this color presentation. Edits must not overlap with the
		/// main edit nor with themselves.
		optional<vector<TextEdit>> additionalTextEdits;

		// No parsing

		ColorPresentation(String label,
						  optional<TextEdit> textEdit,
						  optional<vector<TextEdit>> additionalTextEdits);

		ColorPresentation();

		virtual ~ColorPresentation();
	};
}
