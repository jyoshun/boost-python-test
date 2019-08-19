#!/usr/bin/python
# -*- coding: utf-8 -*-

import virtual_functions_with_default_implementations

base = virtual_functions_with_default_implementations.Base()
class Derived(virtual_functions_with_default_implementations.Base):
    def f(self):
        return 42

derived = Derived()
print(base.f())
print(derived.f())
