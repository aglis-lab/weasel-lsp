#pragma once

#include <wlsp/types/command.hpp>
#include <wlsp/types/diagnostic.hpp>
#include <wlsp/types/partialResult.hpp>
#include <wlsp/types/range.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>
#include <wlsp/types/workspaceEdit.hpp>

namespace wlsp
{

	using namespace std;

	/// A set of predefined code action kinds.
	struct CodeActionKind
	{
		String kind;

		operator String()
		{
			return kind;
		}

		bool operator<(CodeActionKind &other)
		{
			return this->kind < other.kind;
		}

		CodeActionKind(String kind);

		/// Empty kind.
		const static CodeActionKind Empty;

		/// Base kind for quickfix actions: 'quickfix'.
		const static CodeActionKind QuickFix;

		/// Base kind for refactoring actions: 'refactor'.
		const static CodeActionKind Refactor;

		/// Base kind for refactoring extraction actions: 'refactor.extract'.
		///
		/// Example extract actions:
		///
		/// - Extract method
		/// - Extract function
		/// - Extract variable
		/// - Extract interface from class
		/// - ...
		const static CodeActionKind RefactorExtract;

		/// Base kind for refactoring inline actions: 'refactor.inline'.
		///
		/// Example inline actions:
		///
		/// - Inline function
		/// - Inline variable
		/// - Inline constant
		/// - ...
		const static CodeActionKind RefactorInline;

		/// Base kind for refactoring rewrite actions: 'refactor.rewrite'.
		///
		/// Example rewrite actions:
		///
		/// - Convert JavaScript function to class
		/// - Add or remove parameter
		/// - Encapsulate field
		/// - Make method static
		/// - Move method to base class
		/// - ...
		const static CodeActionKind RefactorRewrite;

		/// Base kind for source actions: `source`.
		///
		/// Source code actions apply to the entire file.
		const static CodeActionKind Source;

		/// Base kind for an organize imports source action:
		/// `source.organizeImports`.
		const static CodeActionKind SourceOrganizeImports;
	};

	/// CodeAction request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	/// codeActionLiteralSupport?: {
	///
	/// 	codeActionKind: {
	///
	/// 		valueSet: CodeActionKind[]
	///
	/// 	}
	/// }
	///
	/// isPreferredSupport?: Boolean
	///
	struct CodeActionClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;
		const static String codeActionLiteralSupportKey;
		const static String isPreferredSupportKey;

	public:
		/// Whether code action supports dynamic registration.
		optional<Boolean> dynamicRegistration;

		/// The client supports code action literals as a valid
		/// response of the `textDocument/codeAction` request.
		///
		/// @since 3.8.0
		struct CodeActionLiteralSupport : public ObjectT
		{
		private:
			const static String codeActionKindKey;

		public:
			/// The code action kind is supported with the following value
			/// set.
			struct CodeActionKind : public ObjectT
			{
			private:
				const static String valueSetKey;

				struct ValueSetMaker : public ObjectT
				{
					vector<wlsp::CodeActionKind> &parentArray;

					//====================   Parsing   ==========================//

					// Using default isValid()

					//===========================================================//

					ValueSetMaker(vector<wlsp::CodeActionKind> &parentArray);

					virtual ~ValueSetMaker();
				};

			public:
				/// The code action kind values the client supports. When this
				/// property exists the client also guarantees that it will
				/// handle values outside its set gracefully and falls back
				/// to a default value when unknown.
				vector<wlsp::CodeActionKind> valueSet;

				//====================   Parsing   ==============================//

				// Using default isValid()

				//===============================================================//

				CodeActionKind(vector<wlsp::CodeActionKind> valueSet);

				CodeActionKind();

				virtual ~CodeActionKind();
			};

			/// The code action kind is supported with the following value
			/// set.
			CodeActionKind codeActionKind;

			//====================   Parsing   ==================================//

			//===================================================================//

			CodeActionLiteralSupport(CodeActionKind codeActionKind);

			CodeActionLiteralSupport();

			virtual ~CodeActionLiteralSupport();
		};

		/// The client supports code action literals as a valid
		/// response of the `textDocument/codeAction` request.
		///
		/// @since 3.8.0
		optional<CodeActionLiteralSupport> codeActionLiteralSupport;

		/// Whether code action supports the `isPreferred` property.
		/// @since 3.15.0
		optional<Boolean> isPreferredSupport;

		//====================   Parsing   ======================================//

		//=======================================================================//

		// No writing

		CodeActionClientCapabilities(optional<Boolean> dynamicRegistration,
									 optional<CodeActionLiteralSupport> codeActionLiteralSupport,
									 optional<Boolean> isPreferredSupport);

		CodeActionClientCapabilities();

