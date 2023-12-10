#include <iostream>

#include <bimap/bimap.hpp>

#include <wlsp/types/initialize.hpp>

namespace wlsp
{

	using namespace std;

	const String TextDocumentClientCapabilities::
		synchronizationKey = "synchronization";

	const String TextDocumentClientCapabilities::
		completionKey = "completion";

	const String TextDocumentClientCapabilities::
		hoverKey = "hover";

	const String TextDocumentClientCapabilities::
		signatureHelpKey = "signatureHelp";

	const String TextDocumentClientCapabilities::
		declarationKey = "declaration";

	const String TextDocumentClientCapabilities::
		definitionKey = "definition";

	const String TextDocumentClientCapabilities::
		typeDefinitionKey = "typeDefinition";

	const String TextDocumentClientCapabilities::
		implementationKey = "implementation";

	const String TextDocumentClientCapabilities::
		referencesKey = "references";

	const String TextDocumentClientCapabilities::
		documentHighlightKey = "documentHighlight";

	const String TextDocumentClientCapabilities::
		documentSymbolKey = "documentSymbol";

	const String TextDocumentClientCapabilities::
		codeActionKey = "codeAction";

	const String TextDocumentClientCapabilities::
		codeLensKey = "codeLens";

	const String TextDocumentClientCapabilities::
		documentLinkKey = "documentLink";

	const String TextDocumentClientCapabilities::
		colorProviderKey = "colorProvider";

	const String TextDocumentClientCapabilities::
		formattingKey = "formatting";

	const String TextDocumentClientCapabilities::
		rangeFormattingKey = "rangeFormatting";

	const String TextDocumentClientCapabilities::
		onTypeFormattingKey = "onTypeFormatting";

	const String TextDocumentClientCapabilities::
		renameKey = "rename";

	const String TextDocumentClientCapabilities::
		publishDiagnosticsKey = "publishDiagnostics";

	const String TextDocumentClientCapabilities::
		foldingRangeKey = "foldingRange";

	const String TextDocumentClientCapabilities::
		selectionRangeKey = "selectionRange";

	TextDocumentClientCapabilities::TextDocumentClientCapabilities(
		optional<TextDocumentSyncClientCapabilities> synchronization,
		optional<CompletionClientCapabilities> completion,
		optional<HoverClientCapabilities> hover,
		optional<SignatureHelpClientCapabilities> signatureHelp,
		optional<DeclarationClientCapabilities> declaration,
		optional<DefinitionClientCapabilities> definition,
		optional<TypeDefinitionClientCapabilities> typeDefinition,
		optional<ImplementationClientCapabilities> implementation,
		optional<ReferenceClientCapabilities> references,
		optional<DocumentHighlightClientCapabilities> documentHighlight,
		optional<DocumentSymbolClientCapabilities> documentSymbol,
		optional<CodeActionClientCapabilities> codeAction,
		optional<CodeLensClientCapabilities> codeLens,
		optional<DocumentLinkClientCapabilities> documentLink,
		optional<DocumentColorClientCapabilities> colorProvider,
		optional<DocumentFormattingClientCapabilities> formatting,
		optional<DocumentRangeFormattingClientCapabilities> rangeFormatting,
		optional<DocumentOnTypeFormattingClientCapabilities> onTypeFormatting,
		optional<RenameClientCapabilities> rename,
		optional<PublishDiagnosticsClientCapabilities> publishDiagnostics,
		optional<FoldingRangeClientCapabilities> foldingRange,
		optional<SelectionRangeClientCapabilities> selectionRange) : synchronization(synchronization),
																	 completion(completion),
																	 hover(hover),
																	 signatureHelp(signatureHelp),
																	 declaration(declaration),
																	 definition(definition),
																	 typeDefinition(typeDefinition),
																	 implementation(implementation),
																	 references(references),
																	 documentHighlight(documentHighlight),
																	 documentSymbol(documentSymbol),
																	 codeAction(codeAction),
																	 codeLens(codeLens),
																	 documentLink(documentLink),
																	 colorProvider(colorProvider),
																	 formatting(formatting),
																	 rangeFormatting(rangeFormatting),
																	 onTypeFormatting(onTypeFormatting),
																	 rename(rename),
																	 publishDiagnostics(publishDiagnostics),
																	 foldingRange(foldingRange),
																	 selectionRange(selectionRange){};

