#define Py_LIMITED_API
#include <Python.h>

PyObject * sum(PyObject *, PyObject *);
PyObject * minus(PyObject *, PyObject *);
PyObject * sumof3(PyObject *, PyObject *, PyObject *);

// Workaround missing variadic function support
// https://github.com/golang/go/issues/975
int PyArg_ParseTuple_LL(PyObject * args, long long * a, long long * b) {  
    return PyArg_ParseTuple(args, "LL", a, b);
}

int PyArg_ParseTuple_LL3(PyObject * args, long long * a, long long * b, long long * c) {  
    return PyArg_ParseTuple(args, "LLL", a, b, c);
}

static PyMethodDef FooMethods[] = {  
    {"sum", sum, METH_VARARGS, "Add two numbers."},
    {"sumof3", sumof3, METH_VARARGS, "Add three numbers."},
    {"minus", minus, METH_VARARGS, "Subtract two numbers."},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef foomodule = {  
   PyModuleDef_HEAD_INIT, "foo", NULL, -1, FooMethods
};

PyMODINIT_FUNC  
PyInit_foo(void)  
{
    return PyModule_Create(&foomodule);
}
