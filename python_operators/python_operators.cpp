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
NumberLike&    operator+=(NumberLike& fp, NumberLike other) { fp.value += other.value; return fp; };
NumberLike&    operator+=(NumberLike& fp, int i) { fp.value += i; return fp; };
NumberLike&    operator-=(NumberLike& fp, NumberLike other) { fp.value -= other.value; return fp; };
NumberLike&    operator-=(NumberLike& fp, int i) { fp.value -= i; return fp; };
NumberLike     operator+(NumberLike fp, NumberLike other) { fp += other; return fp; };
NumberLike     operator+(NumberLike fp, int i) { fp += i; return fp; };
NumberLike     operator+(int i, NumberLike fp) { fp += i; return fp; };
NumberLike     operator-(NumberLike fp, NumberLike other) { fp -= other; return fp; };
NumberLike     operator-(NumberLike fp, int i) { fp -= i; return fp; };
NumberLike     operator-(int i, NumberLike fp) { fp.value = i - fp.value; return fp; };
bool           operator<(NumberLike fp, NumberLike other) { return (fp - other).value < 0; };
bool           operator>(NumberLike fp, NumberLike other) { return (fp - other).value > 0; };

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
