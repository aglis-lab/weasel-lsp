#pragma once

#include <wlsp/types/workspaceEdit.hpp>

namespace wlsp
{

	using namespace std;

	/// workspace/applyEdit params
	///
	/// label?: String
	///
	/// edit: WorkspaceEdit
	///
	struct ApplyWorkspaceEditParams : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String labelKey;
		const static String editKey;

	public:
		/// An optional label of the workspace edit. This label is
		/// presented in the user interface for example on an undo
		/// stack to undo the workspace edit.
		optional<String> label;

		/// The edits to apply.
		WorkspaceEdit edit;

		// No parsing

		ApplyWorkspaceEditParams(optional<String> label, WorkspaceEdit edit);

		ApplyWorkspaceEditParams();

		virtual ~ApplyWorkspaceEditParams();
	};

	/// workspace/applyEdit response
	///
	/// applied: Boolean
	///
	/// failureReason?: String
	///
	struct ApplyWorkspaceEditResponse : public ObjectT
	{
	private:
		const static String appliedKey;
		const static String failureReasonKey;

	public:
		/// Indicates whether the edit was applied or not.
		Boolean applied;

		/// An optional textual description for why the edit was not applied.
		/// This may be used may be used by the server for diagnostic
		/// logging or to provide a suitable error for a request that
		/// triggered the edit.
		optional<String> failureReason;

		//====================   Parsing   ======================================//

		// Using default isValid()

		//=======================================================================//

		// No writing

		ApplyWorkspaceEditResponse(Boolean applied, optional<String> failureReason);

		ApplyWorkspaceEditResponse();

		virtual ~ApplyWorkspaceEditResponse();
	};
}
