// Expose class that encapsulation hide the class' data members
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

struct Num
{
    Num() {}
    float get() const { return value; }
    void set(float value) { this->value = value; }
    float value;
};

BOOST_PYTHON_MODULE(class_properties)
{
    class_<Num>("Num")
        .add_property("rovalue", &Num::get)  // class property rovalue is exposed as read-only
        .add_property("value", &Num::get, &Num::set);
}
