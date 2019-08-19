// C++ allows operator overloading. Boost Python takes advantage of this.
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

using namespace boost::python;

// a number like class
class NumberLike
{
public:
    NumberLike(int value = 0) : value(value) {}
    int get() const { return value; }
    void set(int value) { this->value = value; }
    int value;
};

// a set of operators that take on FilePos instances
NumberLike&    operator+=(NumberLike& n, NumberLike other) { n.value += other.value; return n; };
NumberLike&    operator+=(NumberLike& n, int i) { n.value += i; return n; };
NumberLike&    operator-=(NumberLike& n, NumberLike other) { n.value -= other.value; return n; };
NumberLike&    operator-=(NumberLike& n, int i) { n.value -= i; return n; };
NumberLike     operator+(NumberLike n, NumberLike other) { n += other; return n; };
NumberLike     operator+(NumberLike n, int i) { n += i; return n; };
NumberLike     operator+(int i, NumberLike n) { n += i; return n; };
NumberLike     operator-(NumberLike n, NumberLike other) { n -= other; return n; };
NumberLike     operator-(NumberLike n, int i) { n -= i; return n; };
NumberLike     operator-(int i, NumberLike n) { n.value = i - n.value; return n; };
bool           operator<(NumberLike n, NumberLike other) { return (n - other).value < 0; };
bool           operator>(NumberLike n, NumberLike other) { return (n - other).value > 0; };

BOOST_PYTHON_MODULE(python_operators)
{
    class_<NumberLike>("NumberLike")
        .def(init<optional<int>>()) // __init__
        .add_property("value", &NumberLike::get, &NumberLike::set)    // property
        .def(self + self)           // __add__
        .def(self + int())          // __add__
        .def(int() + self)          // __radd__
        .def(self - self)           // __sub__
        .def(self - int())          // __sub__
        .def(int() - self)          // __rsub__
        .def(self += self)          // __iadd__
        .def(self += int())         // __iadd__
        .def(self -= self)          // __isub__
        .def(self -= int())         // __isub__
        .def(self < self)           // __lt__
        .def(self > self)           // __gt__
        ;
};
