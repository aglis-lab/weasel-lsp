#include <wlsp/types/rename.hpp>

namespace wlsp
{

	using namespace std;

	const String RenameClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String RenameClientCapabilities::
		prepareSupportKey = "prepareSupport";

	RenameClientCapabilities::
		RenameClientCapabilities(optional<Boolean> dynamicRegistration,
								 optional<Boolean> prepareSupport) : dynamicRegistration(dynamicRegistration),
																	 prepareSupport(prepareSupport){};

	RenameClientCapabilities::RenameClientCapabilities(){};
	RenameClientCapabilities::~RenameClientCapabilities(){};

	const String RenameOptions::prepareProviderKey = "prepareProvider";

	RenameOptions::RenameOptions(optional<Boolean> workDoneProgress,
								 optional<Boolean> prepareProvider) : WorkDoneProgressOptions(workDoneProgress),
																	  prepareProvider(prepareProvider){};

	RenameOptions::RenameOptions(){};
	RenameOptions::~RenameOptions(){};

	void RenameOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		WorkDoneProgressOptions::partialWrite(writer);

		// prepareProvider?
		if (prepareProvider.has_value())
		{
			writer.Key(prepareProviderKey);
			writer.Bool(*prepareProvider);
		}
	}

	RenameRegistrationOptions::RenameRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<Boolean> prepareProvider) : TextDocumentRegistrationOptions(documentSelector),
											 RenameOptions(workDoneProgress, prepareProvider){};

	RenameRegistrationOptions::RenameRegistrationOptions(){};
	RenameRegistrationOptions::~RenameRegistrationOptions(){};

	void RenameRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		RenameOptions::partialWrite(writer);
	}

	const String RenameParams::newNameKey = "newName";

	RenameParams::RenameParams(TextDocumentIdentifier textDocument,
							   Position position,
							   optional<ProgressToken> workDoneToken,
							   String newName) : TextDocumentPositionParams(textDocument, position),
												 WorkDoneProgressParams(workDoneToken),
												 newName(newName){};

	RenameParams::RenameParams(){};
	RenameParams::~RenameParams(){};
}
