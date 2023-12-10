#include <wlsp/types/diagnostic.hpp>

namespace wlsp
{

	using namespace std;

	const String Diagnostic::rangeKey = "range";
	const String Diagnostic::severityKey = "severity";
	const String Diagnostic::codeKey = "code";
	const String Diagnostic::sourceKey = "source";
	const String Diagnostic::messageKey = "message";
	const String Diagnostic::tagsKey = "tags";
	const String Diagnostic::relatedInformationKey = "relatedInformation";

	Diagnostic::Diagnostic(Range range,
						   optional<DiagnosticSeverity> severity,
						   optional<variant<Number, String>> code,
						   optional<String> source,
						   String message,
						   optional<vector<DiagnosticTag>> tags,
						   optional<vector<DiagnosticRelatedInformation>> relatedInformation) : range(range),
																								severity(severity),
																								code(code),
																								source(source),
																								message(message),
																								tags(tags),
																								relatedInformation(relatedInformation){};

	Diagnostic::Diagnostic(){};
	Diagnostic::~Diagnostic(){};

	void Diagnostic::partialWrite(JsonWriter &writer)
	{
		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// severity?
		if (severity.has_value())
		{
			writer.Key(severityKey);
			writer.Int((int)(*severity));
		}

		// code?
		if (code.has_value())
		{
			writer.Key(codeKey);
			visit(
				overload(
					[&writer](Number n)
					{
						writer.Number(n);
					},
					[&writer](String &str)
					{
						writer.String(str.c_str());
					}),
				*code);
		}

		// source?
		if (source.has_value())
		{
			writer.Key(sourceKey);
			writer.String(*source);
		}

		// message
		writer.Key(messageKey);
		writer.String(message);

		// tags?
		if (tags.has_value())
		{
			writer.Key(tagsKey);
			writer.StartArray();
			for (auto &i : *tags)
			{
				writer.Int((int)i);
			}
			writer.EndArray();
		}

		// relatedInformation?
		if (relatedInformation.has_value())
		{
			writer.Key(relatedInformationKey);
			writer.StartArray();
			for (auto &i : *relatedInformation)
			{
				writer.Object(i);
			}
			writer.EndArray();
		}
	}

	const String DiagnosticRelatedInformation::locationKey = "location";
	const String DiagnosticRelatedInformation::messageKey = "message";

	DiagnosticRelatedInformation::DiagnosticRelatedInformation(Location location,
															   String message) : location(location),
																				 message(message){};

	DiagnosticRelatedInformation::DiagnosticRelatedInformation(){};
	DiagnosticRelatedInformation::~DiagnosticRelatedInformation(){};

	void DiagnosticRelatedInformation::partialWrite(JsonWriter &writer)
	{
		// location
		writer.Key(locationKey);
		writer.Object(location);

		// message
		writer.Key(messageKey);
		writer.String(message);
	}

}
