import  nmap 
nm = nmap.PortScanner()
nm.scan ( '8.8.8.8' ,  '53' )
nm.command_line () 
'nmap -oX - -p 22-443 -sV 8.8.8.8' 
nm .scaninfo () 
{'tcp': {'services': '22-443', 'method': 'connect'}}
nm[ '8.8.8.8' ].hostname() 
'localhost' 
nm['8.8.8.8'].state()
'up' 
nm['8.8.8.8'].all_protocols()
['tcp'] 
nm['8.8.8.8']['tcp'].keys()
[80, 25, 443, 22, 111]
nm['8.8.8.8'].has_tcp(22)
True
nm['8.8.8.8'].has_tcp(23)
False
nm['8.8.8.8']['tcp'][53]
{'state': 'open', 'reason': 'syn-ack', 'name': 'ssh'} 
nm['8.8.8.8'].tcp(53)
{'state': 'open', 'reason': 'syn-ack', 'name': 'ssh'}
nm['8.8.8.8']['tcp'][53]['state']
'open'
print("hello world")
print(nm.all_hosts())
for host in nm.all_hosts():
  print ( '---------------------------------------- ------------ ' ) 
  print('Host : %s (%s)' % (host, nm[host].hostname())) 
  print('State : %s' % nm[host].state()) 
  for proto in nm[host].all_protocols():

    print ( '----------' ) 
    print('Protocol : %s' % proto)
 
    lport = nm[host][proto].keys()

    #lport.sort() 
    for port in lport:
      print ('port : %s\tstate : %s' % (port, nm[host][proto][port]['state']))