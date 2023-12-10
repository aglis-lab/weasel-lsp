#pragma once

#include <rapidjson/writer.h>

#include <wlsp/types/jsonTypes.hpp>

namespace wlsp
{

	using namespace std;
	using namespace rapidjson;

	/// Copied from https://arne-mertz.de/2018/05/overload-build-a-variant-visitor-on-the-fly/
	template <class... Fs>
	struct overload : Fs...
	{
		overload(Fs const &...fs) : Fs{fs}... {};

		using Fs::operator()...;
	};

	/// A writer with some extra functions
	class JsonWriter : public Writer<StringBuffer>
	{
	private:
		/// A buffer
		StringBuffer buffer;

	public:
		JsonWriter() : Writer<StringBuffer>(buffer) {}

		/// Writes an ObjectT
		bool Object(ObjectT &obj);

		/// Writes an int or a double
		bool Number(Number n);

		/// Writes a generic array
		bool Array(Array &a);

		/// Writes almost anything
		bool Any(Any &a);

		/// Writes a new key
		bool Key(wlsp::Key &str)
		{
			return Writer<StringBuffer>::Key(str.c_str(), str.size());
		}

		bool String(const wlsp::String &str)
		{
			return Writer::String(str.c_str());
		}

		/// Gets the json
		const StringBuffer::Ch *GetString() const
		{
			return buffer.GetString();
		}
	};
}
