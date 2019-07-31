// make functions behave polymorphically through virtual functions
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

struct Base
{
    virtual ~Base() {}
    virtual int f() = 0;  // virtual function
};

// a class wrapper that derives from Base that will unintrusively hook into the virtual functions so that a Python override may be called
struct BaseWrap : Base, wrapper<Base>  // wrapper template makes the job of wrapping classes that are meant to overridden in Python, easier
{
    int f()
    {
        return this->get_override("f")();  // BaseWrap's overridden virtual member function f in effect calls the corresponding method of the Python object through get_override
    }
};

BOOST_PYTHON_MODULE(class_virtual_functions)
{
    class_<BaseWrap, boost::noncopyable>("Base")
        .def("f", pure_virtual(&Base::f));  // pure_virtual signals Boost.Python that the function f is a pure virtual function
}
