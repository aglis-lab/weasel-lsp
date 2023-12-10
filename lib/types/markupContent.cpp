#include <wlsp/types/markupContent.hpp>

namespace wlsp
{

	using namespace std;

	const MarkupKind MarkupKind::PlainText = _MarkupKind::PlainText;
	const MarkupKind MarkupKind::Markdown = _MarkupKind::Markdown;

	MarkupKind::MarkupKind(String kind)
	{
		this->kind = _MarkupKind::PlainText;
		if (kind == MARKDOWN)
		{
			this->kind = _MarkupKind::Markdown;
		}
	}

	void MarkupContent::partialWrite(JsonWriter &writer)
	{
		// kind
		writer.Key(kindKey);
		writer.String(kind);

		// value
		writer.Key(valueKey);
		writer.String(value);
	}
}
