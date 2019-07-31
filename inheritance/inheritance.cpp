// Expose classes that are derived from abstract base classes
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

struct Base { virtual ~Base() {} };

struct Derived : Base {};

void b(Base *b) {}

void d(Derived *d) {}

Base* factory() { return new Derived; }

BOOST_PYTHON_MODULE(inheritance)
{
    class_<Base>("Base");
    class_<Derived, bases<Base> >("Derived");
    def("b", b);
    def("d", d);
    def("factory", factory, return_value_policy<manage_new_object>());  // use return_value_policy<manage_new_object> to instruct Python to adopt the pointer to Base and hold the instance in a new Python Base object until the the Python object is destroyed
}
