I'm facing a problem in the code whenever I'm trying to manually run the code with source file "/etc/passwd" and destination "file" Like
	./bbcp /etc/passwd file
After this 
	cmp -s /etc/passwd file
	OR
	diff /etc/passwd file
Not getting any output. It means there are noting the change in the source and destination file that We had created with the code.


On the other hand, whenever I'm running testcp.sh on my code, I get an error that
	/etc/passwd and file differ
in a similar way
	file and file2 differ
