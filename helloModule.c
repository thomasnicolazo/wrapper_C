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

static PyObject *method_helloMult(PyObject *self, PyObject *args) {
    Py_ssize_t num_args = PyTuple_Size(args);  // Get number of arguments
    Py_ssize_t i;

    printf("Hello! ");

    for (i = 0; i < num_args; i++) {
        PyObject *arg = PyTuple_GetItem(args, i);  // Get argument at index i

        if (PyUnicode_Check(arg)) {  // Ensure it's a string
            printf("%s", PyUnicode_AsUTF8(arg));
        } else {
            printf("[Non-string argument]");
        }

        if (i < num_args - 1) {
            printf(", ");  // Add comma between arguments
        }
    }

    printf("\n");
    Py_RETURN_NONE;
}
static PyMethodDef helloMethod[]={
    {"hello", method_hello,METH_VARARGS, "Python interface for print hello 1 arg function"},
    {"helloMult", method_helloMult,METH_VARARGS, "Python interface for print hello n args function"},
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

