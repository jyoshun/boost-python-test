#!/usr/bin/python
# -*- coding: utf-8 -*-

import special_methods

n = special_methods.NumberLike(7)
m = n + 2
print(m)

n0 = special_methods.NumberLike()
m0 = n0 + 1
print(m0)

print(repr(m0))
