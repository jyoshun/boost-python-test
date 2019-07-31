# Boost Python Learn Note

## 1. Install Boost C++ Library in Windows

1. Download Boost from [https://www.boost.org/users/history/version_1_68_0.html](https://www.boost.org/users/history/version_1_68_0.html).

2. Extract 7z/zip file to your boost path, such as `C:\Program Files\boost\`.

3. Execute boostrap.bat:

   ```bash
   .\bootstrap.bat
   ```

4. (optional) Copy file `user-config.jam` from `tools\build\example\` to extract path. Edit it such as:

   ```jam
   using python
   : 3.7 # version
   : C:\\ProgramData\\Anaconda3\\python.exe # Interperter/path to dir
   : C:\\ProgramData\\Anaconda3\\include # includes
   : C:\\ProgramData\\Anaconda3\\libs # libs
   : <address-model>64 # conditions
   ;
   ```

5. Execute b2 command:

   ```bash
   .\b2
   ```

   Execute with config argments such as:

   ```bash
   .\b2 toolset=msvc-14.0 --with-python variant=debug runtime-debugging=on stage --stagedir="./bin/lib32-msvc-14.0" link=static --user-config=user-config.jam address-model=64
   ```


## 2. Coding with Visual Studio 2017

1. Create a C++ Empty Solution and a C++ Empty Project.

2. Add a C++ file(.cpp) such as `hello_ext.cpp`.

   ```C++
   // 当引入 #include <boost/python/xxx> 时，Boost 会默认链接 boost_python 动态链接库，
   // 如果我们想要链接静态链接库，就需要在 include 之前加上 #define BOOST_PYTHON_STATIC_LIB
   #define BOOST_PYTHON_STATIC_LIB
   
   #include <boost/python.hpp>
   #include <iostream>
   #include <stdio.h>
   
   // C++ Code
   char const* greet()
   {
       return "hello, world";
   }
   
   BOOST_PYTHON_MODULE(hello_ext)  // Python 模块开始，与文件名一致
   {
       using namespace boost::python;  // 打开命名空间
       def("greet", greet);
   }
   ```

3. Edit Project Properties:
   1. Properties --> C/C++ --> General --> Additional Include Directories :  Add boost root directory path, such as `C:\Program Files\boost\boost_1_68_0`, and Python include directory path, such as `C:\ProgramData\Anaconda3\include`.
   2. Properties --> Linker --> General --> Additional Library Directories :  Add boost lib directory path, such as `C:\Program Files\boost\boost_1_68_0\stage\lib`， and Python lib directory path, such as `C:\ProgramData\Anaconda3\libs`.
   3. Properties --> Linker --> Input --> Additional Dependencies :  Add boost lib file, such as `C:\Program Files\boost\boost_1_68_0\stage\lib\lib**.lib`.
4. Properties --> Configuration Properties --> General --> Project Defaults :  Set `Configuration Type` as `Dynamic Library(.dll)`, `Filename Extension` as `.pyd`.
   
4. Build the project.

## 3. Python Scripts

1. Create a python script such as `hello.py`:

   ```python
   import hello_ext
   print(hello_ext.greet())
   ```

2. Copy `hello_ext.pyd` to the same directory (from builded project).

3. Run it.

   ```bash
   >>> hello, world
   ```

## Problems & Solutions

1. **Problem:** error C3861: 'unwind_type': identifier not found.

   **Solution:** Enable forward declaration of unwind_type() in msvc14.15 and later. Use [this file](https://github.com/boostorg/python/commit/0d0cd711a764a3b32d2cd19a1049eb9f36b4fd06) to replace the old `unwind_type.hpp` file.

## References

[C++与Python混合编程：Boost.python的安装与使用](https://www.jianshu.com/p/5ccf00a6ca28)

