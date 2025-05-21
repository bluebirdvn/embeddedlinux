#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int readfile(){
	int fd;
	int ret;
	char buf[125] = {0};
	fd = open("./hello.txt", O_RDONLY);
	if(-1 == fd){
		cout<<"open error from readfiel"<<endl;
		return 1;
	}
	cout<<"open successfully"<<endl;
	ret = read(fd, buf, 11);
	if(-1 == ret){
		cout<<"read erorr"<<endl;
		close(fd);
		return 1;
	}
	cout<<"read "<< ret<< "bytes" << buf<<endl;
	close(fd);
	return 0;
	}

int main(){
	int fd;
	fd = open("./hello.txt", O_WRONLY|O_CREAT|O_EXCL, 0644);
	if(-1 == fd){
		cout<<"open erorr from main"<<endl;
		return 1;
	}
	cout<<"open successful"<<endl;
	int ret = write(fd, "hello world", 11);
	if(-1 == ret){
		cout<<"write error"<<endl;
		close(fd);
		return 1;
	}
	cout<<"Write success 11 byte"<<endl;
	close(fd);
	int a = readfile();
	cout<<a<<endl;
	return 0;
	}


