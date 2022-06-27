import os
import sys
import subprocess 

def scan(base, ceiling):
    base_suff = int(base.split('.')[-1])
    for i in range(base_suff, ceiling+1):
        hostname = '.'.join(base.split('.')[:-1] + [str(i),])
        try:
            with open('/dev/null') as f:
                response = subprocess.check_call(['ping', '-c1', '-W2',hostname], stdout=f)
        except subprocess.CalledProcessError:
            print(hostname + ': ', 'DOWN')
        else:
            print(hostname + ': ', 'UP')
def main():
    base = sys.argv[1]
    ceiling = int(sys.argv[2])
    scan(base, ceiling)
if __name__ == "__main__":
    main()