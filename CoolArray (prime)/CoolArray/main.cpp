#include <iostream>
#include <list>

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
        int count = 0;

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
        for (size_t i = 0; i < size + count; i++)
        {
            if (arr[i] != value)
            {
                tmp[index] = arr[i];
                index++;
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

    void splice(const prime<T>& p)
    {
        T tmp[size + p.get_size()];

        for (size_t i = 0; i < size + p.get_size(); i++)
        {
            if (i < size)
            {
                tmp[i] = arr[i];
            }
            else
            {
                tmp[i] = p[i - p.get_size()];
            }
        }

        delete[] arr;

        size += p.get_size();

        arr = new T[size];

        for(size_t i = 0; i < size; i++)
        {
            arr[i] = tmp[i];
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

    T& operator [] (size_t index) const
    {
        return arr[index];
    }

    prime<T>& operator = (const prime<T>& p)
    {
        delete[] arr;

        size = p.get_size();
        arr = new T[size];

        for (size_t i = 0; i < size; i++)
        {
            arr[i] = p[i];
        }

        return *this;
    }

    std::list<T> to_list()
    {
        std::list<T> l;
        for (size_t i = 0; i < size; i++)
        {
            l.push_back(arr[i]);
        }
        return l;
    }

    size_t get_size() const
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

    prime<int> p2;
    p2.add(76258);
    p2.add(9087401);
    p2.add(33345666);

    p.splice(p2);
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    std::cout << "-------------------------" << "\n";

    p.remove(76258, dbv);
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    std::cout << "-------------------------" << "\n";

    prime<int> pp;
    pp.add(123456789);
    pp.add(987654321);
    p = pp;
    for (int i = 0; i < p.get_size(); i++)
    {
        std::cout << p[i] << "\n";
    }

    return 0;
}
