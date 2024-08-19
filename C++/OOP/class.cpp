#include <iostream>
#include <vector>
#include <memory>

class AllCtors
{
    AllCtors();                                         // default constructor
    AllCtors(int x);                                    // param
    AllCtors(const AllCtors &src);                      // copy
    AllCtors &operator=(const AllCtors &rhs);           // copy operator =
    AllCtors &operator=(const AllCtors &&rhs) noexcept; // move =
    AllCtors(const AllCtors &&src) noexcept;            // move ctor
    AllCtors(std::initializer_list<int> args);          // init list
    ~AllCtors();
};

class tmp
{
public:
    tmp(int d)
    {
        std::cout << "TMP CTOR " << d << std::endl;
    };
    tmp(const tmp &src) = default;
};

class Point
{

public:
    Point() : _x(6), arsen{1}, _y(11), _z(22)
    {
        std::cout << "POINT CTOR" << std::endl;
    };
    // Point& operator=(const Point& rhs)= delete;

    Point(const Point &src) = default;
    Point(int x, int y = 20, int z = 30) : arsen{1}, _x{x}, _y{y}, _z{z}
    {
        std::cout << "ctor id:" << _x << std::endl;
    }
    Point(std::initializer_list<int> args) : arsen{1}
    {
        if (args.size() % 2)
        {
            throw std::invalid_argument("ars");
        }
        vectorName.assign((args));
    }
    ~Point()
    {
        std::cout << "dest id:" << _x << std::endl;
    }
    auto getPoint()
    {
        struct tmp
        {
            int x;
            int y;
            int z;
        };
        struct tmp cordinates
        {
            _x, _y, _z
        };

        return cordinates;
    }
    int getX() { return _x; }

    void dump() const
    {
        for (const auto &val : vectorName)
        {
            std::cout << val << std::endl;
        }
    }

private:
    int _x;
    tmp arsen;
    int _y, _z;
    std::vector<int> vectorName;
};

void printMessage(const std::string &src)
{
    std::cout << src << std::endl;
}

void printMessage(std::string &&src)
{
    std::cout << src << std::endl;
}


class unc {
    public:
        unc();
    
    private:
        unc(const unc&);
        unc& operator=(const unc&);
};

class cosnttest  {
    public:
        cosnttest();
        ~cosnttest();

    private:
        int age;
};

int main()
{
    cosnttest obj;
    cosnttest asd;

    obj = asd;

    // try
    // {
    //     Point obj(1);
    //     Point obj2(2);
    //     obj = obj2;
    //     Point obj3(obj);
    //     // obj.dump();
    // }
    // catch (const std::invalid_argument &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // try
    // {
    //     std::string h{"esiiim"};
    //     printMessage(h);
    // }
    // catch (std::invalid_argument &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // Point obj2(obj);
    // Point point {};
    // auto ptr {std::make_unique<Point>(120, 20, 40)};
    // Point *ptr{new Point{}};
    // auto cordinates = point.getPoint();

    //    std::cout << ptr->getX() << std ::endl;
    // delete ptr;
    // ptr = nullptr;
}