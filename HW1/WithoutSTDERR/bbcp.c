#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>

void dataCopy(char *source, char*dest){
    FILE *readFile;
    FILE *writeFile;
    /* open the file for writing */
    readFile = fopen(source, "rb");
    
    /* open the file for writing */
    writeFile = fopen(dest, "wb");

    if (readFile == NULL || writeFile == NULL) {
        exit(1);
    }

    while(!feof(readFile)){
        char readBuffer[1022];
        int readError = fread(&readBuffer, sizeof(char), 1022, readFile);
        if(readError < 0){
            exit(1);
        }

        int writeError1 = fwrite(&readBuffer, sizeof(char), readError, writeFile);
        if(writeError1 < 0){
            exit(1);
        }
		if (readFile == NULL || writeFile == NULL) {
			exit(1);
		}
    }   
	if (readFile == NULL || writeFile == NULL) {
        exit(1);
    }
    if(fclose(readFile) < 0|| fclose(writeFile) < 0){
        exit(1);
    }
    exit(0);
}


int main(int argc, char** argv) {

	if( (argc != 3) || (access(argv[1], R_OK)) || (!strcmp(argv[1], argv[2]))) { 
		// arguments are missings or source and destination same or read access not present
		exit(1);
	}

	struct stat fileOrDirState;
	stat(argv[1], &fileOrDirState);
	
	if(!S_ISREG(fileOrDirState.st_mode)) {
		exit(1);
	}

	stat(argv[2], &fileOrDirState);
	if(!mkdir(dirname(strdup(argv[2])),0777)){
		exit(1);
	}
	else if(S_ISDIR(fileOrDirState.st_mode)) {
		strcat(argv[2],"/");
		strcat(argv[2],basename(strdup(argv[1]))); 
	}

	char copyArgv1[500] = ".";	
	strcat(copyArgv1,"/");
	strcat(copyArgv1,argv[1]);
	if(!strcmp(copyArgv1,argv[2])){
		exit(1);
	}
	
    dataCopy(argv[1],argv[2]);
}