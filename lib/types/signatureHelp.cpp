#include <wlsp/types/signatureHelp.hpp>

namespace wlsp
{

	using namespace std;

	const String SignatureHelpClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String SignatureHelpClientCapabilities::
		signatureInformationKey = "signatureInformation";

	const String SignatureHelpClientCapabilities::
		contextSupportKey = "contextSupport";

	SignatureHelpClientCapabilities::
		SignatureHelpClientCapabilities(optional<Boolean> dynamicRegistration,
										optional<SignatureInformation> signatureInformation,
										optional<Boolean> contextSupport) : dynamicRegistration(dynamicRegistration),
																			signatureInformation(signatureInformation),
																			contextSupport(contextSupport){};

	SignatureHelpClientCapabilities::SignatureHelpClientCapabilities(){};
	SignatureHelpClientCapabilities::~SignatureHelpClientCapabilities(){};

	const String SignatureHelpClientCapabilities::SignatureInformation::
		documentationFormatKey = "documentationFormat";

	const String SignatureHelpClientCapabilities::SignatureInformation::
		parameterInformationKey = "parameterInformation";

	SignatureHelpClientCapabilities::SignatureInformation::
		SignatureInformation(optional<vector<MarkupKind>> documentationFormat,
							 optional<ParameterInformation> parameterInformation) : documentationFormat(documentationFormat),
																					parameterInformation(parameterInformation){};

	SignatureHelpClientCapabilities::SignatureInformation::SignatureInformation(){};
	SignatureHelpClientCapabilities::SignatureInformation::
		~SignatureInformation(){};

	SignatureHelpClientCapabilities::
		SignatureInformation::
			DocumentationFormatMaker::
				DocumentationFormatMaker(vector<MarkupKind> &parentArray) : parentArray(parentArray){};

	SignatureHelpClientCapabilities::
		SignatureInformation::
			DocumentationFormatMaker::
				~DocumentationFormatMaker(){};

	const String SignatureHelpClientCapabilities::
		SignatureInformation::
			ParameterInformation::
				labelOffsetSupportKey = "labelOffsetSupport";

	SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
		ParameterInformation(optional<Boolean> labelOffsetSupport) : labelOffsetSupport(labelOffsetSupport){};

	SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
		ParameterInformation(){};

	SignatureHelpClientCapabilities::SignatureInformation::ParameterInformation::
		~ParameterInformation(){};

	const String SignatureHelpOptions::
		triggerCharactersKey = "triggerCharacters";

	const String SignatureHelpOptions::
		retriggerCharactersKey = "retriggerCharacters";

	SignatureHelpOptions::
		SignatureHelpOptions(optional<Boolean> workDoneProgress,
							 optional<vector<String>> triggerCharacters,
							 optional<vector<String>> retriggerCharacters) : WorkDoneProgressOptions(workDoneProgress),
																			 triggerCharacters(triggerCharacters),
																			 retriggerCharacters(retriggerCharacters){};

	SignatureHelpOptions::SignatureHelpOptions(){};
	SignatureHelpOptions::~SignatureHelpOptions(){};

	void SignatureHelpOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		WorkDoneProgressOptions::partialWrite(writer);

		// triggerCharacters?
		if (triggerCharacters.has_value())
		{
			writer.Key(triggerCharactersKey);
			writer.StartArray();
			for (auto &i : *triggerCharacters)
			{
				writer.String(i);
			}
			writer.EndArray();
		}

