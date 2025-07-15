#ifndef Py_TRIE_HPP
#define Py_TRIE_HPP

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <unordered_map>
#include <string>

// Simple implementation of a Trie
struct TrieNode {
    bool is_end;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() : is_end(false) {}
    ~TrieNode() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }
};

// Define Trie Python object

// Constructor of Trie
static int PyTrie_init(PyTrie* self, PyObject* args, PyObject* kwds) {
    // Allocate the internal state

    return 0;
}

// Destructor of Trie
void PyTrie_dealloc(PyTrie *self) {
    // free the Trie python object and free the memory of the internal state
}

static PyMethodDef PyTrie_methods[] = {
    { NULL, NULL, 0, NULL }
};

static PyTypeObject PyTrieType = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    .tp_name = "datastruct.Trie",
    .tp_basicsize = sizeof(PyTrie),
    .tp_itemsize = 0,
    .tp_dealloc = (destructor)PyTrie_dealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "Trie's documentation",
    .tp_methods = PyTrie_methods,
    .tp_init = (initproc)PyTrie_init,
    .tp_new = PyType_GenericNew,
};

#endif //Py_TRIE_HPP

