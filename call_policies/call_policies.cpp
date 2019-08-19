// Call Policies
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
#include <sstream>
#include <string>

using namespace boost::python;

// f is called passing in a reference to y and a pointer to z
class Example
{
    Example(std::string n) : mName(n) {}
    std::string mName;
public:
    std::string name() const { return mName; }
    static Example* factory()
    {
        return new Example("factory");
    }
    static Example* singleton()
    {
        static Example instance = Example("singleton");
        return &instance;
    }
};

BOOST_PYTHON_MODULE(call_policies)
{
    class_<Example>("Example", no_init)
        .def("__str__", &Example::name)
        .def("factory", &Example::factory, return_value_policy<manage_new_object>())
        .staticmethod("factory")
        .def("singleton", &Example::singleton, return_value_policy<reference_existing_object>())
        .staticmethod("singleton")
        ;
}
