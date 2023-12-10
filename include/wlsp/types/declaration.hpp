#pragma once

#include <wlsp/types/staticRegistration.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>
#include <wlsp/types/partialResult.hpp>

namespace wlsp
{

	using namespace std;

	/// Goto Declaration request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	/// linkSupport?: Boolean
	///
	struct DeclarationClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;
		const static String linkSupportKey;

	public:
		/// Whether declaration supports dynamic registration. If this is set to
		/// `true` the client supports the new `DeclarationRegistrationOptions`
		/// return value for the corresponding server capability as well.
		optional<Boolean> dynamicRegistration;

		/// The client supports additional metadata in the form of declaration
		/// links.
		///
		/// @since 3.14.0
		optional<Boolean> linkSupport;

		//=======================================================================//

		// No writing

		DeclarationClientCapabilities(optional<Boolean> dynamicRegistration,
									  optional<Boolean> linkSupport);

		DeclarationClientCapabilities();

		virtual ~DeclarationClientCapabilities();
	};

	using DeclarationOptions = WorkDoneProgressOptions; // No parsing

	struct DeclarationRegistrationOptions : public DeclarationOptions,
											public TextDocumentRegistrationOptions,
											public StaticRegistrationOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		DeclarationRegistrationOptions(optional<Boolean> workDoneProgress,
									   variant<DocumentSelector, Null> documentSelector,
									   optional<String> id);

		DeclarationRegistrationOptions();

		virtual ~DeclarationRegistrationOptions();
	};

	struct DeclarationParams : public TextDocumentPositionParams,
							   public WorkDoneProgressParams,
							   public PartialResultParams
	{

		//=======================================================================//

		// No writing

		DeclarationParams(TextDocumentIdentifier textDocument,
						  Position position,
						  optional<ProgressToken> workDoneToken,
						  optional<ProgressToken> partialResultToken);

		DeclarationParams();

		virtual ~DeclarationParams();
	};
}
