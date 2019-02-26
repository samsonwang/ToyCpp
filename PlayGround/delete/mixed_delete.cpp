#include <iostream>
class Sample
{
    int * m_ptr;
public:
    Sample()
        {
            std::cout<<"Sample::Constructor\n";
            m_ptr = new int();
        }
    ~Sample() nothrow
        {
            std::cout<<"Sample::Destructor\n";
            delete m_ptr;
            m_ptr = NULL;
        }
};
int main()
{
    Sample * ptrArr = new Sample[5];
    // Calling delete on pointer that contains
    // memory allocated by new[] will cause only
    // one destructor, remaining 4 destructors
    // will not be called, hence memory leak.
    delete ptrArr;
    return 0;
}
