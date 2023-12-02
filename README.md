# Weasel LSP

Originally this repo was inspired by https://github.com/otreblan/libclsp. Because I'm very lazy, Most of the struct are rewriten from libclsp repo. And then I change how it's work and how the API used.

This project created with a hope can be used by other project and create reusable library might be become hard challenge.

Weasel LSP is a library that being used by Weasel Programming Language, and primarily created to be integrated with Weasel Language.

# Structure

This library divided into 2 distinct part, first one is Types and the second one is Server. Types is not directly related into the server but the server is use types through Builder class.

### Types

Types are collections of LSP structure and it's parser. The json library we use is 'rapidjson'.

### Server

Server is class that responsible for communication between Client. It's use types for serialization and to make sure it's easier to code.

Actually, you can use rapidjson directly with Value as an object that being send between Client and Server. But that become so complex and difficult to maintaince.

Server is not directly access types. It's use builder as an helper class. So, server just know how to receive and response the data.
