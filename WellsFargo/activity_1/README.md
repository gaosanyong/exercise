Activity 1 Create a Python wrapper to a simple C++ library via SWIG.

Please follow below steps to build C++ code into a Python module.
```
pip install setuptools
swig -c++ -python matrix.i
python3 setup.py build_ext --inplace
```
