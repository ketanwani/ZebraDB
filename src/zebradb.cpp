#include <iostream>
#include "Connection.h"
#include "StorageFactory.h"
using namespace zebradb;
int main() {    
    Connection* conn = new Connection("local disk");
    IStorage* storage  = StorageFactory::genStorage(StorageType::LOCAL_STORAGE, conn);
    storage->init();
    storage->write(0, "Hello World");    
    std::cout << conn->get_name();
}
