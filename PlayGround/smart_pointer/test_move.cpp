
// from: https://en.cppreference.com/w/cpp/utility/move

#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main() {
    std::string str = "Hello";
    std::vector<std::string> v;

    // uses the push_back(const T&) overload, which means
    // we'll incur the cost of copying str
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";

    // uses the rvalue reference push_back(T&&) overload,
    // which means no strings will be copied; instead, the contents
    // of str will be moved into the vector.  This is less
    // expensive, but also means str might now be empty.
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";

    std::cout << "The contents of the vector are \"" << v[0]
              << "\", \"" << v[1] << "\"\n";

    // the value of v will be unspecified
    // no self assignment check
    v = std::move(v);
    std::cout << "v.size() = " << v.size() << std::endl;
    // P.S. the result is very interesting:
    // vs2015 says v.size() is 2
    // gcc 5.3.0 say v.size() is 0

    return 0;
}
