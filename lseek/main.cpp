#include<iostream>
#include<cerrno>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>

using namespace std;
int main(int count, char** argv){
	char buffer[1024];
	int fd1, fd2;
	int ret;
	if(count!=3){
		cout<<"usage: "<<argv[0]<<endl;
	}else
		return -1;
	fd1 = open(argv[1],O_RDONLY);
	if(-1 == fd1){
		cout<<"open file unsuccessfullly"<<endl;
		strerror(errno);
		return -1;
	}
	fd2 = open(argv[2], O_WRONLY|O_CREAT|O_EXCL,0745);
	if(-1 == fd2){
		cout<<"open file write unsuccessfully"<<endl;
		strerror(errno);
		ret = -1;
		goto error1;
	}
	while((ret = read(fd1, buffer, sizeof(buffer)))>0){
		if(write(fd2, buffer, ret) != ret){
			cout<<"error writing into file"<<endl;
			strerror(errno);
			goto error2;
		}}
	if(ret == -1){
		cout<<"error reading file"<<strerror(errno)<<endl;
		goto error2;
	}

	ret =0;
error2:
	close(fd2);
error1:
	close(fd1);
	
	return 0;

}

