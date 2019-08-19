import python_operators

n = python_operators.NumberLike(7)
other = python_operators.NumberLike(10)

n += 2
print(n.value)
m = n + 2
print(m.value)
m = 2 + n
print(m.value)

n -= 2
print(n.value)
m = n - 2
print(m.value)
m = n - 2
print(m.value)

m = n + other
print(m.value)
m = n - other
print(m.value)

m = n < other
print(m)
m = n > other
print(m)
