import re

str = "A man , a plan , a canal: Panama"
str = str.lower()
str = re.sub(r'[^a-z0-9]','',str)
if str == str[::-1]:
    print("The string is palindrome sequence")
else:
    print ("The string is not palindrome sequence")