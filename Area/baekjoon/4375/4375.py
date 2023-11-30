while True:
    try:
        tmpN=int(input())
    except:
        break
    nDigitCount=1
    nOneOne=1
    while True:
        if nOneOne%tmpN==0:
            print(nDigitCount)
            break

        nOneOne+=10**nDigitCount
        nDigitCount+=1