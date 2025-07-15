#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "include/pycounter.hpp"

static int hello_exec(PyObject *module) {
    // add Counter
    if (PyType_Ready(&PyCounterType) < 0)
        return -1;
    
    if (PyModule_AddObject(module, "Counter", (PyObject *) &PyCounterType) < 0) {
        return -1;
    }

    return 0;
}

PyDoc_STRVAR(bad_fun_doc, "bad_fun function documentation");

PyObject* bad_fun(PyObject *self, PyObject *args) {
    PyErr_SetString(PyExc_NotImplementedError, "Not implemented, yet :)");
    return NULL;
}

static PyMethodDef module_methods[] = {
    { "bad_fun", (PyCFunction) bad_fun, METH_VARARGS, bad_fun_doc },
    { NULL, NULL } /* Sentinel */
};

static PyModuleDef_Slot module_slots[] = {
    { Py_mod_exec, (void*) hello_exec },
    { 0, NULL },
};

static struct PyModuleDef moduledef = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "hello",
    .m_doc = "This is hello's docstring",
    .m_size = 0,
    .m_methods = module_methods,
    .m_slots = module_slots,
};

PyMODINIT_FUNC PyInit_hello(void) {
    return PyModuleDef_Init(&moduledef);
}