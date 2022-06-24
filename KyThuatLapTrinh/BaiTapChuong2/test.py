import sys
import os
import re
ver = sys.version
pattern = re.compile('\A\d{1}.{1}\d{1}.{1}\d{1}.{1}')
ver = re.findall(pattern, ver)

print()
print(ver)
print('Running Python version ----> %s' % (ver))


def readip():
    """
    create a file named ip.txt in the folder where the script is executed.
    In the file enter one ip address or ip address range compatable with
    nmap.
    The script will read the file and insert the ip address when
    prompting for an ip address. Simply hit [Enter] to accept the IP.
    You can override the default by typing in an address.
    This allows you to quickly run several different scans with the same
    IP address.
    """

    try:
        IP = []
        f = open('ip.txt', 'r')
        for line in f:
            IP.append(line)
        f.close
    except:  # FileNotFoundError:
        IPAddress = input('Enter the IP Address or domain name: ')
        with open('ip.txt', 'w') as filehandle:
                filehandle.write(IPAddress)
        return IPAddress

    try:
        if len(IP) != 0:
            ipsaved = IP[0]
            ipsaved = ipsaved.strip('\n')
        if not ipsaved:
            IPAddress = input('Enter the IP Address or domain name: ')
        else:
            IPAddress = input('Enter the IP Address or domain name [%s]: ' % (ipsaved))
            if IPAddress == '':
                IPAddress = ipsaved
            with open('ip.txt', 'w') as filehandle:
                filehandle.write(IPAddress)
        if not IPAddress:
            IPAddress = ipsaved

        return IPAddress
    except:
        print('\n[!] An Unknown Error Occured or CTRL+C was pressed')


print('''
-1 - Print out script options -- https://nmap.org/book/nse-usage.html, https://nmap.org/book/output-formats-commandline-flags.html
     -----------------
 0 - Download Cisco Configs using SNMP -- https://nmap.org/nsedoc/scripts/snmp-ios-config.html
     -----------------
 1 - Check Cipher Suites and Certificates using ports 443, 465, 993, 995 and 3389
     https://nmap.org/nsedoc/scripts/ssl-enum-ciphers.html
     https://nmap.org/nsedoc/scripts/ssl-cert.html
     https://nmap.org/nsedoc/scripts/ssl-cert-intaddr.html
     https://nmap.org/nsedoc/scripts/ssl-known-key.html
     -----------------
 2 - Display SSH fingerprint (Host Keys) on an SSh server -- https://nmap.org/nsedoc/scripts/ssh-hostkey.html
     Display the number of algorithms that the target SSH2 server offers. -- https://nmap.org/nsedoc/scripts/ssh2-enum-algos.html
     Checks if an SSH server supports the obsolete and less secure SSH Protocol V1. - https://nmap.org/nsedoc/scripts/sshv1.html
     -----------------
 3 - Performs routing information gathering through Cisco's (EIGRP) Protocol -- https://nmap.org/nsedoc/scripts/broadcast-eigrp-discovery.html
     -----------------
 4 - Display DHCP options with the NMAP DHCP-Discover scripts
     -----------------
 5 - Nmap script to find vulnerable Samba devices such as a printer, NAS or any device that allows Windows clients to connect.
     -----------------
 6 - Brute Forcing Telnet with NMAP - Requires files of users and guesses -- https://nmap.org/nsedoc/scripts/telnet-brute.html
     -----------------
 7 - EMS - Environmental Monitoring Systems using scripts from https://github.com/digitalbond/Redpoint#enip-enumeratense
           and the Trane Tracer SC script from https://github.com/hkm/nmap-nse-scripts
     -----------------
 8 - DNS Broadcast Discover -- broadcast-dns-service-discovery
     -----------------
 9 - Banner Grab using banner-plus from HD Moore -- https://github.com/hdm/scan-tools/blob/master/nse/banner-plus.nse
     -----------------
 10 - NTP Monlist - Pull down NTP server information -- https://nmap.org/nsedoc/scripts/ntp-monlist.html
      NTP INFO - Pull down general NTP information -- https://nmap.org/nsedoc/scripts/ntp-info.html
     -----------------
 11 - Retrieves the external IP address of a NAT:ed host using the STUN protocol. -- https://nmap.org/nsedoc/scripts/stun-info.html
     -----------------
 12 - DNS Brute - Enumerate DNS hostnames by brute force guessing of common subdomains -- https://nmap.org/nsedoc/scripts/dns-brute.html
     -----------------
 13 - SMB - Various scripts for SMB servers. Make sure you are running nmap 7.50+ as there are a lot of fixes in 7.50.
     -----------------
 14 - SNMP - Is SNMP running on a Windows machine -- https://nmap.org/nsedoc/scripts/snmp-processes.html
      Grab HP printer password using SNMP
     -----------------
 15 - Scan for MS17-010 Wannacry vulnerability -- https://nmap.org/nsedoc/scripts/smb-vuln-ms17-010.html
     -----------------
 16 - MSSQL - Attempt to determine version, config info and check for blank password -- https://nmap.org/nsedoc/scripts/ms-sql-info.html
     -----------------
 17 - Run a fast ping scan on a large IP range. No service detection or port scanning is done.
     -----------------
''')

