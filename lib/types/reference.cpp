#include <wlsp/types/reference.hpp>

namespace wlsp
{

	using namespace std;

	const String ReferenceClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	ReferenceClientCapabilities::
		ReferenceClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	ReferenceClientCapabilities::ReferenceClientCapabilities(){};
	ReferenceClientCapabilities::~ReferenceClientCapabilities(){};

	ReferenceRegistrationOptions::ReferenceRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
											  ReferenceOptions(workDoneProgress){};

	ReferenceRegistrationOptions::ReferenceRegistrationOptions(){};
	ReferenceRegistrationOptions::~ReferenceRegistrationOptions(){};

	void ReferenceRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		ReferenceOptions::partialWrite(writer);
	}

	const String ReferenceContext::includeDeclarationKey = "includeDeclaration";

	ReferenceContext::ReferenceContext(Boolean includeDeclaration) : includeDeclaration(includeDeclaration){};

	ReferenceContext::ReferenceContext(){};
	ReferenceContext::~ReferenceContext(){};

	const String ReferenceParams::contextKey = "context";

	ReferenceParams::ReferenceParams(TextDocumentIdentifier textDocument,
									 Position position,
									 optional<ProgressToken> workDoneToken,
									 optional<ProgressToken> partialResultToken,
									 ReferenceContext context) : TextDocumentPositionParams(textDocument, position),
																 WorkDoneProgressParams(workDoneToken),
																 PartialResultParams(partialResultToken),
																 context(context){};

	ReferenceParams::ReferenceParams(){};
	ReferenceParams::~ReferenceParams(){};
}
