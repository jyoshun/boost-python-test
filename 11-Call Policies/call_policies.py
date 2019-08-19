#!/usr/bin/python
# -*- coding: utf-8 -*-

import call_policies

# e = Example()  # won't work, constructore not available from python
f = call_policies.Example.factory()
s = call_policies.Example.singleton()

print("f =", f)
print("s =", s)