	TextDocumentClientCapabilities::TextDocumentClientCapabilities(){};
	TextDocumentClientCapabilities::~TextDocumentClientCapabilities(){};

	ClientCapabilities::ClientCapabilities(optional<Workspace> workspace,
										   optional<TextDocumentClientCapabilities> textDocument,
										   optional<Any> experimental) : workspace(workspace),
																		 textDocument(textDocument),
																		 experimental(experimental){};

	ClientCapabilities::ClientCapabilities(){};
	ClientCapabilities::~ClientCapabilities(){};

	ClientCapabilities::Workspace::Workspace(optional<Boolean> applyEdit,
											 optional<WorkspaceEditClientCapabilities> workspaceEdit,
											 optional<DidChangeConfigurationClientCapabilities> didChangeConfiguration,
											 optional<DidChangeWatchedFilesClientCapabilities> didChangeWatchedFiles,
											 optional<WorkspaceSymbolClientCapabilities> symbol,
											 optional<ExecuteCommandClientCapabilities> executeCommand,
											 optional<Boolean> workspaceFolders,
											 optional<Boolean> configuration) : applyEdit(applyEdit),
																				workspaceEdit(workspaceEdit),
																				didChangeConfiguration(didChangeConfiguration),
																				didChangeWatchedFiles(didChangeWatchedFiles),
																				symbol(symbol),
																				executeCommand(executeCommand),
																				workspaceFolders(workspaceFolders),
																				configuration(configuration){};

	ClientCapabilities::Workspace::Workspace(){};
	ClientCapabilities::Workspace::~Workspace(){};

	TraceKind::TraceKind(String kind)
	{
		// TODO: CHECK IT
		this->kind = _TraceKind::Off;

		if (kindMap.has_value(kind))
		{
			this->kind = kindMap.get_key(kind);
		}

		// auto newKind = kindMap.right.find(kind);

		// // If the string is in the enum
		// if (newKind != kindMap.right.end())
		// {
		// 	this->kind = newKind->second;
		// }
		// else
		// {
		// 	// Off by default
		// 	this->kind = _TraceKind::Off;
		// }
	}

	TraceKind::TraceKind(_TraceKind kind) : kind(kind){};

	TraceKind::~TraceKind(){};

	// TODO: CHECK IT
	const bimap<TraceKind::_TraceKind, String> TraceKind::kindMap;
	// 	assign::list_of<bimap<_TraceKind, String>::relation>(_TraceKind::Off, "off")(_TraceKind::Messages, "messages")(_TraceKind::Verbose, "verbose");

	const TraceKind TraceKind::Off = _TraceKind::Off;
	const TraceKind TraceKind::Messages = _TraceKind::Messages;
	const TraceKind TraceKind::Verbose = _TraceKind::Verbose;

	InitializeParams::InitializeParams(){};
	InitializeParams::~InitializeParams(){};
	InitializeParams::InitializeParams(
		optional<int> processId,
		optional<ClientInfo> clientInfo,
		optional<Any> initializationOptions,
		ClientCapabilities capabilities,
		optional<TraceKind> trace,
		optional<vector<WorkspaceFolder>> workspaceFolders) : processId(processId),
															  clientInfo(clientInfo),
															  initializationOptions(initializationOptions),
															  capabilities(capabilities),
															  trace(trace),
															  workspaceFolders(workspaceFolders) {}

	InitializeParams::WorkspaceFoldersMaker::
		WorkspaceFoldersMaker(vector<WorkspaceFolder> &parentArray) : parentArray(parentArray){};

	InitializeParams::WorkspaceFoldersMaker::
		~WorkspaceFoldersMaker(){};

	InitializeParams::ClientInfo::ClientInfo(String name, optional<String> version) : name(name),
																					  version(version){};

	InitializeParams::ClientInfo::ClientInfo(){};
	InitializeParams::ClientInfo::~ClientInfo(){};

	const String ServerCapabilities::
		textDocumentSyncKey = "textDocumentSync";

	const String ServerCapabilities::
		completionProviderKey = "completionProvider";

	const String ServerCapabilities::
		hoverProviderKey = "hoverProvider";

	const String ServerCapabilities::
		signatureHelpProviderKey = "signatureHelpProvider";

	const String ServerCapabilities::
		declarationProviderKey = "declarationProvider";

	const String ServerCapabilities::
		definitionProviderKey = "definitionProvider";

