#ifndef Py_COUNTER_HPP
#define Py_COUNTER_HPP

#define PY_SSIZE_T_CLEAN
#include <Python.h>

const char* COUNTER_DOC = "A simple integer counter.";
const char* GET_DOC = "Return the current counter value.";
const char* INCR_DOC = "Increment the counter by 1.";

// Define a Python object
typedef struct {
    PyObject_HEAD
    int value;
    int factor;
} PyCounter;

// Constructor of Counter
static int PyCounter_init(PyCounter* self, PyObject* args, PyObject* kwds) {
    static char* kwlist[] = {"value", "factor", nullptr};
    int value = 0;
    int factor = 1;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|ii", kwlist, &value, &factor))
        return -1;
    // or without kwds: PyArg_ParseTuple(args, "|ii", &initial, &factor)

    self->value = value;
    self->factor = factor;

    return 0;
}

// Destructor of Counter
void PyCounter_dealloc(PyCounter *self) {
    PyTypeObject *tp = Py_TYPE(self);
    tp->tp_free(self);
    
    // free the internal state if needed!
    
    Py_DECREF(tp);
}

static PyObject* PyCounter_get(PyCounter* self, PyObject* Py_UNUSED(ignored)) {
    return PyLong_FromLong(self->value);
}

static PyObject* PyCounter_incr(PyCounter* self, PyObject* Py_UNUSED(ignored)) {
    self->value += self->factor;
    Py_RETURN_NONE;
}

PyObject* PyCounter_str(PyCounter* self) {
    return PyUnicode_FromFormat("Counter(value=%d)", self->value);
}

static PyMethodDef PyCounter_methods[] = {
    { "get", (PyCFunction)PyCounter_get, METH_NOARGS, GET_DOC },
    { "incr", (PyCFunction)PyCounter_incr, METH_NOARGS, INCR_DOC },
    { nullptr, nullptr, 0, nullptr }
};

static PyTypeObject PyCounterType = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    .tp_name = "hello.Counter",
    .tp_basicsize = sizeof(PyCounter),
    .tp_itemsize = 0,
    .tp_dealloc = (destructor) PyCounter_dealloc,
    .tp_str = (reprfunc)PyCounter_str,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = COUNTER_DOC,
    .tp_methods = PyCounter_methods,
    .tp_init = (initproc)PyCounter_init,
    .tp_new = PyType_GenericNew,
};

#endif //Py_COUNTER_HPP
