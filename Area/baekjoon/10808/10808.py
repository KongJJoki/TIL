list_alphabet=[]
for i in range(0,26):
    list_alphabet.append(0)
strS=input()
for i in range(0,len(strS)):
    tmpASCII=ord(strS[i])-97
    list_alphabet[tmpASCII]+=1

for i in range(0,26):
    print(list_alphabet[i],end=" ")