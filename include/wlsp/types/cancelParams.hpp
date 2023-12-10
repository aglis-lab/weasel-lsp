#pragma once

#include <variant>
#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	/// This for request cancelation
	///
	/// id: Number | String
	///
	struct CancelParams : public ObjectT
	{
	private:
		const static String idKey;

	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		/// The request id to cancel.
		variant<Number, String> id;

		//====================   Parsing   ======================================//

		// Using default isValid()

		//=======================================================================//

		CancelParams(variant<Number, String> id);

		CancelParams();

		virtual ~CancelParams();
	};

}
