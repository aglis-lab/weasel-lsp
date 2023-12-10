#include <wlsp/types/textDocumentRegistration.hpp>

namespace wlsp
{

using namespace std;

const String TextDocumentRegistrationOptions::documentSelectorKey = "documentSelector";


TextDocumentRegistrationOptions::
	TextDocumentRegistrationOptions(variant<DocumentSelector, Null> documentSelector):
		documentSelector(documentSelector)
{};

TextDocumentRegistrationOptions::TextDocumentRegistrationOptions(){};
TextDocumentRegistrationOptions::~TextDocumentRegistrationOptions(){};

void TextDocumentRegistrationOptions::partialWrite(JsonWriter &writer)
{
	// documentSelector
	writer.Key(documentSelectorKey);
	visit(overload(
		[&writer](DocumentSelector& arr)
		{
			writer.StartArray();
			for(auto& i: arr)
			{
				writer.Object(i);
			}
			writer.EndArray();
		},
		[&writer](Null)
		{
			writer.Null();
		}
	), documentSelector);
}

}
