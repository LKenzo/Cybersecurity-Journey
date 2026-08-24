# Petani Durr
Category: Forensic
Difficulty: Medium
File Type: pcap
Tools Used: Wireshark

## 1. PCAP Reconnaissance
In this challegne, we're given 1 pcap file and 1 folder that contains android sdcard

<img width="835" height="57" alt="image" src="https://github.com/user-attachments/assets/43021129-3753-4b70-a157-1fafeb041735" />

I started this challenge using wireshark to analyze the network through the given pcap file. 
Here, we can see that the network traffic is filled with TCP protocol, but there are also 8 HTTP protocol. This HTTP packets will be very crucial for this challenge.

<img width="911" height="267" alt="image" src="https://github.com/user-attachments/assets/cb3721e1-2e2f-47ea-bce1-5184ca86c20b" />

If we try to follow one of tcp stream (ex: stream 0). We'll find some important information, this tcp stream is the phase of Unity-Based Android ransomware execution.

<img width="900" height="407" alt="image" src="https://github.com/user-attachments/assets/6b757cca-8b19-4094-bfbf-40556cd36de2" />

## 2. Finding The Encoded Flag
After finding when did the exfiltrationn happened, we'll need to look for HTTP or raw TCP request that originated from the app. After finding one of the HTTP mentioned, we'll need to follow the HTTP stream, and inside of it we'll get a string that looks like it's encoded.

<img width="897" height="332" alt="image" src="https://github.com/user-attachments/assets/de073d4a-e193-451c-ac9d-9c40f6d34efc" />

encoded string: 56475372666732367b4c726c6c6c6c5f6630796933715f6a34786768616c345f7a3613461347a217d
decoded from hex: VGSrfg26{Lrllll_f0yi3q_j4xghal4_z3a4a4z!} -> it looks like a flag format but still not right

We still need to decode it from ROT13:
ITFest26{Yeyyyy_s0lv3d_w4ktuny4_m3n4n4m!} 

<img width="515" height="272" alt="image" src="https://github.com/user-attachments/assets/0ea64e02-bb0a-49c0-9fad-0872632f1168" />

With that, we finished one of the competition forensic challenge.
