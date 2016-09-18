#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
	struct stat buf;
	stat(argv[1], &buf);
	printf("Major %i\n", major(buf.st_dev));
	printf("Minor %i\n",minor(buf.st_dev));
	printf("Inode %i\n",buf.st_ino);
	
	if (S_ISLNK(buf.st_mode))
		printf("Symbolic link\n");
	else if(S_ISREG(buf.st_mode))
		printf("Regular file\n");
	else if(S_ISDIR(buf.st_mode))
		printf("Directory\n");
	// Etc.
	printf("Last access %s\n", ctime(&(buf.st_atime))); 
	return 0;
}
