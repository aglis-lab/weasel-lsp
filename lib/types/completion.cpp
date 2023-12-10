#include <wlsp/types/completion.hpp>
#include <wlsp/types/genericObject.hpp>

namespace wlsp
{

	using namespace std;

	const String CompletionOptions::triggerCharactersKey = "triggerCharacters";
	const String CompletionOptions::allCommitCharactersKey = "allCommitCharacters";
	const String CompletionOptions::resolveProviderKey = "resolveProvider";

	CompletionOptions::CompletionOptions(optional<Boolean> workDoneProgress,
										 optional<vector<String>> triggerCharacters,
										 optional<vector<String>> allCommitCharacters,
										 optional<Boolean> resolveProvider) : WorkDoneProgressOptions(workDoneProgress),
																			  triggerCharacters(triggerCharacters),
																			  allCommitCharacters(allCommitCharacters),
																			  resolveProvider(resolveProvider){};

	CompletionOptions::CompletionOptions(){};
	CompletionOptions::~CompletionOptions(){};

	void CompletionOptions::partialWrite(JsonWriter &writer)
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

		// allCommitCharacters?
		if (allCommitCharacters.has_value())
		{
			writer.Key(allCommitCharactersKey);
			writer.StartArray();
			for (auto &i : *allCommitCharacters)
			{
				writer.String(i);
			}
			writer.EndArray();
		}

