#include <wlsp/types/colorPresentation.hpp>

namespace wlsp
{

	using namespace std;

	const String ColorPresentationParams::textDocumentKey = "textDocument";
	const String ColorPresentationParams::colorKey = "color";
	const String ColorPresentationParams::rangeKey = "range";

	ColorPresentationParams::ColorPresentationParams(optional<ProgressToken> workDoneToken,
													 optional<ProgressToken> partialResultToken,
													 TextDocumentIdentifier textDocument,
													 Color color,
													 Range range) : WorkDoneProgressParams(workDoneToken),
																	PartialResultParams(partialResultToken),
																	textDocument(textDocument),
																	color(color),
																	range(range){};

	ColorPresentationParams::ColorPresentationParams(){};
	ColorPresentationParams::~ColorPresentationParams(){};

	const String ColorPresentation::labelKey = "label";
	const String ColorPresentation::textEditKey = "textEdit";
	const String ColorPresentation::additionalTextEditsKey = "additionalTextEdits";

	ColorPresentation::ColorPresentation(String label,
										 optional<TextEdit> textEdit,
										 optional<vector<TextEdit>> additionalTextEdits) : label(label),
																						   textEdit(textEdit),
																						   additionalTextEdits(additionalTextEdits){};

	ColorPresentation::ColorPresentation(){};
	ColorPresentation::~ColorPresentation(){};

	void ColorPresentation::partialWrite(JsonWriter &writer)
	{
		// label
		writer.Key(labelKey);
		writer.String(label.c_str());

		// textEdit?
		if (textEdit.has_value())
		{
			writer.Key(textEditKey);
			writer.Object(*textEdit);
		}

		// additionalTextEdits?
		if (additionalTextEdits.has_value())
		{
			writer.Key(additionalTextEditsKey);
			writer.StartArray();
			for (auto &i : *additionalTextEdits)
			{
				writer.Object(i);
			}
			writer.EndArray();
		}
	}

}
