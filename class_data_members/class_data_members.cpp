// Expose data members
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

// Exposed data members regarded as read-only or read-write
struct Var
{
    Var(std::string name) : name(name), value() {}
    std::string const name;
    float value;
};

BOOST_PYTHON_MODULE(class_data_members)
{
    class_<Var>("Var", init<std::string>())
        .def_readonly("name", &Var::name)
        .def_readwrite("value", &Var::value);
}
