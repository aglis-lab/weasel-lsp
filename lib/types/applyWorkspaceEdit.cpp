#include <wlsp/types/applyWorkspaceEdit.hpp>

namespace wlsp
{
	using namespace std;

	const String ApplyWorkspaceEditParams::labelKey = "label";
	const String ApplyWorkspaceEditParams::editKey = "edit";

	ApplyWorkspaceEditParams::ApplyWorkspaceEditParams(optional<String> label, WorkspaceEdit edit)
	{
		this->label = label;
		this->edit = edit;
	}
	ApplyWorkspaceEditParams::ApplyWorkspaceEditParams(){};
	ApplyWorkspaceEditParams::~ApplyWorkspaceEditParams(){};

	void ApplyWorkspaceEditParams::partialWrite(JsonWriter &writer)
	{
		// label?
		if (label.has_value())
		{
			writer.Key(labelKey);
			writer.String(*label);
		}

		// edit
		writer.Key(editKey);
		writer.Object(edit);
	}

	const String ApplyWorkspaceEditResponse::appliedKey = "applied";
	const String ApplyWorkspaceEditResponse::failureReasonKey = "failureReason";

	ApplyWorkspaceEditResponse::ApplyWorkspaceEditResponse(Boolean applied, optional<String> failureReason) : applied(applied), failureReason(failureReason){};
	ApplyWorkspaceEditResponse::ApplyWorkspaceEditResponse(){};
	ApplyWorkspaceEditResponse::~ApplyWorkspaceEditResponse(){};
}
