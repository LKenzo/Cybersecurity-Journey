# SOC Fundamentals
10/6/2026

## SOC Types and Roles
SOC is a security team that monitors and analyzes the security of an organization. Primary purpose of SOC team is detecting, analyzing and responding to cybersecurity incidents.

There are 4 SOC Models:
1. In-house SOC -> Internal organization SOC.
2. Virtual SOC -> Remote SOC team.
3. Co-Mangaed SOC -> Internal SOC staff working with an external Security Sevice Provider (MSSP).
4. Command SOC -> SOC team oversees smalles SOCs across region.

SOC Roles:
- SOC Analyst -> Can be cateogrized as Level 1,2, and 3. Classifies alert, looks for the cause, and advises remediation.
- Incident Responder -> Responsible for threat detection.
- Threat Hunter -> cybersecurity professional that proactively seeks out and investigates potential threats and vulnerabilities within organization's network or system.
- Security Engineer ->  Maintined the security Infrastructure of Security Information and Event Management (SIEM) solutions and security Operation center (SOC) products.
- SOC Manager -> Management responsibilites of the SOC team.

## SOC Analyst and Their Responsibilities
A SOC Analyst is the first person to investigate threats to a system. Investigating Varying types of incidents, since there are many various techniques of attack vectors and malicious software.

SOC Analyst reviews alerts in the SIEM and determines which ones are real threats. Use various security and protection products such as:
Endpoint Detection and Response (EDR), Log Management, and SOAR.

Skills and abilites:
- Operating Systems
- Network
- Malware Analysis

## SIEM and Analyst Relationship
A security solution, to detect security threats via event logging. Collect and filter data and provide alerts for supicious events. One of the task of a SOC Analyst is to determine whether the generated alert is a real threat or false alert.

_Some popular SIEM solutions: IBM QRadar, ArcSight ESM, FortiSIEM, Splunk, etc. To get a better picture, you can visit the “Monitoring” page on LetsDefend._

<img width="1316" height="700" alt="image" src="https://github.com/user-attachments/assets/f73dfd6f-79ae-4bf3-a58a-0a37db537fd4" />

## EDR - ENdpoint Detection and Response
EDR or ETDR is an integrated endpoint security solution that combines continuous, real-time monitoring and collection of endpoint data with rule-based automated response and analysis capabilites

<img width="1343" height="430" alt="image" src="https://github.com/user-attachments/assets/3ee0f0ab-525a-4300-97a9-d734ba5ed3ed" />

We can see all of the accesible endpoint devices, we can search for endpoints or search across all hosts if there's an IOC. We can get general information and get browser history, network connection, and process list. Other than that we can do a live investigation by connecting and accessing the machine itself and also isolate a hacked machine from the network.

**EDR Practice is important: [Endpoint SECURITY](https://app.letsdefend.io/endpoint) to practice**

## SOAR (Security Orchestration Automation and Response)
Enables security products and tools in an environment to work together. 

<img width="1320" height="612" alt="image" src="https://github.com/user-attachments/assets/3318089d-dd93-47e6-8a1a-7629aa87e7e3" />

## Threat Intelligence Feed
To get a SOC Team up to date with the latest threat, an intelligece feeds are created. The data (such as malware hashes, C2 (Command&Control) domain/IP addresses etc.) is provided by a third party copany.

## Comman Mistakes Made by SOC Analysts
1. Over-reliance on VirusTotal Results
There can be malicious software that goes undetected by VirtusTotal (AV).

2. Hasty Analysis of Malware in a Sandbox
3-4 minute analysis in sandbox is not enough, a malware might be able to detect a sandbox and not activate, or maybe it will not become active for several minutes.

Malware analysis should take place in a real environment and kept as long as possible.

3. Inadequate Log Analysis
Log analysis sometimes is not permformed properly. Ex: never checking which devices connects to the malware found using Log Management.

4. Overlooking VirusTotal Dates
Always conduct a new search and not just look at the search cache, because an attacker can replace it with malicious content.

<img width="962" height="543" alt="image" src="https://github.com/user-attachments/assets/3de998a0-5985-43a9-ad2b-1637e6ae666b" />

_NIST:
Preparation, Detection/Analysis, Containment / Eradicationand Recovery, Post-Event Activity_



