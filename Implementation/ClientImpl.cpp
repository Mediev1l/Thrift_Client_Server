#include "ClientImpl.hpp"

#include <iostream>

using namespace std;

ClientImpl::ClientImpl(std::shared_ptr<TProtocol> protocol, std::shared_ptr<TTransport> transport)
    : MessengerClient(protocol)
{
    try {
        cout << "opening transport" << endl;
        transport->open();

        cout << "sending message 'Hello world' to the server" << endl;
        auto ret = sendMessage("Hello world"); 
        cout << "Got response from the server!\n" << ret << endl;

        transport->close();
  } catch (apache::thrift::TException& tx) {
      cerr << "ERROR: " << tx.what() << endl;
  }
}

std::string ClientImpl::sendMessage(const std::string& message)
{
    std::string output;
    MessengerClient::sendMessage(output, message);
    return output;
}