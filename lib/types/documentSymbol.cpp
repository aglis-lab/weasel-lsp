#include <wlsp/types/documentSymbol.hpp>

namespace wlsp
{

	using namespace std;

	const String DocumentSymbolClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String DocumentSymbolClientCapabilities::
		symbolKindKey = "symbolKind";

	const String DocumentSymbolClientCapabilities::
		hierarchicalDocumentSymbolSupportKey = "hierarchicalDocumentSymbolSupport";

	DocumentSymbolClientCapabilities::
		DocumentSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
										 optional<SymbolKind> symbolKind,
										 optional<Boolean> hierarchicalDocumentSymbolSupport) : dynamicRegistration(dynamicRegistration),
																								symbolKind(symbolKind),
																								hierarchicalDocumentSymbolSupport(hierarchicalDocumentSymbolSupport){};

	DocumentSymbolClientCapabilities::DocumentSymbolClientCapabilities(){};
	DocumentSymbolClientCapabilities::~DocumentSymbolClientCapabilities(){};

	const String DocumentSymbolClientCapabilities::SymbolKind::
		valueSetKey = "valueSet";

	DocumentSymbolClientCapabilities::SymbolKind::
		SymbolKind(optional<vector<wlsp::SymbolKind>> valueSet) : valueSet(valueSet){};

	DocumentSymbolClientCapabilities::SymbolKind::SymbolKind(){};
	DocumentSymbolClientCapabilities::SymbolKind::~SymbolKind(){};

	DocumentSymbolClientCapabilities::SymbolKind::ValueSetMaker::
		ValueSetMaker(vector<wlsp::SymbolKind> &parentArray) : parentArray(parentArray){};

	DocumentSymbolClientCapabilities::SymbolKind::ValueSetMaker::
		~ValueSetMaker(){};

	DocumentSymbolRegistrationOptions::DocumentSymbolRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
											  DocumentSymbolOptions(workDoneProgress){};

	DocumentSymbolRegistrationOptions::DocumentSymbolRegistrationOptions(){};
	DocumentSymbolRegistrationOptions::~DocumentSymbolRegistrationOptions(){};

	void DocumentSymbolRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		DocumentSymbolOptions::partialWrite(writer);
	}

	const String DocumentSymbolParams::textDocumentKey = "textDocument";

	DocumentSymbolParams::DocumentSymbolParams(optional<ProgressToken> workDoneToken,
											   optional<ProgressToken> partialResultToken,
											   TextDocumentIdentifier textDocument) : WorkDoneProgressParams(workDoneToken),
																					  PartialResultParams(partialResultToken),
																					  textDocument(textDocument){};

	DocumentSymbolParams::DocumentSymbolParams(){};
	DocumentSymbolParams::~DocumentSymbolParams(){};

	const String DocumentSymbol::nameKey = "name";
	const String DocumentSymbol::detailKey = "detail";
	const String DocumentSymbol::kindKey = "kind";
	const String DocumentSymbol::deprecatedKey = "deprecated";
	const String DocumentSymbol::rangeKey = "range";
	const String DocumentSymbol::selectionRangeKey = "selectionRange";
	const String DocumentSymbol::childrenKey = "children";

	DocumentSymbol::DocumentSymbol(String name,
								   optional<String> detail,
								   SymbolKind kind,
								   optional<Boolean> deprecated,
								   Range range,
								   Range selectionRange,
								   optional<vector<DocumentSymbol>> children) : name(name),
																				detail(detail),
																				kind(kind),
																				deprecated(deprecated),
																				range(range),
																				selectionRange(selectionRange),
																				children(children){};

	DocumentSymbol::DocumentSymbol(){};
	DocumentSymbol::~DocumentSymbol(){};

	void DocumentSymbol::partialWrite(JsonWriter &writer)
	{
		// name
		writer.Key(nameKey);
		writer.String(name);

		// detail?
		if (detail.has_value())
		{
			writer.Key(detailKey);
			writer.String(*detail);
		}

		// kind
		writer.Key(kindKey);
		writer.Int((int)kind);

		// deprecated?
		if (deprecated.has_value())
		{
			writer.Key(deprecatedKey);
			writer.Bool(*deprecated);
		}

		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// selectionRange
		writer.Key(selectionRangeKey);
		writer.Object(selectionRange);

		// children?
		if (children.has_value())
		{
			writer.Key(childrenKey);
			writer.StartArray();
			for (auto &i : *children)
			{
				writer.Object(i);
			}
			writer.EndArray();
		}
	}

	const String SymbolInformation::nameKey = "name";
	const String SymbolInformation::kindKey = "kind";
	const String SymbolInformation::deprecatedKey = "deprecated";
	const String SymbolInformation::locationKey = "location";
	const String SymbolInformation::containerNameKey = "containerName";

	SymbolInformation::SymbolInformation(String name,
										 SymbolKind kind,
										 optional<Boolean> deprecated,
										 Location location,
										 optional<String> containerName) : name(name),
																		   kind(kind),
																		   deprecated(deprecated),
																		   location(location),
																		   containerName(containerName){};

	SymbolInformation::SymbolInformation(){};
	SymbolInformation::~SymbolInformation(){};

	void SymbolInformation::partialWrite(JsonWriter &writer)
	{
		// name
		writer.Key(nameKey);
		writer.String(name);

		// kind
		writer.Key(kindKey);
		writer.Int((int)kind);

		// deprecated?
		if (deprecated.has_value())
		{
			writer.Key(deprecatedKey);
			writer.Bool(*deprecated);
		}

		// location
		writer.Key(locationKey);
		writer.Object(location);

		// containerName?
		if (containerName.has_value())
		{
			writer.Key(containerNameKey);
			writer.String(*containerName);
		}
	}

}
