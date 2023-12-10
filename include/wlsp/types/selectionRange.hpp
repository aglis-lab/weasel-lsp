#pragma once

#include <wlsp/types/partialResult.hpp>
#include <wlsp/types/range.hpp>
#include <wlsp/types/staticRegistration.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

	using namespace std;

	/// SelectionRange request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	struct SelectionRangeClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;

	public:
		/// Whether declaration supports dynamic registration. If this is set to
		/// `true` the client supports the new `SelectionRangeRegistrationOptions`
		/// return value for the corresponding server capability as well.
		optional<Boolean> dynamicRegistration;

		//=======================================================================//

		SelectionRangeClientCapabilities(optional<Boolean> dynamicRegistration);

		SelectionRangeClientCapabilities();

		virtual ~SelectionRangeClientCapabilities();
	};

	using SelectionRangeOptions = WorkDoneProgressOptions; // No parsing

	struct SelectionRangeRegistrationOptions : public SelectionRangeOptions,
											   public TextDocumentRegistrationOptions,
											   public StaticRegistrationOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		SelectionRangeRegistrationOptions(optional<Boolean> workDoneProgress,
										  variant<DocumentSelector, Null> documentSelector,
										  optional<String> id);

		SelectionRangeRegistrationOptions();

		virtual ~SelectionRangeRegistrationOptions();
	};

	/// SelectionRange request parameters
	///
	/// textDocument: TextDocumentIdentifier
	///
	/// positions: Position[]
	///
	struct SelectionRangeParams : public WorkDoneProgressParams,
								  public PartialResultParams
	{
	private:
		const static String textDocumentKey;
		const static String positionsKey;

		struct PositionsMaker : public ObjectT
		{
			vector<Position> &parentArray;

			//===================================================================//

			PositionsMaker(vector<Position> &parentArray);

			virtual ~PositionsMaker();
		};

	public:
		/// The text document.
		TextDocumentIdentifier textDocument;

		/// The positions inside the text document.
		vector<Position> positions;

		//=======================================================================//

		// No writing

		SelectionRangeParams(optional<ProgressToken> workDoneToken,
							 optional<ProgressToken> partialResultToken,
							 TextDocumentIdentifier textDocument,
							 vector<Position> positions);

		SelectionRangeParams();

		virtual ~SelectionRangeParams();
	};

	/// Part of the selection range response result
	///
	/// range: Range
	///
	/// parent?: SelectionRange
	///
	struct SelectionRange : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String rangeKey;
		const static String parentKey;

	public:
		/// The range of this selection range.
		Range range;

		/// The parent selection range containing this range.
		/// Therefore `parent.range` must contain `this.range`.
		optional<shared_ptr<SelectionRange>> parent;

		// No parsing
		SelectionRange(Range range,
					   optional<shared_ptr<SelectionRange>> parent);

		SelectionRange(Range range, SelectionRange parent);

		SelectionRange();

		virtual ~SelectionRange();
	};

}
