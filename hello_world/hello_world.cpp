// 当引入 #include <boost/python/xxx> 时，Boost 会默认链接 boost_python 动态链接库，
// 如果我们想要链接静态链接库，就需要在 include 之前加上 #define BOOST_PYTHON_STATIC_LIB
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

// A C++ Function
char const* greet()
{
    return "hello, world";
}

// Writing a Boost.Python wrapper
BOOST_PYTHON_MODULE(hello_world)  // Python Module
{
    using namespace boost::python;  // using namespace
    def("greet", greet);
}
