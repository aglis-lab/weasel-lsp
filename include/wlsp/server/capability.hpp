#pragma once

#include <any>

#include <wlsp/json/jsonWriter.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	struct Capability
	{
		/// The name of the method
		String method;

		Capability(String method) : method(method) {}

		virtual ~Capability() {}

		// Default capabilities
		const static Capability cancelRequest;
		const static Capability progress;
		const static Capability initialize;
		const static Capability initialized;
		const static Capability shutdown;
		const static Capability exit;
		const static Capability windowShowMessage;
		const static Capability windowShowMessageRequest;
		const static Capability windowLogMessage;
		const static Capability windowWorkDoneProgressCreate;
		const static Capability windowWorkDoneProgressCancel;
		const static Capability telemetryEvent;
		const static Capability clientRegisterCapability;
		const static Capability clientUnregisterCapability;
		const static Capability workspaceWorkspaceFolders;
		const static Capability workspaceDidChangeWorkspaceFolders;
		const static Capability workspaceDidChangeConfiguration;
		const static Capability workspaceConfiguration;
		const static Capability workspaceDidChangeWatchedFiles;
		const static Capability workspaceSymbol;
		const static Capability workspaceExecuteCommand;
		const static Capability workspaceApplyEdit;
		// const static Capability textDocumentDidOpen;
		// const static Capability textDocumentDidChange;
		// const static Capability textDocumentWillSave;
		// const static Capability textDocumentWillSaveWaitUntil;
		// const static Capability textDocumentDidSave;
		// const static Capability textDocumentDidClose;
		// const static Capability textDocumentPublishDiagnostics;
		// const static Capability textDocumentCompletion;
		// const static Capability completionItemResolve;
		// const static Capability textDocumentHover;
		// const static Capability textDocumentSignatureHelp;
		// const static Capability textDocumentDeclaration;
		// const static Capability textDocumentDefinition;
		// const static Capability textDocumentTypeDefinition;
		// const static Capability textDocumentImplementation;
		// const static Capability textDocumentReferences;
		// const static Capability textDocumentDocumentHighlight;
		// const static Capability textDocumentDocumentSymbol;
		// const static Capability textDocumentCodeAction;
		// const static Capability textDocumentCodeLens;
		// const static Capability codeLensResolve;
		// const static Capability textDocumentDocumentLink;
		// const static Capability documentLinkResolve;
		// const static Capability textDocumentDocumentColor;
		// const static Capability textDocumentColorPresentation;
		// const static Capability textDocumentFormatting;
		// const static Capability textDocumentRangeFormatting;
		// const static Capability textDocumentOnTypeFormatting;
		// const static Capability textDocumentRename;
	};
}
