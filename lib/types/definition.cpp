#include <wlsp/types/definition.hpp>

namespace wlsp
{

	using namespace std;

	const String DefinitionClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String DefinitionClientCapabilities::
		linkSupportKey = "linkSupport";

	DefinitionClientCapabilities::
		DefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
									 optional<Boolean> linkSupport) : dynamicRegistration(dynamicRegistration),
																	  linkSupport(linkSupport){};

	DefinitionClientCapabilities::DefinitionClientCapabilities(){};
	DefinitionClientCapabilities::~DefinitionClientCapabilities(){};

	DefinitionRegistrationOptions::DefinitionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
											  DefinitionOptions(workDoneProgress){};

	DefinitionRegistrationOptions::DefinitionRegistrationOptions(){};
	DefinitionRegistrationOptions::~DefinitionRegistrationOptions(){};

	void DefinitionRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		DefinitionOptions::partialWrite(writer);
	}

	DefinitionParams::DefinitionParams(TextDocumentIdentifier textDocument,
									   Position position,
									   optional<ProgressToken> workDoneToken,
									   optional<ProgressToken> partialResultToken) : TextDocumentPositionParams(textDocument, position),
																					 WorkDoneProgressParams(workDoneToken),
																					 PartialResultParams(partialResultToken){};

	DefinitionParams::DefinitionParams(){};
	DefinitionParams::~DefinitionParams(){};
}
