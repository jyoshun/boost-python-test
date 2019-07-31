// Expose a C++ class to Python
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

// A C++ class/struct that we want to expose to Python
struct World
{
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};

// A corresponding Boost.Python C++ Wrapper
BOOST_PYTHON_MODULE(exposing_classes)
{
    class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
        ;
}