	const String ServerCapabilities::
		typeDefinitionProviderKey = "typeDefinitionProvider";

	const String ServerCapabilities::
		implementationProviderKey = "implementationProvider";

	const String ServerCapabilities::
		referencesProviderKey = "referencesProvider";

	const String ServerCapabilities::
		documentHighlightProviderKey = "documentHighlightProvider";

	const String ServerCapabilities::
		documentSymbolProviderKey = "documentSymbolProvider";

	const String ServerCapabilities::
		codeActionProviderKey = "codeActionProvider";

	const String ServerCapabilities::
		codeLensProviderKey = "codeLensProvider";

	const String ServerCapabilities::
		documentLinkProviderKey = "documentLinkProvider";

	const String ServerCapabilities::
		colorProviderKey = "colorProvider";

	const String ServerCapabilities::
		documentFormattingProviderKey = "documentFormattingProvider";

	const String ServerCapabilities::
		documentRangeFormattingProviderKey = "documentRangeFormattingProvider";

	const String ServerCapabilities::
		documentOnTypeFormattingProviderKey = "documentOnTypeFormattingProvider";

	const String ServerCapabilities::
		renameProviderKey = "renameProvider";

	const String ServerCapabilities::
		foldingRangeProviderKey = "foldingRangeProvider";

	const String ServerCapabilities::
		executeCommandProviderKey = "executeCommandProvider";

	const String ServerCapabilities::
		selectionRangeProviderKey = "selectionRangeProvider";

	const String ServerCapabilities::
		workspaceSymbolProviderKey = "workspaceSymbolProvider";

	const String ServerCapabilities::
		workspaceKey = "workspace";

	const String ServerCapabilities::
		experimentalKey = "experimental";

	ServerCapabilities::ServerCapabilities(
		optional<variant<TextDocumentSyncOptions, Number>> textDocumentSync,
		optional<CompletionOptions> completionProvider,
		optional<variant<Boolean, HoverOptions>> hoverProvider,
		optional<SignatureHelpOptions> signatureHelpProvider,
		optional<variant<Boolean,
						 DeclarationOptions,
						 DeclarationRegistrationOptions>>
			declarationProvider,
		optional<variant<Boolean, DefinitionOptions>> definitionProvider,
		optional<variant<Boolean,
						 TypeDefinitionOptions,
						 TypeDefinitionRegistrationOptions>>
			typeDefinitionProvider,
		optional<variant<Boolean,
						 ImplementationOptions,
						 ImplementationRegistrationOptions>>
			implementationProvider,
		optional<variant<Boolean, ReferenceOptions>> referencesProvider,
		optional<variant<Boolean,
						 DocumentHighlightOptions>>
			documentHighlightProvider,
		optional<variant<Boolean, DocumentSymbolOptions>> documentSymbolProvider,
		optional<variant<Boolean, CodeActionOptions>> codeActionProvider,
		optional<CodeLensOptions> codeLensProvider,
		optional<DocumentLinkOptions> documentLinkProvider,
		optional<variant<Boolean,
						 DocumentColorOptions,
						 DocumentColorRegistrationOptions>>
			colorProvider,
		optional<variant<Boolean,
						 DocumentFormattingOptions>>
			documentFormattingProvider,
		optional<variant<Boolean,
						 DocumentRangeFormattingOptions>>
			documentRangeFormattingProvider,
		optional<DocumentOnTypeFormattingOptions> documentOnTypeFormattingProvider,
		optional<variant<Boolean, RenameOptions>> renameProvider,
		optional<variant<Boolean,
						 FoldingRangeOptions,
						 FoldingRangeRegistrationOptions>>
			foldingRangeProvider,
		optional<ExecuteCommandOptions> executeCommandProvider,
		optional<variant<Boolean,
						 SelectionRangeOptions,
						 SelectionRangeRegistrationOptions>>
			selectionRangeProvider,
		optional<Boolean> workspaceSymbolProvider,
		optional<Workspace> workspace,
		optional<Any> experimental) : textDocumentSync(textDocumentSync),
									  completionProvider(completionProvider),
									  hoverProvider(hoverProvider),
									  signatureHelpProvider(signatureHelpProvider),
									  declarationProvider(declarationProvider),
									  definitionProvider(definitionProvider),
									  typeDefinitionProvider(typeDefinitionProvider),
									  implementationProvider(implementationProvider),
									  referencesProvider(referencesProvider),
									  documentHighlightProvider(documentHighlightProvider),
									  documentSymbolProvider(documentSymbolProvider),
									  codeActionProvider(codeActionProvider),
									  codeLensProvider(codeLensProvider),
									  documentLinkProvider(documentLinkProvider),
									  colorProvider(colorProvider),
									  documentFormattingProvider(documentFormattingProvider),
									  documentRangeFormattingProvider(documentRangeFormattingProvider),
									  documentOnTypeFormattingProvider(documentOnTypeFormattingProvider),
									  renameProvider(renameProvider),
									  foldingRangeProvider(foldingRangeProvider),
									  executeCommandProvider(executeCommandProvider),
									  selectionRangeProvider(selectionRangeProvider),
									  workspaceSymbolProvider(workspaceSymbolProvider),
									  workspace(workspace),
									  experimental(experimental){};