# select the OS. Posix needs sudo appeneded for some scans.
osname = os.name
if osname == "posix":
    sudo = 'sudo'
else:
    sudo = ''

#
# Select a script to run
# Validate that a script number is entered and not an IP Address
nmapTest = input('Input a number to select a script ')
while len(nmapTest) > 2:
    nmapTest = input('Enter a number to select a script not an IP address: ')

nmapTest = int(nmapTest)
if nmapTest == -1:
    # -1 Help
    print('''
    nmap options
    -iL -> Input from list of hosts/networks. Example  nmap -iL list-of-ips.txt
    -oN -> Save default output to a file. Example nmap -oN outputfile.txt
    -oX -> Save output in XML format. Example nmap -oX outputfile.xml
    -oG -> Save results in a format for grep. Example nmap -oG outputfile.txt
    -oA -> Save in all formats. Example nmap -oA outputfile
     -d -> The debug flag. Levels are 0-9. -d is = to 0, -d9 is highest
     and shouldn't be used normally.
     -v -> Add verbosity to the output
    -vv -> Add more verbosity to the output
    --script-trace -> All incoming and outgoing communication performed
      by the script is printed.
    --script-updatedb -> Update the script database. Only needed when
      new scripts are added
    --script-help=<script name> -> shows a description of what the
      script does. Example - nmap --script-help smb-vuln-cve-2017-7494
    ''')
#
if nmapTest == 0:
    # 0 Download Cisco Configs
    IPAddress = readip()
    SNMP = input('Enter SNMP Private Community String: ')
    print('--'*45)
    print()
    print(f" {sudo} nmap -sU -p 161 --script snmp-ios-config --script-args creds.snmp={SNMP} {IPAddress}")
    print()
    print(f" {sudo}  nmap -d -sU -p 161 -sC {IPAddress} <--> Run default scripts against UDP 161")
    print()
    print('--'*45)
#
elif nmapTest == 1:
    # 1 Checking Server Cipher Suites
    IPAddress = readip()
#    IPAddress=input('Enter the IP Address: ')
    print('--'*45)
    print()
    print(f"{sudo} nmap -vv --script ssl-cert,ssl-enum-ciphers -p 443,465,993,995,3389 {IPAddress}")
    print()
    print(f"{sudo} nmap --script ssl-cert-intaddr -p 443,465,993,995,3389 {IPAddress}")
    print()
    print(f"{sudo} nmap --script ssl-known-key -p 443,465,993,995,3389 {IPAddress}")
    print()
    print('--'*45)
#
elif nmapTest == 2:
    # 2 Discovering SSH Host Keys
    IPAddress = readip()
#    IPAddress=input('Enter the IP Address: ')
    print('--'*45)
    print()
    print(f"{sudo} nmap --script ssh-hostkey {IPAddress}")
    print()
    print(f"{sudo} nmap --script ssh2-enum-algos {IPAddress}")
    print()
    print(f"{sudo} nmap --script sshv1 {IPAddress}")
    print()
    print('--'*45)
#
elif nmapTest == 3:
    IPAddress = readip()
    # 3 EIGRP
    print('--'*45)
    print()
    print(f"{sudo} nmap --script=broadcast-eigrp-discovery {IPAddress}")
    print()
    print('--'*45)
#
elif nmapTest == 4:
    # 4 Troubleshooting DHCP with the NMAP DHCP-Discover script
    IPAddress = readip()
    print('--'*45)
    print()
    print(f"{sudo} nmap -sU -p67 --script broadcast-dhcp-discover")
    print(f"{sudo} nmap -sU -p67 --script dhcp-discover {IPAddress}")
    print(f"{sudo} nmap -6 --script broadcast-dhcp6-discover")

    print()
    print('--'*45)
