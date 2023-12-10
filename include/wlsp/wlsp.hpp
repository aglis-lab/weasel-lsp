#pragma once

#include <rapidjson/rapidjson.h>

#include <wlsp/constant.hpp>
#include <wlsp/exception.hpp>
#include <wlsp/server.hpp>
#include <wlsp/builder.hpp>

namespace wlsp
{
    class BaseServer
    {
    public:
        BaseServer() {}
        ~BaseServer() {}

        virtual void run() = 0;

    protected:
        virtual std::optional<InitializeResult> onInitialize(std::optional<InitializeParams> &) = 0;
        virtual std::optional<Hover> onHover(std::optional<HoverParams> &) = 0;

        Builder builder;
    };

    class IOServer : public BaseServer
    {
    public:
        IOServer()
        {
            PLOGI << "use stdio mode.";
        }
        ~IOServer() {}

        void run();

    protected:
        virtual std::optional<InitializeResult> onInitialize(std::optional<InitializeParams> &)
        {
            NOT_IMPLEMENTED;
        }

        virtual std::optional<Hover> onHover(std::optional<HoverParams> &)
        {
            NOT_IMPLEMENTED;
        }

    private:
        std::string readMessage();
        void writeMessage(RequestMessage &req, ObjectT &resp);

        void partialRun();
    };
} // namespace wlsp

void wlsp::IOServer::writeMessage(RequestMessage &req, ObjectT &resp)
{
    ResponseMessage respMessage(req.id, &resp, {});

    JsonWriter writer;
    respMessage.write(writer);

    auto message = writer.GetString();
    std::cout << CONTENT_LENGTH << strlen(message) << "\r\n\r\n";
    std::cout << message;

    PLOGD << CONTENT_LENGTH << strlen(message);
    PLOGD << message;
}

std::string wlsp::IOServer::readMessage()
{
    int contentLength;
    std::cin.ignore(16); // ignore Content-Length:<space>

    std::cin >> contentLength;
    std::cin.ignore(4); // ignore newlines

    PLOGD << "CCONTENT LENGTH " << contentLength;

    std::string content("", contentLength);
    std::cin.read((char *)content.c_str(), contentLength);

    return content;
}

void wlsp::IOServer::partialRun()
{
    // Get Content
    auto content = this->readMessage();

    // Initialize Document
    rapidjson::Document doc;

    PLOGD << "CONTENT";
    PLOGD << content;
    doc.Parse(content.c_str());
    assert(doc.IsObject());

    auto reqMessage = builder.GetRequestMessage(doc);
    auto jsonValue = JsonValue(doc[PARAMS]);

    PLOGI << "CALL";
    PLOGI << reqMessage.method;
    if (reqMessage.method == METHOD_INITIALIZE)
    {
        auto params = builder.GetInitializeParams(jsonValue);
        auto resp = this->onInitialize(params);
        return this->writeMessage(reqMessage, resp.value());
    }

    if (reqMessage.method == METHOD_HOVER)
    {
        auto params = builder.GetHoverParams(jsonValue);
        auto resp = this->onHover(params);
        return this->writeMessage(reqMessage, resp.value());
    }

    ObjectT resp;
    return this->writeMessage(reqMessage, resp);
}

void wlsp::IOServer::run()
{
    while (true)
    {
        LOGI << "========== FETCH REQUEST ==========";
        partialRun();
    }
}
