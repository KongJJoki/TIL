vowel = ['a','e','i','o','u', 'A', 'E', 'I', 'O', 'U']
while True:
    vowelCount=0
    sentence = input()
    if sentence == "#":
        break
    else:
        for i in sentence:
            if i in vowel:
                vowelCount+=1
    print(vowelCount)