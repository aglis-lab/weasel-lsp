#pragma once

#include <optional>

#include <wlsp/types/textDocumentIdentifier.hpp>

namespace wlsp
{

	using namespace std;

	/// DidCloseTextDocument parameters
	///
	/// textDocument: TextDocumentIdentifier
	///
	struct DidCloseTextDocumentParams : public ObjectT
	{
	private:
		const static String textDocumentKey;

	public:
		/// The document that was closed.
		TextDocumentIdentifier textDocument;

		//=======================================================================//

		// No writing

		DidCloseTextDocumentParams(TextDocumentIdentifier textDocument);

		DidCloseTextDocumentParams();

		virtual ~DidCloseTextDocumentParams();
	};

}
