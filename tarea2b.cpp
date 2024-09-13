#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PyBase {
public:
    virtual ~PyBase() = default;
    virtual void print(ostream& os) const = 0;
};

template<typename T>
class PyObject : public PyBase {
    T value;
public:
    PyObject(const T& v) : value(v) {}

    void print(ostream& os) const override {
        apoyo(os, value);
    }

private:
    template<typename U>
    void apoyo(ostream& os, const U& val) const {
        os << val;
    }

    void apoyo(ostream& os, const bool& val) const {
        os << (val ? "true" : "false");
    }
};

class pylist {
    vector<PyBase*> vec;

public:
    pylist() {}

    template<typename... Args>
    pylist(Args... args) {
        (append(args), ...);
    }

    ~pylist() {
        for (auto obj : vec) {
            delete obj;
        }
    }

    template<typename T>
    void append(const T& value) {
        vec.push_back(new PyObject<T>(value));
    }

    friend ostream& operator<<(ostream& os, const pylist& pl) {
        os << "[";
        for (size_t i = 0; i < pl.vec.size(); ++i) {
            pl.vec[i]->print(os);
            if (i < pl.vec.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    size_t len() const {
        return vec.size();
    }

    PyBase* operator[](size_t index) const {
        return vec[index];
    }
};
int main() {
    pylist l1;          // P.1
    cout << l1 << endl; // []

    l1.append(3);       // P.2
    cout << l1 << endl; // [3]

    l1.append('A');
    l1.append(true);
    l1.append(3.0012);
    cout << l1 << endl; // [3,A,true,3.0012]
    
    pylist l2(1, 2.1, 'A', 'B');    // P.3
    cout << l2 << endl;             // [1,2.1,A,B]

    // P.4 (Una lista dentro de otra)
    l1.append(l2);
    cout << l1 << endl; // [3,A,true,3.0012,[1,2.1,A,B]]
    cout << len(l1) << endl; // 5
    cout << len(l2) << endl; // 4

    // P.5
    cout << l1[1] << endl; // A
    cout << l1[4] << endl; // [1,2.1,A,B,C++]

    // P.6
    l1[0] = 'X';
    cout << l1 << endl; // [X,A,true,3.0012,[1,2.1,A,B]]

    // P.7
    cout << (l1[1] == 'A') << endl; // 1 (verdadero)
    cout << (l1[3] == 3.0) << endl; // 0 (falso)

    }