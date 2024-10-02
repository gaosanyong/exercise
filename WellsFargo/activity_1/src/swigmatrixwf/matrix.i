%module matrix

%{
#include "matrix.h"
%}

%init %{
    setUpLibrary();
    atexit(tearDownLibrary);
%}

%include "std_vector.i";
%include "std_except.i";
using namespace std;
%template(DoubleVector) vector<double>;
%template(DoubleDoubleVector) vector<vector<double>>;

%include "matrix.h"
