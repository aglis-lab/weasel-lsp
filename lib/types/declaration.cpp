#include <wlsp/types/declaration.hpp>

namespace wlsp
{

	using namespace std;

	const String DeclarationClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String DeclarationClientCapabilities::
		linkSupportKey = "linkSupport";

	DeclarationClientCapabilities::
		DeclarationClientCapabilities(optional<Boolean> dynamicRegistration,
									  optional<Boolean> linkSupport) : dynamicRegistration(dynamicRegistration),
																	   linkSupport(linkSupport){};

	DeclarationClientCapabilities::DeclarationClientCapabilities(){};
	DeclarationClientCapabilities::~DeclarationClientCapabilities(){};

	DeclarationRegistrationOptions::
		DeclarationRegistrationOptions(optional<Boolean> workDoneProgress,
									   variant<DocumentSelector, Null> documentSelector,
									   optional<String> id) : DeclarationOptions(workDoneProgress),
															  TextDocumentRegistrationOptions(documentSelector),
															  StaticRegistrationOptions(id){};

	DeclarationRegistrationOptions::DeclarationRegistrationOptions(){};
	DeclarationRegistrationOptions::~DeclarationRegistrationOptions(){};

	void DeclarationRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		DeclarationOptions::partialWrite(writer);
		TextDocumentRegistrationOptions::partialWrite(writer);
		StaticRegistrationOptions::partialWrite(writer);
	}

	DeclarationParams::DeclarationParams(TextDocumentIdentifier textDocument,
										 Position position,
										 optional<ProgressToken> workDoneToken,
										 optional<ProgressToken> partialResultToken) : TextDocumentPositionParams(textDocument, position),
																					   WorkDoneProgressParams(workDoneToken),
																					   PartialResultParams(partialResultToken){};

	DeclarationParams::DeclarationParams(){};
	DeclarationParams::~DeclarationParams(){};
}