	ServerCapabilities::ServerCapabilities(){};
	ServerCapabilities::~ServerCapabilities(){};

	void ServerCapabilities::partialWrite(JsonWriter &writer)
	{
		// textDocumentSync?
		if (textDocumentSync.has_value())
		{
			writer.Key(textDocumentSyncKey);
			visit(overload(
					  [&writer](TextDocumentSyncOptions &obj)
					  {
						  writer.Object(obj);
					  },
					  [&writer](Number n)
					  {
						  writer.Number(n);
					  }),
				  *textDocumentSync);
		}

		// completionProvider?
		if (completionProvider.has_value())
		{
			writer.Key(completionProviderKey);
			writer.Object(*completionProvider);
		}

		// hoverProvider?
		if (hoverProvider.has_value())
		{
			writer.Key(hoverProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](HoverOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *hoverProvider);
		}

		// signatureHelpProvider?
		if (signatureHelpProvider.has_value())
		{
			writer.Key(signatureHelpProviderKey);
			writer.Object(*signatureHelpProvider);
		}

		// declarationProvider?
		if (declarationProvider.has_value())
		{
			writer.Key(declarationProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](DeclarationOptions &obj)
					  {
						  writer.Object(obj);
					  },
					  [&writer](DeclarationRegistrationOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *declarationProvider);
		}

		// definitionProvider?
		if (definitionProvider.has_value())
		{
			writer.Key(definitionProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](DefinitionOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *definitionProvider);
		}

		// typeDefinitionProvider?
		if (typeDefinitionProvider.has_value())
		{
			writer.Key(typeDefinitionProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](TypeDefinitionOptions &obj)
					  {
						  writer.Object(obj);
					  },
					  [&writer](TypeDefinitionRegistrationOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *typeDefinitionProvider);
		}

		// implementationProvider?
		if (implementationProvider.has_value())
		{
			writer.Key(implementationProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](ImplementationOptions &obj)
					  {
						  writer.Object(obj);
					  },
					  [&writer](ImplementationRegistrationOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *implementationProvider);
		}

		// referencesProvider?
		if (referencesProvider.has_value())
		{
			writer.Key(referencesProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](ReferenceOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *referencesProvider);
		}

		// documentHighlightProvider?
		if (documentHighlightProvider.has_value())
		{
			writer.Key(documentHighlightProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](DocumentHighlightOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *documentHighlightProvider);
		}

		// documentSymbolProvider?
		if (documentSymbolProvider.has_value())
		{
			writer.Key(documentSymbolProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](DocumentSymbolOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *documentSymbolProvider);
		}

		// codeActionProvider?
		if (codeActionProvider.has_value())
		{
			writer.Key(codeActionProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](CodeActionOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *codeActionProvider);
		}

		// codeLensProvider?
		if (codeLensProvider.has_value())
		{
			writer.Key(codeLensProviderKey);
			writer.Object(*codeLensProvider);
		}

		// documentLinkProvider?
		if (documentLinkProvider.has_value())
		{
			writer.Key(documentLinkProviderKey);
			writer.Object(*documentLinkProvider);
		}

		// colorProvider?
		if (colorProvider.has_value())
		{
			writer.Key(colorProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](DocumentColorOptions &obj)
					  {
						  writer.Object(obj);
					  },
					  [&writer](DocumentColorRegistrationOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *colorProvider);
		}

		// documentFormattingProvider?
		if (documentFormattingProvider.has_value())
		{
			writer.Key(documentFormattingProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](DocumentFormattingOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *documentFormattingProvider);
		}

		// documentRangeFormattingProvider?
		if (documentRangeFormattingProvider.has_value())
		{
			writer.Key(documentRangeFormattingProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](DocumentRangeFormattingOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *documentRangeFormattingProvider);
		}

		// documentOnTypeFormattingProvider?
		if (documentOnTypeFormattingProvider.has_value())
		{
			writer.Key(documentOnTypeFormattingProviderKey);
			writer.Object(*documentOnTypeFormattingProvider);
		}

		// renameProvider?
		if (renameProvider.has_value())
		{
			writer.Key(renameProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](RenameOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *renameProvider);
		}

		// foldingRangeProvider?
		if (foldingRangeProvider.has_value())
		{
			writer.Key(foldingRangeProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](FoldingRangeOptions &obj)
					  {
						  writer.Object(obj);
					  },
					  [&writer](FoldingRangeRegistrationOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *foldingRangeProvider);
		}

		// executeCommandProvider?
		if (executeCommandProvider.has_value())
		{
			writer.Key(executeCommandProviderKey);
			writer.Object(*executeCommandProvider);
		}

		// selectionRangeProvider?
		if (selectionRangeProvider.has_value())
		{
			writer.Key(selectionRangeProviderKey);
			visit(overload(
					  [&writer](Boolean b)
					  {
						  writer.Bool(b);
					  },
					  [&writer](SelectionRangeOptions &obj)
					  {
						  writer.Object(obj);
					  },
					  [&writer](SelectionRangeRegistrationOptions &obj)
					  {
						  writer.Object(obj);
					  }),
				  *selectionRangeProvider);
		}

		// workspaceSymbolProvider?
		if (workspaceSymbolProvider.has_value())
		{
			writer.Key(workspaceSymbolProviderKey);
			writer.Bool(*workspaceSymbolProvider);
		}

		// workspace?
		if (workspace.has_value())
		{
			writer.Key(workspaceKey);
			writer.Object(*workspace);
		}

		// experimental?
		if (experimental.has_value())
		{
			writer.Key(experimentalKey);
			writer.Any(*experimental);
		}
	}

