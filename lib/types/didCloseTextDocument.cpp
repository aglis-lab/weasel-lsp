#include <wlsp/types/didCloseTextDocument.hpp>

namespace wlsp
{

	using namespace std;

	const String DidCloseTextDocumentParams::textDocumentKey = "textDocument";

	DidCloseTextDocumentParams::
		DidCloseTextDocumentParams(TextDocumentIdentifier textDocument) : textDocument(textDocument){};

	DidCloseTextDocumentParams::DidCloseTextDocumentParams(){};
	DidCloseTextDocumentParams::~DidCloseTextDocumentParams(){};
}
