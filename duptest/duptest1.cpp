#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
#include<string.h>

int main(void){
	int fd1, fd2;
	fd1 = open("./test.txt", O_WRONLY|O_TRUNC|O_APPEND);
	if(-1==fd1){
		perror("open fd1 error");
		return 1;
	}

	fd2= open("./test.txt", O_WRONLY);
	if(-1==fd2){
		perror("open fd2 error");
		close(fd1);
		return 1;
	}
	write(fd1, "Hello world", strlen("Hello world"));
	
	write(fd2, "Hello world in fd2", strlen("Hello world in fd2"));
	
	close(fd1);
	close(fd2);
	return 0;
}

