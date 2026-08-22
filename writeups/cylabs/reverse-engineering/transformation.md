# Transformation
Category: Reverse Engineering
Difficulty: Easy
File Type: Unicode text
Tools Used: Python

## 1. Gather Information
Before downloading the challenge's file, we get to see this on the desc:

```
'.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])
```

<img width="808" height="220" alt="image" src="https://github.com/user-attachments/assets/194e7d4f-588e-4fd7-85e7-cc0c3278f79c" />

The challenge file is a unicode text, which means we can use cat to get the content inside of it.
"灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸形㝦㘲捡㕽"

<img width="702" height="74" alt="image" src="https://github.com/user-attachments/assets/dd1eb53c-f3ea-440d-81e1-a4723afc63d7" />


## 2. Understanding the Code
Before building the script, we need to first understand the encoding logic.

```
'.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])
```

Although this is a one-liner, it breaks down into simple steps:
1. range(0, len(flag), 2) – This loops through the flag, but skips by 2. So it takes indices 0, 2, 4, 6...
2. ord(flag[i]) – Gets the integer (ASCII) value of the current character.
3. << 8 – Shifts that integer left by 8 bits. In decimal, this is the same as multiplying by 256. This creates "empty space" for the next character.
4. + ord(flag[i + 1]) – Adds the integer value of the next character into that empty space.
5. chr(...) – Converts this combined 16-bit number into a single Unicode character.
6. ''.join(...) – Joins all these new Unicode characters into one long encoded string.

Essentially, this script packs two ASCII letters into one Unicode character.

## 3. Build The Script
After understanding how the code worked, we'll now make the script in python.

```
encoded_flag = "灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸形㝦㘲捡㕽"

flag = ""

for char in encoded_flag:
    char = ord(char)
    first_char = chr(char >> 8)
    second_char = chr(char % 256)
    flag += first_char + second_char

print(flag)
    
```
Now if we just run this program, it should shifted the text back.

<img width="351" height="27" alt="image" src="https://github.com/user-attachments/assets/9c323d54-2169-436a-a0f2-9807f694e6be" />

With that, the challenge is solved.
