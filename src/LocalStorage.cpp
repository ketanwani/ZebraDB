#include "LocalStorage.h"
#include "ZebraDBException.h"
#include <filesystem>
using namespace zebradb;
LocalStorage::LocalStorage(Connection* connection) {
    this->m_connection = connection;
}

void LocalStorage::init() {    
    this->m_file = fopen("example.txt", "w+");  // Open for reading
    if(this->m_file == NULL) {
        throw new ZebraDBException("Error in opening file.");
    }
}

std::string LocalStorage::read(std::streampos offset, int length) {

    // Set the file's get pointer to the specified offset
    if (fseek(this->m_file, offset, SEEK_SET)) {
        throw new ZebraDBException("Error seeking to the specified position.");
    }

    // Read the specified length of data
    std::string data(length, '\0');
    fgets(&data[0], length, this->m_file);
    return data;
}

// Write data to the file starting at the specified offset.
void LocalStorage::write(std::streampos offset, const std::string& payload) {
    // Set the file's put pointer to the specified offset
    if (fseek(this->m_file, offset, SEEK_SET)) {
        throw new ZebraDBException("Error seeking to the specified position.");
    }

    // Write the payload to the file
    size_t bytesWritten = fwrite(&payload[0], sizeof(char), payload.length(), this->m_file);

    if (bytesWritten != payload.length()) {
        throw new ZebraDBException("Error writing data to the file");
    }
}
