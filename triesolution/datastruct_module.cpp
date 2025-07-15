#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "include/trie.hpp"

static int datastruct_exec(PyObject *module) {
    // add Trie type here
    if (PyType_Ready(&PyTrieType) < 0)
        return -1;

    if (PyModule_AddObject(module, "Trie", (PyObject*)&PyTrieType) < 0)
        return -1;

    return 0;
}

static PyMethodDef module_methods[] = {
    { NULL, NULL } /* Sentinel */
};

static PyModuleDef_Slot module_slots[] = {
    { Py_mod_exec, (void*) datastruct_exec },
    { 0, NULL },
};

static struct PyModuleDef moduledef = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "datastruct",
    .m_doc = "This is datastruct's docstring",
    .m_size = 0,
    .m_methods = module_methods,
    .m_slots = module_slots,
};

PyMODINIT_FUNC PyInit_datastruct(void) {
    return PyModuleDef_Init(&moduledef);
}