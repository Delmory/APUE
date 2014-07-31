#include "apue.h"
#include <fcntl.h>

int main(){
	char buf1[] = "abcdefghij";
	char buf2[] = "ABCDEFGHIJ";
	int fd;

	if((fd = creat("file.hole", FILE_MODE)) == -1 )
		err_sys("creat error");
	if(write(fd, buf1, 10) != 10)
		err_sys("write error");
	if(lseek(fd, 16384, SEEK_SET) == -1)
		err_sys("lseek error");
	if(write(fd, buf2, 10) == -1)
		err_sys("write error 2");

	exit(0);
}
