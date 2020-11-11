
#pragma once

class Singleton {
public:
    static Singleton& Instance();
    class Init;

public:
    void Foo();

private:
    Singleton();
    Singleton(const Singleton&) = delete;

private:
    friend Init;
    static Singleton* s_pObj;
};

class Singleton::Init {
public:
    Init();
    ~Init();

private:
    static unsigned s_count;
};

static Singleton::Init s_init;
