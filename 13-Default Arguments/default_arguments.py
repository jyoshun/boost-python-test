#!/usr/bin/python
# -*- coding: utf-8 -*-

import default_arguments

# function overloads
print(default_arguments.foo(1))
print(default_arguments.foo(11, 'b'))
print(default_arguments.foo(11, 'b', 333))
print(default_arguments.foo(11, 'b', 333, 4444.44))

# member function overloads
e = default_arguments.Example()

e.doit()
print(e)

print(e.doit(2))

e.doit('Hallo')
print(e)

print('-' * 6)

print(e.makeIt('xxx'), e)
print(e.makeIt('abc', 2), e)
print(e.makeIt('xyz', 3, 'abc'), e)
