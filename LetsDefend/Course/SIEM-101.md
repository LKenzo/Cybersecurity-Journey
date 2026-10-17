# SIEM 101
10/17/2026

## SIEM Introduction
Secuirty Information and Event Managemenet (SIEM) is a security solution that collects data and turn them into meaningful decisions, SIEM also detects potential threats. 

Some of the SIEM Products:
<img width="665" height="722" alt="image" src="https://github.com/user-attachments/assets/772e0ef4-22d6-4dff-b217-ce41320d8849" />

## Log Collection
SIEM collects data from log collection process.

### What is the difference between log and logging?
log is a file that contains events that occur in an os or other software. Logging is the act of keeping a log.

To process all the data we need SIEM to collect all of the logs from various place (hosts, Firewall, Server log, Porxy, etc.).

### Log Agents 
Log Agents can take actions on the logs it collects before forwarding them to the target. Ex: dividing a log with "username: LetsDefend; account: Administrator" into 2 parts

Most SIEM has their own agent software, and it has more capabilities than syslog (one of the most popular network protocol log transfer).

### Agentless
Agentless uses SSH connection or WMI to send logs, it needs username and password of the log server (risking password be stolen). Agentless has limited capabilites and credentials are wrapped in the network.

## Log Aggregation and Parsing
Log Aggregator is the first place where genereated logs are sent. We can edit those logs to send only desired parts before sending them to other destination.

### EPS (Events Per Second)
- Scaling the Aggregator 
- Log Aggregator Process
- Log Modification

## Log Storage
