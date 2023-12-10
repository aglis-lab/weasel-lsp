#include <wlsp/types/willSaveTextDocument.hpp>

namespace wlsp
{

	using namespace std;

	const String WillSaveTextDocumentParams::textDocumentKey = "textDocument";
	const String WillSaveTextDocumentParams::reasonKey = "reason";

	WillSaveTextDocumentParams::
		WillSaveTextDocumentParams(TextDocumentIdentifier textDocument,
								   TextDocumentSaveReason reason) : textDocument(textDocument),
																	reason(reason){};

	WillSaveTextDocumentParams::WillSaveTextDocumentParams(){};
	WillSaveTextDocumentParams::~WillSaveTextDocumentParams(){};
}
