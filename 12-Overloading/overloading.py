#!/usr/bin/python
# -*- coding: utf-8 -*-

import overloading

x = overloading.X()

print(x.f(1))
print(x.f(1, 2.2))
print(x.f(1, 2.2, 'c'))
print(x.f(1, 2, 3))
