a=''
b=[0]*a
for v in [r.randrange(0,a) for _ in range(a)]:b[v]+=1
for i,c in enumerate(b):
    if c:print(*(i for _ in range(c)),'',end='')
