#include <wlsp/types/didChangeWatchedFiles.hpp>

namespace wlsp
{

	using namespace std;

	const String DidChangeWatchedFilesClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	DidChangeWatchedFilesClientCapabilities::
		DidChangeWatchedFilesClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	DidChangeWatchedFilesClientCapabilities::
		DidChangeWatchedFilesClientCapabilities(){};

	DidChangeWatchedFilesClientCapabilities::
		~DidChangeWatchedFilesClientCapabilities(){};

	const String FileSystemWatcher::globPatternKey = "globPattern";
	const String FileSystemWatcher::kindKey = "kind";

	FileSystemWatcher::FileSystemWatcher(String globPattern, optional<WatchKind> kind) : globPattern(globPattern),
																						 kind(kind){};

	FileSystemWatcher::FileSystemWatcher(){};
	FileSystemWatcher::~FileSystemWatcher(){};

	void FileSystemWatcher::partialWrite(JsonWriter &writer)
	{
		// globPattern
		writer.Key(globPatternKey);
		writer.String(globPattern);

		// kind?
		if (kind.has_value())
		{
			writer.Key(kindKey);
			writer.Int((int)(*kind));
		}
	}

	const String DidChangeWatchedFilesRegistrationOptions::watchersKey = "watchers";

	DidChangeWatchedFilesRegistrationOptions::
		DidChangeWatchedFilesRegistrationOptions(vector<FileSystemWatcher> watchers) : watchers(watchers){};

	DidChangeWatchedFilesRegistrationOptions::
		DidChangeWatchedFilesRegistrationOptions(){};

	DidChangeWatchedFilesRegistrationOptions::
		~DidChangeWatchedFilesRegistrationOptions(){};

	void DidChangeWatchedFilesRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// watchers
		writer.Key(watchersKey);
		writer.StartArray();
		for (auto &i : watchers)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}

	const String FileEvent::uriKey = "uri";
	const String FileEvent::typeKey = "type";

	FileEvent::FileEvent(DocumentUri uri, FileChangeType type) : uri(uri),
																 type(type){};

	FileEvent::FileEvent(){};
	FileEvent::~FileEvent(){};

	const String DidChangeWatchedFilesParams::changesKey = "changes";

	DidChangeWatchedFilesParams::DidChangeWatchedFilesParams(vector<FileEvent> changes) : changes(changes){};

	DidChangeWatchedFilesParams::DidChangeWatchedFilesParams(){};
	DidChangeWatchedFilesParams::~DidChangeWatchedFilesParams(){};

	DidChangeWatchedFilesParams::ChangesMaker::
		ChangesMaker(vector<FileEvent> &parentArray) : parentArray(parentArray){};

	DidChangeWatchedFilesParams::ChangesMaker::~ChangesMaker(){};
}
