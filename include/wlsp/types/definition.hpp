#pragma once

#include <wlsp/types/staticRegistration.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>
#include <wlsp/types/partialResult.hpp>

namespace wlsp
{

	using namespace std;

	/// Goto Definition request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	/// linkSupport?: Boolean
	///
	struct DefinitionClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;
		const static String linkSupportKey;

	public:
		/// Whether declaration supports dynamic registration.
		optional<Boolean> dynamicRegistration;

		/// The client supports additional metadata in the form of declaration
		/// links.
		///
		/// @since 3.14.0
		optional<Boolean> linkSupport;

		//=======================================================================//

		// No writing

		DefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
									 optional<Boolean> linkSupport);

		DefinitionClientCapabilities();

		virtual ~DefinitionClientCapabilities();
	};

	using DefinitionOptions = WorkDoneProgressOptions; // No parsing

	struct DefinitionRegistrationOptions : public TextDocumentRegistrationOptions,
										   public DefinitionOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		DefinitionRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress);

		DefinitionRegistrationOptions();

		virtual ~DefinitionRegistrationOptions();
	};

	struct DefinitionParams : public TextDocumentPositionParams,
							  public WorkDoneProgressParams,
							  public PartialResultParams
	{

		//=======================================================================//

		// No writing

		DefinitionParams(TextDocumentIdentifier textDocument,
						 Position position,
						 optional<ProgressToken> workDoneToken,
						 optional<ProgressToken> partialResultToken);

		DefinitionParams();

		virtual ~DefinitionParams();
	};
}
