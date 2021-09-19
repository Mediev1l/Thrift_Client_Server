#pragma once
#include "Messenger.h"

using namespace MessengerNamespace;
using namespace apache::thrift;

class ServerImpl : public MessengerIf
{
public:
    ServerImpl();
    ~ServerImpl() {};

    void sendMessage(std::string& _return, const std::string& text) override;
};

class ServerFactory : virtual public MessengerIfFactory 
{
public:
  ~ServerFactory() override = default;

  MessengerIf* getHandler(const TConnectionInfo& connInfo) override;
  void releaseHandler(MessengerIf* handler) override;
};