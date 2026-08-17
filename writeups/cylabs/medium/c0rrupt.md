# C0rrupt (Data)

**Category:** Forensic  
**Difficulty:** Medium (Harder Medium)  
**Tools Used:** `file`, `xxd`, `pngcheck`, `hexedit` / `xxd -r`, Python (`zlib`)
Link: https://learn.cylabacademy.org/library/53?page=6&category=4

## 1. Initial Reconnaissance
The challenge provided a single file named `c0rrupt` (no extension). My first instinct was to identify what type of file it was.
<img width="325" height="58" alt="image" src="https://github.com/user-attachments/assets/7106cb63-0f76-423b-8298-c8501e7d3a72" />


We can see that the file type is a data. Then to check further I’ll be checking the file’s hex value by using xxd and checking the head to check for hints.

<img width="586" height="362" alt="image" src="https://github.com/user-attachments/assets/e7a74d12-9f38-4249-920c-da5654e5cdea" />


It looks like just how the challenge title descirbe, a corrupt file. Looking further in the ASCII Preview from the xxd, There’s a some readable strings that we can get like RGB, gAMA, pHYs. All of these readable strings are specific data chunks that are commonly found inside PNG files.

Now that we’ve identified the file type, we need to back up the original file using cp before attempting any repairs.

<img width="331" height="57" alt="image" src="https://github.com/user-attachments/assets/1a0c8be5-8177-47d1-b9e6-bcd14ff275a9" />


After duplicating the file, we’ll proceed with the first step that is fixing the hex header to png, the first few bytes that represents its file type. We can do this by editing the bytes using hexedit.

Current hex header: 89 65 4E 34 0D 0A B0
PNG hex header: 89 50 4E 47 0D 0A 1A

## 2. Understanding the Corruption
To diagnose the exact corruption, I used pngcheck, a tool specifically designed to validate PNG file structure:
<img width="923" height="21" alt="image" src="https://github.com/user-attachments/assets/9bf57a4b-03e4-4794-a887-acb8b61da95e" />

After the file hex header fix. I also noticed that this PNG file is missing one of the most essential part of PNG specification on its header, that is the IHDR Chunk.

It looks like the file is corrupted and changed IHDR to C”DR

<img width="586" height="373" alt="image" src="https://github.com/user-attachments/assets/b32583a5-bd1f-431b-8c1f-1926a67106bf" />

## 3. Fixing the CRC
To fix this issue, we can use hexedit, and change the two bytes.

From: 43 22 44 52
To : 49 48 44 52

<img width="960" height="267" alt="image" src="https://github.com/user-attachments/assets/9b258bc8-b94f-4332-81df-5ec7df4f5f02" />

## 4. Verification
Next, we’ll have  to verify the validity of the PNG file, by using pngcheck to see if we’ve missed any other issue.

```bash
pngcheck -c -v [file.png]
```

-c is for colorization of the output
-v is to check the validity of the file (checking chunk data)

<img width="326" height="46" alt="image" src="https://github.com/user-attachments/assets/ca8d19ed-982c-47c2-99de-8e4a73cb8afd" />

## 5. Repeat step 3-4
After running the tool to the PNG file, we can see that it detects an error in the File. It says there is an error on the CRC and it’s inside of pHYs chunk.

The pngcheck actually gave us the answer on what to change. It excpects the value to be 49 52 24 F0 instead of 38 D8 2C 82.

Now the next problem is where to mke that change. To locate the CRC, we need to understand the anatomy of a PNG chunk.

| **Part** | **Size** | **Description** |
| --- | --- | --- |
| **1. Length** | 4 bytes | Tells the computer how many bytes of *Data* are inside. |
| **2. Name** | 4 bytes | The 4-letter ID of the chunk (IHDR, IDAT, etc). |
| **3. Data** | *Variable* | The actual content (size matches the Length number). |
| **4. CRC** | 4 bytes | The security seal (checksum) to prove the data wasn't corrupted. |

Now that we understand the chunk anatomy, we can track down the CRC. pngcheck shows the pHYS chunk starts at offset 0x42 (byte 66 in decimal). From that offset, the next field is the length, which tells us the size of the chunk’s data in bytes. 

Locating CRC:

pHYS (Name) starts at 66, and the name itself takes 4 bytes.
→ 66 + 4 = 70

then the data has a size of 9 bytes.

→ 70 + 9 = 79

Meaning the CRC will start at byte 79.

<img width="562" height="192" alt="image" src="https://github.com/user-attachments/assets/2e745794-a7f6-4fee-9653-bdfe9f7a9860" />

To apply everything, we’ll use the CLI patching. By combining printf to generate the correct CRC hex and dd to inject them at the exact offset, we can safely overwrite the bad data.

