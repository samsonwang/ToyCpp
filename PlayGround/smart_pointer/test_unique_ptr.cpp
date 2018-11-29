

// code from https://en.cppreference.com/w/cpp/memory/unique_ptr

#include <memory>
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <fstream>
#include <cassert>
#include <functional>

struct B {
    virtual void bar() { std::cout << "B::bar\n"; }
    virtual ~B() = default;
};
struct D : B {
    D() { std::cout << "D::D\n";  }
    ~D() { std::cout << "D::~D\n";  }
    void bar() override { std::cout << "D::bar\n";  }
};

void test1() {
    std::unique_ptr<int> pInt(new int(0));
    std::cout << *pInt << std::endl;
    *pInt = 10;
    std::cout << *pInt << std::endl;
}

void test2() {
    std::unique_ptr<int[]> pInt(new int[10]);
    for (int i = 0; i<10; ++i) {
        pInt[i] = i;
    }
    for (int i=0; i<10; ++i) {
        std::cout << pInt[i] << " ";
    }
    std::cout << std::endl;
}

void test3() {
    // no copyable
    std::unique_ptr<int> pInt = std::make_unique<int>(1);

    // this will get compile error
    // std::unique_ptr<int> pInt2 = pInt;
    auto pInt2 = std::move(pInt);

}

void test4() {
    // polymorphism is supported

}

void close_file(std::FILE* fp) { std::fclose(fp); }
void test5() {
    // custom deleter
    std::cout << "Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        std::unique_ptr<std::FILE, decltype(&close_file)> fp(std::fopen("demo.txt", "r"),
                                                             &close_file);
        if(fp) // fopen could have failed; in which case fp holds a null pointer
            std::cout << (char)std::fgetc(fp.get()) << '\n';
    } // fclose() called here, but only if FILE* is not a null pointer
    // (that is, if fopen succeeded)

    std::cout << "Custom lambda-expression deleter demo\n";
    {
        std::unique_ptr<int, std::function<void(int*)>> p(new int, [](int* ptr) {
            std::cout << "destroying from a custom deleter...\n";
            delete ptr;
        });  // p owns D
    } // the lambda above is called and D is destroyed

}

// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p) {
    p->bar();
    return p;
}

// unique ownership semantics demo
void test6() {
    auto p = std::make_unique<D>(); // p is a unique_ptr that owns a D
    auto q = pass_through(std::move(p));
    assert(!p); // now p owns nothing and holds a null pointer
    q->bar();   // and q owns the D object
}

int main(int argc, char* argv[]) {

    test1();

    test2();

    test3();

    test5();

    return 0;
}
