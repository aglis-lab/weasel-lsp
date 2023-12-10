#include <wlsp/types/workDoneProgress.hpp>
#include <functional>

namespace wlsp
{

	using namespace std;

	const pair<String, String> WorkDoneProgressBegin::kind = {"kind", "begin"};

	const String WorkDoneProgressBegin::titleKey = "title";
	const String WorkDoneProgressBegin::cancellableKey = "cancellable";
	const String WorkDoneProgressBegin::messageKey = "message";
	const String WorkDoneProgressBegin::percentageKey = "percentage";

	WorkDoneProgressBegin::WorkDoneProgressBegin(String title,
												 optional<Boolean> cancellable,
												 optional<String> message,
												 optional<Number> percentage) : title(title),
																				cancellable(cancellable),
																				message(message),
																				percentage(percentage){};

	WorkDoneProgressBegin::WorkDoneProgressBegin(){};
	WorkDoneProgressBegin::~WorkDoneProgressBegin(){};

	void WorkDoneProgressBegin::partialWrite(JsonWriter &writer)
	{
		// kind
		writer.Key(kind.first);
		writer.String(kind.second);

		// title
		writer.Key(titleKey);
		writer.String(title);

		// cancellable?
		if (cancellable.has_value())
		{
			writer.Key(cancellableKey);
			writer.Bool(*cancellable);
		}

		// message?
		if (message.has_value())
		{
			writer.Key(messageKey);
			writer.String(*message);
		}

		// percentage?
		if (percentage.has_value())
		{
			writer.Key(percentageKey);
			writer.Number(*percentage);
		}
	}

	const pair<String, String> WorkDoneProgressReport::kind = {"kind", "report"};

	const String WorkDoneProgressReport::cancellableKey = "cancellable";
	const String WorkDoneProgressReport::messageKey = "message";
	const String WorkDoneProgressReport::percentageKey = "percentage";

	WorkDoneProgressReport::WorkDoneProgressReport(optional<Boolean> cancellable,
												   optional<String> message,
												   optional<Number> percentage) : cancellable(cancellable),
																				  message(message),
																				  percentage(percentage){};

	WorkDoneProgressReport::WorkDoneProgressReport(){};
	WorkDoneProgressReport::~WorkDoneProgressReport(){};

	void WorkDoneProgressReport::partialWrite(JsonWriter &writer)
	{
		// kind
		writer.Key(kind.first);
		writer.String(kind.second);

		// cancellable?
		if (cancellable.has_value())
		{
			writer.Key(cancellableKey);
			writer.Bool(*cancellable);
		}

		// message?
		if (message.has_value())
		{
			writer.Key(messageKey);
			writer.String(*message);
		}

		// percentage?
		if (percentage.has_value())
		{
			writer.Key(percentageKey);
			writer.Number(*percentage);
		}
	}

	const pair<String, String> WorkDoneProgressEnd::kind = {"kind", "end"};

	const String WorkDoneProgressEnd::messageKey = "message";

	WorkDoneProgressEnd::WorkDoneProgressEnd(optional<String> message) : message(message){};

	WorkDoneProgressEnd::WorkDoneProgressEnd(){};
	WorkDoneProgressEnd::~WorkDoneProgressEnd(){};

	void WorkDoneProgressEnd::partialWrite(JsonWriter &writer)
	{
		// kind
		writer.Key(kind.first);
		writer.String(kind.second);

		// message?
		if (message.has_value())
		{
			writer.Key(messageKey);
			writer.String(*message);
		}
	}

	const String WorkDoneProgressParams::workDoneTokenKey = "workDoneToken";

	WorkDoneProgressParams::
		WorkDoneProgressParams(optional<ProgressToken> workDoneToken) : workDoneToken(workDoneToken){};

	WorkDoneProgressParams::WorkDoneProgressParams(){};
	WorkDoneProgressParams::~WorkDoneProgressParams(){};

	const String WorkDoneProgressOptions::workDoneProgressKey = "workDoneProgress";

	WorkDoneProgressOptions::
		WorkDoneProgressOptions(optional<Boolean> workDoneProgress) : workDoneProgress(workDoneProgress){};

	WorkDoneProgressOptions::WorkDoneProgressOptions(){};
	WorkDoneProgressOptions::~WorkDoneProgressOptions(){};

	void WorkDoneProgressOptions::partialWrite(JsonWriter &writer)
	{
		// workDoneProgress?
		if (workDoneProgress.has_value())
		{
			writer.Key(workDoneProgressKey);
			writer.Bool(*workDoneProgress);
		}
	}

	const String WorkDoneProgressCreateParams::tokenKey = "token";

	WorkDoneProgressCreateParams::WorkDoneProgressCreateParams(ProgressToken token) : token(token){};

	WorkDoneProgressCreateParams::WorkDoneProgressCreateParams(){};
	WorkDoneProgressCreateParams::~WorkDoneProgressCreateParams(){};

	void WorkDoneProgressCreateParams::partialWrite(JsonWriter &writer)
	{
		// token
		writer.Key(tokenKey);
		visit(overload(
				  [&writer](Number n)
				  {
					  writer.Number(n);
				  },
				  [&writer](String &str)
				  {
					  writer.String(str);
				  }),
			  token);
	}

	const String WorkDoneProgressCancelParams::tokenKey = "token";

	WorkDoneProgressCancelParams::WorkDoneProgressCancelParams(ProgressToken token) : token(token){};

	WorkDoneProgressCancelParams::WorkDoneProgressCancelParams(){};
	WorkDoneProgressCancelParams::~WorkDoneProgressCancelParams(){};

	const String ProgressParams::tokenKey = "token";
	const String ProgressParams::valueKey = "value";

	ProgressParams::ProgressParams(ProgressToken token,
								   variant<WorkDoneProgressBegin,
										   WorkDoneProgressReport,
										   WorkDoneProgressEnd>
									   value) : token(token),
												value(value){};

	ProgressParams::ProgressParams(){};
	ProgressParams::~ProgressParams(){};

	void ProgressParams::partialWrite(JsonWriter &writer)
	{
		// token
		writer.Key(tokenKey);
		visit(overload(
				  [&writer](Number n)
				  {
					  writer.Number(n);
				  },
				  [&writer](String &str)
				  {
					  writer.String(str);
				  }),
			  token);

		// value
		writer.Key(valueKey);
		visit(overload(
				  [&writer](WorkDoneProgressBegin &obj)
				  {
					  writer.Object(obj);
				  },
				  [&writer](WorkDoneProgressReport &obj)
				  {
					  writer.Object(obj);
				  },
				  [&writer](WorkDoneProgressEnd &obj)
				  {
					  writer.Object(obj);
				  }),
			  value);
	}

}
