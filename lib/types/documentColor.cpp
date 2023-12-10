#include <wlsp/types/documentColor.hpp>

namespace wlsp
{

	using namespace std;

	const String DocumentColorClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	DocumentColorClientCapabilities::
		DocumentColorClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	DocumentColorClientCapabilities::DocumentColorClientCapabilities(){};
	DocumentColorClientCapabilities::~DocumentColorClientCapabilities(){};

	DocumentColorRegistrationOptions::DocumentColorRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<String> id,
		optional<Boolean> workDoneProgress) : TextDocumentRegistrationOptions(documentSelector),
											  StaticRegistrationOptions(id),
											  DocumentColorOptions(workDoneProgress){};

	DocumentColorRegistrationOptions::DocumentColorRegistrationOptions(){};
	DocumentColorRegistrationOptions::~DocumentColorRegistrationOptions(){};

	void DocumentColorRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		StaticRegistrationOptions::partialWrite(writer);
		DocumentColorOptions::partialWrite(writer);
	}

	const String DocumentColorParams::textDocumentKey = "textDocument";

	DocumentColorParams::DocumentColorParams(optional<ProgressToken> workDoneToken,
											 optional<ProgressToken> partialResultToken,
											 TextDocumentIdentifier textDocument) : WorkDoneProgressParams(workDoneToken),
																					PartialResultParams(partialResultToken),
																					textDocument(textDocument){};

	DocumentColorParams::DocumentColorParams(){};
	DocumentColorParams::~DocumentColorParams(){};

	const String Color::redKey = "red";
	const String Color::greenKey = "green";
	const String Color::blueKey = "blue";
	const String Color::alphaKey = "alpha";

	Color::Color(Number red, Number green, Number blue, Number alpha) : red(red),
																		green(green),
																		blue(blue),
																		alpha(alpha){};

	Color::Color(){};
	Color::~Color(){};

	void Color::partialWrite(JsonWriter &writer)
	{
		// red
		writer.Key(redKey);
		writer.Number(red);

		// green
		writer.Key(greenKey);
		writer.Number(green);

		// blue
		writer.Key(blueKey);
		writer.Number(blue);

		// alpha
		writer.Key(alphaKey);
		writer.Number(alpha);
	}

	const String ColorInformation::rangeKey = "range";
	const String ColorInformation::colorKey = "color";

	ColorInformation::ColorInformation(Range range, Color color) : range(range),
																   color(color){};

	ColorInformation::ColorInformation(){};
	ColorInformation::~ColorInformation(){};

	void ColorInformation::partialWrite(JsonWriter &writer)
	{
		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// color
		writer.Key(colorKey);
		writer.Object(color);
	}

}
