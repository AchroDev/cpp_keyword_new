#include <iostream>
#include <string>

using String = std::string;

// "new" keyword in C++
// The new keyword does two things, it allocates memory and it calls the constructor

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
    int *a2 = new int;    // single 4byte int stored on the heap
    int *b = new int[50]; // designating 200 bytes by using a size 50 array

    Entity *e = new Entity();                     // new heap allocation using the Entity
    Entity *e = (Entity *)malloc(sizeof(Entity)); // This line of code is essentially doing the same thing as the above line, except it doesn't call the constructor

    // Placement new example, calling the constructor and initializing the Entity in a specific memory address
    Entity *p = new (b) Entity();

    delete a2;
    free(a2);   // Like above with 'malloc', delete calls the C function free() to free the memory. Except it doesn't call the deconstructor
    delete[] b; // If you call a "new" instance with [] then you must delete with the brackets as well.
    delete e;

    std::cin.get();
}
