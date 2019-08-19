// When you want to wrap functions (or member functions) that either:
// 1. have default arguments, or
// 2. are overloaded with a common sequence of initial arguments
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
#include <sstream>
#include <string>

using namespace boost::python;

class Example
{
public:
    Example() {}
    void doit() { mS = "void"; }
    std::string doit(unsigned int i)
    {
        std::stringstream s;
        s << i;
        mS = s.str();
        return mS;
    }
    void doit(std::string s) { mS = s; }

    int makeIt(std::string s, int n = 1, std::string t = "")
    {
        std::stringstream u;
        for (unsigned int i = 0; i < n; i++)
            u << s;
        mS = u.str() + t;
        return n + (t.size() > 0 ? 1 : 0);
    }

    std::string print() const { return mS; }
private:
    std::string mS;
};

std::string foo(int a, char b = 1, unsigned c = 2, double d = 3)
{
    std::stringstream f;
    f << "foo(a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << ")";
    return f.str();
}

// function overloads
BOOST_PYTHON_FUNCTION_OVERLOADS(foo_overloads, foo, 1, 4)

// member function overloads
// 1, 3 means args amount in [1, 3]
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(makeIt_overloads, makeIt, 1, 3)

BOOST_PYTHON_MODULE(default_arguments)
{
    def("foo", foo, foo_overloads());

    void        (Example::*d1)()             = &Example::doit;
    std::string (Example::*d2)(unsigned int) = &Example::doit;
    void        (Example::*d3)(std::string)  = &Example::doit;

    class_<Example>("Example")
        .def("__str__", &Example::print)
        .def("doit", d1)
        .def("doit", d2)
        .def("doit", d3)
        .def("makeIt", &Example::makeIt, makeIt_overloads())
        ;
}

// original code from: https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/tutorial/functions.html#tutorial.functions.default_arguments
//// a function f with default arguments
//int f(int, double = 3.14, char const* = "hello");
//// write "thin wrappers"
//int f1(int x) { return x; }
//int f2(int x, double y) { return f(x, y); }
//
//BOOST_PYTHON_MODULE(default_arguments)
//{
//    // in module init
//    def("f", f);    // all arguments
//    def("f", f2);   // two arguments
//    def("f", f1);   // one argument
//}
