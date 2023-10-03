#define once
#include <string>
using namespace std;
namespace zebradb {
class Connection {
    private:
    std::string m_name;
    public:
    Connection(string name) {
        this->m_name = name;
    }
    std::string get_name();
};
}