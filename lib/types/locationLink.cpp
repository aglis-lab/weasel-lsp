#include <wlsp/types/locationLink.hpp>

namespace wlsp
{

	const String LocationLink::originSelectionRangeKey = "originSelectionRange";
	const String LocationLink::targetUriKey = "targetUri";
	const String LocationLink::targetRangeKey = "targetRange";
	const String LocationLink::targetSelectionRangeKey = "targetSelectionRange";

	LocationLink::LocationLink(optional<Range> originSelectionRange,
							   DocumentUri targetUri,
							   Range targetRange,
							   Range targetSelectionRange) : originSelectionRange(originSelectionRange),
															 targetUri(targetUri),
															 targetRange(targetRange),
															 targetSelectionRange(targetSelectionRange){};

	LocationLink::LocationLink(){};
	LocationLink::~LocationLink(){};

	void LocationLink::partialWrite(JsonWriter &writer)
	{
		// originSelectionRange?
		if (originSelectionRange.has_value())
		{
			writer.Key(originSelectionRangeKey);
			writer.Object(*originSelectionRange);
		}

		// targetUri
		writer.Key(targetUriKey);
		writer.String(targetUri);

		// targetRange
		writer.Key(targetRangeKey);
		writer.Object(targetRange);

		// targetSelectionRange
		writer.Key(targetSelectionRangeKey);
		writer.Object(targetSelectionRange);
	}

}
