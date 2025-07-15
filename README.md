## Setup

- Create virtual environment with `python3 -m venv .venv`.
- Activate virtual environment with `source .venv/bin/activate`. Verify by running `whereis python` and ensuring it locates into the virtual environment.
- To know in which folder your `Python.h` file is located, run `python3.12-config --includes`.
- VSCode: edit the file `.vscode/c_cpp_properties.json`

## Useful readings

- [Introduction to Python/C API](https://docs.python.org/3/c-api/intro.html)
- [Embedding Python in Another Application](https://docs.python.org/3/extending/embedding.html#compiling-and-linking-under-unix-like-systems)
- [Parsing arguments and building values](https://docs.python.org/3/c-api/arg.html)