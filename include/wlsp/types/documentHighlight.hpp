#pragma once

#include <wlsp/types/partialResult.hpp>
#include <wlsp/types/range.hpp>
#include <wlsp/types/textDocumentPosition.hpp>
#include <wlsp/types/textDocumentRegistration.hpp>
#include <wlsp/types/workDoneProgress.hpp>

namespace wlsp
{

using namespace std;

/// DocumentHighlight request client capabilities
///
/// dynamicRegistration?: Boolean
///
struct DocumentHighlightClientCapabilities: public ObjectT
{
private:
	const static String dynamicRegistrationKey;

public:
	/// Whether declaration supports dynamic registration.
	optional<Boolean> dynamicRegistration;

	//=======================================================================//

	// No writing

	DocumentHighlightClientCapabilities(optional<Boolean> dynamicRegistration);

	DocumentHighlightClientCapabilities();

	virtual ~DocumentHighlightClientCapabilities();
};

/// Find references server capability
using DocumentHighlightOptions = WorkDoneProgressOptions; // No parsing

struct DocumentHighlightRegistrationOptions:
	public TextDocumentRegistrationOptions,
	public DocumentHighlightOptions
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

public:
	// No parsing

	DocumentHighlightRegistrationOptions(
		variant<DocumentSelector, Null> documentSelector,
		optional<Boolean> workDoneProgress);

	DocumentHighlightRegistrationOptions();

	virtual ~DocumentHighlightRegistrationOptions();
};

/// Document highlight request parameters
struct DocumentHighlightParams:
	public TextDocumentPositionParams,
	public WorkDoneProgressParams,
	public PartialResultParams
{
	//=======================================================================//

	// No writing

	DocumentHighlightParams(TextDocumentIdentifier textDocument,
		Position position,
		optional<ProgressToken> workDoneToken,
		optional<ProgressToken> partialResultToken);

	DocumentHighlightParams();

	virtual ~DocumentHighlightParams();
};

/// A document highlight kind.
enum class DocumentHighlightKind
{
	/// A textual occurrence.
	Text = 1,

	/// Read-access of a symbol, like reading a variable.
	Read = 2,

	/// Write-access of a symbol, like writing to a variable.
	Write = 3
};

/// A document highlight is a range inside a text document which deserves
/// special attention. Usually a document highlight is visualized by changing
/// the background color of its range.
struct DocumentHighlight: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String rangeKey;
	const static String kindKey;

public:
	/// The range this highlight applies to.
	Range range;

	/// The highlight kind, default is DocumentHighlightKind.Text.
	optional<DocumentHighlightKind> kind;

	// No parsing

	DocumentHighlight(Range range, optional<DocumentHighlightKind> kind);

	DocumentHighlight();

	virtual ~DocumentHighlight();
};

}
