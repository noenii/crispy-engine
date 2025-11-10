#using python to screw with files :)
#file = open(name, mode)
#'r' to read
'''
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
'''

import os

cwd = os.getcwd()
print(cwd)  #prints current dir
#os.chdir('crispy-engine/code/')
#path = os.path.join(os.getcwd(), "projects")
#os.mkdir(path)
#os.rmdir(os.path.join(cwd, "projects"))

#mkdirs will make all intermediate dirs are missing

print(os.listdir(os.path.join(os.getcwd(), "crispy-engine/code/"))) #same as the dir command on windows cmd

#os.remove("C:/Windows/System32")
#os.remove(path, file) removes files only, not dirs

#os.chmod(file, perm)  changes permissions of a file/dir, must be passed in octal format "0o600"
print(os.getcwd())
os.chdir("crispy-engine/code/learning/")

print(os.stat("20.py")) #prints file metadata

print(os.name)  #prints os type

#the os module has its own exceptions like IOError

#os.popen(command[, mode[, bufsize]]) allows python files to run commands

#os.rename(file, name)  to rename files

print(os.path.exists("20.py"))   #checks if path exists

print(os.path.getsize("20.py"))  #get size of file, returns size in bytes