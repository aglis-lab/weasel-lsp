#pragma once

#include <wlsp/types/documentFormatting.hpp>

namespace wlsp
{

using namespace std;

/// DocumentOnTypeFormatting request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentOnTypeFormattingClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	//=======================================================================//

	// No writing

	DocumentOnTypeFormattingClientCapabilities(
		optional<Boolean> dynamicRegistration);

	DocumentOnTypeFormattingClientCapabilities();

	virtual ~DocumentOnTypeFormattingClientCapabilities();
};

/// DocumentOnTypeFormatting server capability
///
/// firstTriggerCharacter: String
///
/// moreTriggerCharacter?: String[]
///
struct DocumentOnTypeFormattingOptions: public virtual ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String firstTriggerCharacterKey;
	const static String moreTriggerCharacterKey;

public:
	/// A character on which formatting should be triggered, like `}`.
	String firstTriggerCharacter;

	/// More trigger characters.
	optional<vector<String>> moreTriggerCharacter;

	// No parsing

	DocumentOnTypeFormattingOptions(String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter);

	DocumentOnTypeFormattingOptions();

	virtual ~DocumentOnTypeFormattingOptions();
};

struct DocumentOnTypeFormattingRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentOnTypeFormattingOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	DocumentOnTypeFormattingRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		String firstTriggerCharacter,
		optional<vector<String>> moreTriggerCharacter);

	DocumentOnTypeFormattingRegistrationOptions();

	virtual ~DocumentOnTypeFormattingRegistrationOptions();
};

/// Document on type formatting request parameters
///
/// ch: String
///
/// options: FormattingOptions
///
struct DocumentOnTypeFormattingParams: public TextDocumentPositionParams
{
private:
	const static String chKey;
	const static String optionsKey;

public:
	/// The character that has been typed.
	String ch;

	/// The format options.
	FormattingOptions options;

	//=======================================================================//

	// No writing

	DocumentOnTypeFormattingParams(TextDocumentIdentifier textDocument,
		Position position,
		String ch,
		FormattingOptions options);

	DocumentOnTypeFormattingParams();

	virtual ~DocumentOnTypeFormattingParams();
};

}
