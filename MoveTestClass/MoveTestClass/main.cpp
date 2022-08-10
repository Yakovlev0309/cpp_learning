#include <iostream>
#include <vector>

using ldouble = double;

struct Test
{
    ldouble x;
    ldouble y;
    std::vector<int> z;

    //Constructor
    Test() : x(0), y(0), z({}) {}

    //Move constructor
    Test(Test&& t) : x(t.x), y(t.y), z(std::move(t.z))
    {
        Swap(t);
        Clear(t);
    }

    //Move assignment operator
    Test& operator = (Test&& t)
    {
        Clear(*this);
        Swap(t);
        return *this;
    }

    void Swap(Test& t)
    {
        std::swap(x, t.x);
        std::swap(y, t.y);
        z.swap(t.z);
    }

    void Clear(Test& t)
    {
        t.x = 0;
        t.y = 0;
        t.z = {};
    }

    ~Test() = default;
};

int main()
{
    Test _1;
    _1.x = 4;
    _1.z.push_back(15.53);
    Test _2;

    std::cout << "Before moving" << "\n";
    std::cout << _1.x << "\n";
    std::cout << _2.x << "\n";

    _2 = std::move(_1);

    std::cout << "After moving" << "\n";
    std::cout << _1.x << "\n";
    std::cout << _2.x << "\n";

    if (_1.z.empty())
    {
        std::cout << "Old vector is empty" << "\n";
        std::cout << _2.z[0] << "\n";
    }

    return 0;
}