#
elif nmapTest == 5:
    # 5 Troubleshooting IPv6 DHCP discover
    IPAddress = readip()
    print('--'*45)
    print()
    print('Download script from https://svn.nmap.org/nmap/scripts/smb-vuln-cve-2017-7494.nse')
    print(f"{sudo} nmap --script smb-vuln-cve-2017-7494 -p 445 {IPAddress}")
    print(f"{sudo} nmap --script smb-vuln-cve-2017-7494 --script-args smb-vuln-cve-2017-7494.check-version -p445 {IPAddress}")
    print()
    print('--'*45)
#
elif nmapTest == 6:
    # 6 Brute Forcing Telnet with NMAP
    IPAddress = readip()
    print('--'*45)
    print()
    print(f"{sudo} nmap -p 23 --script telnet-brute --script-args userdb=users.txt,passdb=pw4.txt {IPAddress}")
    print()
    print('--'*45)
#
elif nmapTest == 7:
    # 7 BACNET
    IPAddress = readip()
#    IPAddress=input('Enter the IP Address: ')
    print('--'*45)
    print('Identify and enumerate enumerate ICS applications and devices')
    print('--'*45)
    print('download scripts from https://github.com/digitalbond/Redpoint#enip-enumeratense')
    print(f'{sudo} nmap -sU -p 47808 -n --script bacnet-info.nse {IPAddress}')
    print(f'{sudo} nmap -sU -p 47808 -n --script BACnet-discover-enumerate {IPAddress}')
    print(f'{sudo} nmap -sU -p 47808 -n --script BACnet-discover-enumerate --script-args full=yes {IPAddress}')
#    print()
    print('--'*45)
#    print('Identify and enumerate CoDeSys V2 controllers')
#    print()
    print(f'{sudo} nmap -p 1200,2455 --script codesys-v2-discover {IPAddress}')
 #   print()
    print('--'*45)
#    print('Identify and enumerate EtherNet/IP devices from Rockwell Automation and other vendors')
#    print()
    print(f'{sudo} nmap -p 44818 --script enip-enumerate {IPAddress}')
#    print()
    print('--'*45)
#    print('Identify and enumerate Niagara Fox devices')
#    print()
    print(f'{sudo} nmap -p 1911 --script fox-info {IPAddress}')
#    print()
    print('--'*45)
#    print()
    print(f'{sudo} nmap -p 502 --script modicon-info.nse -sV {IPAddress}')
#    print()
    print('--'*45)
#    print('Identify and enumerate Omron PLCs')
#    print()
    print(f'{sudo} nmap -p 9600 --script omrontcp-info {IPAddress}')
    print(f'{sudo} nmap -sU -p 9600 --script omronudp-info {IPAddress}')
#    print()
    print('--'*45)
#    print('Identify and enumerate PC Worx Protocol enabled PLCs')
#    print()
    print(f'{sudo} nmap -p 1962 --script pcworx-info -sV {IPAddress}')
#    print()
    print('--'*45)
#    print('Identify and enumerate ProConOS enabled PLCs')
#    print()
    print('nmap -p 20547 --script proconos-info -sV', IPAddress)
#    print()
    print('--'*45)
#    print('Identify and enumerate Siemens SIMATIC S7 PLCs')
#    print()
    print('nmap -p 102 --script s7-enumerate -sV', IPAddress)
#    print()
    print('--'*45)
#    print()
#    print('Identify and enumerate Trane Trace SC Devices')
    print(f'{sudo} nmap -p 80 --script trane-info.nse {IPAddress}')
#    print()
    print('--'*45)
    print('Scans Trane Tracer SC devices. Returns Administrators name, email, phone')
    print()
    print(f'{sudo} nmap -p 80 --script http-vuln-cve2016-0870.nse {IPAddress}')
#    print()
    print('--'*45)
    print('Identify and enumerate Unitronics PLCs via PCOM protocol')
    print('https://unitronicsplc.com/Download/SoftwareUtilities/Unitronics%20PCOM%20Protocol.pdf')
    print()
    print(f'{sudo} nmap -p 20256 --script pcom-discover.nse --script-args=pcom-discover.aggressive=true  {IPAddress}')
#    print()
    print('--'*45)
    print('Enumerates SCADA Modbus slave ids (sids) and collects their device information')
    print()
    print(f'{sudo} nmap -p 502 --script modbus-discover.nse --script-args=''modbus-discover.aggressive=true'' ', IPAddress)
 #   print()
    print('--'*45)

elif nmapTest == 8:
    # 8 DNS Broadcast Discover
    print('--'*45)
    print()
    print('nmap --script=broadcast-dns-service-discovery')
    print()
    print('--'*45)
