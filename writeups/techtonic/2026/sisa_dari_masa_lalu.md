# Sisa dari Masa Lalu

**Category:** Forensic\
**File Type:** img\
**Tools Used:** `foremost`, `cyberchef`

## The Writeup

<img width="620" height="132" alt="image" src="https://github.com/user-attachments/assets/715bee36-90d1-4cd5-9912-ca663aabc22b" />

First Thing to do with an .img file is we need to use binwalk to scan the files inside of it. In this .img file, I scanned two png files. Extracting using "binwalk -e will" result us with a file that can't be opened (Corrupt), the reason is because binwalk can only auto extract signtaure that has internal extractor.

<img width="547" height="65" alt="image" src="https://github.com/user-attachments/assets/faf4f12c-f56e-4ce8-a6ba-d1a1069de214" />

Because of that reason, we'll need to use foremost to extract the png files.

<img width="275" height="92" alt="image" src="https://github.com/user-attachments/assets/a2943ba5-ca7a-432a-bad7-892545f52f4d" />

After done extracting, we get to see the 2 png files inside of our folder, where one of them being the fake flag and the other seems to be the front part of a flag "carve_"

<img width="261" height="150" alt="image" src="https://github.com/user-attachments/assets/c1d6b835-9eb5-42aa-8d5d-0975e51676d0" />

We can get the last part of the flag by using this command

```
strings disk_usang_img | tail -n 50
```

It will output the instructionof what encoding it use and the encoded string itself. 

<img width="426" height="318" alt="image" src="https://github.com/user-attachments/assets/1969ec6b-73f3-4133-af76-d4e9b5a483c9" />

Using the instruction on cyberchef, we get to see the flag of this challenge. With that, we get to solve this challenge.
