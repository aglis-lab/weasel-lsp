#include <wlsp/types/didOpenTextDocument.hpp>

namespace wlsp
{

	using namespace std;

	const String DidOpenTextDocumentParams::textDocumentKey = "textDocument";

	DidOpenTextDocumentParams::DidOpenTextDocumentParams(TextDocumentItem textDocument) : textDocument(textDocument){};

	DidOpenTextDocumentParams::DidOpenTextDocumentParams(){};
	DidOpenTextDocumentParams::~DidOpenTextDocumentParams(){};
}
