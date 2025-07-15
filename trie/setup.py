from setuptools import setup, Extension
import os

# Use environment SDK if available
# or set it manually by running export SDKROOT=$(xcrun --sdk macosx --show-sdk-path)
sdk_path = os.environ.get("SDKROOT", "")
extra_compile_args = ['-O3', '-std=c++17']
extra_link_args = [] #['-lc++']

if sdk_path:
    extra_compile_args += [f'-isysroot', sdk_path]
    extra_link_args += [f'-isysroot', sdk_path]
    
setup(
    name="datastruct",
    version="1.0.0",
    description="Description",
    author="Domenico Ferraro",
    author_email="ferraro.domenico125@gmail.com",
    ext_modules=[
        Extension(
            "datastruct", 
            ["datastruct_module.cpp"],
            include_dirs=['include'],
            language="c++",
            extra_compile_args=extra_compile_args,
            extra_link_args=extra_link_args,
            # use a safe subset of the Python C API to get a forward-compatibility guarantee 
            # to support any future version of Python, without recompilation
            py_limited_api = True
        )
    ],
    package_dir={"": "."},
    python_requires=">=3.8",
)