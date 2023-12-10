#include <wlsp/server/server.hpp>

namespace wlsp
{

using namespace std;

void Server::startIO()
{
	// TODO
}

void Server::addCapability(Capability capability)
{
	capabilityMutex.lock();

	capabiliyMap.emplace(capability.method, capability);

	capabilityMutex.unlock();
}

optional<Capability> Server::getCapability(String method)
{
	optional<Capability> resu;

	capabilityMutex.lock_shared();

	auto capability = capabiliyMap.find(method);

	if(capability != capabiliyMap.end())
	{
		resu = capability->second;
	}
	else
	{
		resu = nullopt;
	}

	capabilityMutex.unlock_shared();

	return resu;

}

void Server::addRequest(variant<Number, String> id,
	String method,
	RequestKind kind)
{
	switch(kind)
	{
		case RequestKind::toClient:
			requestSentMutex.lock();

			requestSentMap.emplace(id, method);

			requestSentMutex.unlock();
			break;

		case RequestKind::fromClient:
			requestRecievedMutex.lock();

			requestRecievedMap.emplace(id, method);

			requestRecievedMutex.unlock();
			break;
	}
}

String Server::completeRequest(variant<Number, String> id, RequestKind kind)
{
	String resu;

	map<variant<Number, String>, String>::iterator mapIterator;

	switch(kind)
	{
		case RequestKind::toClient:
			requestSentMutex.lock();

			mapIterator = requestSentMap.find(id);
			if(mapIterator != requestSentMap.end())
			{
				resu = mapIterator->second;
				requestSentMap.erase(mapIterator);
			}

			requestSentMutex.unlock();
			break;

		case RequestKind::fromClient:
			requestRecievedMutex.lock();

			mapIterator = requestRecievedMap.find(id);
			if(mapIterator != requestRecievedMap.end())
			{
				resu = mapIterator->second;
				requestRecievedMap.erase(mapIterator);
			}

			requestRecievedMutex.unlock();
			break;
	}

	return resu;
}

Server::Server(){};
Server::~Server(){};

}
