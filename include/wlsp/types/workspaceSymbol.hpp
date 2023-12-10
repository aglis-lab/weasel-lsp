#pragma once

#include <wlsp/types/documentSymbol.hpp>

namespace wlsp
{

using namespace std;

/// WorkspaceSymbol request client capabilities
///
/// dynamicRegistration?: Boolean
///
/// symbolKind?: {
///
/// 	valueSet?: SymbolKind[]
/// }
///
struct WorkspaceSymbolClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;
	const static String symbolKindKey;

public:
	/// Whether declaration supports dynamic registration. If this is set to
	/// `true` the client supports the new `WorkspaceSymbolRegistrationOptions`
	/// return value for the corresponding server capability as well.
	optional<Boolean> dynamicRegistration;

	/// Specific capabilities for the `SymbolKind` in the `workspace/symbol`
	/// request.
	struct SymbolKind: public ObjectT
	{
	private:
		const static String valueSetKey;

		struct ValueSetMaker: public ObjectT
		{
			SymbolKind& parent;


			//===============================================================//


			ValueSetMaker(SymbolKind& parent);

			virtual ~ValueSetMaker();
		};

	public:
		/// The symbol kind values the client supports. When this
		/// property exists the client also guarantees that it will
		/// handle values outside its set gracefully and falls back
		/// to a default value when unknown.
		///
		/// If this property is not present the client only supports
		/// the symbol kinds from `File` to `Array` as defined in
		/// the initial version of the protocol.
		optional<vector<wlsp::SymbolKind>> valueSet;
		// No writing

		SymbolKind(optional<vector<wlsp::SymbolKind>> valueSet);

		SymbolKind();

		virtual ~SymbolKind();
	};

	/// Specific capabilities for the `SymbolKind` in the `workspace/symbol`
	/// request.
	optional<SymbolKind> symbolKind;

	//=======================================================================//

	// No writing

	WorkspaceSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SymbolKind> symbolKind);


	WorkspaceSymbolClientCapabilities();

	virtual ~WorkspaceSymbolClientCapabilities();
};

using WorkspaceSymbolOptions = WorkDoneProgressOptions;// No parsing

using WorkspaceSymbolRegistrationOptions = WorkspaceSymbolOptions;// No parsing

/// The parameters of a Workspace Symbol Request.
///
/// query: String
///
struct WorkspaceSymbolParams:
	public WorkDoneProgressParams,
	public PartialResultParams
{
private:
	const static String queryKey;

public:
	/// A query string to filter symbols by. Clients may send an empty
	/// string here to request all symbols.
	String query;

	//=======================================================================//

	// No writing

	WorkspaceSymbolParams(optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken,
		String query);

	WorkspaceSymbolParams();

	virtual ~WorkspaceSymbolParams();
};

}
