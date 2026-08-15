Link: https://learn.cylabacademy.org/library/450?page=1&category=4

This challenge description tells us that there are players trying to trick us with imitation flags which indicates there are going to be many files. It says to verify the correct file we need to use SHA-256 and decrypt the correct file.

To find the correct flag we need to use sha256sum to the directory that contains the flags. Which will result us with a ton of hashes

<img width="643" height="108" alt="image" src="https://github.com/user-attachments/assets/6674d1ce-8dd0-4f1c-a47f-9f6e723d386f" />

To identify the right one we need a comparison, and that comparison is checksum.txt

With checksum.txt we can do the same command as previous but grep the file with the same value as checksum.txt

<img width="643" height="35" alt="image" src="https://github.com/user-attachments/assets/39adf5f0-616b-494c-803c-d88ae07cbeee" />

After successfully identifying the correct file, we need to decrypt the file with the decrypt script to get the flag.

<img width="398" height="37" alt="image" src="https://github.com/user-attachments/assets/7616403c-e112-4346-b92b-f0668c4f1eb5" />

Challenge completed.
