// overloaded member functions
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

struct X
{
    bool f(int a)
    {
        return true;
    }
    bool f(int a, double b)
    {
        return true;
    }
    bool f(int a, double b, char c)
    {
        return true;
    }
    int f(int a, int b, int c)
    {
        return a + b + c;
    }
};

// Class X has 4 overloaded functions.
// We will start by introducing some member function pointer variables :
bool (X::*fx1)(int)               = &X::f;
bool (X::*fx2)(int, double)       = &X::f;
bool (X::*fx3)(int, double, char) = &X::f;
int  (X::*fx4)(int, int, int)     = &X::f;

BOOST_PYTHON_MODULE(overloading)
{
    class_<X>("X")
        .def("f", fx1)
        .def("f", fx2)
        .def("f", fx3)
        .def("f", fx4)
        ;
}
