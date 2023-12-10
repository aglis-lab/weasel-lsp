#include <wlsp/types/codeLens.hpp>

namespace wlsp
{

	using namespace std;

	const String CodeLensClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	CodeLensClientCapabilities::
		CodeLensClientCapabilities(optional<Boolean> dynamicRegistration) : dynamicRegistration(dynamicRegistration){};

	CodeLensClientCapabilities::CodeLensClientCapabilities(){};
	CodeLensClientCapabilities::~CodeLensClientCapabilities(){};

	const String CodeLensOptions::resolveProviderKey = "resolveProvider";

	CodeLensOptions::CodeLensOptions(optional<Boolean> workDoneProgress,
									 optional<Boolean> resolveProvider) : WorkDoneProgressOptions(workDoneProgress),
																		  resolveProvider(resolveProvider){};

	CodeLensOptions::CodeLensOptions(){};
	CodeLensOptions::~CodeLensOptions(){};

	void CodeLensOptions::partialWrite(JsonWriter &writer)
	{
		// Parent
		WorkDoneProgressOptions::partialWrite(writer);

		// resolveProvider?
		if (resolveProvider.has_value())
		{
			writer.Key(resolveProviderKey);
			writer.Bool(*resolveProvider);
		}
	}

	CodeLensRegistrationOptions::CodeLensRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress,
		optional<Boolean> resolveProvider) : TextDocumentRegistrationOptions(documentSelector),
											 CodeLensOptions(workDoneProgress, resolveProvider){};

	CodeLensRegistrationOptions::CodeLensRegistrationOptions(){};
	CodeLensRegistrationOptions::~CodeLensRegistrationOptions(){};

	void CodeLensRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		CodeLensOptions::partialWrite(writer);
	}

	const String CodeLensParams::textDocumentKey = "textDocument";

	CodeLensParams::CodeLensParams(optional<ProgressToken> workDoneToken,
								   optional<ProgressToken> partialResultToken,
								   TextDocumentIdentifier textDocument) : WorkDoneProgressParams(workDoneToken),
																		  PartialResultParams(partialResultToken),
																		  textDocument(textDocument){};

	CodeLensParams::CodeLensParams(){};
	CodeLensParams::~CodeLensParams(){};

	const String CodeLens::rangeKey = "range";
	const String CodeLens::commandKey = "command";
	const String CodeLens::dataKey = "data";

	CodeLens::CodeLens(Range range,
					   optional<Command> command,
					   optional<Any> data) : range(range),
											 command(command),
											 data(data){};

	CodeLens::CodeLens(){};
	CodeLens::~CodeLens(){};

	void CodeLens::partialWrite(JsonWriter &writer)
	{
		// range
		writer.Key(rangeKey);
		writer.Object(range);

		// command?
		if (command.has_value())
		{
			writer.Key(commandKey);
			writer.Object(*command);
		}

		// data?
		if (data.has_value())
		{
			writer.Key(dataKey);
			writer.Any(*data);
		}
	}

}
