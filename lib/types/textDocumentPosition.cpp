#include <wlsp/types/textDocumentPosition.hpp>

namespace wlsp
{

	using namespace std;

	TextDocumentPositionParams::TextDocumentPositionParams(
		TextDocumentIdentifier textDocument,
		Position position) : textDocument(textDocument),
							 position(position){};

	TextDocumentPositionParams::TextDocumentPositionParams(){};
	TextDocumentPositionParams::~TextDocumentPositionParams(){};
}
