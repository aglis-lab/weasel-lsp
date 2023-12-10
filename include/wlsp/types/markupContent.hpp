#pragma once

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

#define MARKDOWN "markdown"
#define PLAINTEXT "plaintext"

namespace wlsp
{
	/// Describes the content type that a client supports in various
	/// result literals like `Hover`, `ParameterInfo` or `CompletionItem`.
	class MarkupKind
	{
	public:
		enum class _MarkupKind
		{
			PlainText,
			Markdown
		};

	private:
		_MarkupKind kind;

		MarkupKind(_MarkupKind kind) : kind(kind){};

	public:
		/// Plain text is supported as a content format
		const static MarkupKind PlainText;

		/// Markdown is supported as a content format
		const static MarkupKind Markdown;

		MarkupKind() : kind(_MarkupKind::PlainText){};

		MarkupKind(String kind);

		virtual ~MarkupKind() {}

		operator String()
		{
			if (kind == _MarkupKind::Markdown)
			{
				return MARKDOWN;
			}

			return PLAINTEXT;
		}

		bool operator<(MarkupKind &other)
		{
			return this->kind < other.kind;
		}
	};

	/// A `MarkupContent` literal represents a string value which content is
	/// interpreted base on its kind flag. Currently the protocol supports
	/// `plaintext` and `markdown` as markup kinds.
	///
	/// If the kind is `markdown` then the value can contain fenced code blocks
	/// like in GitHub issues. See
	/// https://help.github.com/articles/creating-and-highlighting-code-blocks/#syntax-highlighting
	///
	/// kind: MarkupKind
	///
	/// value: String
	///
	struct MarkupContent : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		static constexpr NativeString kindKey = "kind";
		static constexpr NativeString valueKey = "value";

	public:
		/// The type of the Markup
		MarkupKind kind;

		/// The content itself
		String value;

		//=======================================================================//

		MarkupContent(MarkupKind kind, String value) : kind(kind), value(value) {}

		MarkupContent() {}

		virtual ~MarkupContent() {}
	};
}
