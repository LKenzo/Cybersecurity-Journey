# Kalkulator Ilegal

**Category:** Reverse Engineering\
**File Type:** bin\
**Tools Used:** `Ghidra`, Python

## 1. Basic Reconnaisance

<img width="556" height="97" alt="image" src="https://github.com/user-attachments/assets/adb55160-0c6e-4936-a7c0-58dbc2d2dc39" />

Executing the bin file, we're expected to input a number to continue the program. If the inputted number is wrong, then the program will output "SALAH. Coba lagi"

We will continue to the next step by analysing the logic of the program using Ghidra.

<img width="503" height="277" alt="image" src="https://github.com/user-attachments/assets/9aad9bde-e2ae-48ec-8e44-af334b3dbb79" />

From this function, we can see that there's an if condition where it compares uVar6 (User Input) with a hexadecimal value. But, uVar6 isn't purely user input, it first has to go to a block of code which will scramble it.

<img width="598" height="100" alt="image" src="https://github.com/user-attachments/assets/68b07277-6f69-4da6-baae-2354bafcd220" />

Now, since both of these are bijective, which means all inputs will result the same ouptut, it means we can reverse it. From this, we can create a script using python witht he same scramble steps that is reversed, so we can get the local_30 value.

<img width="311" height="437" alt="image" src="https://github.com/user-attachments/assets/0f79df40-0aaa-4ebb-8f82-5ac076e9b938" />

Executing the code will get us this output : 5219682941233435720

This output then can be inputted inside of the calculator program, which then will give us the flag itself.

<img width="557" height="128" alt="image" src="https://github.com/user-attachments/assets/263f7cf9-85fb-4f66-9c4f-11c7d5f7408e" />
