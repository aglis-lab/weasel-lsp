#pragma once

#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	/// Text documents are identified using a URI.
	///
	/// uri: DocumentUri
	///
	struct TextDocumentIdentifier : public ObjectT
	{
	public:
		friend class Builder;

	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		static constexpr NativeString uriKey = "uri";

	public:
		/// The text document's URI.
		DocumentUri uri;

		//=======================================================================//

		TextDocumentIdentifier(DocumentUri uri) : uri(uri){};
		TextDocumentIdentifier(){};

		virtual ~TextDocumentIdentifier(){};
	};

	/// An identifier to denote a specific version of a text document.
	///
	/// version: Number | Null
	///
	struct VersionedTextDocumentIdentifier : public TextDocumentIdentifier
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String versionKey;

	public:
		/// The version number of this document. If a versioned text document identifier
		/// is sent from the server to the client and the file is not open in the editor
		/// (the server has not received an open notification before) the server can send
		/// `null` to indicate that the version is known and the content on disk is the
		/// master (as speced with document content ownership).
		///
		/// The version number of a document will increase after each change, including
		/// undo/redo. The number doesn't need to be consecutive.
		variant<Number, Null> version;

		//=======================================================================//

		VersionedTextDocumentIdentifier(DocumentUri uri, variant<Number, Null> version);

		VersionedTextDocumentIdentifier();

		virtual ~VersionedTextDocumentIdentifier();
	};

}
