// Expose additional constructors
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

// A C++ class/struct that we want to expose to Python
struct World
{
    World(std::string msg) : msg(msg) {}  // added constructor
    World(double x, double y) {}  // additional constructor
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};

// A corresponding Boost.Python C++ Wrapper
BOOST_PYTHON_MODULE(constructors)
{
    //class_<World>("World", no_init)  // do not expose any constructors by use no_init instead
    class_<World>("World", init<std::string>())  // expose one constructor
        .def(init<double, double>())  // expose additional constructors by passing more init<...>s
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
}
