#include <wlsp/types/workspaceSymbol.hpp>

namespace wlsp
{

	using namespace std;

	const String WorkspaceSymbolClientCapabilities::
		dynamicRegistrationKey = "dynamicRegistration";

	const String WorkspaceSymbolClientCapabilities::
		symbolKindKey = "symbolKind";

	WorkspaceSymbolClientCapabilities::
		WorkspaceSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
										  optional<SymbolKind> symbolKind) : dynamicRegistration(dynamicRegistration),
																			 symbolKind(symbolKind){};

	WorkspaceSymbolClientCapabilities::WorkspaceSymbolClientCapabilities(){};
	WorkspaceSymbolClientCapabilities::~WorkspaceSymbolClientCapabilities(){};

	const String WorkspaceSymbolClientCapabilities::SymbolKind::
		valueSetKey = "valueSet";

	WorkspaceSymbolClientCapabilities::SymbolKind::
		SymbolKind(optional<vector<wlsp::SymbolKind>> valueSet) : valueSet(valueSet){};

	WorkspaceSymbolClientCapabilities::SymbolKind::SymbolKind(){};
	WorkspaceSymbolClientCapabilities::SymbolKind::~SymbolKind(){};

	WorkspaceSymbolClientCapabilities::SymbolKind::ValueSetMaker::
		ValueSetMaker(SymbolKind &parent) : parent(parent){};

	WorkspaceSymbolClientCapabilities::SymbolKind::ValueSetMaker::
		~ValueSetMaker(){};

	const String WorkspaceSymbolParams::queryKey = "query";

	WorkspaceSymbolParams::WorkspaceSymbolParams(
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		String query) : WorkDoneProgressParams(workDoneToken),
						PartialResultParams(partialResultToken),
						query(query){};

	WorkspaceSymbolParams::WorkspaceSymbolParams(){};
	WorkspaceSymbolParams::~WorkspaceSymbolParams(){};
}
