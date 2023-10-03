#pragma once
#include <stdio.h>
#include "StorageType.h"
#include "IStorage.h"
namespace zebradb {
class Connection;
class StorageFactory {
public:
    static IStorage* genStorage(StorageType type, Connection* conn);
};
}
