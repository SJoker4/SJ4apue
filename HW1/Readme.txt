Iam getting the following problems when iam executing bbcp.c
Tried my best to debug these. Some are termed as expected success but due to failed command, the test cases failed.

6 test cases are failing out of 30

Expected failure, but command returned 0:
/root/sugamjoker/bbcp file file2
Files '/etc/passwd' and 'file' differ.
Files 'big' and 'file' differ.
cp: existing: No space left on device 
Expected success, but command failed:
   /root/sugamjoker/bbcp small existing
Files 'small' and 'existing' differ.
./testcp.sh: cannot create file1: file system full
Files 'file1' and "file2' differ.
/testcp.sh: 6/30 tests failed.
