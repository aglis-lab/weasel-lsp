#include <wlsp/types/foldingRange.hpp>

namespace wlsp
{

	using namespace std;

	const String FoldingRangeClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String FoldingRangeClientCapabilities::
		rangeLimitKey = "rangeLimit";

	const String FoldingRangeClientCapabilities::
		lineFoldingOnlyKey = "lineFoldingOnly";

	FoldingRangeClientCapabilities::
		FoldingRangeClientCapabilities(optional<Boolean> dynamicRegistration,
									   optional<Number> rangeLimit,
									   optional<Boolean> lineFoldingOnly) : dynamicRegistration(dynamicRegistration),
																			rangeLimit(rangeLimit),
																			lineFoldingOnly(lineFoldingOnly){};

	FoldingRangeClientCapabilities::FoldingRangeClientCapabilities(){};
	FoldingRangeClientCapabilities::~FoldingRangeClientCapabilities(){};

	FoldingRangeRegistrationOptions::
		FoldingRangeRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress,
			optional<String> id) : TextDocumentRegistrationOptions(documentSelector),
								   FoldingRangeOptions(workDoneProgress),
								   StaticRegistrationOptions(id){};

	FoldingRangeRegistrationOptions::FoldingRangeRegistrationOptions(){};
	FoldingRangeRegistrationOptions::~FoldingRangeRegistrationOptions(){};

	void FoldingRangeRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		FoldingRangeOptions::partialWrite(writer);
		StaticRegistrationOptions::partialWrite(writer);
	}

	const String FoldingRangeParams::textDocumentKey = "textDocument";

	FoldingRangeParams::FoldingRangeParams(optional<ProgressToken> workDoneToken,
										   optional<ProgressToken> partialResultToken,
										   TextDocumentIdentifier textDocument) : WorkDoneProgressParams(workDoneToken),
																				  PartialResultParams(partialResultToken),
																				  textDocument(textDocument){};

	FoldingRangeParams::FoldingRangeParams(){};
	FoldingRangeParams::~FoldingRangeParams(){};

	FoldingRangeKind::FoldingRangeKind(String kind) : kind(kind){};

	FoldingRangeKind::~FoldingRangeKind(){};

	const FoldingRangeKind FoldingRangeKind::Comment = "comment"s;
	const FoldingRangeKind FoldingRangeKind::Imports = "imports"s;
	const FoldingRangeKind FoldingRangeKind::Region = "region"s;

	const String FoldingRange::startLineKey = "startLine";
	const String FoldingRange::startCharacterKey = "startCharacter";
	const String FoldingRange::endLineKey = "endLine";
	const String FoldingRange::endCharacterKey = "endCharacter";
	const String FoldingRange::kindKey = "kind";

	FoldingRange::FoldingRange(Number startLine,
							   optional<Number> startCharacter,
							   Number endLine,
							   optional<Number> endCharacter,
							   optional<FoldingRangeKind> kind) : startLine(startLine),
																  startCharacter(startCharacter),
																  endLine(endLine),
																  endCharacter(endCharacter),
																  kind(kind){};

	FoldingRange::FoldingRange(){};
	FoldingRange::~FoldingRange(){};

	void FoldingRange::partialWrite(JsonWriter &writer)
	{
		// startLine
		writer.Key(startLineKey);
		writer.Number(startLine);

		// startCharacter?
		if (startCharacter.has_value())
		{
			writer.Key(startCharacterKey);
			writer.Number(*startCharacter);
		}

		// endLine
		writer.Key(endLineKey);
		writer.Number(endLine);

		// endCharacter?
		if (endCharacter.has_value())
		{
			writer.Key(endCharacterKey);
			writer.Number(*endCharacter);
		}

		// kind?
		if (kind.has_value())
		{
			writer.Key(kindKey);
			writer.String(*kind);
		}
	}

}
