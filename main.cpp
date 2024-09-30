#include <iostream>
#include <string>

using String = std::string;

// The "new" keyword in C++

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}
    Entity(const String &name) : m_Name(name) {}

    const String &GetName() const { return m_Name; }
};

int main()
{
    int a = 2;            // stored on the stack
    int *a = new int;     // single 4byte int stored on the heap
    int *b = new int[50]; // designating 200 bytes by using a size 50 array

    Entity *e = new Entity[50]; // new heap allocation using the Entity

    std::cin.get();
}
