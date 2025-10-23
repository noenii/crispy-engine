#using python to screw with files :)
#file = open(name, mode)
#'r' to read

a = open('txt.txt', 'r') #r = read, will throw an error if file is not found

b = open('txt.txt', 'w') #w = write, will overwrite the file if it exists and will make a new one if it does not

#but how to actually see the content?

print(a.read()) #prints out the content

#how to write?

b.write('random text')

#you should close files when your finished

a.close()
b.close()

#but you can use with which automates everything

with open('txt.txt', 'r') as c:
    #does everything in here
    print(c.read())

#also should use try except blocks to make sure the file closes if any errors occur (finally)