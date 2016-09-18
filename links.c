#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv){
	char* path = argv[1]; //File path is the first arg
	struct stat statbuf;

	stat(path, &statbuf);
	if (!S_ISREG(statbuf.st_mode)) {
		printf("Not a regular file.");
		return -1;
	}
	
	// Create a symbolic link
	char* newpath = malloc(sizeof(char) * (strlen(path)+5));
	strcpy(newpath, path);
	symlink(path, strcat(newpath, ".sym"));
	free(newpath);

	// Create a hard link
	newpath = malloc(sizeof(char) * (strlen(path)+6));
	strcpy(newpath, path);
	link(path, strcat(newpath, ".hard"));
	
	free(newpath);
	return 0;
}
