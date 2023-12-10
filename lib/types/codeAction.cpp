#include <wlsp/types/codeAction.hpp>

namespace wlsp
{

	using namespace std;

	CodeActionKind::CodeActionKind(String kind) : kind(kind){};

	const CodeActionKind
		CodeActionKind::Empty = ""s,
		CodeActionKind::QuickFix = "quickfix"s,
		CodeActionKind::Refactor = "refactor"s,
		CodeActionKind::RefactorExtract = "refactor.extract"s,
		CodeActionKind::RefactorInline = "refactor.inline"s,
		CodeActionKind::RefactorRewrite = "refactor.rewrite"s,
		CodeActionKind::Source = "source"s,
		CodeActionKind::SourceOrganizeImports = "source.organizeImports"s;

	const String CodeActionClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String CodeActionClientCapabilities::
		codeActionLiteralSupportKey = "codeActionLiteralSupport";

	const String CodeActionClientCapabilities::
		isPreferredSupportKey = "isPreferredSupport";

	CodeActionClientCapabilities::
		CodeActionClientCapabilities(optional<Boolean> dynamicRegistration,
									 optional<CodeActionLiteralSupport> codeActionLiteralSupport,
									 optional<Boolean> isPreferredSupport) : dynamicRegistration(dynamicRegistration),
																			 codeActionLiteralSupport(codeActionLiteralSupport),
																			 isPreferredSupport(isPreferredSupport){};

	CodeActionClientCapabilities::CodeActionClientCapabilities(){};
	CodeActionClientCapabilities::~CodeActionClientCapabilities(){};

	const String CodeActionClientCapabilities::CodeActionLiteralSupport::
		codeActionKindKey = "codeActionKind";

	CodeActionClientCapabilities::CodeActionLiteralSupport::
		CodeActionLiteralSupport(CodeActionKind codeActionKind) : codeActionKind(codeActionKind){};

	CodeActionClientCapabilities::CodeActionLiteralSupport::
		CodeActionLiteralSupport(){};

	CodeActionClientCapabilities::CodeActionLiteralSupport::~CodeActionLiteralSupport(){};

	const String CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::valueSetKey = "valueSet";

	CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::CodeActionKind(vector<wlsp::CodeActionKind> valueSet) : valueSet(valueSet){};

	CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::CodeActionKind(){};

	CodeActionClientCapabilities::CodeActionLiteralSupport::CodeActionKind::~CodeActionKind(){};

	CodeActionClientCapabilities::
		CodeActionLiteralSupport::
			CodeActionKind::
				ValueSetMaker::
					ValueSetMaker(vector<wlsp::CodeActionKind> &parentArray) : parentArray(parentArray){};

	CodeActionClientCapabilities::
		CodeActionLiteralSupport::
			CodeActionKind::
				ValueSetMaker::
					~ValueSetMaker(){};

	const String CodeActionOptions::codeActionKindsKey = "codeActionKinds";

	CodeActionOptions::CodeActionOptions(optional<Boolean> workDoneProgress,
										 optional<vector<CodeActionKind>> codeActionKinds) : WorkDoneProgressOptions(workDoneProgress),
																							 codeActionKinds(codeActionKinds){};

	CodeActionOptions::CodeActionOptions(){};
	CodeActionOptions::~CodeActionOptions(){};

	void CodeActionOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		WorkDoneProgressOptions::partialWrite(writer);

		// codeActionKinds?
		if (codeActionKinds.has_value())
		{
			writer.Key(codeActionKindsKey);
			writer.StartArray();
			for (auto &i : *codeActionKinds)
			{
				writer.String(i);
			}
			writer.EndArray();
		}
	}

	CodeActionRegistrationOptions::CodeActionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<vector<CodeActionKind>> codeActionKinds) : TextDocumentRegistrationOptions(documentSelector),
															CodeActionOptions(workDoneProgress, codeActionKinds){};

	CodeActionRegistrationOptions::CodeActionRegistrationOptions(){};
	CodeActionRegistrationOptions::~CodeActionRegistrationOptions(){};

	void CodeActionRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		CodeActionOptions::partialWrite(writer);
	}

	const String CodeActionContext::diagnosticsKey = "diagnostics";
	const String CodeActionContext::onlyKey = "only";

	CodeActionContext::CodeActionContext(vector<Diagnostic> diagnostics,
										 optional<vector<CodeActionKind>> only) : diagnostics(diagnostics),
																				  only(only){};

	CodeActionContext::CodeActionContext(){};
	CodeActionContext::~CodeActionContext(){};

	CodeActionContext::DiagnosticsMaker::
		DiagnosticsMaker(vector<Diagnostic> &parentArray) : parentArray(parentArray){};

	CodeActionContext::DiagnosticsMaker::
		~DiagnosticsMaker(){};

	CodeActionContext::OnlyMaker::OnlyMaker(vector<CodeActionKind> &parentArray) : parentArray(parentArray){};

	CodeActionContext::OnlyMaker::
		~OnlyMaker(){};

	const String CodeActionParams::textDocumentKey = "textDocument";
	const String CodeActionParams::rangeKey = "range";
	const String CodeActionParams::contextKey = "context";

	CodeActionParams::CodeActionParams(optional<ProgressToken> workDoneToken,
									   optional<ProgressToken> partialResultToken,
									   TextDocumentIdentifier textDocument,
									   Range range,
									   CodeActionContext context) : WorkDoneProgressParams(workDoneToken),
																	PartialResultParams(partialResultToken),
																	textDocument(textDocument),
																	range(range),
																	context(context){};

	CodeActionParams::CodeActionParams(){};
	CodeActionParams::~CodeActionParams(){};

	const String CodeAction::titleKey = "title";
	const String CodeAction::kindKey = "kind";
	const String CodeAction::diagnosticsKey = "diagnostics";
	const String CodeAction::isPreferredKey = "isPreferred";
	const String CodeAction::editKey = "edit";
	const String CodeAction::commandKey = "command";

	CodeAction::CodeAction(String title,
						   optional<CodeActionKind> kind,
						   optional<vector<Diagnostic>> diagnostics,
						   optional<Boolean> isPreferred,
						   optional<WorkspaceEdit> edit,
						   optional<Command> command) : title(title),
														kind(kind),
														diagnostics(diagnostics),
														isPreferred(isPreferred),
														edit(edit),
														command(command){};

	CodeAction::CodeAction(){};
	CodeAction::~CodeAction(){};

	void CodeAction::partialWrite(JsonWriter &writer)
	{
		// title
		writer.Key(titleKey);
		writer.String(title);

		// kind?
		if (kind.has_value())
		{
			writer.Key(kindKey);
			writer.String(*kind);
		}

		// diagnostics?
		if (diagnostics.has_value())
		{
			writer.Key(diagnosticsKey);
			writer.StartArray();
			for (auto &i : *diagnostics)
			{
				writer.Object(i);
			}
			writer.EndArray();
		}

		// isPreferred?
		if (isPreferred.has_value())
		{
			writer.Key(isPreferredKey);
			writer.Bool(*isPreferred);
		}

		// edit?
		if (edit.has_value())
		{
			writer.Key(editKey);
			writer.Object(*edit);
		}

		// command?
		if (command.has_value())
		{
			writer.Key(commandKey);
			writer.Object(*command);
		}
	}

}
