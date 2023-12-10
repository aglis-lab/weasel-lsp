#pragma once

#include <stdint.h>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	/// A position in a text document
	///
	/// line: Number
	///
	/// character: Number
	///
	struct Position : public ObjectT
	{
	public:
		friend class Builder;

	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		static constexpr NativeString lineKey = "line";
		static constexpr NativeString characterKey = "character";

	public:
		/// Line position in a document (zero-based).
		Uint line;

		/// Character offset on a line in a document (zero-based). Assuming that the line is
		/// represented as a string, the `character` value represents the gap between the
		/// `character` and `character + 1`.
		///
		/// If the character value is greater than the line length it defaults back to the
		/// line length.
		Uint character;

		//=======================================================================//

		Position(Uint line, Uint character);

		Position();

		virtual ~Position();
	};

}
