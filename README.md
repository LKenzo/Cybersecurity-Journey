# Cybersecurity Journey

Welcome to my personal cybersecurity knowledge base. This repository contains two main things:

1. **CTF Writeups**: Detailed walkthroughs for forensic, reversing, and pwn challenges I've solved (e.g., Cylab Labs).
2. **Certification Notes**: My study materials for certifications (currently FCF – Fortinet Certified Fundamentals).

---
## CTF Writeups (Active)

### Forensic

| Challenge | Difficulty | Tools Used | Summary |
| :--- | :--- | :--- | :--- |
| [**c0rrupt**]([CTF-Writeups/c0rrupt.md](https://github.com/LKenzo/Cybersecurity-Journey/blob/main/writeups/cylabs/medium/c0rrupt.md)) | Medium | `xxd`, `pngcheck`, Python | Repaired a corrupted PNG by recalculating the CRC checksum. |
| [**Verify**]([CTF-Writeups/verify.md](https://github.com/LKenzo/Cybersecurity-Journey/blob/main/writeups/cylabs/easy/verify.md)) | Easy | `sha256sum`, `grep` | Verified file integrity by comparing hash checksums. |
| [**SideChannel**]() | Hard | Python, `subprocess`, `time` | Brute-forced an 8-digit PIN via a timing side-channel attack on an ELF binary. |
| *More coming soon...* | - | - | - |

> Click the challenge names to view the full walkthrough.

---

## CF Notes (Archived / In Progress)

I studied for the **Fortinet Certified Fundamentals (FCF)** certification and successfully passed it. However, the official training material was heavily reliant on AI-generated content and lacked deep technical depth.

Rather than deleting the notes, I'm keeping them here **as an archive** in case they help someone with a quick reference, but **I do not recommend them as a primary study source**.

- **Status**: Incomplete (I stopped updating midway because the material was redundant).
- **Recommendation**: If you're studying for FCF, I'd suggest cross-referencing with Fortinet's official documentation and hands-on labs instead.

You can find the existing notes here: [FCF-Notes/](https://github.com/LKenzo/Cybersecurity-Journey/tree/main/FCF)

---

## Toolbox

Tools I frequently use across both CTFs and general forensics:

- **Binary/File Analysis**: `xxd`, `hexedit`, `binwalk`, `strings`, `file`, `pngcheck`
- **Network**: `Wireshark`, `tshark`
- **Hashing/Crypto**: `sha256sum`, `openssl`, Python (`hashlib`, `zlib`)
- **Reverse Engineering**: `Ghidra`, `gdb`, `radare2`
- **Scripting**: Python 3, Bash
---

## Connect with Me

- **GitHub**: [LKenzo](https://github.com/LKenzo)
- **LinkedIn**: [Maximillian Frenat](https://www.linkedin.com/in/maximillian-frenat-80ab41286/)

---

## Disclaimer

All writeups are my own original work. The FCF notes are provided "as-is" and may be incomplete.
