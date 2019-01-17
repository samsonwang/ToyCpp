
#include <ostream>
#include <vector>

template<class T>
std::ostream& operator<< (std::ostream& os,
                          const std::vector<T>& vec) {
    for (const auto& i : vec) {
        os << i << " ";
    }
    return os;
}
