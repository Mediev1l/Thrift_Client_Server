#include "ServerImpl.hpp"

#include <iostream>
#include <thrift/transport/TSocket.h>

using namespace std;
using namespace apache::thrift::transport;

ServerImpl::ServerImpl()
    : MessengerIf()
{

}

void ServerImpl::sendMessage(std::string& _return, const std::string& text)
{
    _return = "Response from server to message: " + text + '\n';
}

MessengerIf* ServerFactory::getHandler(const TConnectionInfo& connInfo)
{
    std::shared_ptr<TSocket> sock = std::dynamic_pointer_cast<TSocket>(connInfo.transport);


    //Info log
    cout << "Incoming connection\n";
    cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
    cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
    cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
    cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";

    return new ServerImpl;
}

void ServerFactory::releaseHandler(MessengerIf* handler)
{
    delete handler;
}