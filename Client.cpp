#include "ClientImpl.hpp"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main()
{
    std::shared_ptr<TTransport> socket(new TSocket("localhost", 9099));
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    
    ClientImpl x(protocol, transport);

    return 0;
}