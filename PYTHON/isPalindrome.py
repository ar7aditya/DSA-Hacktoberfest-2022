word = input("Enter a word or number: ")
reversed_word = ""

for i in range(1, len(word)+1):
    reversed_word+=word[-i]

if reversed_word.lower() == word.lower():
    print(f"{word} is a palindrome")
else:
    print(f"{word} is not a palindrome")