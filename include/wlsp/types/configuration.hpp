#pragma once

#include <optional>

#include <wlsp/types/objectT.hpp>

namespace wlsp
{

	using namespace std;

	struct ConfigurationItem : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String scopeUriKey;
		const static String sectionKey;

	public:
		/// The scope to get the configuration section for.
		optional<DocumentUri> scopeUri;

		/// The configuration section asked for.
		optional<String> section;

		// No parsing

		ConfigurationItem(optional<DocumentUri> scopeUri, optional<String> section);

		ConfigurationItem();

		virtual ~ConfigurationItem();
	};

	struct ConfigurationParams : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String itemsKey;

	public:
		vector<ConfigurationItem> items;

		// No parsing

		ConfigurationParams(vector<ConfigurationItem> items);

		ConfigurationParams();

		virtual ~ConfigurationParams();
	};
}
