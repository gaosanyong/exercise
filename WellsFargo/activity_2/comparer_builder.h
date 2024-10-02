#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class comparer_builder {
private:
    using CompareFunc = function<bool(const T&, const T&)>;
    vector<CompareFunc> comparisons;

public:
    template<typename M>
    comparer_builder& by(M member);

    comparer_builder& build();

    bool operator()(const T& lhs, const T& rhs) const;
};
