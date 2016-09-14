#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char** argv){
	
	DIR* dir = opendir(argv[1]);

	chdir(argv[1]);
	struct dirent* ent = readdir(dir);
	while(ent != NULL){
		printf("%s",ent->d_name);
		struct stat info;
		
		lstat(ent->d_name, &info);
		
		if (S_ISDIR(info.st_mode)) printf("/\n");
		else if (S_ISLNK(info.st_mode)) {
			printf("->");
			char link[pathconf("/", _PC_PATH_MAX)+1];
			ssize_t len = readlink(ent->d_name , link, sizeof(link));
			link[len] = '\0';
			printf("%s\n", link);
		}
		else if (S_ISREG(info.st_mode)){
			if (info.st_mode & S_IXUSR) printf("*");
			printf("\n");
		}
		ent = readdir(dir);
	}
 	return 0;
}
