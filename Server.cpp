#include "ServerImpl.hpp"

#include <iostream>

#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TTransportUtils.h>

using namespace std;
using namespace apache::thrift::server;
using namespace apache::thrift::transport;

int main() {
  TThreadedServer server(
    std::make_shared<MessengerProcessorFactory>(std::make_shared<ServerFactory>()),
    std::make_shared<TServerSocket>(9099),
    std::make_shared<TBufferedTransportFactory>(),
    std::make_shared<TBinaryProtocolFactory>());


  cout << "Starting the server..." << endl;
  server.serve();
  cout << "Done." << endl;

  return 0;
}
