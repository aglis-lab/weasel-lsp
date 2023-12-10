#pragma once

#include <wlsp/types/position.hpp>
#include <wlsp/types/textDocumentIdentifier.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

using namespace std;

/// Rename request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// prepareSupport?: Boolean
///
struct RenameClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;
	const static String prepareSupportKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	/// Client supports testing for validity of rename operations
	/// before execution.
	///
	/// @since version 3.12.0
	optional<Boolean> prepareSupport;

	//=======================================================================//

	// No writing

	RenameClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<Boolean> prepareSupport);

	RenameClientCapabilities();

	virtual ~RenameClientCapabilities();
};

/// RenameOptions may only be specified if the client states that it supports
/// prepareSupport in its initial initialize request.
///
/// prepareProvider?: Boolean
///
struct RenameOptions: public WorkDoneProgressOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String prepareProviderKey;

public:
	/// Renames should be checked and tested before being executed.
	optional<Boolean> prepareProvider;

	// No parsing

	RenameOptions(optional<Boolean> workDoneProgress,
		optional<Boolean> prepareProvider);

	RenameOptions();

	virtual ~RenameOptions();
};

struct RenameRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public RenameOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	RenameRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<Boolean> prepareProvider);

	RenameRegistrationOptions();

	virtual ~RenameRegistrationOptions();
};

/// Document range formatting request parameters
///
/// newName: String
///
struct RenameParams: public TextDocumentPositionParams,
	public WorkDoneProgressParams
{
private:
	const static String newNameKey;

public:
	/// The new name of the symbol. If the given name is not valid the
	/// request must return a ResponseError with an
	/// appropriate message set.
	String newName;

	//=======================================================================//

	// No writing

	RenameParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		String newName);

	RenameParams();

	virtual ~RenameParams();
};

}
