#pragma once

#include <wlsp/types/diagnostic.hpp>

namespace wlsp
{

	using namespace std;

	/// Publish diagnostic client capability
	///
	/// relatedInformation?: Boolean
	///
	/// tagSupport?: {
	///
	/// 	valueSet: DiagnosticTag[]
	/// }
	///
	/// versionSupport?: Boolean
	///
	struct PublishDiagnosticsClientCapabilities : public ObjectT
	{
	private:
		const static String relatedInformationKey;
		const static String tagSupportKey;
		const static String versionSupportKey;

	public:
		/// Whether the clients accepts diagnostics with related information.
		optional<Boolean> relatedInformation;

		/// Client supports the tag property to provide meta data about a
		/// diagnostic.
		/// Clients supporting tags have to handle unknown tags gracefully.
		///
		/// @since 3.15.0
		struct TagSupport : public ObjectT
		{
		private:
			const static String valueSetKey;

			struct ValueSetMaker : public ObjectT
			{
				/// The array to make
				vector<DiagnosticTag> &parentArray;

				//===============================================================//

				ValueSetMaker(vector<DiagnosticTag> &parentArray);
				virtual ~ValueSetMaker();
			};

		public:
			/// The tags supported by the client.
			vector<DiagnosticTag> valueSet;

			TagSupport(vector<DiagnosticTag> valueSet);

			TagSupport();

			virtual ~TagSupport();
		};

		/// Client supports the tag property to provide meta data about a
		/// diagnostic.
		/// Clients supporting tags have to handle unknown tags gracefully.
		///
		/// @since 3.15.0
		optional<TagSupport> tagSupport;

		/// Whether the client interprets the version property of the
		/// `textDocument/publishDiagnostics` notification's parameter.
		///
		/// @since 3.15.0
		optional<Boolean> versionSupport;

		//=======================================================================//

		// No writing

		PublishDiagnosticsClientCapabilities(optional<Boolean> relatedInformation,
											 optional<TagSupport> tagSupport,
											 optional<Boolean> versionSupport);

		PublishDiagnosticsClientCapabilities();

		virtual ~PublishDiagnosticsClientCapabilities();
	};

	/// Publish diagnostic notification parameters.
	///
	/// uri: DocumentUri
	///
	/// version?: Number
	///
	/// diagnostics: Diagnostic[]
	///
	struct PublishDiagnosticsParams : public ObjectT
	{
	protected:
		/// This is like write() but without the object bounds.
		virtual void partialWrite(JsonWriter &writer);

	private:
		const static String uriKey;
		const static String versionKey;
		const static String diagnosticsKey;

	public:
		/// The URI for which diagnostic information is reported.
		DocumentUri uri;

		/// Optional the version number of the document the diagnostics are published
		/// for.
		///
		/// @since 3.15.0
		optional<Number> version;

		/// An array of diagnostic information items.
		vector<Diagnostic> diagnostics;

		// No parsing

		PublishDiagnosticsParams(DocumentUri uri,
								 optional<Number> version,
								 vector<Diagnostic> diagnostics);

		PublishDiagnosticsParams();

		virtual ~PublishDiagnosticsParams();
	};

}
