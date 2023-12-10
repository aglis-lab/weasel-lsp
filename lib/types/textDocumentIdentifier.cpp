#include <wlsp/types/textDocumentIdentifier.hpp>

namespace wlsp
{

	using namespace std;

	void TextDocumentIdentifier::partialWrite(JsonWriter &writer)
	{
		// uri
		writer.Key(uriKey);
		writer.String(uri);
	}

	const String VersionedTextDocumentIdentifier::versionKey = "version";

	VersionedTextDocumentIdentifier::
		VersionedTextDocumentIdentifier(DocumentUri uri,
										variant<Number, Null> version) : TextDocumentIdentifier(uri),
																		 version(version){};

	VersionedTextDocumentIdentifier::VersionedTextDocumentIdentifier(){};
	VersionedTextDocumentIdentifier::~VersionedTextDocumentIdentifier(){};

	void VersionedTextDocumentIdentifier::partialWrite(JsonWriter &writer)
	{
		// Parent
		TextDocumentIdentifier::partialWrite(writer);

		// version
		writer.Key(versionKey);
		visit(overload(
				  [&writer](Number n)
				  {
					  writer.Number(n);
				  },
				  [&writer](Null)
				  {
					  writer.Null();
				  }),
			  version);
	}

}
