#pragma once

#include <optional>

#include <wlsp/json/jsonValue.hpp>

#include <wlsp/types.hpp>

namespace wlsp
{
    class Builder
    {
    public:
        Builder() {}
        ~Builder() {}

        // RequestMessage
        RequestMessage GetRequestMessage(JsonDocument &value);

        // InitializeParams
        std::optional<InitializeParams> GetInitializeParams(JsonValue &value);
        std::optional<InitializeParams::ClientInfo> GetInitializeParamsClient(JsonValue &value);
        WorkspaceFolder GetWorkspaceFolder(JsonValue &value);

        // Client Capabilties
        wlsp::ClientCapabilities GetClientCapabilities(JsonValue &value);
        wlsp::ClientCapabilities::Workspace GetClientWorkspace(JsonValue &value);

        // Hover Params
        std::optional<HoverParams> GetHoverParams(JsonValue &value);

        // Text Docoument
        TextDocumentIdentifier GetTextDocument(JsonValue &value);

        // Get Position
        Position GetPosition(JsonValue &value);

    protected:
        /// The last id used for a request sent to the client
        int lastId = 0;
    };
} // namespace wlsp

wlsp::RequestMessage wlsp::Builder::GetRequestMessage(wlsp::JsonDocument &value)
{
    assert(value.HasMember(Message::jsonrpcKey));
    assert(value.HasMember(RequestMessage::methodKey));

    return RequestMessage(
        value[Message::jsonrpcKey].GetString(),
        value.HasMember(RequestMessage::idKey) ? value[RequestMessage::idKey].GetInt() : std::optional<int>(),
        value[RequestMessage::methodKey].GetString());
}

std::optional<wlsp::InitializeParams> wlsp::Builder::GetInitializeParams(wlsp::JsonValue &value)
{
    if (!value.IsObject())
    {
        return {};
    }

    InitializeParams params;

    // Initialize Params
    params.processId = value.GetIntOptional(InitializeParams::processIdKey);
    params.locale = value.GetStringOptional(InitializeParams::localeKey);
    params.trace = TraceKind(value.GetString(InitializeParams::traceKey));

    // Client Info
    if (value.HasMember(InitializeParams::clientInfoKey))
    {
        auto jsonVal = value[InitializeParams::clientInfoKey];
        params.clientInfo = this->GetInitializeParamsClient(jsonVal);
    }

    // Parse Workspace Folders
    if (value.HasMemberArray(InitializeParams::workspaceFoldersKey))
    {
        auto jsonArray = value[InitializeParams::workspaceFoldersKey].GetArray();
        std::vector<WorkspaceFolder> arr(jsonArray.Size());
        for (auto &item : jsonArray)
        {
            auto jsonVal = JsonValue(item);
            arr.push_back(this->GetWorkspaceFolder(jsonVal));
        }
    }

    // Capabilities
    // if (value.HasMember(InitializeParams::capabilitiesKey))
    // {
    //     auto jsonVal = value[InitializeParams::capabilitiesKey];
    //     params.capabilities = this->GetClientCapabilities(jsonVal);
    // }

    return params;
}

std::optional<wlsp::InitializeParams::ClientInfo> wlsp::Builder::GetInitializeParamsClient(JsonValue &value)
{
    if (!value.IsObject())
    {
        return {};
    }

    return InitializeParams::ClientInfo(
        value.GetString(InitializeParams::ClientInfo::nameKey),
        value.GetStringOptional(InitializeParams::ClientInfo::versionKey));
}

wlsp::WorkspaceFolder wlsp::Builder::GetWorkspaceFolder(JsonValue &value)
{
    assert(value.IsObject());

    return WorkspaceFolder(
        value.GetString(WorkspaceFolder::uriKey),
        value.GetString(WorkspaceFolder::nameKey));
}

wlsp::ClientCapabilities wlsp::Builder::GetClientCapabilities(JsonValue &value)
{
    wlsp::ClientCapabilities data;

    // TODO: Missing Implementation
    // Window
    // General
    // NotebookDocument

    // Initialize Workspace
    if (value.HasMember(ClientCapabilities::workspaceKey))
    {
        auto jsonVal = value[ClientCapabilities::workspaceKey];
        data.workspace = this->GetClientWorkspace(jsonVal);
    }

    // Initialize Text Document
    if (value.HasMember(ClientCapabilities::textDocumentKey))
    {
    }

    // Initialize Experimental
    if (value.HasMember(ClientCapabilities::experimentalKey))
    {
    }

    // Initialize Window

    // Initialize General

    // Initialize NotebookDocument

    return data;
}

wlsp::ClientCapabilities::Workspace wlsp::Builder::GetClientWorkspace(JsonValue &value)
{
}

std::optional<wlsp::HoverParams> wlsp::Builder::GetHoverParams(JsonValue &value)
{
    assert(value.HasMember(HoverParams::textDocumentKey));
    assert(value.HasMember(HoverParams::positionKey));

    auto documentVal = value[HoverParams::textDocumentKey];
    auto positionVal = value[HoverParams::positionKey];

    return HoverParams(
        GetTextDocument(documentVal),
        GetPosition(positionVal),
        std::optional<ProgressToken>());
}

wlsp::TextDocumentIdentifier wlsp::Builder::GetTextDocument(JsonValue &value)
{
    assert(value.HasMemberString(TextDocumentIdentifier::uriKey));

    return TextDocumentIdentifier(value.GetString(TextDocumentIdentifier::uriKey));
}

wlsp::Position wlsp::Builder::GetPosition(JsonValue &value)
{
    assert(value.HasMemberInt(Position::lineKey));
    assert(value.HasMemberInt(Position::characterKey));

    return Position(value.GetUint(Position::lineKey), value.GetUint(Position::characterKey));
}
