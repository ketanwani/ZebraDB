#pragma once
#include <stdio.h>
#include <fstream>
namespace zebradb {
class IStorage {
public:
    virtual void init() = 0;
    virtual std::string read(std::streampos offset, int length) = 0;
    virtual void write(std::streampos offset, const std::string& payload) = 0;
};
}
