#!/usr/bin/env python

from distutils.core import setup, Extension

matrix_module = Extension("_matrix",
      sources = ["matrix_wrap.cxx", "matrix.cpp"],
      extra_compile_args=["-std=c++20"],
      extra_link_args=["-std=c++20"]
      )

setup(name = "matrix",
      version = "0.0.1",
      author = "Ye Gao",
      description = "A matrix class in Python realized in C++ via SWIG",
      ext_modules = [matrix_module],
      py_modules = ["matrix"]
      )
