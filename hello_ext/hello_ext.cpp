// ������ #include <boost/python/xxx> ʱ��Boost ��Ĭ������ boost_python ��̬���ӿ⣬
// ���������Ҫ���Ӿ�̬���ӿ⣬����Ҫ�� include ֮ǰ���� #define BOOST_PYTHON_STATIC_LIB
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
#include <iostream>
#include <stdio.h>

// C++ Code
char const* greet()
{
    return "hello, world";
}

BOOST_PYTHON_MODULE(hello_ext)  // Python ģ�鿪ʼ
{
    using namespace boost::python;  // �������ռ�
    def("greet", greet);
}
