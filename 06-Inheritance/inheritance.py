#!/usr/bin/python
# -*- coding: utf-8 -*-

import inheritance

base = inheritance.Base()
derived = inheritance.Derived()

inheritance.b(base)
inheritance.d(derived)

inheritance.b(derived)
# not possible, d is only for Derived objects
# inheritance.d(base)

x = inheritance.factory()
inheritance.b(x)
