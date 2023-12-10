#pragma once

#include <wlsp/types/textDocumentIdentifier.hpp>
#include <wlsp/types/position.hpp>

namespace wlsp
{

	using namespace std;

	/// A parameter literal used in requests to pass a text document
	/// and a position inside that document.
	///
	/// textDocument: TextDocumentIdentifier
	///
	/// position: Position
	///
	struct TextDocumentPositionParams : public virtual ObjectT
	{
	public:
		friend class Builder;

	private:
		static constexpr NativeString textDocumentKey = "textDocument";
		static constexpr NativeString positionKey = "position";

	public:
		/// The text document.
		TextDocumentIdentifier textDocument;

		/// The position inside the text document.
		Position position;

		//=======================================================================//

		// No writing

		TextDocumentPositionParams(TextDocumentIdentifier textDocument,
								   Position position);

		TextDocumentPositionParams();

		virtual ~TextDocumentPositionParams();
	};

}
