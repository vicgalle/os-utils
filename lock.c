#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv){
	int fd = open(argv[1],O_RDWR);
	struct flock lock;
	
	//Init the structure
	memset (&lock, 0, sizeof(lock));
	fcntl(fd, F_GETLK, &lock);
	
	if (lock.l_type == F_UNLCK){
		printf("Get the lock\n");
		lock.l_type = F_WRLCK;
		fcntl(fd, F_SETLK, &lock);
		const time_t act = time(0);
		char* hour;
		hora = ctime(&act);
		write(fd, hour, strlen(hour));
		sleep(30);
		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
	}
	else printf("Locked. We left as if nothing happened.\n");
	close(fd); 
	return 0; 

}
