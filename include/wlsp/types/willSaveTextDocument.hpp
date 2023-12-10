#pragma once

#include <optional>

#include <wlsp/types/textDocumentIdentifier.hpp>

namespace wlsp
{

using namespace std;

/// Represents reasons why a text document is saved.
enum class TextDocumentSaveReason
{
	/// Manually triggered, e.g. by the user pressing save, by starting
	/// debugging, or by an API call.
	Manual = 1,

	/// Automatic after a delay.
	AfterDelay = 2,

	/// When the editor lost focus.
	FocusOut = 3
};

/// The parameters send in a will save text document notification.
///
/// textDocument: TextDocumentIdentifie
///
/// reason: TextDocumentSaveReason
///
struct WillSaveTextDocumentParams: public ObjectT
{
private:
	const static String textDocumentKey;
	const static String reasonKey;

public:
	/// The document that will be saved.
	TextDocumentIdentifier textDocument;

	/// The 'TextDocumentSaveReason'.
	TextDocumentSaveReason reason;

	//=======================================================================//

	// No writing

	WillSaveTextDocumentParams(TextDocumentIdentifier textDocument,
		TextDocumentSaveReason reason);

	WillSaveTextDocumentParams();

	virtual ~WillSaveTextDocumentParams();
};

}
