#pragma once

#include <variant>
#include <optional>

#include <wlsp/types/location.hpp>

namespace wlsp
{

	using namespace std;

	/// Represents a related message and source code location for a diagnostic.
	///
	/// location: Location
	///
	/// message: String
	///
	struct DiagnosticRelatedInformation : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String locationKey;
		const static String messageKey;

	public:
		/// The location of this related diagnostic information.
		Location location;

		/// The message of this related diagnostic information.
		String message;

		//=======================================================================//

		DiagnosticRelatedInformation(Location location, String message);

		DiagnosticRelatedInformation();

		virtual ~DiagnosticRelatedInformation();
	};

	enum class DiagnosticSeverity
	{
		/// Reports an error.
		Error = 1,

		/// Reports a warning.
		Warning = 2,

		/// Reports an information.
		Information = 3,

		/// Reports a hint.
		Hint = 4
	};

	enum class DiagnosticTag
	{
		/// Unused or unnecessary code.
		///
		/// Clients are allowed to render diagnostics with this tag faded out
		/// instead of having an error squiggle.
		Unnecessary = 1,

		/// Deprecated or obsolete code.
		///
		/// Clients are allowed to rendered diagnostics with this tag strike through.
		Deprecated = 2
	};

	/// Represents a diagnostic, such as a compiler error or warning.
	///
	/// range: Range
	///
	/// severity?: DiagnosticSeverity
	///
	/// code?: Number | String
	///
	/// source?: String
	///
	/// message: String
	///
	/// tags?: DiagnosticTag[]
	///
	/// relatedInformation?: DiagnosticRelatedInformation[]
	///
	struct Diagnostic : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String rangeKey;
		const static String severityKey;
		const static String codeKey;
		const static String sourceKey;
		const static String messageKey;
		const static String tagsKey;
		const static String relatedInformationKey;

		struct TagsMaker : public ObjectT
		{

			// The object where the array is build
			Diagnostic *parent;

			//===================================================================//
		};

		struct RelatedInformationMaker : public ObjectT
		{

			// The object where the array is build
			Diagnostic *parent;

			//===================================================================//
		};

	public:
		/// The range at which the message applies.
		Range range;

		/// The diagnostic's severity. Can be omitted. If omitted it is up to the
		/// client to interpret diagnostics as error, warning, info or hint.
		optional<DiagnosticSeverity> severity;

		/// The diagnostic's code, which might appear in the user interface.
		optional<variant<Number, String>> code;

		/// A human-readable string describing the source of this
		/// diagnostic, e.g. 'typescript' or 'super lint'.
		optional<String> source;

		/// The diagnostic's message.
		String message;

		/// Additional metadata about the diagnostic.
		///
		/// @since 3.15.0
		optional<vector<DiagnosticTag>> tags;

		/// An array of related diagnostic information, e.g. when symbol-names within
		/// a scope collide all definitions can be marked via this property.
		optional<vector<DiagnosticRelatedInformation>> relatedInformation;

		//=======================================================================//

		Diagnostic(Range range,
				   optional<DiagnosticSeverity> severity,
				   optional<variant<Number, String>> code,
				   optional<String> source,
				   String message,
				   optional<vector<DiagnosticTag>> tags,
				   optional<vector<DiagnosticRelatedInformation>> relatedInformation);

		Diagnostic();

		virtual ~Diagnostic();
	};
}
