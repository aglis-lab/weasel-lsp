#pragma once

#include <wlsp/types/staticRegistration.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>
#include <wlsp/types/partialResult.hpp>

namespace wlsp
{

using namespace std;

/// Goto type definition request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// linkSupport?: Boolean
///
struct TypeDefinitionClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;
	const static String linkSupportKey;

public:
	/// Whether implementation supports dynamic registration. If this is set to
	/// `true` the client supports the new `TypeDefinitionRegistrationOptions`
	/// return value for the corresponding server capability as well.
	optional<Boolean> dynamicRegistration;

	/// The client supports additional metadata in the form of declaration
	/// links.
	///
	/// @since 3.14.0
	optional<Boolean> linkSupport;

	//=======================================================================//

	// No writing

	TypeDefinitionClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> linkSupport);

	TypeDefinitionClientCapabilities();

	virtual ~TypeDefinitionClientCapabilities();
};

using TypeDefinitionOptions = WorkDoneProgressOptions; // No parsing

struct TypeDefinitionRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public TypeDefinitionOptions,
	public StaticRegistrationOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	TypeDefinitionRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<String> id);

	TypeDefinitionRegistrationOptions();

	virtual ~TypeDefinitionRegistrationOptions();
};

struct TypeDefinitionParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams,
	public PartialResultParams
{
	//=======================================================================//

	// No writing

	TypeDefinitionParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken);

	TypeDefinitionParams();

	virtual ~TypeDefinitionParams();
};

}
