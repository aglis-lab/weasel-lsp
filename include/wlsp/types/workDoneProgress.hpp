#pragma once

#include <optional>

#include <wlsp/types/jsonTypes.hpp>
#include <wlsp/types/objectT.hpp>
#include <wlsp/types/genericObject.hpp>

namespace wlsp
{

	using namespace std;

	/// To start progress reporting a $/progress notification
	/// with the following payload must be sent:
	///
	/// kind: 'begin'
	///
	/// title: String
	///
	/// cancellable?: Boolean
	///
	/// message?: String
	///
	/// percentage?: Number
	///
	struct WorkDoneProgressBegin : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String titleKey;
		const static String cancellableKey;
		const static String messageKey;
		const static String percentageKey;

	public:
		const static pair<String, String> kind;

		/// Mandatory title of the progress operation. Used to briefly inform about
		/// the kind of operation being performed.
		///
		/// Examples: "Indexing" or "Linking dependencies".
		String title;

		/// Controls if a cancel button should show to allow the user to cancel the
		/// long running operation. Clients that don't support cancellation are allowed
		/// to ignore the setting.
		optional<Boolean> cancellable;

		/// Optional, more detailed associated progress message. Contains
		/// complementary information to the `title`.
		///
		/// Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
		/// If unset, the previous progress message (if any) is still valid.
		optional<String> message;

		/// Optional progress percentage to display (value 100 is considered 100%).
		/// If not provided infinite progress is assumed and clients are allowed
		/// to ignore the `percentage` value in subsequent in report notifications.
		///
		/// The value should be steadily rising. Clients are free to ignore values
		/// that are not following this rule.
		optional<Number> percentage;

		//=======================================================================//

		WorkDoneProgressBegin(String title,
							  optional<Boolean> cancellable,
							  optional<String> message,
							  optional<Number> percentage);

		WorkDoneProgressBegin();

		virtual ~WorkDoneProgressBegin();
	};

	/// Reporting progress is done using the following payload:
	///
	/// kind: 'report'
	///
	/// cancellable?: Boolean
	///
	/// message?: String
	///
	/// percentage?: Number
	///
	struct WorkDoneProgressReport : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String cancellableKey;
		const static String messageKey;
		const static String percentageKey;

	public:
		const static pair<String, String> kind;

		/// Controls enablement state of a cancel button. This property is only valid if a cancel
		/// button got requested in the `WorkDoneProgressStart` payload.
		///
		/// Clients that don't support cancellation or don't support control the button's
		/// enablement state are allowed to ignore the setting.
		optional<Boolean> cancellable;

		/// Optional, more detailed associated progress message. Contains
		/// complementary information to the `title`.
		///
		/// Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
		/// If unset, the previous progress message (if any) is still valid.
		optional<String> message;

		/// Optional progress percentage to display (value 100 is considered 100%).
		/// If not provided infinite progress is assumed and clients are allowed
		/// to ignore the `percentage` value in subsequent in report notifications.
		///
		/// The value should be steadily rising. Clients are free to ignore values
		/// that are not following this rule.
		optional<Number> percentage;

		//=======================================================================//

		WorkDoneProgressReport(optional<Boolean> cancellable,
							   optional<String> message,
							   optional<Number> percentage);

		WorkDoneProgressReport();

		virtual ~WorkDoneProgressReport();
	};

	/// Signaling the end of a progress reporting is done using the following
	/// payload
	///
	/// kind: 'end'
	///
	/// message?: String
	///
	struct WorkDoneProgressEnd : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String messageKey;

	public:
		const static pair<String, String> kind;

		/// Optional, a final message indicating to for example indicate
		/// the outcome of the operation.
		optional<String> message;

		//=======================================================================//

		WorkDoneProgressEnd(optional<String> message);

		WorkDoneProgressEnd();

		virtual ~WorkDoneProgressEnd();
	};

	/// A parameter literal used to pass a work done progress token.
	///
	/// workDoneToken?: ProgressToken
	///
	struct WorkDoneProgressParams : public virtual ObjectT
	{
	private:
		const static String workDoneTokenKey;

	public:
		/// An optional token that a server can use to report work done progress.
		optional<ProgressToken> workDoneToken;

		//=======================================================================//

		// No writing

		WorkDoneProgressParams(optional<ProgressToken> workDoneToken);

		WorkDoneProgressParams();

		virtual ~WorkDoneProgressParams();
	};

	/// Options to signal work done progress support in server capabilities.
	///
	/// workDoneProgress?: boolean
	///
	struct WorkDoneProgressOptions : public virtual ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String workDoneProgressKey;

	public:
		optional<Boolean> workDoneProgress;

		// No parsing

		WorkDoneProgressOptions(optional<Boolean> workDoneProgress);

		WorkDoneProgressOptions();

		virtual ~WorkDoneProgressOptions();
	};

	/// The window/workDoneProgress/create request is sent from the server to
	/// the client to ask the client to create a work done progress.
	///
	/// token: ProgressToken
	///
	struct WorkDoneProgressCreateParams : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String tokenKey;

	public:
		/// The token to be used to report progress.
		ProgressToken token;

		// No parsing

		WorkDoneProgressCreateParams(ProgressToken token);

		WorkDoneProgressCreateParams();

		virtual ~WorkDoneProgressCreateParams();
	};

	/// The window/workDoneProgress/cancel notification is sent from the client to
	/// the server to cancel a progress initiated on the server side using the
	/// window/workDoneProgress/create.
	///
	/// token: ProgressToken
	///
	struct WorkDoneProgressCancelParams : public ObjectT
	{
	private:
		const static String tokenKey;

	public:
		/// The token to be used to report progress.
		ProgressToken token;

		//=======================================================================//

		// No writing

		WorkDoneProgressCancelParams(ProgressToken token);

		WorkDoneProgressCancelParams();

		virtual ~WorkDoneProgressCancelParams();
	};

	/// $/progress parameters
	///
	/// token: ProgressToken
	///
	/// value: WorkDoneProgressBegin | WorkDoneProgressReport | WorkDoneProgressEnd
	///
	struct ProgressParams : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String tokenKey;
		const static String valueKey;

		struct ValueMaker : public ObjectT
		{
			/// The object where value is
			ProgressParams &parent;

			/// A cache for the values recieved before kind:
			GenericObject cache;

			//===================================================================//

			ValueMaker(ProgressParams &parent);

			virtual ~ValueMaker();
		};

	public:
		/// The progress token provided by the client or server.
		ProgressToken token;

		/// The progress data.
		variant<WorkDoneProgressBegin,
				WorkDoneProgressReport,
				WorkDoneProgressEnd>
			value;

		//=======================================================================//

		ProgressParams(ProgressToken token,
					   variant<WorkDoneProgressBegin,
							   WorkDoneProgressReport,
							   WorkDoneProgressEnd>
						   value);

		ProgressParams();

		virtual ~ProgressParams();
	};

}
