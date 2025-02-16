#include <Python.h>


static PyObject *method_hello(PyObject *self, PyObject *args){
    char *myString=NULL;
    if(!PyArg_ParseTuple(args,"s",&myString)){
        return NULL;
    }
    printf(" Hello ! ,");
    printf("%s",myString);
    printf("\n");
    Py_RETURN_NONE;
}

static PyMethodDef helloMethod[]={
    {"hello", method_hello,METH_VARARGS, "Python interface for print hello args function"},
    {NULL,NULL,0,NULL}};

static struct PyModuleDef helloModule= {
    PyModuleDef_HEAD_INIT,
    "hello",
    "Python interface for print hello args function",
    -1,
    helloMethod
    };

PyMODINIT_FUNC PyInit_hello(void) {
    return PyModule_Create(&helloModule);
}

