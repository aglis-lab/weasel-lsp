#pragma once

#include <optional>

#include <wlsp/types/objectT.hpp>

namespace wlsp
{

using namespace std;

/// General parameters to register for a capability
///
/// id: String
///
/// method: String
///
/// registerOptions?: Any
///
struct Registration: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String idKey;
	const static String methodKey;
	const static String registerOptionsKey;

public:
	/// The id used to register the request. The id can be used to deregister
	/// the request again.
	String id;

	/// The method / capability to register for.
	String method;

	/// Options necessary for the registration.
	///
	/// It should be a *RegistrationOptions.
	/// Like TextDocumentRegistrationOptions.
	optional<Any> registerOptions;


	// No parsing


	Registration(String id, String method, optional<Any> registerOptions);

	Registration();

	virtual ~Registration();
};

/// The client/registerCapability request is sent from the server
/// to the client to register for a new capability on the client side.
///
/// registrations: Registration[]
///
struct RegistrationParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String registrationsKey;

public:
	vector<Registration> registrations;

	// No parsing

	RegistrationParams(vector<Registration> registrations);

	RegistrationParams();

	virtual ~RegistrationParams();
};


/// General parameters to unregister for a capability
///
/// id: String
///
/// method: String
///
struct Unregistration: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String idKey;
	const static String methodKey;

public:
	/// The id used to unregister the request or notification. Usually an id
	/// provided during the register request.
	String id;

	/// The method / capability to unregister for.
	String method;

	// No parsing

	Unregistration(String id, String method);

	Unregistration();

	virtual ~Unregistration();
};

/// The client/unregisterCapability request is sent from the server
/// to the client to unregister a previously registered capability.
///
/// unregisterations: UnRegistration[]
///
struct UnregistrationParams: public ObjectT
{
protected:
	/// This is like write() but without the object bounds.
	virtual void partialWrite(JsonWriter &writer);

private:
	const static String unregisterationsKey;

public:
	/// This should correctly be named `unregistrations`. However changing this
	/// is a breaking change and needs to wait until we deliver a 4.x version
	/// of the specification.
	vector<Unregistration> unregisterations;

	// No parsing

	UnregistrationParams(vector<Unregistration> unregisterations);

	UnregistrationParams();

	virtual ~UnregistrationParams();
};
}