		// retriggerCharacters?
		if (retriggerCharacters.has_value())
		{
			writer.Key(retriggerCharactersKey);
			writer.StartArray();
			for (auto &i : *retriggerCharacters)
			{
				writer.String(i);
			}
			writer.EndArray();
		}
	}

	SignatureHelpRegistrationOptions::SignatureHelpRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<vector<String>> triggerCharacters,
		optional<vector<String>> retriggerCharacters) : TextDocumentRegistrationOptions(documentSelector),
														SignatureHelpOptions(workDoneProgress,
																			 triggerCharacters,
																			 retriggerCharacters){};

	SignatureHelpRegistrationOptions::SignatureHelpRegistrationOptions(){};
	SignatureHelpRegistrationOptions::~SignatureHelpRegistrationOptions(){};

	void SignatureHelpRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		SignatureHelpOptions::partialWrite(writer);
	}

	const String ParameterInformation::labelKey = "label";
	const String ParameterInformation::documentationKey = "documentation";

	ParameterInformation::
		ParameterInformation(variant<String, array<Number, 2>> label,
							 optional<variant<String, MarkupContent>> documentation) : label(label),
																					   documentation(documentation){};

	ParameterInformation::ParameterInformation(){};
	ParameterInformation::~ParameterInformation(){};

	void ParameterInformation::partialWrite(JsonWriter &writer)
	{
		// label
		writer.Key(labelKey);
		visit(overload(
				  [&writer](String &str)
				  {
					  writer.String(str);
				  },
				  [&writer](array<Number, 2> &arr)
				  {
					  writer.StartArray();
					  writer.Number(arr[0]);
					  writer.Number(arr[1]);
					  writer.EndArray();
				  }),
			  label);

		// documentation?
		if (documentation.has_value())
		{
			writer.Key(documentationKey);
			visit(overload(
					  [&writer](String &str)
					  {
						  writer.String(str);
					  },
					  [&writer](MarkupContent &obj)
					  {
						  writer.Object(obj);
					  }),
				  *documentation);
		}
	}

	ParameterInformation::LabelMaker::LabelMaker(array<Number, 2> &parentArray) : parentArray(parentArray){};

	ParameterInformation::LabelMaker::
		~LabelMaker(){};

	const String SignatureInformation::labelKey = "label";
	const String SignatureInformation::documentationKey = "documentation";
	const String SignatureInformation::parametersKey = "parameters";

	SignatureInformation::SignatureInformation(String label,
											   optional<variant<String, MarkupContent>> documentation,
											   optional<vector<ParameterInformation>> parameters) : label(label),
																									documentation(documentation),
																									parameters(parameters){};

	SignatureInformation::SignatureInformation(){};
	SignatureInformation::~SignatureInformation(){};

	void SignatureInformation::partialWrite(JsonWriter &writer)
	{
		// label
		writer.Key(labelKey);
		writer.String(label);

		// documentation?
		if (documentation.has_value())
		{
			writer.Key(documentationKey);
			visit(overload(
					  [&writer](String &str)
					  {
						  writer.String(str);
					  },
					  [&writer](MarkupContent &obj)
					  {
						  writer.Object(obj);
					  }),
				  *documentation);
		}

		// parameters?
		if (parameters.has_value())
		{
			writer.Key(parametersKey),
				writer.StartArray();
			for (auto &i : *parameters)
			{
				writer.Object(i);
			}
			writer.EndArray();
		}
	}

	SignatureInformation::ParametersMaker::
		ParametersMaker(vector<ParameterInformation> &parentArray) : parentArray(parentArray){};

	SignatureInformation::ParametersMaker::
		~ParametersMaker(){};

	const String SignatureHelp::signaturesKey = "signatures";
	const String SignatureHelp::activeSignatureKey = "activeSignature";
	const String SignatureHelp::activeParameterKey = "activeParameter";

	SignatureHelp::SignatureHelp(vector<SignatureInformation> signatures,
								 optional<Number> activeSignature,
								 optional<Number> activeParameter) : signatures(signatures),
																	 activeSignature(activeSignature),
																	 activeParameter(activeParameter){};

	SignatureHelp::SignatureHelp(){};
	SignatureHelp::~SignatureHelp(){};

	void SignatureHelp::partialWrite(JsonWriter &writer)
	{
		// signatures
		writer.Key(signaturesKey);
		writer.StartArray();
		for (auto &i : signatures)
		{
			writer.Object(i);
		}
		writer.EndArray();

		// activeSignature?
		if (activeSignature.has_value())
		{
			writer.Key(activeSignatureKey);
			writer.Number(*activeSignature);
		}

		// activeParameter?
		if (activeParameter.has_value())
		{
			writer.Key(activeParameterKey);
			writer.Number(*activeParameter);
		}
	}

	SignatureHelp::SignaturesMaker::
		SignaturesMaker(vector<SignatureInformation> &parentArray) : parentArray(parentArray){};

	SignatureHelp::SignaturesMaker::
		~SignaturesMaker(){};

	const String SignatureHelpContext::
		triggerKindKey = "triggerKind";

	const String SignatureHelpContext::
		triggerCharacterKey = "triggerCharacter";

	const String SignatureHelpContext::
		isRetriggerKey = "isRetrigger";

	const String SignatureHelpContext::
		activeSignatureHelpKey = "activeSignatureHelp";

	SignatureHelpContext::
		SignatureHelpContext(SignatureHelpTriggerKind triggerKind,
							 optional<String> triggerCharacter,
							 Boolean isRetrigger,
							 optional<SignatureHelp> activeSignatureHelp) : triggerKind(triggerKind),
																			triggerCharacter(triggerCharacter),
																			isRetrigger(isRetrigger),
																			activeSignatureHelp(activeSignatureHelp){};

	SignatureHelpContext::SignatureHelpContext(){};
	SignatureHelpContext::~SignatureHelpContext(){};

	const String SignatureHelpParams::contextKey = "context";

	SignatureHelpParams::SignatureHelpParams(TextDocumentIdentifier textDocument,
											 Position position,
											 optional<ProgressToken> workDoneToken,
											 optional<SignatureHelpContext> context) : TextDocumentPositionParams(textDocument, position),
																					   WorkDoneProgressParams(workDoneToken),
																					   context(context){};

	SignatureHelpParams::SignatureHelpParams(){};
	SignatureHelpParams::~SignatureHelpParams(){};
}
