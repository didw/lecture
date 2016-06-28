#include "python.h" 
// ctrl + shift + b
static PyObject * 
extest_strlen(PyObject *self, PyObject *args)
{
    const char* str=NULL;
    int len; 
    if (!PyArg_ParseTuple(args, "s", &str)) // �Ű����� ���� �м��ϰ� ���������� �Ҵ� ��ŵ�ϴ�.
         return NULL; 
    len = strlen(str); 
    return Py_BuildValue("i", len);  //python type conversion..
}

static PyMethodDef extestMethods[] = {
{"strlen", extest_strlen, METH_VARARGS,
 "count a string length."},
 {NULL, NULL, 0, NULL} // �迭�� ���� ��Ÿ���ϴ�.
}; 


static struct PyModuleDef extestmodule = {
    PyModuleDef_HEAD_INIT,
    "extest",            // ��� �̸�
    "It is test module.", // ��� ������ ���� �κ�, ����� __doc__�� ����˴ϴ�.
    -1,extestMethods
};

PyMODINIT_FUNC
PyInit_extest(void)
{
    return PyModule_Create(&extestmodule);
}




