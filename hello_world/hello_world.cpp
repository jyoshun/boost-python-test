// ������ #include <boost/python/xxx> ʱ��Boost ��Ĭ������ boost_python ��̬���ӿ⣬
// ���������Ҫ���Ӿ�̬���ӿ⣬����Ҫ�� include ֮ǰ���� #define BOOST_PYTHON_STATIC_LIB
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
