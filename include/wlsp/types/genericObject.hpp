#pragma once

#include <wlsp/types/objectT.hpp>

namespace wlsp
{
	/// This helps to parse a generic array
	struct ArrayMaker : public ObjectT
	{
		/// The array to make
		Array &parentArray;

		//=======================================================================//

		ArrayMaker(Array &parentArray);

		virtual ~ArrayMaker();
	};

	/// Parses an array of objects
	template <typename Object>
	struct ObjectArrayMaker : public ObjectT
	{
		vector<Object> &parentArray;

		ObjectArrayMaker<Object>(vector<Object> &parentArray) : parentArray(parentArray){};

		virtual ~ObjectArrayMaker<Object>(){};
	};

	/// An object with no predefined key-value pairs.
	struct GenericObject : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	public:
		/// Key-value pairs of anything
		map<String, Any> children;

		//====================   Reparsing   ====================================//

		/// This calls events on the handler with its children
		void reParse(JsonHandler &handler);

		//=======================================================================//

		GenericObject(map<String, Any> children);

		GenericObject();

		virtual ~GenericObject();
	};
}
