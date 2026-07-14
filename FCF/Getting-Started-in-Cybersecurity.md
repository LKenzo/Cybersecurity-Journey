# Fortinet FCF

# Getting Started in Cybersecurity
---
## Key Points
### Lesson 1 - Firewall
#### Packet Filter (Stateless)
- Filters packets using rules.
- Does not track connections.
- Fast but limited.

#### Stateful Firewall
- Tracks active network connections.
- Uses the 5-tuple and connection state.
- Better than stateless, but still limited to network traffic.

#### Third-Generation Firewall
- Adds application-layer inspection.
- Performs Deep Packet Inspection (DPI).
- May include antivirus and antispam.

#### Next-Generation Firewall (NGFW)
- NGFWs inspect applications and suspicious files, making them much more effective against modern threats.
- Combines previous firewall capabilities.
- Uses multiple layers of inspection:
  1. Rule-based packet filtering
  2. Deep Packet Inspection (DPI)
  3. Sandbox analysis for suspicious files
- Benefits:
  - Better visibility
  - Higher security
  - High-performance inspection
 
### Lesson 2 - Network Access Control
- Controls access to a network based on security policies.

How does it work?
- Verifies users and devices.
- Checks compliance (OS, device, location).
- Grants, restricts, or quarantines access.

Why is it useful?
- Prevents unauthorized access.
- Segments the network.
- Automates security enforcement.

Important terms
- Authenticator
- Authentication Server
- Device Profiling
- Network Segmentation

### Lesson 3 - Sandbox
- A system that isolates actions of an application in a safe virtual environment

Why used?
- To defense against zero-day attacks

How does it work?
- Mimics computer system and application that allows potential threats to run safely in the environment
- If found as malicious it will be quarantined

Sandbox Evolved
- First Gen -> Does not share threat information (Threat Intelligence) with other security devices
- Second Gen -> Integrates better with other security devices and share information with a threat intelligence in cloud
- Third Gen -> Aautomate and introduce AI to help detect breaches and prevent it, uses MITRE ATT&CK

### Lesson 4 - Web Applicaton Firewall (WAF)
- Monitors and filter out HTTP/HTTPS oncoming traffic to and from web app
- WAF stop attack from web, such as:
  - SQL Injection
  - Cross-site scripting
  - File inclusion
  - Secuirty misconfiguration
 
Why made?
- Traditional edge firewall blocked certains protocols and ports (such as 80 or 443)
- www has become a huge trend and most people use it

#### WAF 2nd Generation
- Made because of the number of false positive that was made by the 1st Gen

What Change?
- It can learn from application behavior to create a baseline on what to block
- Introduced heuristic and detect variants of known signatures (like sql that been camouflaged)

Downside
- Couldn't keep up with the growth of exploits
- Can't defend zero-day

#### Evolution of WAF Development
- Implementation of Machine Learning

Upgrades:
  - Role based permissions
  - Share information and collaborate with other security devices
  - Expose and quarantine zero-day exploit and share signature to other devices
  - Upload new discoveries to Threat intelligence

### Lesson 5 - Secure Email Gateway (SEG)
- Technology that protects user from mail-based threats and ensures the privacy of the email

Why is it needed?
- Mail is one of the method to distribute malware, fraud, or phishing attack
- Throughout the year, phishing attacks victims continue to grow

Features:
- Content Filter 
- Data Loss Prevention
- Spam Filter
- Authenication and Identity Verification
- Malware Filter
- Encryption

How does SEG Work?
- SEG check the Sender Policy Framework (SPF) to see the user's record
- SPF is best use with DKIM and DMARC

### Lesson 6 - Content Filtering
- Process to screen or resctrict access to suspicious items

Types of Content Filters
- Search Engine Filters
- Email Filters
- DNS-Based Content Filters
- Web Filters

Benefits of Content Filters
- Block access to malicious sites
- Blocking access before initiating malicious download
- Increase bandwith and speed of connection
- Increase employee productivity

### Lesson 7 - Wi-Fi
- A wireless technology that allows connection of Local Area Network devices
- Disadvantage of Wi-Fi is security, bad actors can listen in to communication

Wi-Fi Security Protocols
- Wired equivelent privacy (WEP)
- Wi-Fi Protected Access (WPA)
- WPA v.3
  - A more secure handshakre
  - Easier to add devices
  - Increased cryptographic key size

### Lesson 8 - Endpoint Hardening Techniques
Why do we need this?
- The number of endpoints because of IoT devices has increased, causing unsecured devices can allow unaotorized access.

#### Categories of Endpoint Hardening
Administrative Controls
- Passwords
- User Restrictions
- Principle of Least Privilege (PoLP)

Local Endpoint Protection
- OS and startup hardening
- Boot Management
- Disk security and encryption
- Data Loss Prevention (DLP)

Endpoint Maintenance
- Auto-updates/Patching
- Policy Checks
- Backups

Endpoint Monitoring
- Endpoint Protection Platform (EPP)
- Intrusion Detection Systems (IDS)
- Endpoint Detection and Response (EDR)


##### Disk Security and Encryption
Most common way to encrypt these devices
-> Use Full Disk Encryption (FDE)

Another way to encrypt devices
-> Use Self-Encrypting Drive (SED)

### Lesson 9 - Endpoint Monitoring
Endpoint Solutions
-> Helps manage and protect various types of endpoints

Endpoint Protection Platform (EPP)
- Defensive measure against malicious attacks
- Help administrators maintain uniform software updates
- Allow monitoring 

Intrusion Detection Systems (IDS)
- Constantly scans computer for Indicator of Compromise
- Identify and stops threats

Endpoint Detection and Response (EDR)
- Predict and Recognize suspicious files and programs
- Send alerts to other connected endpoints
- Has tools to help gather data on new threats

## Nice to Know
- Captive Portal is another method to control acces to network

DLP (Data Loss Prevention)
- refers to a set of strategies, tools, and processes designed to ensure that sensitive information is not leaked, misused, or accessed by unauthorized users.

SLP (Service Location Protocol)
- Allows Devices to find and communicate with each other on a LAN wihtout manual configuration

Spam Filter Technologies:
- Bayesian filters
- Deny lists
- Allow lists
- Machine Learning Algorithms

- IEEE 802.11 standards

Risk to Wi-Fi Networks
- Bad actors can set up a fake Access Point for people to connect as free Wi-Fi

## Questions
- Why does a packet need deep inspections, can a packet transfer malicious deep inside of it?
  Answer:

- If SEG has feature like authentication and identity verification, how does one get attacked by phising on a organization?
  Answer:

- What does hardening firmware mean?
  Answer:

- How do you Physcially secure a device so that attackers don't have physical access and what how do people lock down their bios and boot time system, how does that help prevents these typse of attacks?
  Answer:
  
## Summary

