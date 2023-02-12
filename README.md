# unique_class_id
unique_class_id is a header-only C++ library that allows giving classes a unique ID and then comparing classes based on their unique IDs.

## Description
Unique class id library is a header-only library that allows classes to have unique IDs and then compare classes based on their unique IDs.

To use the library, simply include the header "unique_class_id.hpp" in your code.

An example of using the library is shown below:

```cpp
#include "unique_class_id.hpp"

class A {
    GENERATE_UNIQUE_CLASS_ID(A)
};

class B : public A {
    GENERATE_UNIQUE_CLASS_ID(B)
};

class Base {
public:
    virtual unique_class_id::class_id_t id() = 0;
};

class DerivedA : public Base {
    GENERATE_UNIQUE_CLASS_ID(DerivedA)
};

class DerivedB : public Base {
    GENERATE_UNIQUE_CLASS_ID(DerivedB)
};

int main() {
    A *a = new A();
    B *b = new B();

    if (unique_class_id::is_same_class<A>(b)) {
        std::cout << "Same class" << std::endl;
    } else {
        std::cout << "Different class" << std::endl;
    }

    Base *base_ptr = new DerivedA();
    unique_class_id::class_id_t base_id = base_ptr->id();
    unique_class_id::class_id_t derived_a_id = DerivedA().id();
    unique_class_id::class_id_t derived_b_id = DerivedB().id();
    if (base_id == derived_a_id) {
        std::cout << "Base pointer is pointing to DerivedA\n";
    } else 
    if (base_id == derived_b_id) {
        std::cout << "Base pointer is pointing to DerivedB\n";
    }

    return 0;
}
```
