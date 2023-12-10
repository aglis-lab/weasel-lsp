#pragma once

#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	/// workspace/workspaceFolders server capabilities
	///
	/// supported?: Boolean
	///
	/// changeNotifications?: String | Boolean
	///
	struct WorkspaceFoldersServerCapabilities : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String supportedKey;
		const static String changeNotificationsKey;

	public:
		/// The server has support for workspace folders
		optional<Boolean> supported;

		/// Whether the server wants to receive workspace folder
		/// change notifications.
		///
		/// If a string is provided the string is treated as an ID
		/// under which the notification is registered on the client
		/// side. The ID can be used to unregister for these events
		/// using the `client/unregisterCapability` request.
		optional<variant<String, Boolean>> changeNotifications;

		// No parsing

		WorkspaceFoldersServerCapabilities(optional<Boolean> supported,
										   optional<variant<String, Boolean>> changeNotifications);

		WorkspaceFoldersServerCapabilities();

		virtual ~WorkspaceFoldersServerCapabilities();
	};

	/// Response of workspace/workspaceFolders
	///
	/// uri: DocumentUri
	///
	/// name: String
	///
	struct WorkspaceFolder : public ObjectT
	{
	public:
		static constexpr NativeString uriKey = "uri";
		static constexpr NativeString nameKey = "name";

	public:
		/// The associated URI for this workspace folder.
		DocumentUri uri;

		/// The name of the workspace folder. Used to refer to this
		/// workspace folder in the user interface.
		String name;

		//=======================================================================//

		// No writing

		WorkspaceFolder(DocumentUri uri, String name);

		WorkspaceFolder();

		virtual ~WorkspaceFolder();
	};

}
