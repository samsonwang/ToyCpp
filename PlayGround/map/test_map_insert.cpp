
#include <map>
#include <iostream>
#include <utility>

int main(int argc, char* argv[]) {
    std::map<int, int> mapTest;
    mapTest[1] = 1;

    auto retPair = mapTest.insert(std::make_pair(1, 2));
    std::cout << retPair.second << std::endl;  // 0

    std::cout << mapTest[1] << std::endl; // 1

    return 0;
}
