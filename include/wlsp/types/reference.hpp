#pragma once

#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>
#include <wlsp/types/partialResult.hpp>

namespace wlsp
{

	using namespace std;

	/// Goto Reference request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	struct ReferenceClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;

	public:
		/// Whether declaration supports dynamic registration.
		optional<Boolean> dynamicRegistration;

		//=======================================================================//

		// No writing

		ReferenceClientCapabilities(optional<Boolean> dynamicRegistration);

		ReferenceClientCapabilities();

		virtual ~ReferenceClientCapabilities();
	};

	/// Find references server capability
	using ReferenceOptions = WorkDoneProgressOptions; // No parsing

	struct ReferenceRegistrationOptions : public TextDocumentRegistrationOptions,
										  public ReferenceOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		ReferenceRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress);

		ReferenceRegistrationOptions();

		virtual ~ReferenceRegistrationOptions();
	};

	/// An option for the find references request.
	///
	/// includeDeclaration: Boolean
	///
	struct ReferenceContext : public ObjectT
	{
	private:
		const static String includeDeclarationKey;

	public:
		Boolean includeDeclaration;

		//=======================================================================//

		// No writing

		ReferenceContext(Boolean includeDeclaration);

		ReferenceContext();

		virtual ~ReferenceContext();
	};

	/// Find references request parameters
	///
	/// context: ReferenceContext
	///
	struct ReferenceParams : public TextDocumentPositionParams,
							 public WorkDoneProgressParams,
							 public PartialResultParams
	{
	private:
		const static String contextKey;

	public:
		ReferenceContext context;

		//=======================================================================//

		// No writing

		ReferenceParams(TextDocumentIdentifier textDocument,
						Position position,
						optional<ProgressToken> workDoneToken,
						optional<ProgressToken> partialResultToken,
						ReferenceContext context);

		ReferenceParams();

		virtual ~ReferenceParams();
	};

}
