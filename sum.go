package main

// #cgo pkg-config: python3
// #define Py_LIMITED_API
// #include <Python.h>
// int PyArg_ParseTuple_LL(PyObject *, long long *, long long *);
// int PyArg_ParseTuple_LLL(PyObject *, long long *, long long *, long long *);
import "C"

//export sum
func sum(self, args *C.PyObject) *C.PyObject {  
    var a, b C.longlong
    if C.PyArg_ParseTuple_LL(args, &a, &b) == 0 {
        return nil
    }
    return C.PyLong_FromLongLong(a + b)
}


//export minus
func minus(self, args *C.PyObject) *C.PyObject {  
    var a, b C.longlong
    if C.PyArg_ParseTuple_LL(args, &a, &b) == 0 {
        return nil
    }
    return C.PyLong_FromLongLong(a - b)
}

//export sumof3
func sumof3(self, args *C.PyObject) *C.PyObject {  
    var a, b, c C.longlong
    if C.PyArg_ParseTuple_LLL(args, &a, &b, &c) == 0 {
        return nil
    }
    return C.PyLong_FromLongLong(a + b + c)
}

func main() {}  
