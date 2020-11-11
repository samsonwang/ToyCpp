
#include "singleton.h"
#include <cstdio>

Singleton* Singleton::s_pObj = nullptr;
unsigned Singleton::Init::s_count = 0;

Singleton& Singleton::Instance() {
    return *s_pObj;
}

Singleton::Singleton() {
    printf("Singleton::Singleton\n");
}

void Singleton::Foo() {
    printf("Singleton::Foo\n");
}

Singleton::Init::Init() {
    if (s_count++ == 0) {
        Singleton::s_pObj = new Singleton;
    }
}

Singleton::Init::~Init() {
    if (--s_count == 0) {
        delete Singleton::s_pObj;
    }
}
