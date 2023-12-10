#include <wlsp/types/typeDefinition.hpp>

namespace wlsp
{

	using namespace std;

	const String TypeDefinitionClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String TypeDefinitionClientCapabilities::
		linkSupportKey = "linkSupport";

	TypeDefinitionClientCapabilities::
		TypeDefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
										 optional<Boolean> linkSupport) : dynamicRegistration(dynamicRegistration),
																		  linkSupport(linkSupport){};

	TypeDefinitionClientCapabilities::TypeDefinitionClientCapabilities(){};
	TypeDefinitionClientCapabilities::~TypeDefinitionClientCapabilities(){};

	TypeDefinitionRegistrationOptions::
		TypeDefinitionRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress,
			optional<String> id) : TextDocumentRegistrationOptions(documentSelector),
								   TypeDefinitionOptions(workDoneProgress),
								   StaticRegistrationOptions(id){};

	TypeDefinitionRegistrationOptions::TypeDefinitionRegistrationOptions(){};
	TypeDefinitionRegistrationOptions::~TypeDefinitionRegistrationOptions(){};

	void TypeDefinitionRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		TypeDefinitionOptions::partialWrite(writer);
		StaticRegistrationOptions::partialWrite(writer);
	}

	TypeDefinitionParams::TypeDefinitionParams(TextDocumentIdentifier textDocument,
											   Position position,
											   optional<ProgressToken> workDoneToken,
											   optional<ProgressToken> partialResultToken) : TextDocumentPositionParams(textDocument, position),
																							 WorkDoneProgressParams(workDoneToken),
																							 PartialResultParams(partialResultToken){};

	TypeDefinitionParams::TypeDefinitionParams(){};
	TypeDefinitionParams::~TypeDefinitionParams(){};
}
