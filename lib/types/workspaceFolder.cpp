#include <wlsp/types/workspaceFolder.hpp>

namespace wlsp
{

	using namespace std;

	const String WorkspaceFoldersServerCapabilities::
		supportedKey = "supported";
	const String WorkspaceFoldersServerCapabilities::
		changeNotificationsKey = "changeNotifications";

	WorkspaceFoldersServerCapabilities::
		WorkspaceFoldersServerCapabilities(optional<Boolean> supported,
										   optional<variant<String, Boolean>> changeNotifications) : supported(supported),
																									 changeNotifications(changeNotifications){};

	WorkspaceFoldersServerCapabilities::WorkspaceFoldersServerCapabilities(){};
	WorkspaceFoldersServerCapabilities::~WorkspaceFoldersServerCapabilities(){};

	void WorkspaceFoldersServerCapabilities::partialWrite(JsonWriter &writer)
	{
		// supported?
		if (supported.has_value())
		{
			writer.Key(supportedKey);
			writer.Bool(*supported);
		}

		// changeNotifications?
		if (changeNotifications.has_value())
		{
			writer.Key(changeNotificationsKey);
			visit(overload(
					  [&writer](String &str)
					  {
						  writer.String(str);
					  },
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  }),
				  *changeNotifications);
		}
	}

	WorkspaceFolder::WorkspaceFolder(DocumentUri uri, String name) : uri(uri),
																	 name(name){};

	WorkspaceFolder::WorkspaceFolder(){};
	WorkspaceFolder::~WorkspaceFolder(){};
}
