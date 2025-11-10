"""
a = "strings!"
print(a + " aren't they cool?")

b = '''multi
line
strings'''

print(b + ", preserves new lines \\n")


c = "aki is an idiot"
'''
print(c[1:6])
print(c[4:])
print(c[:3])
print(c[::-1])
'''
for letter in c:
    print(letter)

c = 'smth'
print(f'{c}, smh you can update strings')
del c
try:
    print(f'{c}\nit worked huh')
except:
    print('didnt work huh')

d = 'sowwy aki'
e = d.replace('aki', '~aki-chan')
print(e)

print(len(e))

e = e.upper()
print(e)
e = e.lower()
print(e)
#ignores non letters lmao
#strip() to remove surrounding whitespace


f = 'i am my'
g = ' biggest glazer\n'

print(f + g)
#str concatenation with + leads to no spaces, and with comma leads to one space char

h = f + g
print(h * 5)
"""
i = 'power of f strings'
#f strings to insert variables
print(f'the {i}!')

j = 'hi im {} and i am {} years old'.format('aki', 15)
print(j)

#checks if smth in a str, returns True or False
print('aki' in j)