This approach is much safer and more scalable for complex fixes that use math, rather than using hexedit.

**dd** arguments:
of → to specify the file target
bs →  to set the byte size
seek → to set the location of the injection
count → to safely insert [num] bytes of data
conv → applies conversion rules to the data stream (notrunc will set it to not overwrite the rest of the file)

<img width="708" height="92" alt="image" src="https://github.com/user-attachments/assets/a3c3677f-b7f7-43af-906d-80b4eb233e73" />

After executing the command. We’ll validate the file again using pngcheck to check if there’s something missing.

We see that There’s an error that says invalid chunk length after the pHYS chunk. Which means, we need to check the values after pHYS chunk

<img width="636" height="198" alt="image" src="https://github.com/user-attachments/assets/ba9362ce-8c43-4a59-a3b9-347fb60bb47e" />

To check it, we can specify our xxd to show the lines that are giving the error. If last time, CRC starts at 79 and the CRC itself will take 4 bytes, then the starting byte we’re targeting is 79 + 4 = 83 (0x53 in hexadecimal).

- g 1: Groups the output by single bytes.
- s 0x53: Sets the starting byte (seek).
- l 77: Limits the output to show exactly 77 bytes.

<img width="642" height="121" alt="image" src="https://github.com/user-attachments/assets/85fb8d9e-278e-4236-894e-96786cc450e3" />

There are two main issues with this chunk. First, the 'invalid chunk length' error happens because pngcheck is reading AA AA FF A5 (2.8 million bytes) as the real chunk’s data length, which is abnormaly long. Second, the chunk name is corrupted. The 4 bytes immediately following the length (AB 44 45 54) decode to «DET , which is not an official PNG chunk name. 

To see further about PNG specs: https://en.wikipedia.org/wiki/PNG

After research for PNG specification, My best guess is that this is an IDAT chunk. The spec states that multiple IDAT chunks must appear consecutively with no other chunks in between, making it the only logical fit here."

So we’ll use the same patching method of using printf and dd to change the chunk’s name hex from AB 44 45 54 («DET) to 49 44 41 54 (IDAT).

<img width="688" height="95" alt="image" src="https://github.com/user-attachments/assets/12a41506-3ef4-44d3-9584-73aed966817b" />

Then, to calculate the chunk's true data length, we need to find the exact boundary of the next IDAT chunk. To map out where all the IDAT chunks are located inside the file, we can use:

```bash
binwalk -R “IDAT” [file.png]
```

-R  for scanning specified sequence of bytes inside of the file

Calculation:

Since the next IDAT chunk starts at 0x10008, and the 4 bytes length field (back to chunk anatomy) comes just before it, our broken chunk must end exactly at 0x10004 .

To find the raw data size, we subtract the starting point of the data (0x5B) and the 4-byte CRC seal at the end:
0x10004 (Absolute End) - 0x5B (Data Start) - 0x4 (CRC) = 0xFFA5 (65445)

→ To further explain, 0x10004 is the length of the whole file until the next IDAT chunk’s length field. Because We only need the length of the chunk’s data, we need to remove the unnecessary bytes, that is the byte from before 87 (where IDAT chunk’s name start) + 4 (Because a chunk’s name need 4 bytes) = 91 (0x5B), lastly is the CRC (4 bytes).

Since the length field requires 4 bytes, our true length is 00 00 FF A5.

<img width="650" height="161" alt="image" src="https://github.com/user-attachments/assets/72c23742-a605-4da9-bf45-b36200e06c93" />

Use the printf to generate the correct hex value (00 00), then dd to inject it to the correct offset.

<img width="623" height="96" alt="image" src="https://github.com/user-attachments/assets/a1f5656a-d101-4175-acfb-79b6aa28a3b2" />

check the validity of the PNG file again using pngcheck. This time it detects no error.

<img width="608" height="268" alt="image" src="https://github.com/user-attachments/assets/fca0d64f-2f9b-4df2-a703-3cbab76f4177" />

So, The PNG file should now be fixed and can be opened.

<img width="1110" height="437" alt="image" src="https://github.com/user-attachments/assets/d1953371-8b47-4396-89dd-e4aacfc014db" />

Challenge Completed

## 5. Lesson Learned
1. First step of CLI Patching, always make a backup file. Always safe the original file intact (Learned this from someone write up, since I was stuck on some parts).
Link: https://medium.com/@sobatistacyber/picoctf-writeup-c0rrupt-cc24de6f61e9
2. A tool that checks for the validity of png (pngchecker).
3. How to do CLI Patch Method (using dd)
4. Checking File Specification specifically png specs for this challenge.
