#pragma once

#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>

namespace wlsp
{
	/// Represents a reference to a command.
	///
	/// title: String
	///
	/// command: String
	///
	/// arguments?: Array
	///
	struct Command : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String titleKey;
		const static String commandKey;
		const static String argumentsKey;

	public:
		/// Title of the command, like `save`.
		String title;

		/// The identifier of the actual command handler.
		String command;

		/// Arguments that the command handler should be
		/// invoked with.
		std::optional<Array> arguments;

		//=======================================================================//

		Command(String title, String command, std::optional<Array> arguments);

		Command();

		virtual ~Command();
	};
}
