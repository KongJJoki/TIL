nanLength=[]
realNan=[]
nanTotal=0
nanTotalTmp=0
noNan1=0
noNan2=0

for i in range(0,9):
    nanLength.append(int(input()))
nanLength.sort()

nanTotal=sum(nanLength)
nanTotalTmp=nanTotal

for i in range(0,8):
    for j in range(i+1,9):
        nanTotalTmp=nanTotal
        nanTotalTmp-=nanLength[i]
        nanTotalTmp-=nanLength[j]
        if nanTotalTmp==100:
            noNan1=nanLength[i]
            noNan2=nanLength[j]
            break
        
nanLength.remove(noNan1)
nanLength.remove(noNan2)

for i in range(0,7):
    print(nanLength[i])