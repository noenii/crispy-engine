import random as r

rawLi = [r.randint(0, 999) for _ in range(20)]

def counter(aLi, digit):
    buckets = [[] for _ in range(10)]
    for elem in aLi:
        stripped = elem[-(digit + 1)]
        buckets[int(stripped)].append(elem)
    sorted_list = [item for bucket in buckets for item in bucket]
    return sorted_list

def radix(aLi):
    max_len = len(str(max(aLi)))
    dummy = [str(n).zfill(max_len) for n in aLi]
    for digit in range(max_len):
        dummy = counter(dummy, digit)
    return [int(x) for x in dummy]

print("unsorted:", rawLi)
print("sorted:", radix(rawLi))