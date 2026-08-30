encoded_flag = "灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸形㝦㘲捡㕽"

flag = ""

for char in encoded_flag:
    char = ord(char)
    first_char = chr(char >> 8)
    second_char = chr(char % 256)
    flag += first_char + second_char

print(flag)
    