#ifndef Py_TRIE_HPP
#define Py_TRIE_HPP

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <unordered_map>
#include <string>

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
typedef struct {
    PyObject_HEAD
    TrieNode* root;
} PyTrie;

// Constructor of Trie
static int PyTrie_init(PyTrie* self, PyObject* args, PyObject* kwds) {
    self->root = new TrieNode();

    return 0;
}

// Destructor of Trie
void PyTrie_dealloc(PyTrie *self) {
    PyTypeObject *tp = Py_TYPE(self);
    tp->tp_free(self);
    
    delete self->root;
    
    Py_DECREF(tp);
}

static PyObject* PyTrie_insert(PyTrie* self, PyObject* args) {
    const char* word;
    if (!PyArg_ParseTuple(args, "s", &word))
        return nullptr;

    TrieNode* node = self->root;
    for (const char* p = word; *p; ++p) {
        if (!node->children[*p])
            node->children[*p] = new TrieNode();
        node = node->children[*p];
    }
    node->is_end = true;

    Py_RETURN_NONE;
}

static PyObject* PyTrie_search(PyTrie* self, PyObject* args) {
    const char* word;
    if (!PyArg_ParseTuple(args, "s", &word))
        return nullptr;

    TrieNode* node = self->root;
    for (const char* p = word; *p; ++p) {
        if (!node->children.count(*p))
            Py_RETURN_FALSE;
        node = node->children[*p];
    }
    if (node->is_end)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static void startswith_dfs(TrieNode* node, std::string& current, PyObject* list) {
    if (node->is_end) {
        PyObject* py_word = PyUnicode_FromString(current.c_str());
        PyList_Append(list, py_word);
        Py_DECREF(py_word);
    }

    for (const auto& pair : node->children) {
        current.push_back(pair.first);
        startswith_dfs(pair.second, current, list);
        current.pop_back();
    }
}

static PyObject* PyTrie_startswith(PyTrie* self, PyObject* args) {
    const char* prefix;
    if (!PyArg_ParseTuple(args, "s", &prefix))
        return nullptr;

    TrieNode* node = self->root;
    for (const char* p = prefix; *p; ++p) {
        if (!node->children.count(*p))
            return PyList_New(0);  // return empty list
        node = node->children[*p];
    }

    PyObject* result = PyList_New(0);
    auto current = std::string(prefix);
    startswith_dfs(node, current, result);

    return result;
}

static PyMethodDef PyTrie_methods[] = {
    { "insert", (PyCFunction)PyTrie_insert, METH_VARARGS, "Insert a word" },
    { "search", (PyCFunction)PyTrie_search, METH_VARARGS, "Search for a word" },
    { "starts_with", (PyCFunction)PyTrie_startswith, METH_VARARGS, "Return words that start with a given prefix" },
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

