#pragma once

#include <optional>

#include <wlsp/types/markupContent.hpp>
#include <wlsp/types/range.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

	using namespace std;

	/// Hover request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	/// contentFormat?: MarkupKind[]
	///
	struct HoverClientCapabilities : public ObjectT
	{
	private:
		static constexpr NativeString dynamicRegistrationKey = "dynamicRegistration";
		static constexpr NativeString contentFormatKey = "contentFormat";

		struct ContentFormatMaker : public ObjectT
		{
			vector<MarkupKind> &parentArray;

			//===================================================================//

			ContentFormatMaker(vector<MarkupKind> &parentArray) : parentArray(parentArray) {}

			virtual ~ContentFormatMaker() {}
		};

	public:
		/// Whether hover supports dynamic registration.
		optional<Boolean> dynamicRegistration;

		/// Client supports the follow content formats for the content
		/// property. The order describes the preferred format of the client.
		optional<vector<MarkupKind>> contentFormat;

		//=======================================================================//

		// No writing

		HoverClientCapabilities(optional<Boolean> dynamicRegistration,
								optional<vector<MarkupKind>> contentFormat);

		HoverClientCapabilities() {}

		virtual ~HoverClientCapabilities() {}
	};

	/// Hover request server capabilities
	using HoverOptions = WorkDoneProgressOptions; // No parsing

	/// Hover request registration options
	struct HoverRegistrationOptions : public TextDocumentRegistrationOptions,
									  public HoverOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		HoverRegistrationOptions(variant<DocumentSelector, Null> documentSelector,
								 optional<Boolean> workDoneProgress);

		HoverRegistrationOptions() {}

		virtual ~HoverRegistrationOptions() {}
	};

	/// textDocument/hover parameters
	struct HoverParams : public TextDocumentPositionParams,
						 public WorkDoneProgressParams
	{

		//=======================================================================//

		// No writing

		HoverParams(TextDocumentIdentifier textDocument,
					Position position,
					optional<ProgressToken> workDoneToken);

		HoverParams() {}

		virtual ~HoverParams() {}
	};

	/// The result of a hover request.
	///
	/// contents: MarkedString | MarkedString[] | MarkupContent
	///
	/// range?: Range
	///
	struct Hover : public ObjectT
	{
	public:
		friend class Builder;

	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		static constexpr NativeString contentsKey = "contents";
		static constexpr NativeString rangeKey = "range";

	public:
		/// The hover's content
		MarkupContent contents;

		/// An optional range is a range inside a text document
		/// that is used to visualize a hover, e.g. by changing the background color.
		optional<Range> range;

		// No parsing
		Hover() {}
		Hover(MarkupContent contents) : contents(contents) {}
		Hover(MarkupContent contents, optional<Range> range) : contents(contents), range(range) {}

		virtual ~Hover() {}
	};
}
