# PsExec Hunt Lab
10/18/2026
Tools: Wireshark

## Scenario
An alert from the Intrusion Detection System (IDS) flagged suspicious lateral movement activity involving PsExec. This indicates potential unauthorized access and movement across the network. As a SOC Analyst, your task is to investigate the provided PCAP file to trace the attacker’s activities. Identify their entry point, the machines targeted, the extent of the breach, and any critical indicators that reveal their tactics and objectives within the compromised environment.

## Writeup
I'm given one pcapng file. My task is to investigate provided PCAP file to trace the attacker's activities.

<img width="1032" height="248" alt="image" src="https://github.com/user-attachments/assets/bd165e07-ff89-4900-9eb0-e4706d5f4d86" />

The first task is to identify the IP address of the machine, where the attacker gained access first. Now to do this, we need to learn more about what PsExec actually is

<img width="886" height="657" alt="image" src="https://github.com/user-attachments/assets/9dd9f8ef-bd1f-4b93-9ee9-48847a5388af" /> 

So after doing a research, PsExec is a command-line utility from Microsoft and it lets system administrator to execute processes remotely. One of the key detail here is PsExec uses SMB protocol over TCP to communicates with the server. So with this information, I can try to focus more on SMB protocol.

<img width="1821" height="412" alt="image" src="https://github.com/user-attachments/assets/cec82d22-0f9e-4161-812b-c95f48a07960" />

After a quick search, we get to see one of SMB packet (No. 144) where there's an ip that reuqested to create PSEXESVC.exe file. This basically meant (10.0.0.133) is the IP we're trying to look for.

<img width="601" height="253" alt="image" src="https://github.com/user-attachments/assets/99252799-504a-4393-8788-b9bae3929537" />

