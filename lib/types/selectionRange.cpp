#include <wlsp/types/selectionRange.hpp>

namespace wlsp
{

	using namespace std;

	const String SelectionRangeClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	SelectionRangeClientCapabilities::
		SelectionRangeClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	SelectionRangeClientCapabilities::SelectionRangeClientCapabilities(){};
	SelectionRangeClientCapabilities::~SelectionRangeClientCapabilities(){};

	SelectionRangeRegistrationOptions::
		SelectionRangeRegistrationOptions(optional<Boolean> workDoneProgress,
										  variant<DocumentSelector, Null> documentSelector,
										  optional<String> id) : SelectionRangeOptions(workDoneProgress),
																 TextDocumentRegistrationOptions(documentSelector),
																 StaticRegistrationOptions(id){};

	SelectionRangeRegistrationOptions::SelectionRangeRegistrationOptions(){};
	SelectionRangeRegistrationOptions::~SelectionRangeRegistrationOptions(){};

	void SelectionRangeRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		SelectionRangeOptions::partialWrite(writer);
		TextDocumentRegistrationOptions::partialWrite(writer);
		StaticRegistrationOptions::partialWrite(writer);
	}

	const String SelectionRangeParams::textDocumentKey = "textDocument";
	const String SelectionRangeParams::positionsKey = "positions";

	SelectionRangeParams::SelectionRangeParams(
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		TextDocumentIdentifier textDocument,
		vector<Position> positions) : WorkDoneProgressParams(workDoneToken),
									  PartialResultParams(partialResultToken),
									  textDocument(textDocument),
									  positions(positions){};

	SelectionRangeParams::SelectionRangeParams(){};
	SelectionRangeParams::~SelectionRangeParams(){};

	SelectionRangeParams::PositionsMaker::
		PositionsMaker(vector<Position> &parentArray) : parentArray(parentArray){};

	SelectionRangeParams::PositionsMaker::
		~PositionsMaker(){};

	const String SelectionRange::rangeKey = "range";
	const String SelectionRange::parentKey = "parent";

	SelectionRange::SelectionRange(Range range,
								   optional<shared_ptr<SelectionRange>> parent) : range(range),
																				  parent(parent){};

	SelectionRange::SelectionRange(Range range, SelectionRange parent) : range(range),
																		 parent(make_shared<SelectionRange>(parent)){};

	SelectionRange::SelectionRange(){};
	SelectionRange::~SelectionRange(){};

	void SelectionRange::partialWrite(JsonWriter &writer)
	{
		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// parent?
		if (parent.has_value())
		{
			writer.Key(parentKey);
			writer.Object(**parent);
		}
	}

}
