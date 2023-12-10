#include <wlsp/types/implementation.hpp>

namespace wlsp
{

	using namespace std;

	const String ImplementationClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String ImplementationClientCapabilities::
		linkSupportKey = "linkSupport";

	ImplementationClientCapabilities::
		ImplementationClientCapabilities(optional<Boolean> dynamicRegistration,
										 optional<Boolean> linkSupport) : dynamicRegistration(dynamicRegistration),
																		  linkSupport(linkSupport){};

	ImplementationClientCapabilities::ImplementationClientCapabilities(){};
	ImplementationClientCapabilities::~ImplementationClientCapabilities(){};

	ImplementationRegistrationOptions::
		ImplementationRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress,
			optional<String> id) : TextDocumentRegistrationOptions(documentSelector),
								   ImplementationOptions(workDoneProgress),
								   StaticRegistrationOptions(id){};

	ImplementationRegistrationOptions::ImplementationRegistrationOptions(){};
	ImplementationRegistrationOptions::~ImplementationRegistrationOptions(){};

	void ImplementationRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		ImplementationOptions::partialWrite(writer);
		StaticRegistrationOptions::partialWrite(writer);
	}

	ImplementationParams::ImplementationParams(TextDocumentIdentifier textDocument,
											   Position position,
											   optional<ProgressToken> workDoneToken,
											   optional<ProgressToken> partialResultToken) : TextDocumentPositionParams(textDocument, position),
																							 WorkDoneProgressParams(workDoneToken),
																							 PartialResultParams(partialResultToken){};

	ImplementationParams::ImplementationParams(){};
	ImplementationParams::~ImplementationParams(){};
}
