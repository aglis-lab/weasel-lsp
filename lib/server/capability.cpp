#include <wlsp/server/capability.hpp>

#include <wlsp/types.hpp>

namespace wlsp
{

	using namespace std;

	// Cancellation Support
	const Capability Capability::cancelRequest = {"$/cancelRequest"};

	const Capability Capability::progress = {"$/progress"};

	const Capability Capability::initialize = {"initialize"};

	const Capability Capability::initialized = {"initialized"};

	const Capability Capability::shutdown = {"shutdown"};

	const Capability Capability::exit = {"exit"};

	const Capability Capability::windowShowMessage = {"window/showMessage"};

	const Capability Capability::windowShowMessageRequest = {"window/showMessageRequest"};

	const Capability Capability::windowLogMessage = {"window/logMessage"};

	const Capability Capability::windowWorkDoneProgressCreate = {"window/workDoneProgress/create"};

	const Capability Capability::windowWorkDoneProgressCancel = {"window/workDoneProgress/cancel"};

	const Capability Capability::telemetryEvent = {"telemetry/event"};

	const Capability Capability::clientRegisterCapability = {"client/registerCapability"};

	const Capability Capability::clientUnregisterCapability = {"client/unregisterCapability"};

	const Capability Capability::workspaceWorkspaceFolders = {"workspace/workspaceFolders"};

	const Capability Capability::workspaceDidChangeWorkspaceFolders = {"workspace/didChangeWorkspaceFolders"};

	const Capability Capability::workspaceDidChangeConfiguration = {"workspace/didChangeConfiguration’"};

	const Capability Capability::workspaceConfiguration = {"workspace/configuration"};

	const Capability Capability::workspaceDidChangeWatchedFiles = {"workspace/didChangeWatchedFiles"};

	const Capability Capability::workspaceSymbol = {"workspace/symbol"};

	const Capability Capability::workspaceExecuteCommand = {"workspace/executeCommand"};

	const Capability Capability::workspaceApplyEdit = {"workspace/applyEdit"};

	// const Capability Capability::textDocumentDidOpen = {
	// 	// Method
	// 	"textDocument/didOpen",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DidOpenTextDocumentParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	nullopt};

	// const Capability Capability::textDocumentDidChange = {
	// 	// Method
	// 	"textDocument/didChange",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DidChangeTextDocumentParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	nullopt};

	// const Capability Capability::textDocumentWillSave = {
	// 	// Method
	// 	"textDocument/willSave",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<WillSaveTextDocumentParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	nullopt};

	// const Capability Capability::textDocumentWillSaveWaitUntil = {
	// 	// Method
	// 	"textDocument/willSaveWaitUntil",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<WillSaveTextDocumentParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<TextEdit> &vec)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : vec)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<TextEdit>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentDidSave = {
	// 	// Method
	// 	"textDocument/didSave",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DidSaveTextDocumentParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	nullopt};

	// const Capability Capability::textDocumentDidClose = {
	// 	// Method
	// 	"textDocument/didClose",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DidCloseTextDocumentParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	nullopt};

	// const Capability Capability::textDocumentPublishDiagnostics = {
	// 	// Method
	// 	"textDocument/publishDiagnostics",

	// 	// Request
	// 	{
	// 		// Writer
	// 		[](JsonWriter &writer, any &data)
	// 		{
	// 			writer.Object(any_cast<PublishDiagnosticsParams &>(data));
	// 		},

	// 		// Reader
	// 		nullopt},

	// 	// Response
	// 	nullopt};

