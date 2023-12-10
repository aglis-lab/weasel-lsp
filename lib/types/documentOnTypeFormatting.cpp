#include <wlsp/types/documentOnTypeFormatting.hpp>

namespace wlsp
{

	using namespace std;

	const String DocumentOnTypeFormattingClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	DocumentOnTypeFormattingClientCapabilities::
		DocumentOnTypeFormattingClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	DocumentOnTypeFormattingClientCapabilities::
		DocumentOnTypeFormattingClientCapabilities(){};

	DocumentOnTypeFormattingClientCapabilities::
		~DocumentOnTypeFormattingClientCapabilities(){};

	const String DocumentOnTypeFormattingOptions::
		firstTriggerCharacterKey = "firstTriggerCharacter";

	const String DocumentOnTypeFormattingOptions::
		moreTriggerCharacterKey = "moreTriggerCharacter";

	DocumentOnTypeFormattingOptions::
		DocumentOnTypeFormattingOptions(String firstTriggerCharacter,
										optional<vector<String>> moreTriggerCharacter) : firstTriggerCharacter(firstTriggerCharacter),
																						 moreTriggerCharacter(moreTriggerCharacter){};

	DocumentOnTypeFormattingOptions::DocumentOnTypeFormattingOptions(){};
	DocumentOnTypeFormattingOptions::~DocumentOnTypeFormattingOptions(){};

	void DocumentOnTypeFormattingOptions::partialWrite(JsonWriter &writer)
	{
		// firstTriggerCharacter
		writer.Key(firstTriggerCharacterKey),
			writer.String(firstTriggerCharacter);

		// moreTriggerCharacter?
		if (moreTriggerCharacter.has_value())
		{
			writer.Key(moreTriggerCharacterKey);
			writer.StartArray();
			for (auto &i : *moreTriggerCharacter)
			{
				writer.String(i);
			}
			writer.EndArray();
		}
	}

	DocumentOnTypeFormattingRegistrationOptions::
		DocumentOnTypeFormattingRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			String firstTriggerCharacter,
			optional<vector<String>> moreTriggerCharacter) : TextDocumentRegistrationOptions(documentSelector),
															 DocumentOnTypeFormattingOptions(firstTriggerCharacter,
																							 moreTriggerCharacter){};

	DocumentOnTypeFormattingRegistrationOptions::
		DocumentOnTypeFormattingRegistrationOptions(){};

	DocumentOnTypeFormattingRegistrationOptions::
		~DocumentOnTypeFormattingRegistrationOptions(){};

	void DocumentOnTypeFormattingRegistrationOptions::
		partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		DocumentOnTypeFormattingOptions::partialWrite(writer);
	}

	const String DocumentOnTypeFormattingParams::chKey = "ch";
	const String DocumentOnTypeFormattingParams::optionsKey = "options";

	DocumentOnTypeFormattingParams::DocumentOnTypeFormattingParams(
		TextDocumentIdentifier textDocument,
		Position position,
		String ch,
		FormattingOptions options) : TextDocumentPositionParams(textDocument, position),
									 ch(ch),
									 options(options){};

	DocumentOnTypeFormattingParams::DocumentOnTypeFormattingParams(){};
	DocumentOnTypeFormattingParams::~DocumentOnTypeFormattingParams(){};
}
