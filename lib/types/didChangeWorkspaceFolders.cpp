#include <wlsp/types/didChangeWorkspaceFolders.hpp>

namespace wlsp
{

	using namespace std;

	const String WorkspaceFoldersChangeEvent::addedKey = "added";
	const String WorkspaceFoldersChangeEvent::removedKey = "removed";

	WorkspaceFoldersChangeEvent::WorkspaceFoldersChangeEvent(
		vector<WorkspaceFolder> added,
		vector<WorkspaceFolder> removed) : added(added),
										   removed(removed){};

	WorkspaceFoldersChangeEvent::WorkspaceFoldersChangeEvent(){};
	WorkspaceFoldersChangeEvent::~WorkspaceFoldersChangeEvent(){};

	WorkspaceFoldersChangeEvent::AddedRemovedMaker::
		AddedRemovedMaker(vector<WorkspaceFolder> &parentArray) : parentArray(parentArray){};

	WorkspaceFoldersChangeEvent::AddedRemovedMaker::~AddedRemovedMaker(){};

	const String DidChangeWorkspaceFoldersParams::eventKey = "event";

	DidChangeWorkspaceFoldersParams::
		DidChangeWorkspaceFoldersParams(WorkspaceFoldersChangeEvent event) : event(event){};

	DidChangeWorkspaceFoldersParams::DidChangeWorkspaceFoldersParams(){};
	DidChangeWorkspaceFoldersParams::~DidChangeWorkspaceFoldersParams(){};
}