		virtual ~CodeActionClientCapabilities();
	};

	/// Code action server capability
	///
	/// codeActionKinds?: CodeActionKind[]
	///
	struct CodeActionOptions : public WorkDoneProgressOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String codeActionKindsKey;

	public:
		/// CodeActionKinds that this server may return.
		///
		/// The list of kinds may be generic, such as `CodeActionKind.Refactor`,
		/// or the server may list out every specific kind they provide.
		optional<vector<CodeActionKind>> codeActionKinds;

		// No parsing

		CodeActionOptions(optional<Boolean> workDoneProgress,
						  optional<vector<CodeActionKind>> codeActionKinds);

		CodeActionOptions();

		virtual ~CodeActionOptions();
	};

	struct CodeActionRegistrationOptions : public TextDocumentRegistrationOptions,
										   public CodeActionOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		CodeActionRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress,
			optional<vector<CodeActionKind>> codeActionKinds);

		CodeActionRegistrationOptions();

		virtual ~CodeActionRegistrationOptions();
	};

	/// Contains additional diagnostic information about the context in which
	/// a code action is run.
	///
	/// diagnostics: Diagnostic[]
	///
	/// only?: CodeActionKind[]
	///
	struct CodeActionContext : public ObjectT
	{
	private:
		const static String diagnosticsKey;
		const static String onlyKey;

		struct DiagnosticsMaker : public ObjectT
		{
			vector<Diagnostic> &parentArray;

			//===================================================================//

			DiagnosticsMaker(vector<Diagnostic> &parentArray);

			virtual ~DiagnosticsMaker();
		};

		struct OnlyMaker : public ObjectT
		{
			vector<CodeActionKind> &parentArray;

			//===================================================================//

			OnlyMaker(vector<CodeActionKind> &parentArray);

			virtual ~OnlyMaker();
		};

	public:
		/// An array of diagnostics known on the client side overlapping the range
		/// provided to the `textDocument/codeAction` request. They are provided so
		/// that the server knows which errors are currently presented to the user
		/// for the given range. There is no guarantee that these accurately
		/// reflect the error state of the resource. The primary parameter to
		/// compute code actions is the provided range.
		vector<Diagnostic> diagnostics;

		/// Requested kind of actions to return.
		///
		/// Actions not of this kind are filtered out by the client before being
		/// shown. So servers can omit computing them.
		optional<vector<CodeActionKind>> only;

		//=======================================================================//

		// No writing

		CodeActionContext(vector<Diagnostic> diagnostics,
						  optional<vector<CodeActionKind>> only);

		CodeActionContext();

		virtual ~CodeActionContext();
	};

	/// Params for the CodeActionRequest
	///
	/// textDocument: TextDocumentIdentifier
	///
	/// range: Range
	///
	/// context: CodeActionContext
	///
	struct CodeActionParams : public WorkDoneProgressParams,
							  public PartialResultParams
	{
	private:
		const static String textDocumentKey;
		const static String rangeKey;
		const static String contextKey;

	public:
		/// The document in which the command was invoked.
		TextDocumentIdentifier textDocument;

		/// The range for which the command was invoked.
		Range range;

		/// Context carrying additional information.
		CodeActionContext context;

		//=======================================================================//

		// No writing

		CodeActionParams(optional<ProgressToken> workDoneToken,
						 optional<ProgressToken> partialResultToken,
						 TextDocumentIdentifier textDocument,
						 Range range,
						 CodeActionContext context);

		CodeActionParams();

		virtual ~CodeActionParams();
	};

	/// A code action represents a change that can be performed in code, e.g. to
	/// fix a problem or to refactor code.
	///
	/// A CodeAction must set either `edit` and/or a `command`. If both are
	/// supplied, the `edit` is applied first, then the `command` is executed.
	///
	/// title: String
	///
	/// kind?: CodeActionKind
	///
	/// diagnostics?: Diagnostic[]
	///
	/// isPreferred?: Boolean
	///
	/// edit?: WorkspaceEdit
	///
	/// command?: Command
	///
	struct CodeAction : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String titleKey;
		const static String kindKey;
		const static String diagnosticsKey;
		const static String isPreferredKey;
		const static String editKey;
		const static String commandKey;

	public:
		/// A short, human-readable, title for this code action.
		String title;

		/// The kind of the code action.
		///
		/// Used to filter code actions.
		optional<CodeActionKind> kind;

		/// The diagnostics that this code action resolves.
		optional<vector<Diagnostic>> diagnostics;

		/// Marks this as a preferred action. Preferred actions are used by the
		/// `auto fix` command and can be targeted by keybindings.
		///
		/// A quick fix should be marked preferred if it properly addresses the
		/// underlying error.  A refactoring should be marked preferred if it is
		/// the most reasonable choice of actions to take.
		///
		/// @since 3.15.0
		optional<Boolean> isPreferred;

		/// The workspace edit this code action performs.
		optional<WorkspaceEdit> edit;

		/// A command this code action executes. If a code action
		/// provides an edit and a command, first the edit is
		/// executed and then the command.
		optional<Command> command;

		// No parsing

		CodeAction(String title,
				   optional<CodeActionKind> kind,
				   optional<vector<Diagnostic>> diagnostics,
				   optional<Boolean> isPreferred,
				   optional<WorkspaceEdit> edit,
				   optional<Command> command);

		CodeAction();

		virtual ~CodeAction();
	};

}
