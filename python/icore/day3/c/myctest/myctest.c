#include <python.h>
#include <stdio.h>

int main()
{
    PyObject* module, *result;
    Py_Initialize();        // DLL memory loading

    module = PyImport_ImportModule("3_python2c");
    int a = 10, b = 20, my_sum = 4;
    result = PyObject_CallMethod(module, "c_sum", "ii", a, b);
    PyArg_Parse(result, "i", &my_sum);
    printf("%d + %d = %d\n", a, b, my_sum);

    PyObject* testobj;
    testobj = PyObject_CallMethod(module, "test", NULL);
    result = PyObject_CallMethod(testobj, "t_sum", "ii", a, b);
    PyArg_Parse(result, "i", &my_sum);
    printf("%d + %d = %d\n", a, b, my_sum);

    return 0;
}
