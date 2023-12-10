#pragma once

#include <optional>

#include <wlsp/types/didSaveTextDocument.hpp>

namespace wlsp
{

	using namespace std;

	/// Defines how the host (editor) should sync document changes to
	/// the language server.
	enum TextDocumentSyncKind
	{

		/// Documents should not be synced at all.
		None = 0,

		/// Documents are synced by always sending the full content
		/// of the document.
		Full = 1,

		/// Documents are synced by sending the full content on open.
		/// After that only incremental updates to the document are
		/// send.
		Incremental = 2
	};

	/// TextDocumentSync options
	///
	/// openClose?: Boolean
	///
	/// change?: TextDocumentSyncKind
	///
	/// willSave?: Boolean
	///
	/// willSaveWaitUntil?: Boolean
	///
	/// save?: SaveOptions
	///
	struct TextDocumentSyncOptions : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String openCloseKey;
		const static String changeKey;
		const static String willSaveKey;
		const static String willSaveWaitUntilKey;
		const static String saveKey;

	public:
		/// Open and close notifications are sent to the server. If omitted
		/// open close notification should not be sent.
		optional<Boolean> openClose;

		/// Change notifications are sent to the server. See TextDocumentSyncKind.None,
		/// TextDocumentSyncKind.Full and TextDocumentSyncKind.Incremental. If omitted
		/// it defaults to TextDocumentSyncKind.None.
		optional<TextDocumentSyncKind> change;

		/// If present will save notifications are sent to the server.
		/// If omitted the notification should not be sent.
		optional<Boolean> willSave;

		/// If present will save wait until requests are sent to the server.
		/// If omitted the request should not be sent.
		optional<Boolean> willSaveWaitUntil;

		/// If present save notifications are sent to the server.
		/// If omitted the notification should not be sent.
		optional<SaveOptions> save;

		// No parsing

		TextDocumentSyncOptions(optional<Boolean> openClose,
								optional<TextDocumentSyncKind> change,
								optional<Boolean> willSave,
								optional<Boolean> willSaveWaitUntil,
								optional<SaveOptions> save);

		TextDocumentSyncOptions();

		virtual ~TextDocumentSyncOptions();
	};

	/// Client capability for syncing textDocument's
	///
	/// dynamicRegistration?: Boolean;
	///
	/// willSave?: Boolean;
	///
	/// willSaveWaitUntil?: Boolean;
	///
	/// didSave?: Boolean;
	///
	struct TextDocumentSyncClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;
		const static String willSaveKey;
		const static String willSaveWaitUntilKey;
		const static String didSaveKey;

	public:
		/// Whether text document synchronization supports dynamic registration.
		optional<Boolean> dynamicRegistration;

		/// The client supports sending will save notifications.
		optional<Boolean> willSave;

		/// The client supports sending a will save request and
		/// waits for a response providing text edits which will
		/// be applied to the document before it is saved.
		optional<Boolean> willSaveWaitUntil;

		/// The client supports did save notifications.
		optional<Boolean> didSave;

		//=======================================================================//

		// No writing

		TextDocumentSyncClientCapabilities(optional<Boolean> dynamicRegistration,
										   optional<Boolean> willSave,
										   optional<Boolean> willSaveWaitUntil,
										   optional<Boolean> didSave);

		TextDocumentSyncClientCapabilities();

		virtual ~TextDocumentSyncClientCapabilities();
	};

}
