#include <iostream>
#include <iterator>

struct deleting_by_value {};

deleting_by_value dbv;

template <typename T>
class prime
{
private:
    T* arr;
    size_t size;

public:
    prime()
    {
        size = 0;
        arr = new T[size];
    }

    void add(const T& value)
    {
        T tmp[size];

        for(size_t i = 0; i < size; i++)
        {
            tmp[i] = arr[i];
        }

        delete[] arr;

        arr = new T[++size];

        for(size_t i = 0; i < size - 1; i++)
        {
            arr[i] = tmp[i];
        }

        arr[size - 1] = value;
    }

    void remove(size_t index)
    {
        if (size > 0 && index < size)
        {
            T tmp[--size];

            for (size_t i = 0; i < size + 1; i++)
            {
                if (i < index)
                {
                    tmp[i] = arr[i];
                }
                if (i > index)
                {
                    tmp[i - 1] = arr[i];
                }
            }

            delete[] arr;

            arr = new T[size];

            for(size_t i = 0; i < size; i++)
            {
                arr[i] = tmp[i];
            }
        }
    }

    void remove(const T& value, deleting_by_value& dbv)
    {
        int count;

        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                count++;
            }
        }

        size -= count;

        T tmp[size];
        int index = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                index++;
            }
            else
            {
                tmp[i] = arr[i + index];
            }
        }

        delete[] arr;

        arr = new T[size];

        for(size_t i = 0; i < size; i++)
        {
            arr[i] = tmp[i];
        }
    }

    void insert(const T& value, size_t index)
    {
        if (index >= 0 && index <= size)
        {
            T tmp[++size];

            for (size_t i = 0; i < size; i++)
            {
                if (i < index)
                {
                    tmp[i] = arr[i];
                }
                if (i > index)
                {
                    tmp[i] = arr[i - 1];
                }
            }

            tmp[index] = value;

            delete[] arr;

            arr = new T[size];

            for(size_t i = 0; i < size; i++)
            {
                arr[i] = tmp[i];
            }
        }
    }

    void reverse()
    {
        T tmp[size];

        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = arr[size - 1 - i];
        }

        delete[] arr;

        arr = new T[size];

        for(size_t i = 0; i < size; i++)
        {
            arr[i] = tmp[i];
        }
    }

    void splice(const prime& p)
    {
        T tmp[size + p.get_size()];

        for (size_t i = 0; i < size + p.get_size(); i++)
        {
            if (i < size)
            {

            }
            else
            {

            }
        }
    }

    bool contains(const T& value)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    void clear()
    {
        delete[] arr;
        size = 0;
        arr = new T[size];
    }

    bool empty()
    {
        if (size != 0)
        {
            return false;
        }
        return true;
    }

    T operator[](int index)
    {
        return arr[index];
    }

    size_t get_size()
    {
        return size;
    }

    T front()
    {
        return arr[0];
    }

    T back()
    {
        return arr[size - 1];
    }
};

int main()
{
    prime<int> p;
    p.add(14);
    p.add(22);
    p.add(6);
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    std::cout << "-------------------------" << "\n";

    p.insert(31415, 2);
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    std::cout << "-------------------------" << "\n";

    p.remove(0);
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    std::cout << "-------------------------" << "\n";

    p.reverse();
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    std::cout << "-------------------------" << "\n";

    p.remove(31415, dbv);
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    return 0;
}