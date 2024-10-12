scp -i ./id_ed25519 ./test.txt hieujoyce@localhost:/home/hieujoyce/

ssh -t -i ./id_ed25519 hieujoyce@localhost ^
"^
   scp -i ~/id_ed25519 ~/test.txt root@172.17.0.3:/; ^
   ssh -t -i ~/id_ed25519 root@172.17.0.3 ^
      \^"^
          cat /test.txt; ^
          echo \^"Co Dai\^" ^> /test.txt; ^
          cat /test.txt; ^
          bash -l^
      \^"
^" 

pause >nul