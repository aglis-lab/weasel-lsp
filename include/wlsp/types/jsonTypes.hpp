#pragma once

#include <string>
#include <variant>
#include <vector>
#include <memory>

namespace wlsp
{
    using namespace std;
    class ObjectT;

    /// Primitive json-rpc types
    using String = std::string;
    using NativeString = const char *;
    using Number = std::variant<int, double>;
    using Uint = unsigned int;
    using Boolean = bool;
    using Null = std::monostate;

    /// Structured json-rpc types
    using Object = std::shared_ptr<ObjectT>; // Types in variant have to be CopyConstructible
    using Array = std::vector<std::variant<String, Number, Boolean, Null, Object>>;

    /// A collection of all json-rpc types
    using Any = std::variant<String, Number, Boolean, Null, Object, Array>;

    /// Protocol types
    using DocumentUri = String;
    using ProgressToken = std::variant<Number, String>;

    /// A utility type
    using Key = const String;

    // Some operator overloads for the Number type
    Number operator+(Number const &n1, Number const &n2);
    Number operator-(Number const &n1, Number const &n2);
    Number operator*(Number const &n1, Number const &n2);
    Number operator/(Number const &n1, Number const &n2);
    Number operator|(Number const &n1, Number const &n2);

    Number &operator+=(Number &n1, Number const &n2);
    Number &operator-=(Number &n1, Number const &n2);
    Number &operator*=(Number &n1, Number const &n2);
    Number &operator/=(Number &n1, Number const &n2);
}
