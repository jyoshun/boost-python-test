// Virtual Functions with Default Implementations
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

struct Base
{
    virtual ~Base() {}
    virtual int f() { return 0;  }
};

// default implementations
struct BaseWrap : Base, wrapper<Base>
{
    int f()
    {
        if (override f = this->get_override("f"))
            return f();  // *note*
        return Base::f();
    }
    int default_f() { return this->Base::f(); }
};

BOOST_PYTHON_MODULE(virtual_functions_with_default_implementations)
{
    class_<BaseWrap, boost::noncopyable>("Base")
        .def("f", &Base::f, &BaseWrap::default_f)
        ;
}
