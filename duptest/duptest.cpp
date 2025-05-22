#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(void){
	int fd1;
	int fd2;
	int ret;
	char buf[100];
	fd1 = open("./test.txt", O_RDWR|O_TRUNC);
	if(-1==fd1){
		perror("open error");
		return 1;
	}
	fd2 = dup2(fd1,1000);
	cout<<"fd2 = "<<fd2<<endl;
	if(-1==fd2){
		perror("dup error");
		close(fd1);
		return 1;
	}
	const char *msg = "hello world";
	ret = write(fd1, msg, strlen(msg));
	if(-1 == ret){
		perror("write error");
		close(fd1);
		close(fd2);
		return 1;
	}
	lseek(fd2, 0, SEEK_SET);
	ret = read(fd2, buf, strlen(msg));
	if(-1==ret){
		perror("read error");
		close(fd1);
		close(fd2);
		return 1;
	}
	cout<<"read: "<< buf<<endl;
	close(fd1);
	close(fd2);
	return 0;
}





