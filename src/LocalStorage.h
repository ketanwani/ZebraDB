#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Connection.h"
#include "IStorage.h"

namespace zebradb {
class LocalStorage: public IStorage {
private:
    Connection* m_connection;
    FILE* m_file;

public:
    LocalStorage(Connection *connection);

    virtual void init();

    virtual std::string read(std::streampos offset, int length);

    virtual void write(std::streampos offset, const std::string& payload);
};
}
