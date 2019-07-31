import class_properties

x = class_properties.Num()
x.value = 3.14
print(x.value, x.rovalue)

x.rovalue = 2.17  # error!
