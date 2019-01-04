
#include <chrono>
#include <iostream>
#include <iomanip>

void test_1() {
    // calculate time span




}

int main() {
    std::cout << "Hello World" << std::endl;

    std::chrono::system_clock::time_point now
        = std::chrono::system_clock::now();

    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    //    std::time_t now_t = std::time(NULL);
    std::cout << "time_t now_c:" << now_c << std::endl;
    std::cout << std::put_time(std::localtime(&now_c), "%A %c") << std::endl;

    char tmstr[128];
    if (std::strftime(tmstr, sizeof(tmstr), "%A %c", std::localtime(&now_c))) {
        std::cout << "tmstr: " << tmstr << std::endl;
    }



    return 0;
}
