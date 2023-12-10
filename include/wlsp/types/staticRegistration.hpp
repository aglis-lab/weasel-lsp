#pragma once

#include <optional>

#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

/// Static registration options can be used to register a feature in the
/// initialize result with a given server control ID to be able to un-register
/// the feature later on.
///
/// id?: String
///
struct StaticRegistrationOptions: public virtual ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String idKey;

public:
	/// The id used to register the request. The id can be used to deregister
	/// the request again. See also Registration#id.
	optional<String> id;

	// No parsing

	StaticRegistrationOptions(optional<String> id);

	StaticRegistrationOptions();

	virtual ~StaticRegistrationOptions();
};

}
