this = False
if(this is True):
    print("this is true")
else:
    print("this is false")
#also a shorter version
result = "this is true" if this is True else "this is false"
print(result)

age = 15

if age >= 18:
    print("unc")
elif age > 14:
    print("must be awkward")
else:
    print("infant")
#can also nest if statements but not everyone is yandere dev

day = 7

match day:
    case 1:
        print("土曜日")
    case 2:
        print("月曜日")
    case 3:
        print("火曜日")
    case 4:
        print("水曜日")
    case 5:
        print("木曜日")
    case 6:
        print("金曜日")
    case 7:
        print("日曜日")
    case _:
        print("1-7")