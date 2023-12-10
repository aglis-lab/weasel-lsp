#pragma once

#include <wlsp/types/textDocumentItem.hpp>

namespace wlsp
{

	using namespace std;

	/// The document open notification is sent from the client to the server
	/// to signal newly opened text documents.
	///
	/// textDocument: TextDocumentItem
	///
	struct DidOpenTextDocumentParams : public ObjectT
	{
	private:
		const static String textDocumentKey;

	public:
		/// The document that was opened.
		TextDocumentItem textDocument;

		//=======================================================================//

		// No writing

		DidOpenTextDocumentParams(TextDocumentItem textDocument);

		DidOpenTextDocumentParams();

		virtual ~DidOpenTextDocumentParams();
	};

}
