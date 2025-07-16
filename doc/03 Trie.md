# DataStruct

Let's create a library which name is `datastruct`, it provides a `BitSet` class:
```python
from datastruct import Trie

t = Trie()
t.insert("car")
t.insert("cart")
t.insert("cat")
t.insert("dog")

print(f'word "cat" is in the Trie: {t.search("cat")}')

print(t.starts_with("ca"))  # ['car', 'cart', 'cat']
print(t.starts_with("dog"))  # ['dog']
print(t.starts_with("z"))    # []
```

## Folder structure

```
datastruct/
├── datastruct_module.cpp
├── trie.hpp
├── setup.py
├── Makefile
```

# To do

1. Define the C++ object `PyTrie`. Remember PyObject_HEAD!
2. Implement the Type methods:
    - The constructor `__init__`
    - The deallocator `__del__`. Remember to cleanup the internal state! Remember Python uses reference counting!
3. Add instance methods by declaring them with `PyMethodDef[]` and implement them as C++ functions
    - We want to support `insert(word)`, `search(word)` and `starts_with(word)`
4. You should define a Python Type `PyTypeObject` like this:

```
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
```
  - When you get the prefix from the args it is not a `std::string` but instead a `char*`!

```
const char* prefix;
if (!PyArg_ParseTuple(args, "s", &prefix))
    return nullptr;
```
  - Good to know:
    - To create a Python list do `PyObject* list = PyList_New(0);`
    - To create a python object of a string from a c++ string/char array do `PyObject* pyword = PyUnicode_FromString(cppstring)`
    - You cannot append a string in a python list, you can only append a python object into it! The append function can be called via `PyList_Append(list, pyword);`
    - Creating a python object of a string increases the reference count, remember to decrease it after you call `PyList_Append`
6. [OPTIONAL] Implement iterator support to support iterating for each word in the trie
    - Define a new iterator type and implement `.tp_iter` and `.tp_iternext`
```
typedef struct {
    PyObject_HEAD
    PyBitSet* bitset;
    Py_ssize_t index;
} PyBitSetIter;
```
7. Initialize the module (i.e. `datastruct` library) in `datastruct_module.cpp` like we did for the `hello` library
    - Remember to add the `Trie` Type like we added the `Counter` type before!

## Build & run

Ensure you are in the `trie/` folder. Build the library with `make build` and run the playground Python code with `python3 playground.py`.