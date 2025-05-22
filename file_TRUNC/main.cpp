#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
#include<string.h>
int main(void){
	int fd;
	fd = open("./test.txt", O_RDONLY|O_APPEND|O_WRONLY);
	
	if (-1 == fd){
		perror("open error");
		return 1;
	}
	int ret;
	const char *msg = "Da ghi them vao cuoi file\n";
	ret = write(fd, msg, strlen(msg));
	if(-1==ret){
		perror("write error");
		close(fd);
		return 1;
	}	
	close(fd);
	return 0;
}

