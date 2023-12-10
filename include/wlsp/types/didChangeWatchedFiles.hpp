#pragma once

#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	/// DidChangeWatchedFiles notification capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	struct DidChangeWatchedFilesClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;

	public:
		/// Did change watched files notification supports dynamic registration.
		/// Please note that the current protocol doesn't support static
		/// configuration for file changes from the server side.
		optional<Boolean> dynamicRegistration;

		//=======================================================================//

		// No writing

		DidChangeWatchedFilesClientCapabilities(optional<Boolean> dynamicRegistration);

		DidChangeWatchedFilesClientCapabilities();

		virtual ~DidChangeWatchedFilesClientCapabilities();
	};

	enum class WatchKind
	{
		/// Interested in create events.
		Create = 1,

		/// Interested in change events
		Change = 2,

		/// Interested in delete events
		Delete = 4
	};

	// Operators for WatchKind
	// Copied from the filesystem <bits/fs_fwd.h> header

	constexpr WatchKind operator&(WatchKind l, WatchKind r) noexcept
	{
		using underType = typename underlying_type<WatchKind>::type;

		return static_cast<WatchKind>(
			static_cast<underType>(l) & static_cast<underType>(r));
	}

	constexpr WatchKind operator|(WatchKind l, WatchKind r) noexcept
	{
		using underType = typename underlying_type<WatchKind>::type;

		return static_cast<WatchKind>(
			static_cast<underType>(l) | static_cast<underType>(r));
	}

	constexpr WatchKind operator^(WatchKind l, WatchKind r) noexcept
	{
		using underType = typename underlying_type<WatchKind>::type;

		return static_cast<WatchKind>(
			static_cast<underType>(l) ^ static_cast<underType>(r));
	}

	constexpr WatchKind operator~(WatchKind l) noexcept
	{
		using underType = typename underlying_type<WatchKind>::type;

		return static_cast<WatchKind>(~static_cast<underType>(l));
	}

	inline WatchKind &operator&=(WatchKind &l, WatchKind &r) noexcept
	{
		return l = l & r;
	}

	inline WatchKind &operator|=(WatchKind &l, WatchKind &r) noexcept
	{
		return l = l | r;
	}

	inline WatchKind &operator^=(WatchKind &l, WatchKind &r) noexcept
	{
		return l = l ^ r;
	}

	/// Watcher of file changes
	///
	/// globPattern: String
	///
	/// kind?: WatchKind
	///
	struct FileSystemWatcher : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String globPatternKey;
		const static String kindKey;

	public:
		/// The  glob pattern to watch.
		///
		/// Glob patterns can have the following syntax:
		/// - `*` to match one or more characters in a path segment
		/// - `?` to match on one character in a path segment
		/// - `**` to match any number of path segments, including none
		/// - `{}` to group conditions
		/// - `[]` to declare a range of characters to match in a path segment
		/// - `[!...]` to negate a range of characters to match in a path segment
		String globPattern;

		/// The kind of events of interest. If omitted it defaults
		/// to WatchKind::Create | WatchKind::Change | WatchKind::Delete
		/// which is 7.
		optional<WatchKind> kind;

		// No parsing

		FileSystemWatcher(String globPattern, optional<WatchKind> kind);

		FileSystemWatcher();

		virtual ~FileSystemWatcher();
	};

	/// Describe options to be used when registering for file system change events.
	///
	/// watchers: FileSystemWatcher[]
	///
	struct DidChangeWatchedFilesRegistrationOptions : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String watchersKey;

	public:
		/// The watchers to register.
		vector<FileSystemWatcher> watchers;

		// No parsing

		DidChangeWatchedFilesRegistrationOptions(vector<FileSystemWatcher> watchers);

		DidChangeWatchedFilesRegistrationOptions();

		virtual ~DidChangeWatchedFilesRegistrationOptions();
	};

	/// The file event type.
	enum class FileChangeType
	{
		/// The file got created.
		Created = 1,

		/// The file got changed.
		Changed = 2,

		/// The file got deleted.
		Deleted = 3
	};

	/// An event describing a file change.
	///
	/// uri: DocumentUri
	///
	/// type: Number
	///
	struct FileEvent : public ObjectT
	{
	private:
		const static String uriKey;
		const static String typeKey;

	public:
		/// The file's URI.
		DocumentUri uri;

		/// The change type.
		FileChangeType type;

		//=======================================================================//

		// No writing

		FileEvent(DocumentUri uri, FileChangeType type);

		FileEvent();

		virtual ~FileEvent();
	};

	/// DidChangeWatchedFiles params
	///
	/// changes: FileEvent[]
	///
	struct DidChangeWatchedFilesParams : public ObjectT
	{
	private:
		const static String changesKey;

		struct ChangesMaker : public ObjectT
		{
			vector<FileEvent> &parentArray;

			//===================================================================//

			ChangesMaker(vector<FileEvent> &parentArray);

			virtual ~ChangesMaker();
		};

	public:
		/// The actual file events.
		vector<FileEvent> changes;

		//=======================================================================//

		// No writing

		DidChangeWatchedFilesParams(vector<FileEvent> changes);

		DidChangeWatchedFilesParams();

		virtual ~DidChangeWatchedFilesParams();
	};

}