	// const Capability Capability::textDocumentCompletion = {
	// 	// Method
	// 	"textDocument/completion",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<CompletionParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<CompletionItem> &vec)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : vec)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](CompletionList &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<CompletionItem>, CompletionList, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::completionItemResolve = {
	// 	// Method
	// 	"completionItem/resolve",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<CompletionItem>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  writer.Object(any_cast<CompletionItem &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentHover = {
	// 	// Method
	// 	"textDocument/hover",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<HoverParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](Hover &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<Hover, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentSignatureHelp = {
	// 	// Method
	// 	"textDocument/signatureHelp",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<SignatureHelpParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](SignatureHelp &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<SignatureHelp, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentDeclaration = {
	// 	// Method
	// 	"textDocument/declaration",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DeclarationParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](Location &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](vector<Location> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](vector<LocationLink> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<Location, vector<Location>, vector<LocationLink>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentDefinition = {
	// 	// Method
	// 	"textDocument/definition",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DefinitionParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](Location &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](vector<Location> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](vector<LocationLink> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<Location, vector<Location>, vector<LocationLink>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentTypeDefinition = {
	// 	// Method
	// 	"textDocument/typeDefinition",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<TypeDefinitionParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](Location &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](vector<Location> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](vector<LocationLink> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<Location, vector<Location>, vector<LocationLink>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentImplementation = {
	// 	// Method
	// 	"textDocument/implementation",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<ImplementationParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](Location &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](vector<Location> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](vector<LocationLink> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<Location, vector<Location>, vector<LocationLink>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentReferences = {
	// 	// Method
	// 	"textDocument/references",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<ReferenceParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<Location> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<Location>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentDocumentHighlight = {
	// 	// Method
	// 	"textDocument/documentHighlight",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentHighlightParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<DocumentHighlight> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<DocumentHighlight>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentDocumentSymbol = {
	// 	// Method
	// 	"textDocument/documentSymbol",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentSymbolParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<DocumentSymbol> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](vector<SymbolInformation> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<DocumentSymbol>, vector<SymbolInformation>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentCodeAction = {
	// 	// Method
	// 	"textDocument/codeAction",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<CodeActionParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<variant<Command, CodeAction>> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							visit(overload(
	// 									  [&writer](Command &obj)
	// 									  {
	// 										  writer.Object(obj);
	// 									  },
	// 									  [&writer](CodeAction &obj)
	// 									  {
	// 										  writer.Object(obj);
	// 									  }),
	// 								  i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<variant<Command, CodeAction>>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentCodeLens = {
	// 	// Method
	// 	"textDocument/codeLens",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<CodeLensParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<CodeLens> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<CodeLens>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::codeLensResolve = {
	// 	// Method
	// 	"codeLens/resolve",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<CodeLens>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  writer.Object(any_cast<CodeLens &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentDocumentLink = {
	// 	// Method
	// 	"textDocument/documentLink",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentLinkParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<DocumentLink> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<DocumentLink>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::documentLinkResolve = {
	// 	// Method
	// 	"documentLink/resolve",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentLink>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  writer.Object(any_cast<DocumentLink &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentDocumentColor = {
	// 	// Method
	// 	"textDocument/documentColor",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentColorParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  auto &arr = any_cast<vector<ColorInformation> &>(data);

	// 		  writer.StartArray();
	// 		  for (auto &i : arr)
	// 		  {
	// 			  writer.Object(i);
	// 		  }
	// 		  writer.EndArray();
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentColorPresentation = {
	// 	// Method
	// 	"textDocument/colorPresentation",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<ColorPresentationParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  auto &arr = any_cast<vector<ColorPresentation> &>(data);

	// 		  writer.StartArray();
	// 		  for (auto &i : arr)
	// 		  {
	// 			  writer.Object(i);
	// 		  }
	// 		  writer.EndArray();
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentFormatting = {
	// 	// Method
	// 	"textDocument/formatting",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentFormattingParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<TextEdit> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<TextEdit>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentRangeFormatting = {
	// 	// Method
	// 	"textDocument/rangeFormatting",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentRangeFormattingParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<TextEdit> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<TextEdit>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentOnTypeFormatting = {
	// 	// Method
	// 	"textDocument/onTypeFormatting",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<DocumentOnTypeFormattingParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](vector<TextEdit> &arr)
	// 					{
	// 						writer.StartArray();
	// 						for (auto &i : arr)
	// 						{
	// 							writer.Object(i);
	// 						}
	// 						writer.EndArray();
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<vector<TextEdit>, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

	// const Capability Capability::textDocumentRename = {
	// 	// Method
	// 	"textDocument/rename",

	// 	// Request
	// 	{
	// 		// Writer
	// 		nullopt,

	// 		// Reader
	// 		[](JsonHandler &handler, optional<any> &data)
	// 		{
	// 			auto &params = data.emplace().emplace<RenameParams>();

	// 			return ValueSetter{
	// 				// String
	// 				nullopt,

	// 				// Number
	// 				nullopt,

	// 				// Boolean
	// 				nullopt,

	// 				// Null
	// 				nullopt,

	// 				// Array
	// 				nullopt,

	// 				// Object
	// 				[&handler, &params]()
	// 				{
	// 					handler.pushInitializer();
	// 				}};
	// 		}},

	// 	// Response
	// 	{{// Writer
	// 	  [](JsonWriter &writer, any &data)
	// 	  {
	// 		  visit(overload(
	// 					[&writer](WorkspaceEdit &obj)
	// 					{
	// 						writer.Object(obj);
	// 					},
	// 					[&writer](Null)
	// 					{
	// 						writer.Null();
	// 					}),
	// 				any_cast<variant<WorkspaceEdit, Null> &>(data));
	// 	  },

	// 	  // Reader
	// 	  nullopt}}};

}
