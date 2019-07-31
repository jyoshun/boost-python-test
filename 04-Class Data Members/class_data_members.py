import class_data_members

x = class_data_members.Var('pi')
x.value = 3.14
print(x.name, 'is around', x.value)

# name is exposed as read-only while value is exposed as read-write.
x.name = 'e' # can't change name
# Traceback (most recent call last):
#   File "<stdin>", line 8, in ?
# AttributeError: can't set attribute
