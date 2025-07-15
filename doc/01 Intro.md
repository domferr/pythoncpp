# Cython
https://github.com/cython/cython/blob/master/docs/examples/quickstart/cythonize/integrate_cy.pyx

# pybind11
https://github.com/pybind/pybind11/blob/master/docs/basics.rst

# Python C API

https://github.com/python/cpython
- Numpy: https://github.com/numpy/numpy/tree/main/numpy/_core/include/numpy
- Tensorflow: https://github.com/tensorflow/tensorflow/blob/00732e36489268538fb3f3ccd92ca01424099398/tensorflow/python/eager/pywrap_tensor.cc#L22
- FastFlow: https://github.com/domferr/fastflow-python

## Standard libraries example

```python
from math import factorial

factorial(4) # 24
```
Implemented [here](https://github.com/python/cpython/blob/cb59eaefeda5ff44ac0c742bff2b8afc023be313/Modules/clinic/mathmodule.c.h#L247-L254)!

# Agenda

1. Learn the basics implementing our first library!
2. Implementing a more interesting library
3. Food time!

Feel free to stop me at anytime for any questions!