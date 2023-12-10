#pragma once

// #include <boost/bimap.hpp>
// #include <boost/assign.hpp>

#include <wlsp/types/objectT.hpp>
#include <wlsp/types/partialResult.hpp>
#include <wlsp/types/staticRegistration.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

	using namespace std;

	/// Folding range request client capabilities
	///
	/// dynamicRegistration?: Boolean
	///
	/// rangeLimit?: Number
	///
	/// lineFoldingOnly?: Boolean
	///
	struct FoldingRangeClientCapabilities : public ObjectT
	{
	private:
		const static String dynamicRegistrationKey;
		const static String rangeLimitKey;
		const static String lineFoldingOnlyKey;

	public:
		/// Whether implementation supports dynamic registration. If this is set to
		/// `true` the client supports the new `FoldingRangeRegistrationOptions`
		/// return value for the corresponding server capability as well.
		optional<Boolean> dynamicRegistration;

		/// The maximum number of folding ranges that the client prefers to receive
		/// per document. The value serves as a hint, servers are free to follow
		/// the limit.
		optional<Number> rangeLimit;

		/// If set, the client signals that it only supports folding complete lines.
		/// If set, client will ignore specified `startCharacter` and `endCharacter`
		/// properties in a FoldingRange.
		optional<Boolean> lineFoldingOnly;

		//=======================================================================//

		// No writing

		FoldingRangeClientCapabilities(optional<Boolean> dynamicRegistration,
									   optional<Number> rangeLimit,
									   optional<Boolean> lineFoldingOnly);

		FoldingRangeClientCapabilities();

		virtual ~FoldingRangeClientCapabilities();
	};

	using FoldingRangeOptions = WorkDoneProgressOptions; // No parsing

	struct FoldingRangeRegistrationOptions : public TextDocumentRegistrationOptions,
											 public FoldingRangeOptions,
											 public StaticRegistrationOptions
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		// No parsing

		FoldingRangeRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress,
			optional<String> id);

		FoldingRangeRegistrationOptions();

		virtual ~FoldingRangeRegistrationOptions();
	};

	/// Folding range request parameters
	///
	/// textDocument: TextDocumentIdentifier
	///
	struct FoldingRangeParams : public WorkDoneProgressParams,
								public PartialResultParams
	{
	private:
		const static String textDocumentKey;

	public:
		/// The text document.
		TextDocumentIdentifier textDocument;

		//=======================================================================//

		// No writing

		FoldingRangeParams(optional<ProgressToken> workDoneToken,
						   optional<ProgressToken> partialResultToken,
						   TextDocumentIdentifier textDocument);

		FoldingRangeParams();

		virtual ~FoldingRangeParams();
	};

	/// Known range kinds
	struct FoldingRangeKind
	{

		String kind;

		/// Folding range for a comment
		const static FoldingRangeKind Comment;

		/// Folding range for a imports or includes
		const static FoldingRangeKind Imports;

		/// Folding range for a region (e.g. `#region`)
		const static FoldingRangeKind Region;

		FoldingRangeKind(String kind);

		virtual ~FoldingRangeKind();

		operator String()
		{
			return kind;
		}

		bool operator<(FoldingRangeKind &other)
		{
			return this->kind < other.kind;
		}
	};

	/// Represents a folding range.
	///
	/// startLine: Number
	///
	/// startCharacter?: Number
	///
	/// endLine: Number
	///
	/// endCharacter?: Number
	///
	/// kind?: String
	///
	struct FoldingRange : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String startLineKey;
		const static String startCharacterKey;
		const static String endLineKey;
		const static String endCharacterKey;
		const static String kindKey;

	public:
		/// The zero-based line number from where the folded range starts.
		Number startLine;

		/// The zero-based character offset from where the folded range starts.
		/// If not defined, defaults to the length of the start line.
		optional<Number> startCharacter;

		/// The zero-based line number where the folded range ends.
		Number endLine;

		/// The zero-based character offset before the folded range ends.
		/// If not defined, defaults to the length of the end line.
		optional<Number> endCharacter;

		/// Describes the kind of the folding range such as `comment` or `region`.
		/// The kind is used to categorize folding ranges and used by commands like
		/// 'Fold all comments'. See FoldingRangeKind for an enumeration of
		/// standardized kinds.
		optional<FoldingRangeKind> kind;

		// No parsing

		FoldingRange(Number startLine,
					 optional<Number> startCharacter,
					 Number endLine,
					 optional<Number> endCharacter,
					 optional<FoldingRangeKind> kind);

		FoldingRange();

		virtual ~FoldingRange();
	};

}
