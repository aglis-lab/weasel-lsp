#include <wlsp/types/fileResourceChanges.hpp>

namespace wlsp
{

using namespace std;

const String CreateFileOptions::overwriteKey      = "overwrite";
const String CreateFileOptions::ignoreIfExistsKey = "ignoreIfExists";

CreateFileOptions::CreateFileOptions(optional<Boolean> overwrite,
	optional<Boolean> ignoreIfExists):
		overwrite(overwrite),
		ignoreIfExists(ignoreIfExists)
{};

CreateFileOptions::CreateFileOptions(){};
CreateFileOptions::~CreateFileOptions(){};

void CreateFileOptions::partialWrite(JsonWriter &writer)
{
	// overwrite?
	if(overwrite.has_value())
	{
		writer.Key(overwriteKey);
		writer.Bool(*overwrite);
	}

	// ignoreIfExists?
	if(ignoreIfExists.has_value())
	{
		writer.Key(ignoreIfExistsKey);
		writer.Bool(*ignoreIfExists);
	}
}


const pair<String, String> CreateFile::kind = {"kind", "create"};

const String CreateFile::uriKey     = "uri";
const String CreateFile::optionsKey = "options";

CreateFile::CreateFile(DocumentUri uri, optional<CreateFileOptions> options):
	uri(uri),
	options(options)
{};

CreateFile::CreateFile(){};
CreateFile::~CreateFile(){};

void CreateFile::partialWrite(JsonWriter &writer)
{
	// kind
	writer.Key(kind.first);
	writer.String(kind.second);

	// uri
	writer.Key(uriKey);
	writer.String(uri);

	// options?
	if(options.has_value())
	{
		writer.Key(optionsKey);
		writer.Object(*options);
	}
}


const String RenameFileOptions::overwriteKey      = "overwrite";
const String RenameFileOptions::ignoreIfExistsKey = "ignoreIfExists";

RenameFileOptions::RenameFileOptions(optional<Boolean> overwrite,
	optional<Boolean> ignoreIfExists):
		overwrite(overwrite),
		ignoreIfExists(ignoreIfExists)
{};

RenameFileOptions::RenameFileOptions(){};
RenameFileOptions::~RenameFileOptions(){};

void RenameFileOptions::partialWrite(JsonWriter &writer)
{
	// overwrite?
	if(overwrite.has_value())
	{
		writer.Key(overwriteKey);
		writer.Bool(*overwrite);
	}

	// ignoreIfExists?
	if(ignoreIfExists.has_value())
	{
		writer.Key(ignoreIfExistsKey);
		writer.Bool(*ignoreIfExists);
	}
}


const pair<String, String> RenameFile::kind = {"kind", "rename"};

const String RenameFile::oldUriKey  = "oldUri";
const String RenameFile::newUriKey  = "newUri";
const String RenameFile::optionsKey = "options";

RenameFile::RenameFile(DocumentUri oldUri,
	DocumentUri newUri,
	optional<RenameFileOptions> options):
		oldUri(oldUri),
		newUri(newUri),
		options(options)
{};

RenameFile::RenameFile(){};
RenameFile::~RenameFile(){};

void RenameFile::partialWrite(JsonWriter &writer)
{
	// kind
	writer.Key(kind.first);
	writer.String(kind.second);

	// oldUri
	writer.Key(oldUriKey);
	writer.String(oldUri);

	// newUri
	writer.Key(newUriKey);
	writer.String(newUri);

	// options?
	if(options.has_value())
	{
		writer.Key(optionsKey);
		writer.Object(*options);
	}
}


const String DeleteFileOptions::recursiveKey         = "recursive";
const String DeleteFileOptions::ignoreIfNotExistsKey = "ignoreIfNotExists";

DeleteFileOptions::DeleteFileOptions(optional<Boolean> recursive,
	optional<Boolean> ignoreIfNotExists):
		recursive(recursive),
		ignoreIfNotExists(ignoreIfNotExists)
{};

DeleteFileOptions::DeleteFileOptions(){};
DeleteFileOptions::~DeleteFileOptions(){};

void DeleteFileOptions::partialWrite(JsonWriter &writer)
{
	// recursive?
	if(recursive.has_value())
	{
		writer.Key(recursiveKey);
		writer.Bool(*recursive);
	}

	// ignoreIfNotExists?
	if(ignoreIfNotExists.has_value())
	{
		writer.Key(ignoreIfNotExistsKey);
		writer.Bool(*ignoreIfNotExists);
	}
}


const pair<String, String> DeleteFile::kind = {"kind", "delete"};

const String DeleteFile::uriKey     = "uri";
const String DeleteFile::optionsKey = "options";

DeleteFile::DeleteFile(DocumentUri uri, optional<DeleteFileOptions> options):
	uri(uri),
	options(options)
{};

DeleteFile::DeleteFile(){};
DeleteFile::~DeleteFile(){};

void DeleteFile::partialWrite(JsonWriter &writer)
{
	// kind
	writer.Key(kind.first);
	writer.String(kind.second);

	// uri
	writer.Key(uriKey);
	writer.String(uri);

	// options?
	if(options.has_value())
	{
		writer.Key(optionsKey);
		writer.Object(*options);
	}
}

}
