#pragma once

#include <wlsp/types/documentFilter.hpp>

namespace wlsp
{

using namespace std;

/// Options to dynamically register for requests for a set of text documents.
///
/// documentSelector: DocumentSelector | Null
///
struct TextDocumentRegistrationOptions: public virtual ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String documentSelectorKey;

public:
	/// A document selector to identify the scope of the registration.
	/// If set to null the document selector provided on the client side
	/// will be used.
	variant<DocumentSelector, Null> documentSelector;

	// No parsing

	TextDocumentRegistrationOptions(variant<DocumentSelector, Null> documentSelector);

	TextDocumentRegistrationOptions();

	virtual ~TextDocumentRegistrationOptions();
};

}
