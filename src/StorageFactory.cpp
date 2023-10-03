#include "StorageFactory.h"
#include "LocalStorage.h"

using namespace zebradb;

IStorage* StorageFactory::genStorage(StorageType type, Connection* conn) {
    if(type == StorageType::LOCAL_STORAGE) {
        return new LocalStorage(conn);
    }
    return NULL;
}
