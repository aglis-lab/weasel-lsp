#pragma once

#include <optional>

#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

/// Options to create a file.
///
/// overwrite?: Boolean
///
/// ignoreIfExists?: Boolean
///
struct CreateFileOptions: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String overwriteKey;
	const static String ignoreIfExistsKey;

public:
	/// Overwrite existing file. Overwrite wins over `ignoreIfExists`
	optional<Boolean> overwrite;

	/// Ignore if exists.
	optional<Boolean> ignoreIfExists;

	// No parsing

	CreateFileOptions(optional<Boolean> overwrite, optional<Boolean> ignoreIfExists);

	CreateFileOptions();

	virtual ~CreateFileOptions();
};

/// Create file operation
///
/// kind: 'create'
///
/// uri: DocumentUri
///
/// options?: CreateFileOptions
///
struct CreateFile: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String uriKey;
	const static String optionsKey;

public:
	/// A create
	const static pair<String, String> kind;

	/// The resource to create.
	DocumentUri uri;

	/// Additional options
	optional<CreateFileOptions> options;

	// No parsing

	CreateFile(DocumentUri uri, optional<CreateFileOptions> options);

	CreateFile();

	virtual ~CreateFile();
};

/// Rename file options
///
/// overwrite?: Boolean
///
/// ignoreIfExists?: Boolean
///
struct RenameFileOptions: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String overwriteKey;
	const static String ignoreIfExistsKey;

public:
	/// Overwrite existing file. Overwrite wins over `ignoreIfExists`
	optional<Boolean> overwrite;

	/// Ignore if exists.
	optional<Boolean> ignoreIfExists;

	// No parsing

	RenameFileOptions(optional<Boolean> overwrite, optional<Boolean> ignoreIfExists);

	RenameFileOptions();

	virtual ~RenameFileOptions();
};

/// Rename file operation
///
/// kind: 'rename'
///
/// oldUri: DocumentUri
///
/// newUri: DocumentUri
///
/// options?: RenameFileOptions
///
struct RenameFile: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String oldUriKey;
	const static String newUriKey;
	const static String optionsKey;

public:
	/// A rename
	const static pair<String, String> kind;

	/// The old (existing) location.
	DocumentUri oldUri;

	/// The new location.
	DocumentUri newUri;

	/// Rename options.
	optional<RenameFileOptions> options;

	// No parsing

	RenameFile(DocumentUri oldUri,
		DocumentUri newUri,
		optional<RenameFileOptions> options);

	RenameFile();

	virtual ~RenameFile();
};

/// Delete file options
///
/// recursive?: Boolean
///
/// ignoreIfNotExists?: Boolean
///
struct DeleteFileOptions: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String recursiveKey;
	const static String ignoreIfNotExistsKey;

public:
	/// Delete the content recursively if a folder is denoted.
	optional<Boolean> recursive;

	/// Ignore the operation if the file doesn't exist.
	optional<Boolean> ignoreIfNotExists;

	// No parsing

	DeleteFileOptions(optional<Boolean> recursive,
		optional<Boolean> ignoreIfNotExists);

	DeleteFileOptions();

	virtual ~DeleteFileOptions();
};

/// Delete file operation
///
/// kind: 'delete'
///
/// uri: DocumentUri
///
/// options?: DeleteFileOptions
///
struct DeleteFile: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String uriKey;
	const static String optionsKey;

public:
	/// A delete
	const static pair<String, String> kind;

	/// The file to delete.
	DocumentUri uri;

	/// Delete options.
	optional<DeleteFileOptions> options;

	// No parsing

	DeleteFile(DocumentUri uri, optional<DeleteFileOptions> options);

	DeleteFile();

	virtual ~DeleteFile();
};

}
