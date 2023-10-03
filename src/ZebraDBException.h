#include <exception>
#include <string>
namespace zebradb {
class ZebraDBException : public std::exception {
public:
  ZebraDBException(const std::string& message) : message_(message) {}
private:
  std::string message_;
};
}