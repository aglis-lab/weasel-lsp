#include <stdexcept>

#include <wlsp/types/workspaceEdit.hpp>

namespace wlsp
{

	using namespace std;

	const String WorkspaceEdit::changesKey = "changes";
	const String WorkspaceEdit::documentChangesKey = "documentChanges";

	WorkspaceEdit::WorkspaceEdit(optional<Changes> changes,
								 optional<
									 variant<
										 vector<TextDocumentEdit>,
										 vector<
											 variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>>>>
									 documentChanges) : changes(changes),
														documentChanges(documentChanges){};

	WorkspaceEdit::WorkspaceEdit(){};
	WorkspaceEdit::~WorkspaceEdit(){};

	void WorkspaceEdit::partialWrite(JsonWriter &writer)
	{
		// changes?
		if (changes.has_value())
		{
			writer.Key(changesKey);
			writer.Object(*changes);
		}

		// documentChanges?
		if (documentChanges.has_value())
		{
			writer.Key(documentChangesKey);
			visit(overload(
					  [&writer](vector<TextDocumentEdit> &vec)
					  {
						  writer.StartArray();
						  for (auto &i : vec)
						  {
							  writer.Object(i);
						  }
						  writer.EndArray();
					  },
					  [&writer](vector<variant<TextDocumentEdit,
											   CreateFile,
											   RenameFile,
											   DeleteFile>> &vec)
					  {
						  writer.StartArray();
						  for (auto &i : vec)
						  {
							  visit(overload(
										[&writer](TextDocumentEdit &obj)
										{
											writer.Object(obj);
										},
										[&writer](CreateFile &obj)
										{
											writer.Object(obj);
										},
										[&writer](RenameFile &obj)
										{
											writer.Object(obj);
										},
										[&writer](DeleteFile &obj)
										{
											writer.Object(obj);
										}),
									i);
						  }
						  writer.EndArray();
					  }),
				  *documentChanges);
		}
	}

	void WorkspaceEdit::Changes::partialWrite(JsonWriter &writer)
	{
		// changes
		for (auto &i : changes)
		{
			writer.Key(i.first);
			writer.StartArray();
			for (auto &j : i.second)
			{
				writer.Object(j);
			}
			writer.EndArray();
		}
	}

	// TODO: CHECK IT
	const stde::bimap<ResourceOperationKind::Kind, String> ResourceOperationKind::kindMap;
	// const boost::bimap<ResourceOperationKind::Kind, String>
	// 	ResourceOperationKind::kindMap =
	// 		boost::assign::list_of<boost::bimap<Kind, String>::relation>(Kind::Create, "create")(Kind::Rename, "rename")(Kind::Delete, "delete");

	ResourceOperationKind::ResourceOperationKind(Kind kind) : kind(kind){};

	ResourceOperationKind::ResourceOperationKind(String kind)
	{
		// TODO: CHECK  IT
		if (!kindMap.has_value(kind))
		{
			throw invalid_argument("Kind not found in the map");
		}

		this->kind = kindMap.get_key(kind);

		// auto newKind = kindMap.right.find(kind);

		// if (newKind != kindMap.right.end())
		// {
		// 	this->kind = newKind->second;
		// }
		// else
		// {
		// 	throw invalid_argument("Kind not found in the map");
		// }
	}

	ResourceOperationKind::~ResourceOperationKind(){};

	const ResourceOperationKind ResourceOperationKind::Create = Kind::Create;
	const ResourceOperationKind ResourceOperationKind::Rename = Kind::Rename;
	const ResourceOperationKind ResourceOperationKind::Delete = Kind::Delete;

	// TODO: CHECK IT
	const stde::bimap<FailureHandlingKind::Kind, String> FailureHandlingKind::kindMap;
	// const boost::bimap<FailureHandlingKind::Kind, String>
	// FailureHandlingKind::kindMap =
	// 	boost::assign::list_of<boost::bimap<Kind, String>::relation>
	// 		(Kind::Abort,                 "abort")
	// 		(Kind::Transactional,         "transactional")
	// 		(Kind::TextOnlyTransactional, "textOnlyTransactional")
	// 		(Kind::Undo,                  "undo");

	FailureHandlingKind::FailureHandlingKind(Kind kind) : kind(kind){};

	FailureHandlingKind::FailureHandlingKind(String kind)
	{
		// TODO: CHECK IT
		if (!kindMap.has_value(kind))
		{
			throw invalid_argument("Kind not found in the map");
		}

		this->kind = kindMap.get_key(kind);

		// auto newKind = kindMap.right.find(kind);

		// if (newKind != kindMap.right.end())
		// {
		// 	this->kind = newKind->second;
		// }
		// else
		// {
		// 	throw invalid_argument("Kind not found in the map");
		// }
	}

	FailureHandlingKind::~FailureHandlingKind(){};

	const FailureHandlingKind FailureHandlingKind::Abort = Kind::Abort,
							  FailureHandlingKind::Transactional = Kind::Transactional,
							  FailureHandlingKind::TextOnlyTransactional = Kind::TextOnlyTransactional,
							  FailureHandlingKind::Undo = Kind::Undo;

	WorkspaceEdit::Changes::Changes(map<DocumentUri, vector<TextEdit>> changes) : changes(changes){};

	WorkspaceEdit::Changes::Changes(){};
	WorkspaceEdit::Changes::~Changes(){};

	const String WorkspaceEditClientCapabilities::
		documentChangesKey = "documentChanges";

	const String WorkspaceEditClientCapabilities::
		resourceOperationsKey = "resourceOperations";

	const String WorkspaceEditClientCapabilities::
		failureHandlingKey = "failureHandling";

	WorkspaceEditClientCapabilities::
		WorkspaceEditClientCapabilities(optional<Boolean> documentChanges,
										optional<vector<ResourceOperationKind>> resourceOperations,
										optional<FailureHandlingKind> failureHandling) : documentChanges(documentChanges),
																						 resourceOperations(resourceOperations),
																						 failureHandling(failureHandling){};

	WorkspaceEditClientCapabilities::WorkspaceEditClientCapabilities(){};
	WorkspaceEditClientCapabilities::~WorkspaceEditClientCapabilities(){};

	WorkspaceEditClientCapabilities::ResourceOperationsMaker::
		ResourceOperationsMaker(vector<ResourceOperationKind> &parentArray) : parentArray(parentArray){};

	WorkspaceEditClientCapabilities::ResourceOperationsMaker::
		~ResourceOperationsMaker(){};
}
