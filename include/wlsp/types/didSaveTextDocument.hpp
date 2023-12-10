#pragma once

#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/textDocumentIdentifier.hpp>

namespace wlsp
{

using namespace std;

/// DidSaveTextDocument Server capability
///
/// includeText?: Boolean
///
struct SaveOptions: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String includeTextKey;

public:
	/// The client is supposed to include the content on save.
	optional<Boolean> includeText;

	// No parsing

	SaveOptions(optional<Boolean> includeText);

	SaveOptions();

	virtual ~SaveOptions();
};

/// DidSaveTextDocument registration options
///
/// includeText?: Boolean
///
struct TextDocumentSaveRegistrationOptions: public TextDocumentRegistrationOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String includeTextKey;

public:
	/// The client is supposed to include the content on save.
	optional<Boolean> includeText;

	// No parsing

	TextDocumentSaveRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> includeText);

	TextDocumentSaveRegistrationOptions();

	virtual ~TextDocumentSaveRegistrationOptions();
};

/// DidSaveTextDocument parameters
///
/// textDocument: TextDocumentIdentifier
///
/// text?: String
///
struct DidSaveTextDocumentParams: public ObjectT
{
private:
	const static String textDocumentKey;
	const static String textKey;

public:
	/// The document that was saved.
	TextDocumentIdentifier textDocument;

	/// Optional the content when saved. Depends on the includeText value
	/// when the save notification was requested.
	optional<String> text;

	//=======================================================================//

	// No writing

	DidSaveTextDocumentParams(TextDocumentIdentifier textDocument,
		optional<String> text);

	DidSaveTextDocumentParams();

	virtual ~DidSaveTextDocumentParams();
};

}
