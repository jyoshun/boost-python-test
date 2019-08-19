// Python has a few more Special Methods.
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
#include <sstream>
#include <string>

using namespace boost::python;

// a number like class
class NumberLike
{
public:
    NumberLike(int value = 0) : value(value) {}
    NumberLike& operator+=(int i)
    {
        value += 1;
        return *this;
    }
    std::string str() const
    {
        std::stringstream s;
        s << value;
        return s.str();
    }
    std::string repr() const
    {
        std::stringstream s;
        s << "NumberLike(" << value << ")";
        return s.str();
    }
private:
    int value;
};

NumberLike operator+(NumberLike n, int i)
{
    n += i;
    return n;
};

BOOST_PYTHON_MODULE(special_methods)
{
    class_<NumberLike>("NumberLike")
        .def(init<optional<int>>())             // __init__
        .def(self + int())                      // __add__
        .def("__str__", &NumberLike::str)       // __str__
        .def("__repr__", &NumberLike::repr)     // __repr__
        ;
};


// original code from: https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/tutorial/exposing.html#tutorial.exposing.class_operators_special_function.special_methods
//class Rational
//{
//public: operator double() const;
//};
//
//Rational pow(Rational, Rational);
//Rational abs(Rational);
//ostream& operator<<(ostream&, Rational);
//
//BOOST_PYTHON_MODULE(special_methods)
//{
//    class_<Rational>("Rational")
//        .def(float_(self))                    // __float__
//        .def(pow(self, other<Rational>))      // __pow__
//        .def(abs(self))                       // __abs__
//        .def(str(self))                       // __str__
//        ;
//};
