#include <wlsp/types/documentLink.hpp>

namespace wlsp
{

	using namespace std;

	const String DocumentLinkClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String DocumentLinkClientCapabilities::
		tooltipSupportKey = "tooltipSupport";

	DocumentLinkClientCapabilities::
		DocumentLinkClientCapabilities(optional<Boolean> dynamicRegistration,
									   optional<Boolean> tooltipSupport) : dynamicRegistration(dynamicRegistration),
																		   tooltipSupport(tooltipSupport){};

	DocumentLinkClientCapabilities::DocumentLinkClientCapabilities(){};
	DocumentLinkClientCapabilities::~DocumentLinkClientCapabilities(){};

	const String DocumentLinkOptions::resolveProviderKey = "resolveProvider";

	DocumentLinkOptions::DocumentLinkOptions(optional<Boolean> workDoneProgress,
											 optional<Boolean> resolveProvider) : WorkDoneProgressOptions(workDoneProgress),
																				  resolveProvider(resolveProvider){};

	DocumentLinkOptions::DocumentLinkOptions(){};
	DocumentLinkOptions::~DocumentLinkOptions(){};

	void DocumentLinkOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		WorkDoneProgressOptions::partialWrite(writer);

		// resolveProvider?
		if (resolveProvider.has_value())
		{
			writer.Key(resolveProviderKey);
			writer.Bool(*resolveProvider);
		}
	}

	DocumentLinkRegistrationOptions::DocumentLinkRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<Boolean> resolveProvider) : TextDocumentRegistrationOptions(documentSelector),
											 DocumentLinkOptions(workDoneProgress, resolveProvider){};

	DocumentLinkRegistrationOptions::DocumentLinkRegistrationOptions(){};
	DocumentLinkRegistrationOptions::~DocumentLinkRegistrationOptions(){};

	void DocumentLinkRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		DocumentLinkOptions::partialWrite(writer);
	}

	const String DocumentLinkParams::textDocumentKey = "textDocument";

	DocumentLinkParams::DocumentLinkParams(optional<ProgressToken> workDoneToken,
										   optional<ProgressToken> partialResultToken,
										   TextDocumentIdentifier textDocument) : WorkDoneProgressParams(workDoneToken),
																				  PartialResultParams(partialResultToken),
																				  textDocument(textDocument){};

	DocumentLinkParams::DocumentLinkParams(){};
	DocumentLinkParams::~DocumentLinkParams(){};

	const String DocumentLink::rangeKey = "range";
	const String DocumentLink::targetKey = "target";
	const String DocumentLink::tooltipKey = "tooltip";
	const String DocumentLink::dataKey = "data";

	DocumentLink::DocumentLink(Range range,
							   optional<DocumentUri> target,
							   optional<String> tooltip,
							   optional<Any> data) : range(range),
													 target(target),
													 tooltip(tooltip),
													 data(data){};

	DocumentLink::DocumentLink(){};
	DocumentLink::~DocumentLink(){};

	void DocumentLink::partialWrite(JsonWriter &writer)
	{
		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// target?
		if (target.has_value())
		{
			writer.Key(targetKey);
			writer.String(*target);
		}

		// tooltip?
		if (tooltip.has_value())
		{
			writer.Key(tooltipKey);
			writer.String(*tooltip);
		}

		// data?
		if (data.has_value())
		{
			writer.Key(dataKey);
			writer.Any(*data);
		}
	}

}
