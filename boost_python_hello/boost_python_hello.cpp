#include <boost/python.hpp>
#include <iostream>

using namespace std;
using namespace boost::python;

#if PY_MAJOR_VERSION >= 3
#   define INIT_MODULE PyInit_mymodule
extern "C" PyObject* INIT_MODULE();
#else
#   define INIT_MODULE initmymodule
extern "C" void INIT_MODULE();
#endif

char const* fun_from_cpp()
{
    return "fun_from_cpp";
}

int add_from_cpp(int a, int b)
{
    return (a + b);
}

int main(int argc, char** argv)
{
    try
    {
        Py_Initialize();

        object main_module = import("__main__");
        object main_namespace = main_module.attr("__dict__");

        main_namespace["fun_from_cpp"] = fun_from_cpp;
        main_namespace["add_from_cpp"] = add_from_cpp;

        object ignored1 = exec_file("boost_python_hello.py", main_namespace, main_namespace);

        object ignored2 = exec("show_py()", main_namespace);
        object ignored3 = exec("add_py_show(9, 8)", main_namespace);
        //object ignored4 = exec("result = 5 ** 2", main_namespace);

        int five_squared = extract<int>(main_namespace["result"]);

        cout << "result from main_namespace is : " << five_squared << endl;
    }
    catch (error_already_set& e)
    {
        PyErr_PrintEx(0);
        return 1;
    }

    return 0;
}