	const String ServerCapabilities::Workspace::
		workspaceFoldersKey = "workspaceFolders";

	ServerCapabilities::Workspace::
		Workspace(optional<WorkspaceFoldersServerCapabilities> workspaceFolders) : workspaceFolders(workspaceFolders){};

	ServerCapabilities::Workspace::Workspace(){};
	ServerCapabilities::Workspace::~Workspace(){};

	void ServerCapabilities::Workspace::partialWrite(JsonWriter &writer)
	{
		// workspaceFolders?
		if (workspaceFolders.has_value())
		{
			writer.Key(workspaceFoldersKey);
			writer.Object(*workspaceFolders);
		}
	}

	InitializedParams::InitializedParams(){};
	InitializedParams::~InitializedParams(){};

	InitializeResult::InitializeResult(ServerCapabilities capabilities,
									   optional<ServerInfo> serverInfo) : capabilities(capabilities),
																		  serverInfo(serverInfo){};

	InitializeResult::InitializeResult(){};
	InitializeResult::~InitializeResult(){};

	void InitializeResult::partialWrite(JsonWriter &writer)
	{
		// capabilities
		writer.Key(capabilitiesKey);
		writer.Object(capabilities);

		// serverInfo?
		if (serverInfo.has_value())
		{
			writer.Key(serverInfoKey);
			writer.Object(*serverInfo);
		}
	}

	InitializeResult::ServerInfo::
		ServerInfo(String name, optional<String> version) : name(name),
															version(version){};

	InitializeResult::ServerInfo::ServerInfo(){};
	InitializeResult::ServerInfo::~ServerInfo(){};

	void InitializeResult::ServerInfo::partialWrite(JsonWriter &writer)
	{
		// name
		writer.Key(nameKey);
		writer.String(name);

		// version?
		if (version.has_value())
		{
			writer.Key(versionKey);
			writer.String(*version);
		}
	}

	InitializeError::InitializeError(Boolean retry) : retry(retry){};

	InitializeError::InitializeError(){};
	InitializeError::~InitializeError(){};

	void InitializeError::partialWrite(JsonWriter &writer)
	{
		// retry
		writer.Key(retryKey);
		writer.Bool(retry);
	}
}
