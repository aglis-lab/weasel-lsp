#include <iostream>

#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Appenders/ColorConsoleAppender.h>

#include <wlsp/types.hpp>
#include <wlsp/wlsp.hpp>
#include <wlsp/version.h>

class Server : public wlsp::IOServer
{
protected:
	std::optional<wlsp::InitializeResult> onInitialize(std::optional<wlsp::InitializeParams> &params)
	{
		wlsp::InitializeResult result;

		// Document Sync
		// result.capabilities.textDocumentSync = wlsp::TextDocumentSyncKind::Full;

		// Hover
		result.capabilities.hoverProvider = true;

		// documentFormattingProvider
		// result.capabilities.documentFormattingProvider = true;

		// Completion Provider
		auto completionOptions = wlsp::CompletionOptions();
		completionOptions.triggerCharacters = {"."};
		result.capabilities.completionProvider = completionOptions;

		// Client Info
		result.serverInfo = wlsp::InitializeResult::ServerInfo(SERVER_NAME, SERVER_VERSION);

		return result;
	}

	virtual std::optional<wlsp::Hover> onHover(std::optional<wlsp::HoverParams> &)
	{
		return wlsp::Hover(wlsp::MarkupContent(wlsp::MarkupKind::Markdown, "```json	\
			{	\
				\"firstName\": \"John\", \
				\"lastName\": \"Smith\", \
				\"age\": 25	\
			}	\
		```"));
	}
};

// none = 0,
// fatal = 1,
// error = 2,
// warning = 3,
// info = 4,
// debug = 5,
// verbose = 6
int main()
{
	// plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	// plog::init(plog::verbose, &consoleAppender);

	plog::init(plog::verbose, "/Users/zaen/Projects/Projects/weasel-lang/weasel-lsp/temp/plog.log");

	Server().run();
}