		// resolveProvider?
		if (resolveProvider.has_value())
		{
			writer.Key(resolveProviderKey);
			writer.Bool(*resolveProvider);
		}
	}

	CompletionRegistrationOptions::
		CompletionRegistrationOptions(
			variant<DocumentSelector, Null> documentSelector,
			optional<Boolean> workDoneProgress,
			optional<vector<String>> triggerCharacters,
			optional<vector<String>> allCommitCharacters,
			optional<Boolean> resolveProvider) : TextDocumentRegistrationOptions(documentSelector),
												 CompletionOptions(workDoneProgress,
																   triggerCharacters,
																   allCommitCharacters,
																   resolveProvider){};

	CompletionRegistrationOptions::CompletionRegistrationOptions(){};
	CompletionRegistrationOptions::~CompletionRegistrationOptions(){};

	void CompletionRegistrationOptions::partialWrite(JsonWriter &writer)
	{
		// Parents
		TextDocumentRegistrationOptions::partialWrite(writer);
		CompletionOptions::partialWrite(writer);
	}

	const String CompletionContext::triggerKindKey = "triggerKind";
	const String CompletionContext::triggerCharacterKey = "triggerCharacter";

	CompletionContext::CompletionContext(CompletionTriggerKind triggerKind,
										 optional<String> triggerCharacter) : triggerKind(triggerKind),
																			  triggerCharacter(triggerCharacter){};

	CompletionContext::CompletionContext(){};
	CompletionContext::~CompletionContext(){};

	const String CompletionParams::contextKey = "context";

	CompletionParams::CompletionParams(TextDocumentIdentifier textDocument,
									   Position position,
									   optional<ProgressToken> workDoneToken,
									   optional<ProgressToken> partialResultToken,
									   optional<CompletionContext> context) : TextDocumentPositionParams(textDocument, position),
																			  WorkDoneProgressParams(workDoneToken),
																			  PartialResultParams(partialResultToken),
																			  context(context){};

	CompletionParams::CompletionParams(){};
	CompletionParams::~CompletionParams(){};

	const String CompletionItem::labelKey = "label";
	const String CompletionItem::kindKey = "kind";
	const String CompletionItem::tagsKey = "tags";
	const String CompletionItem::detailKey = "detail";
	const String CompletionItem::documentationKey = "documentation";
	const String CompletionItem::deprecatedKey = "deprecated";
	const String CompletionItem::preselectKey = "preselect";
	const String CompletionItem::sortTextKey = "sortText";
	const String CompletionItem::filterTextKey = "filterText";
	const String CompletionItem::insertTextKey = "insertText";
	const String CompletionItem::insertTextFormatKey = "insertTextFormat";
	const String CompletionItem::textEditKey = "textEdit";
	const String CompletionItem::additionalTextEditsKey = "additionalTextEdits";
	const String CompletionItem::commitCharactersKey = "commitCharacters";
	const String CompletionItem::commandKey = "command";
	const String CompletionItem::dataKey = "data";

	CompletionItem::CompletionItem(String label,
								   optional<CompletionItemKind> kind,
								   optional<vector<CompletionItemTag>> tags,
								   optional<String> detail,
								   optional<variant<String, MarkupContent>> documentation,
								   optional<Boolean> preselect,
								   optional<String> sortText,
								   optional<String> filterText,
								   optional<String> insertText,
								   optional<InsertTextFormat> insertTextFormat,
								   optional<TextEdit> textEdit,
								   optional<vector<TextEdit>> additionalTextEdits,
								   optional<vector<String>> commitCharacters,
								   optional<Command> command,
								   optional<Any> data) : label(label),
														 kind(kind),
														 tags(tags),
														 detail(detail),
														 documentation(documentation),
														 preselect(preselect),
														 sortText(sortText),
														 filterText(filterText),
														 insertText(insertText),
														 insertTextFormat(insertTextFormat),
														 textEdit(textEdit),
														 additionalTextEdits(additionalTextEdits),
														 commitCharacters(commitCharacters),
														 command(command),
														 data(data){};

	CompletionItem::CompletionItem(){};
	CompletionItem::~CompletionItem(){};

	void CompletionItem::partialWrite(JsonWriter &writer)
	{
		// label
		writer.Key(labelKey);
		writer.String(label);

		// kind?
		if (kind.has_value())
		{
			writer.Key(kindKey);
			writer.Int((int)(*kind));
		}

		// tags?
		if (tags.has_value())
		{
			writer.Key(tagsKey);
			writer.StartArray();
			for (auto i : *tags)
			{
				writer.Int((int)i);
			}
			writer.EndArray();
		}

		// detail?
		if (detail.has_value())
		{
			writer.Key(detailKey);
			writer.String(*detail);
		}

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

		// preselect?
		if (preselect.has_value())
		{
			writer.Key(preselectKey);
			writer.Bool(*preselect);
		}

		// sortText?
		if (sortText.has_value())
		{
			writer.Key(sortTextKey);
			writer.String(*sortText);
		}

		// filterText?
		if (filterText.has_value())
		{
			writer.Key(filterTextKey);
			writer.String(*filterText);
		}

		// insertText?
		if (insertText.has_value())
		{
			writer.Key(insertTextKey);
			writer.String(*insertText);
		}

		// insertTextFormat?
		if (insertTextFormat.has_value())
		{
			writer.Key(insertTextFormatKey);
			writer.Int((int)(*insertTextFormat));
		}

		// textEdit?
		if (textEdit.has_value())
		{
			writer.Key(textEditKey);
			writer.Object(*textEdit);
		}

		// additionalTextEdits?
		if (additionalTextEdits.has_value())
		{
			writer.Key(additionalTextEditsKey);
			writer.StartArray();
			for (auto i : *additionalTextEdits)
			{
				writer.Object(i);
			}
			writer.EndArray();
		}

		// commitCharacters?
		if (commitCharacters.has_value())
		{
			writer.Key(commitCharactersKey);
			writer.StartArray();
			for (auto i : *commitCharacters)
			{
				writer.String(i);
			}
			writer.EndArray();
		}

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

	CompletionItem::TagsMaker::TagsMaker(vector<CompletionItemTag> &parentArray) : parentArray(parentArray){};

	CompletionItem::TagsMaker::~TagsMaker(){};

	CompletionItem::CommitCharactersMaker::CommitCharactersMaker(vector<String> &parentArray) : parentArray(parentArray){};

	CompletionItem::CommitCharactersMaker::~CommitCharactersMaker(){};

	const String CompletionList::isIncompleteKey = "isIncomplete";
	const String CompletionList::itemsKey = "items";

	CompletionList::CompletionList(Boolean isIncomplete,
								   vector<CompletionItem> items) : isIncomplete(isIncomplete),
																   items(items){};

	CompletionList::CompletionList(){};
	CompletionList::~CompletionList(){};

	void CompletionList::partialWrite(JsonWriter &writer)
	{
		// isIncomplete
		writer.Key(isIncompleteKey);
		writer.Bool(isIncomplete);

		// items
		writer.Key(itemsKey);
		writer.StartArray();
		for (auto &i : items)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}

	const String CompletionClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String CompletionClientCapabilities::
		completionItemKey = "completionItem";

	const String CompletionClientCapabilities::
		completionItemKindKey = "completionItemKind";

	const String CompletionClientCapabilities::
		contextSupportKey = "contextSupport";

	CompletionClientCapabilities::
		CompletionClientCapabilities(optional<Boolean> dynamicRegistration,
									 optional<CompletionItem> completionItem,
									 optional<CompletionItemKind> completionItemKind,
									 optional<Boolean> contextSupport) : dynamicRegistration(dynamicRegistration),
																		 completionItem(completionItem),
																		 completionItemKind(completionItemKind),
																		 contextSupport(contextSupport){};

	CompletionClientCapabilities::CompletionClientCapabilities(){};
	CompletionClientCapabilities::~CompletionClientCapabilities(){};

	const String CompletionClientCapabilities::CompletionItem::
		snippetSupportKey = "snippetSupport";

	const String CompletionClientCapabilities::CompletionItem::
		commitCharactersSupportKey = "commitCharactersSupport";

	const String CompletionClientCapabilities::CompletionItem::
		documentationFormatKey = "documentationFormat";

	const String CompletionClientCapabilities::CompletionItem::
		deprecatedSupportKey = "deprecatedSupport";

	const String CompletionClientCapabilities::CompletionItem::
		preselectSupportKey = "preselectSupport";

	const String CompletionClientCapabilities::CompletionItem::
		tagSupportKey = "tagSupport";

	CompletionClientCapabilities::CompletionItem::
		CompletionItem(optional<Boolean> snippetSupport,
					   optional<Boolean> commitCharactersSupport,
					   optional<vector<MarkupKind>> documentationFormat,
					   optional<Boolean> deprecatedSupport,
					   optional<Boolean> preselectSupport,
					   optional<TagSupport> tagSupport) : snippetSupport(snippetSupport),
														  commitCharactersSupport(commitCharactersSupport),
														  documentationFormat(documentationFormat),
														  deprecatedSupport(deprecatedSupport),
														  preselectSupport(preselectSupport),
														  tagSupport(tagSupport){};

	CompletionClientCapabilities::CompletionItem::CompletionItem(){};
	CompletionClientCapabilities::CompletionItem::~CompletionItem(){};

	CompletionClientCapabilities::CompletionItem::DocumentationFormatMaker::
		DocumentationFormatMaker(vector<MarkupKind> &parentArray) : parentArray(parentArray){};

	CompletionClientCapabilities::CompletionItem::DocumentationFormatMaker::
		~DocumentationFormatMaker(){};

	const string CompletionClientCapabilities::CompletionItem::TagSupport::
		valueSetKey = "valueSet";

	CompletionClientCapabilities::CompletionItem::TagSupport::
		TagSupport(vector<CompletionItemTag> valueSet) : valueSet(valueSet){};

	CompletionClientCapabilities::CompletionItem::TagSupport::TagSupport(){};
	CompletionClientCapabilities::CompletionItem::TagSupport::~TagSupport(){};

	CompletionClientCapabilities::CompletionItem::TagSupport::ValueSetMaker::
		ValueSetMaker(vector<CompletionItemTag> &parentArray) : parentArray(parentArray){};

	CompletionClientCapabilities::CompletionItem::TagSupport::ValueSetMaker::
		~ValueSetMaker(){};

	const String CompletionClientCapabilities::CompletionItemKind::
		valueSetKey = "valueSet";

	CompletionClientCapabilities::CompletionItemKind::
		CompletionItemKind(optional<vector<wlsp::CompletionItemKind>> valueSet) : valueSet(valueSet){};

	CompletionClientCapabilities::CompletionItemKind::CompletionItemKind(){};
	CompletionClientCapabilities::CompletionItemKind::~CompletionItemKind(){};

	CompletionClientCapabilities::CompletionItemKind::ValueSetMaker::
		ValueSetMaker(vector<wlsp::CompletionItemKind> &parentArray) : parentArray(parentArray){};

	CompletionClientCapabilities::CompletionItemKind::ValueSetMaker::
		~ValueSetMaker(){};
}
