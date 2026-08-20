# Very very very hidden

**Category:** Forensic\
**Difficulty:** Hard\
**File Type:** pcap\
**Tools Used:** `wireshark`, Python (`pil`)

## 1. Initial Reconnaissance
The step to do first when dealing with a pcap file is to look at the protocol hierarchy stats.

<img width="893" height="478" alt="image" src="https://github.com/user-attachments/assets/a9549434-282b-488a-9856-ab7b33dfe057" />

We can see that we're dealing with mostly TCP and there we can also see there are some HTTP packets.

With HTTP, the basic thing to do is to export the objects, and inside of it we can see some of the object that we can export. Two of them are a png where both of them represent an identitcal image but with different quality, the evil one has a lower quality hintin us it's probably a steganography.

<img width="757" height="197" alt="image" src="https://github.com/user-attachments/assets/db700a2a-1ae8-4981-8543-eaea4445c6fc" />

But after doing some basics png check using like _file_ and _exiftool_, there doesn't seem to be anything off about it. 

## 2. The Hint
The creator of this challenge is hinting us to check random queries, which probably indicates DNS traffic.

<img width="260" height="38" alt="image" src="https://github.com/user-attachments/assets/bfd8a144-8064-464d-82aa-897f71c32831" />

DNS are important, because it reveals the history of every connection a device attempts to make, basically like a browser history.

<img width="1155" height="32" alt="image" src="https://github.com/user-attachments/assets/5ec07ddb-892d-4c17-99e3-acde9ab20031" />
<img width="1476" height="73" alt="image" src="https://github.com/user-attachments/assets/cf1f2d65-a07d-42ce-9519-a9576178f295" />

While it looked random at first, if we really do gather it together, There are many attempts of connection to github, powershell, and something about encrypted. Well since the DNS is likely giving us a hint about it, we can try and search something about steganography, powershell, and maybe a github repo.

<img width="997" height="610" alt="image" src="https://github.com/user-attachments/assets/d0ee0206-ace2-4b32-b436-1fd56b8b51d6" />

After some search, I get to find this repo. Why this repo? because the example is using almost the same name pattern as the challenge, kiwi -> evil_kiwi, duck -> evil_duck.


## 3. Reversing The Code
Since this is an old challenge, there are many decode script out there for this already. But I was trying to create my own using python, but I do still had a hard time understanding it, so I got helped by AI to finish it up (Well I guiding me), here's the code.

```
from PIL import Image
import sys

def main():
    img = Image.open(sys.argv[1])
    pixels = img.load()
    width, height = img.size

    secret = []

    for y in range(height):
        for x in range(width):
            r, g, b = pixels[x, y]
            byte = ((b & 0x0F) << 4) | (g & 0x0F)
            secret.append(byte)

    result = bytes(secret).split(b'\x00')[0]
    print(result.decode('ascii', errors='ignore'))

main()
```

Here's the output:

<img width="1242" height="398" alt="image" src="https://github.com/user-attachments/assets/6c1b4f55-3160-4fdd-9ab1-09dd5d345335" />

It looks like the output, is not the flag itself. It's giving us more scripts and two hardcoded strings. The script is basically encrypting the 1st string with 2nd string using xor. This can be decrypted using cyberchef xor with the 2nd string as the key.

<img width="1086" height="569" alt="image" src="https://github.com/user-attachments/assets/cbbda21e-b21e-4e6a-bec5-319c0add4795" />

And there we go, There's the flag.

## Lesson Learned
Reverse Engineering is hard, and Powershell scripts are really hard to understand. I need to spend more time learning Reverse Engineering and Scripting in python.
