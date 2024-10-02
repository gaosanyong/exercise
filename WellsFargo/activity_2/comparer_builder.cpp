#include "comparer_builder.h"

template<typename T>
template<typename M>
comparer_builder<T>& comparer_builder<T>::by(M member) {
    auto comparison = [member](const T& lhs, const T& rhs) {
        return invoke(member, lhs) < invoke(member, rhs);
    };
    comparisons.push_back(comparison);
    return *this;
}

template<typename T>
comparer_builder<T>& comparer_builder<T>::build() {
    return *this;
}

template<typename T>
bool comparer_builder<T>::operator()(const T& lhs, const T& rhs) const {
    for (const auto& comparison : comparisons) {
        if (comparison(lhs, rhs)) return true;
        else if (comparison(rhs, lhs)) return false;
    }
    return false;
}


struct MyStruct {
private:
    int x2;
    string x3;
public:
    int x1;
    int get_x2() const { return x2; }
    const string& get_x3() const { return x3; }

    MyStruct(int x1, int x2, string x3) : x1(x1), x2(x2), x3(x3){}
};

int main() {
    vector<MyStruct> v{
        MyStruct(2, 6, "c++"),
        MyStruct(2, 5, "java"),
        MyStruct(2, 4, "python"),
        MyStruct(1, 1, "javascript"),
        MyStruct(1, 2, "typescript"),
        MyStruct(1, 2, "rust"),
        MyStruct(1, 2, "go")
    };
    sort(v.begin(), v.end(), comparer_builder<MyStruct>().by(&MyStruct::x1).by(&MyStruct::get_x2).by(&MyStruct::get_x3).build());
    for (const auto& item : v) {
        cout << "x1: " << item.x1 << ", x2: " << item.get_x2() << ", x3: " << item.get_x3() << endl;
    }
    return 0;
}

