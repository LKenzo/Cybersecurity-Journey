# DISKO 2

**Category:** Forensic\
**Difficulty:** Medium\
**File Type:** dd\
**Tools Used:** `file`, `dd`, `strings`\
## 1. Initial Reconnaisance
The first step of reconnaisance is to check the file type, and we can do this by using _file_ command.
<img width="1870" height="69" alt="image" src="https://github.com/user-attachments/assets/8dc386d5-ed4e-4e4e-acfb-59353c1ee0cb" />

The file type is a DOS/MBR which is a disk partitioning. Before doing any extraction, we should use _fdisk -l_ to view the partition table.
<img width="526" height="204" alt="image" src="https://github.com/user-attachments/assets/16c001a7-d2b8-4dc4-876c-b25190ec2de1" />

## 2. Disk Extraction process
The challenge itself is hinting us to only extract partition 1 that is the linux, and if we don't it'll all be gone. To do this, we need to use _dd_ to extract the disk precisely.
<img width="582" height="146" alt="image" src="https://github.com/user-attachments/assets/e36cbb5b-21cb-4720-a463-e5bc4ab7fd94" />

## 3. Finding The Flag
Now the actual next step is mounting the extracted partition so we can explore it ourselves, but for a quick scan I used strings on the extracted partition to search for the flag.
<img width="420" height="79" alt="image" src="https://github.com/user-attachments/assets/1ce324c2-589d-4e5a-ac7d-e8ee06989d56" />

Boom we got flag, problem solved.

## Lesson Learned
Always use strings for quick checkup on a partition.
