#pragma once

#include <wlsp/types/command.hpp>
#include <wlsp/types/diagnostic.hpp>
#include <wlsp/types/partialResult.hpp>
#include <wlsp/types/range.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

	using namespace std;

	/// CodeLens request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	struct CodeLensClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;

	public:
		/// Whether code action supports dynamic registration.
		optional<Boolean> dynamicRegistration;

		//=======================================================================//

		// No writing

		CodeLensClientCapabilities(optional<Boolean> dynamicRegistration);

		CodeLensClientCapabilities();

		virtual ~CodeLensClientCapabilities();
	};

	/// Code lens server capability
	///
	/// resolveProvider?: Boolean
	///
	struct CodeLensOptions : public WorkDoneProgressOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String resolveProviderKey;

	public:
		/// Code lens has a resolve provider as well.
		optional<Boolean> resolveProvider;

		// No parsing

		CodeLensOptions(optional<Boolean> workDoneProgress,
						optional<Boolean> resolveProvider);

		CodeLensOptions();

		virtual ~CodeLensOptions();
	};

	struct CodeLensRegistrationOptions : public TextDocumentRegistrationOptions,
										 public CodeLensOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		CodeLensRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress,
			optional<Boolean> resolveProvider);

		CodeLensRegistrationOptions();

		virtual ~CodeLensRegistrationOptions();
	};

	/// Params for the CodeLensRequest
	///
	/// textDocument: TextDocumentIdentifier
	///
	struct CodeLensParams : public WorkDoneProgressParams,
							public PartialResultParams
	{
	private:
		const static String textDocumentKey;

	public:
		/// The document in which the command was invoked.
		TextDocumentIdentifier textDocument;

		//=======================================================================//

		// No writing

		CodeLensParams(optional<ProgressToken> workDoneToken,
					   optional<ProgressToken> partialResultToken,
					   TextDocumentIdentifier textDocument);

		CodeLensParams();

		virtual ~CodeLensParams();
	};

	/// A code lens represents a command that should be shown along with
	/// source text, like the number of references, a way to run tests, etc.
	///
	/// A code lens is _unresolved_ when no command is associated to it. For
	/// performance reasons the creation of a code lens and resolving should be
	/// done in two stages.
	///
	/// range: Range
	///
	/// command?: Command
	///
	/// data?: Any
	///
	struct CodeLens : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String rangeKey;
		const static String commandKey;
		const static String dataKey;

	public:
		/// The range in which this code lens is valid. Should only span a single
		/// line.
		Range range;

		/// The command this code lens represents.
		optional<Command> command;

		/// A data entry field that is preserved on a code lens item between
		/// a code lens and a code lens resolve request.
		optional<Any> data;

		// No parsing

		CodeLens(Range range,
				 optional<Command> command,
				 optional<Any> data);

		CodeLens();

		virtual ~CodeLens();
	};
}
