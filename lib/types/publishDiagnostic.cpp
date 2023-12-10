#include <wlsp/types/publishDiagnostic.hpp>

namespace wlsp
{

	using namespace std;

	const String PublishDiagnosticsClientCapabilities::
		relatedInformationKey = "relatedInformation";

	const String PublishDiagnosticsClientCapabilities::
		tagSupportKey = "tagSupport";

	const String PublishDiagnosticsClientCapabilities::
		versionSupportKey = "versionSupport";

	PublishDiagnosticsClientCapabilities::
		PublishDiagnosticsClientCapabilities(optional<Boolean> relatedInformation,
											 optional<TagSupport> tagSupport,
											 optional<Boolean> versionSupport) : relatedInformation(relatedInformation),
																				 tagSupport(tagSupport),
																				 versionSupport(versionSupport){};

	PublishDiagnosticsClientCapabilities::PublishDiagnosticsClientCapabilities(){};

	PublishDiagnosticsClientCapabilities::
		~PublishDiagnosticsClientCapabilities(){};

	const String PublishDiagnosticsClientCapabilities::TagSupport::
		valueSetKey = "valueSet";

	PublishDiagnosticsClientCapabilities::TagSupport::
		TagSupport(vector<DiagnosticTag> valueSet) : valueSet(valueSet){};

	PublishDiagnosticsClientCapabilities::TagSupport::TagSupport(){};
	PublishDiagnosticsClientCapabilities::TagSupport::~TagSupport(){};

	PublishDiagnosticsClientCapabilities::TagSupport::ValueSetMaker::
		ValueSetMaker(vector<DiagnosticTag> &parentArray) : parentArray(parentArray){};

	PublishDiagnosticsClientCapabilities::TagSupport::ValueSetMaker::
		~ValueSetMaker(){};

	const String PublishDiagnosticsParams::uriKey = "uri";
	const String PublishDiagnosticsParams::versionKey = "version";
	const String PublishDiagnosticsParams::diagnosticsKey = "diagnostics";

	PublishDiagnosticsParams::PublishDiagnosticsParams(DocumentUri uri,
													   optional<Number> version,
													   vector<Diagnostic> diagnostics) : uri(uri),
																						 version(version),
																						 diagnostics(diagnostics){};

	PublishDiagnosticsParams::PublishDiagnosticsParams(){};
	PublishDiagnosticsParams::~PublishDiagnosticsParams(){};

	void PublishDiagnosticsParams::partialWrite(JsonWriter &writer)
	{
		// uri
		writer.Key(uriKey);
		writer.String(uri);

		// version?
		if (version.has_value())
		{
			writer.Key(versionKey);
			writer.Number(*version);
		}

		// diagnostics
		writer.Key(diagnosticsKey);
		writer.StartArray();
		for (auto &i : diagnostics)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}

}
