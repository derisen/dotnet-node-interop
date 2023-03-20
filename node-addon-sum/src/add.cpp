#include <windows.h>
#include <iostream>
#include <io.h>

#ifndef F_OK
#define F_OK 0
#endif

int addFunc(int firstInt, int secondInt, char *path)
{
    // Check if the library file exists
    if (_access(path, F_OK) == -1)
    {
        std::cout << "Couldn't find library at the specified path" << std::endl;
        std::cout << "The path is: " << path << std::endl;
        return 0;
    }

    // Call sum function defined in C# shared library
    HINSTANCE handle = LoadLibraryA(path);

    if (NULL == handle)
    {
        std::cout << "Couldn't find the handle" << std::endl;
        return 0;
    }

    typedef int (*myFunc)(int, int);

    myFunc MyImport = (myFunc)GetProcAddress(handle, "add");

    if (NULL == MyImport)
    {
        std::cout << "Couldn't set MyImport" << std::endl;
        return 0;
    }

    int result = MyImport(firstInt, secondInt);

    return result;
};
