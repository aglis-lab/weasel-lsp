#include <wlsp/types/documentFilter.hpp>

namespace wlsp
{

using namespace std;

const String DocumentFilter::languageKey = "language";
const String DocumentFilter::schemeKey   = "scheme";
const String DocumentFilter::patternKey  = "pattern";

DocumentFilter::DocumentFilter(optional<String> language,
	optional<String> scheme,
	optional<String> pattern):
		language(language),
		scheme(scheme),
		pattern(pattern)
{};

DocumentFilter::DocumentFilter(){};
DocumentFilter::~DocumentFilter(){};

void DocumentFilter::partialWrite(JsonWriter &writer)
{
	// language?
	if(language.has_value())
	{
		writer.Key(languageKey);
		writer.String(*language);
	}

	// scheme?
	if(scheme.has_value())
	{
		writer.Key(schemeKey);
		writer.String(*scheme);
	}

	// pattern?
	if(pattern.has_value())
	{
		writer.Key(patternKey);
		writer.String(*pattern);
	}
}

}
