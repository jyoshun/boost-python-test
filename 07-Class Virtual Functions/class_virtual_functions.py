import class_virtual_functions

class PythonDerived(class_virtual_functions.Base):
    def f(self):
        return 666

# RuntimeError: Pure virtual function called
# base = class_virtual_functions.Base()
# print(base.f())

derived = PythonDerived()
print(derived.f())
