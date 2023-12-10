#include <wlsp/types/textDocumentSync.hpp>

namespace wlsp
{

	using namespace std;

	const String TextDocumentSyncOptions::openCloseKey = "openClose";
	const String TextDocumentSyncOptions::changeKey = "change";
	const String TextDocumentSyncOptions::willSaveKey = "willSave";
	const String TextDocumentSyncOptions::willSaveWaitUntilKey = "willSaveWaitUntil";
	const String TextDocumentSyncOptions::saveKey = "save";

	TextDocumentSyncOptions::TextDocumentSyncOptions(optional<Boolean> openClose,
													 optional<TextDocumentSyncKind> change,
													 optional<Boolean> willSave,
													 optional<Boolean> willSaveWaitUntil,
													 optional<SaveOptions> save) : openClose(openClose),
																				   change(change),
																				   willSave(willSave),
																				   willSaveWaitUntil(willSaveWaitUntil),
																				   save(save){};

	TextDocumentSyncOptions::TextDocumentSyncOptions(){};
	TextDocumentSyncOptions::~TextDocumentSyncOptions(){};

	void TextDocumentSyncOptions::partialWrite(JsonWriter &writer)
	{
		// openClose?
		if (openClose.has_value())
		{
			writer.Key(openCloseKey);
			writer.Bool(*openClose);
		}

		// change?
		if (change.has_value())
		{
			writer.Key(changeKey);
			writer.Int((int)(*change));
		}

		// willSave?
		if (willSave.has_value())
		{
			writer.Key(willSaveKey);
			writer.Bool(*willSave);
		}

		// willSaveWaitUntil?
		if (willSaveWaitUntil.has_value())
		{
			writer.Key(willSaveWaitUntilKey);
			writer.Bool(*willSaveWaitUntil);
		}

		// save?
		if (save.has_value())
		{
			writer.Key(saveKey);
			writer.Object(*save);
		}
	}

	const String TextDocumentSyncClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String TextDocumentSyncClientCapabilities::
		willSaveKey = "willSave";

	const String TextDocumentSyncClientCapabilities::
		willSaveWaitUntilKey = "willSaveWaitUntil";

	const String TextDocumentSyncClientCapabilities::
		didSaveKey = "didSave";

	TextDocumentSyncClientCapabilities::
		TextDocumentSyncClientCapabilities(optional<Boolean> dynamicRegistration,
										   optional<Boolean> willSave,
										   optional<Boolean> willSaveWaitUntil,
										   optional<Boolean> didSave) : dynamicRegistration(dynamicRegistration),
																		willSave(willSave),
																		willSaveWaitUntil(willSaveWaitUntil),
																		didSave(didSave){};

	TextDocumentSyncClientCapabilities::TextDocumentSyncClientCapabilities(){};
	TextDocumentSyncClientCapabilities::~TextDocumentSyncClientCapabilities(){};
}
