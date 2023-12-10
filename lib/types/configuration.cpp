#include <wlsp/types/configuration.hpp>

namespace wlsp
{

	using namespace std;

	const String ConfigurationItem::scopeUriKey = "scopeUri";
	const String ConfigurationItem::sectionKey = "section";

	ConfigurationItem::ConfigurationItem(optional<DocumentUri> scopeUri,
										 optional<String> section) : scopeUri(scopeUri),
																	 section(section){};

	ConfigurationItem::ConfigurationItem(){};
	ConfigurationItem::~ConfigurationItem(){};

	void ConfigurationItem::partialWrite(JsonWriter &writer)
	{
		// scopeUri?
		if (scopeUri.has_value())
		{
			writer.Key(scopeUriKey);
			writer.String((*scopeUri).c_str());
		}

		// section?
		if (section.has_value())
		{
			writer.Key(sectionKey);
			writer.String((*section));
		}
	}

	const String ConfigurationParams::itemsKey = "items";

	ConfigurationParams::ConfigurationParams(vector<ConfigurationItem> items) : items(items){};

	ConfigurationParams::ConfigurationParams(){};
	ConfigurationParams::~ConfigurationParams(){};

	void ConfigurationParams::partialWrite(JsonWriter &writer)
	{
		// items
		writer.Key(itemsKey);
		writer.StartArray();
		for (auto &i : items)
		{
			writer.Object(i);
		}
		writer.EndArray();
	}

}