#
elif nmapTest == 9:
    # 9 Banner Grab
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -sV --script=banner-plus.nse {IPAddress}')
    print()
    print('--'*45)
#
elif nmapTest == 10:
    # 10 NTP Monlist
    #    NTP INFO
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -sU -p 123 -n --script=ntp-monlist  {IPAddress}')
#    print('%s nmap -sU -p 123 --script ntp-info %s' % (sudo, IPAddress))
    print()
    print('--'*45)
#
elif nmapTest == 11:
    # 11 STUN INFO
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -sV -PN -sU -p 3478 --script stun-info {IPAddress}')
    print()
    print('--'*45)
#
elif nmapTest == 12:
    # 12 DNS Brute
    DNSDomain = input('Enter the DNS Domain Name ')
    print('--'*45)
    print()
    print(f'nmap --script dns-brute --script-args dns-brute.threads=10,dns-brute.domain={DNSDomain}')
    print(f'nmap --script dns-brute --script-args dns-brute.srv,dns-brute.threads=10,dns-brute.domain=%s,dns-brute.hostlist=<filename>  {DNSDomain}')
    print(f'hostlist is a file of hosts strings to try. Defaults to nselib/data/vhosts-full.lst')
    print(f'http://securityblog.gr/2547/enumerate-dns-hostnames-using-nmap/ for more information')
    print()
    print('--'*45)
#
elif nmapTest == 13:
    # 13 SMB
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -p445 --script=smb-os-discovery.nse {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smb-enum-users.nse {IPAddress}')
    print(f'{sudo} nmap -F -d --script smb-enum-shares --script-args smbuser=username,smbdomain=domain,smbpass=password {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smb-brute --script-args=userdb=usernames.txt {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smb-pwdump --script-args=smbuser=administrator,smbpass=dVd0brx1,rcrack=rcrack,rtable=*.rt {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smb-brute --script-args=userdb=usernames.txt,passdb=hashes.txt {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smb-pwdump --script-args=smbuser=administrator,smbhash=dVd0brx1,rcrack=rcrack,rtable=*.rt {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smb-enum-shares,smb-ls {IPAddress}')
    print(f"{sudo} nmap -p445 --script=smb-ls --script-args 'share=c$,path=\\temp' {IPAddress}")
    print(f'{sudo} nmap -p445 --script=smb-mbenum {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smb-security-mode.nse {IPAddress}')
    print(f'{sudo} nmap -p U:137,T:139 -sU -sS --script=smb-security-mode.nse {IPAddress}')
    print(f'{sudo} nmap -p445 --script=smbv2-enabled.nse {IPAddress}')
    print(f'{sudo} nmap -p U:137,T:139 -sU -sS --script=smbv2-enabled.nse {IPAddress}')
    print()
    print('--'*45)
#
elif nmapTest == 14:
    # 14 SNMP on Windows
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -sU -p 161 --script=snmp-processes {IPAddress}')
    print('Grab HP Printer Password')
    print(f'snmpget -v 1 -c public {IPAddress} .1.3.6.1.4.1.11.2.3.9.1.1.13.0 ')
    print(f'snmpget -v 1 -c public {IPAddress} .iso.3.6.1.4.1.11.2.3.9.4.2.1.3.9.1.1.0')
    print(f'snmpget -v 1 -c internal {IPAddress} .1.3.6.1.4.1.11.2.3.9.1.1.13.0')
    print()
    print('--'*45)
#
elif nmapTest == 15:
    # 15 Basic Script Scan
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -Pn -p445 --open --max-hostgroup 3 --script smb-vuln-ms17-010 {IPAddress}')
    print()
    print('Include -d for debugging output. This will show more detail about the scan')
    print()
    print(f'{sudo} nmap -d -Pn -p445 --open --max-hostgroup 3 --script smb-vuln-ms17-010 {IPAddress}')
    print()
    print('--'*45)
#
elif nmapTest == 16:
    # 16 SQL
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -sn --script ms-sql-empty-password --script-args mssql.instance-all {IPAddress}')
    print(f'{sudo} nmap -p 445 --script ms-sql-info {IPAddress}')
    print(f'{sudo} nmap -p 1433 --script ms-sql-info --script-args mssql.instance-port=1433 {IPAddress}')
    print()
    print('--'*45)
#
elif nmapTest == 17:
    # 17 Rapid Scan of large address space
    IPAddress = readip()
    print('--'*45)
    print()
    print(f'{sudo} nmap -n -sP --min-rate 1000 --max-retries 0 --max-rtt-timeout 100ms --max-scan-delay 0 {IPAddress}')
    print()
    print('--'*45)