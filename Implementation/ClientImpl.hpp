#pragma once
#include "Messenger.h"

#include <string>

using namespace MessengerNamespace;
using namespace apache::thrift::protocol;


class ClientImpl : public MessengerClient
{
public:
    ClientImpl(std::shared_ptr<TProtocol> protocol, std::shared_ptr<TTransport> transport);

    std::string sendMessage(const std::string& message);
};