#pragma once

#include <map>
#include <shared_mutex>

#include <wlsp/server/jsonHandler.hpp>
#include <wlsp/server/capability.hpp>

namespace wlsp
{

	using namespace std;

	enum class RequestKind
	{
		/// The request waits a response from the client.
		toClient,

		/// The request waits a response from the server.
		fromClient
	};

	class Server
	{
	private:
		/// A map with the capabilities that the server supports.
		map<String, Capability> capabiliyMap;

		/// A mutex for the capability map.
		mutable shared_mutex capabilityMutex;

		/// A map with the requests send to the client.
		/// The key is the id and the value is the method.
		map<variant<Number, String>, String> requestSentMap;

		/// A mutex for the requestSent map.
		mutable shared_mutex requestSentMutex;

		/// A map with the requests recieved from the client.
		/// The key is the id and the value is the method.
		map<variant<Number, String>, String> requestRecievedMap;

		/// A mutex for the requestSent map.
		mutable shared_mutex requestRecievedMutex;

		/// The last id used for a request sent to the client
		int lastId = 0;

	public:
		/// This starts the server and seeks for the Initialize request.
		void startIO();

		/// This function adds a new capability to the server, but doesn't
		/// send the client/registerCapability request.
		void addCapability(Capability capability);

		/// Returns the capability of the method given. If no capability is found
		/// the optional<> is set to nullopt.
		optional<Capability> getCapability(String method);

		/// Adds a request to one of the two request maps.
		void addRequest(variant<Number, String> id, String method, RequestKind kind);

		/// Completes a request and returns the method name.
		String completeRequest(variant<Number, String> id, RequestKind kind);

		Server();
		virtual ~Server();
	};
}
