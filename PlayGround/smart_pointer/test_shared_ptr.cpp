
// code from https://en.cppreference.com/w/cpp/memory/shared_ptr

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

struct Base
{
    Base() { std::cout << "  Base::Base()\n"; }
    // Note: non-virtual destructor is OK here
    ~Base() { std::cout << "  Base::~Base()\n"; }
};

struct Derived: public Base
{
    Derived() { std::cout << "  Derived::Derived()\n"; }
    ~Derived() { std::cout << "  Derived::~Derived()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
    std::cout << "before sleep in a thread:\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << "\n\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p; // thread-safe, even though the
    // shared use_count is incremented
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << "  lp.get() = " << lp.get()
                  << ", lp.use_count() = " << lp.use_count() << "\n\n";
    }
}

int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();

    std::cout << "Created a shared Derived (as a pointer to Base)\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << "\n\n";

    std::thread t1(thr, p);
    //    std::treadn t2(thr, p);
    //    std::thread t3(thr, p);

    std::cout << "Before reset from main:\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << "\n\n";

    //p.reset(); // release ownership from main
    std::cout << "Shared ownership between 3 threads and released\n"
              << "ownership from main:\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << "\n\n";

    t1.join();
    //    t2.join();
    //    t3.join();

    std::cout << "Shared ownership between 3 threads and released\n"
              << "after thread joined,  from main:\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << "\n\n";


    std::cout << "All threads completed, the last one deleted Derived\n";
}
