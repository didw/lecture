#include "python.h" 

// ctrl + shift + b
static PyObject *
extest_strlen(PyObject *self, PyObject *args)
{
  const char* str = NULL;
  int len;
  if (!PyArg_ParseTuple(args, "s", &str)) // �Ű����� ���� �м��ϰ� ���������� �Ҵ� ��ŵ�ϴ�.
    return NULL;
  len = strlen(str);
  return Py_BuildValue("i", len);  //python type conversion..
}

static PyObject *
extest_hap(PyObject *self, PyObject *args)
{
  int a;
  int b;
  int result;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) // �Ű����� ���� �м��ϰ� ���������� �Ҵ� ��ŵ�ϴ�.
    return NULL;

  result = a + b;
  return Py_BuildValue("i", result);  //python type conversion..
}

static PyObject *
extest_divide(PyObject *self, PyObject *args)
{
  int a;
  int b;
  double result;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) // �Ű����� ���� �м��ϰ� ���������� �Ҵ� ��ŵ�ϴ�.
    return NULL;

  if (!b) {
    PyErr_SetString(PyExc_Exception, "divided by zero");
    return NULL;
  }

  result = (double)a / b;
  return Py_BuildValue("d", result);  //python type conversion..
}

static PyObject *
extest_shape(PyObject *self, PyObject *args)
{
  float r;
  int h;
  int w;
  double circle;
  int rect;
  if (!PyArg_ParseTuple(args, "fii", &r, &h, &w)) // �Ű����� ���� �м��ϰ� ���������� �Ҵ� ��ŵ�ϴ�.
    return NULL;

  circle = r*r*3.14;
  rect = h*w;
  return Py_BuildValue("(d,i)", circle, rect);  //python type conversion..
}

struct Test
{
  int aa;
  int bb;
  char* cc;
};


static PyObject *
extest_sfn(PyObject *self, PyObject *args)
{
  struct Test* p;

  if (!PyArg_ParseTuple(args, "l", &p))
    return NULL;

  printf("aa=%d,bb=%d,cc=%s\n", p->aa, p->bb, p->cc);
  p->aa = 200;
  p->bb = 300;

  return Py_BuildValue("(i,i)", p->aa, p->bb);
}


static PyMethodDef extestMethods[] = {
  { "strlen", extest_strlen, METH_VARARGS,
  "count a string length." },
  { "hap", extest_hap, METH_VARARGS,
  "sum ...." },
  { "divide", extest_divide, METH_VARARGS,
  "sum ...." },
  { "shape", extest_shape, METH_VARARGS,
  "sum ...." },
  { "sfn", extest_sfn, METH_VARARGS,
  "sum ...." },
  { NULL, NULL, 0, NULL } // �迭�� ���� ��Ÿ���ϴ�.
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




