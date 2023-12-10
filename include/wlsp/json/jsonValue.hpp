#pragma once

#include <rapidjson/document.h>

#include <wlsp/types/jsonTypes.hpp>

namespace wlsp
{
    using JsonArray = rapidjson::GenericArray<false, rapidjson::GenericValue<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>>;
    using JsonDocument = rapidjson::Document;

    struct JsonValue
    {
    public:
        JsonValue(rapidjson::Value &value) : value(value) {}

        rapidjson::Value &value;

        bool IsNull() const { return value.IsNull(); }
        bool IsFalse() const { return value.IsFalse(); }
        bool IsTrue() const { return value.IsTrue(); }
        bool IsBool() const { return value.IsBool(); }
        bool IsObject() const { return value.IsObject(); }
        bool IsArray() const { return value.IsArray(); }
        bool IsNumber() const { return value.IsNumber(); }
        bool IsInt() const { return value.IsInt(); }
        bool IsUint() const { return value.IsUint(); }
        bool IsInt64() const { return value.IsInt64(); }
        bool IsUint64() const { return value.IsUint64(); }
        bool IsDouble() const { return value.IsDouble(); }
        bool IsString() const { return value.IsString(); }

        bool HasMember(NativeString key) const { return value.HasMember(key); }
        bool HasMemberArray(NativeString key) const { return value.HasMember(key) && value[key].IsArray(); }
        bool HasMemberInt(NativeString key) const { return value.HasMember(key) && value[key].IsInt(); }
        bool HasMemberString(NativeString key) const { return value.HasMember(key) && value[key].IsString(); }

        JsonArray GetArray() { return value.GetArray(); }

        JsonValue operator[](NativeString key)
        {
            return JsonValue(value[key]);
        }

        JsonValue operator=(rapidjson::Value &val)
        {
            return JsonValue(val);
        }

        String GetString(NativeString key)
        {
            assert(value.HasMember(key));
            assert(value[key].IsString());

            return value[key].GetString();
        }

        String GetStringOptional(NativeString key)
        {
            if (!value.HasMember(key))
            {
                return {};
            }

            if (!value[key].IsString())
            {
                return {};
            }

            return value[key].GetString();
        }

        int GetInt(NativeString key)
        {
            assert(value.HasMember(key));
            assert(value[key].IsInt());

            return value[key].GetInt();
        }

        Uint GetUint(NativeString key)
        {
            assert(value.HasMember(key));
            assert(value[key].IsUint());

            return value[key].GetUint();
        }

        std::optional<int> GetIntOptional(NativeString key)
        {
            if (!value.HasMember(key))
            {
                return {};
            }

            if (!value[key].IsInt())
            {
                return {};
            }

            return value[key].GetInt();
        }
    };
} // namespace wlsp
