#pragma once

#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

/// A parameter literal used to pass a partial result token.
///
/// partialResultToken?: ProgressToken
///
struct PartialResultParams: public virtual ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String partialResultTokenKey;

public:
	/// An optional token that a server can use to report partial results
	/// (e.g. streaming) to the client.
	optional<ProgressToken> partialResultToken;

	//=======================================================================//


	PartialResultParams(optional<ProgressToken> partialResultToken);

	PartialResultParams();

	virtual ~PartialResultParams();
};

}
