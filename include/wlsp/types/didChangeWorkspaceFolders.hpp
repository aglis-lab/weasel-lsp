#pragma once

#include <wlsp/types/workspaceFolder.hpp>

namespace wlsp
{

	using namespace std;

	/// The workspace folder change event.
	///
	/// added: WorkspaceFolder[]
	///
	/// removed: WorkspaceFolder[]
	///
	struct WorkspaceFoldersChangeEvent : public ObjectT
	{
	private:
		const static String addedKey;
		const static String removedKey;

		struct AddedRemovedMaker : public ObjectT
		{
			/// A reference to the vector to make
			vector<WorkspaceFolder> &parentArray;

			//===================================================================//

			AddedRemovedMaker(vector<WorkspaceFolder> &parentArray);

			virtual ~AddedRemovedMaker();
		};

	public:
		/// The array of added workspace folders
		vector<WorkspaceFolder> added;

		/// The array of the removed workspace folders
		vector<WorkspaceFolder> removed;

		//=======================================================================//

		// No writing

		WorkspaceFoldersChangeEvent(vector<WorkspaceFolder> added,
									vector<WorkspaceFolder> removed);

		WorkspaceFoldersChangeEvent();

		virtual ~WorkspaceFoldersChangeEvent();
	};

	/// The workspace/didChangeWorkspaceFolders notification is sent from the client
	/// to the server to inform the server about workspace folder configuration
	/// changes
	///
	/// event: WorkspaceFoldersChangeEvent
	///
	struct DidChangeWorkspaceFoldersParams : public ObjectT
	{
	private:
		const static String eventKey;

	public:
		/// The actual workspace folder change event.
		WorkspaceFoldersChangeEvent event;

		//=======================================================================//

		// No writing

		DidChangeWorkspaceFoldersParams(WorkspaceFoldersChangeEvent event);

		DidChangeWorkspaceFoldersParams();

		virtual ~DidChangeWorkspaceFoldersParams();
	};
}
