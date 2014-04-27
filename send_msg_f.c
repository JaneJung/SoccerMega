#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <linux/fb.h>
#include <string.h>

#define BLUETOOTH_DEV "/dev/ttyUSB0"
#define BAUDRATE 9600

int main(void)
{
    int fd;
    char w1;
    char r1;
    char buf[255];
    int i=0;
    int check_read = 0;
    int check_write;
    
    char c1[2];
    char ch;
    int cnt = 0;
    char gar;
    
    char data[10] = {'a', 'b', 'c','d','e','f','g','h', 'i','j'};
       
    fflush(stdin);
    
    struct termios oldtio,newtio, options;

    if((fd = open(BLUETOOTH_DEV, O_RDWR | O_NOCTTY ))< 0)
    {
        perror("open error");
        exit(-1);
    }

    fcntl(fd, F_SETFL);            // Configure port reading
    tcgetattr(fd, &options);       // Get the current options for the port
    cfsetispeed(&options, B9600);    // Set the baud rates to 230400
    cfsetospeed(&options, B9600);

    options.c_cflag |= (CLOCAL | CREAD);    // Enable the receiver and set local mode
    options.c_cflag &= ~PARENB;             // No parity bit
    options.c_cflag &= ~CSTOPB;             // 1 stop bit
    options.c_cflag &= ~CSIZE;              // Mask data size
    options.c_cflag |=  CS8;                // Select 8 data bits
    options.c_cflag &= ~CRTSCTS;            // Disable hardware flow control

    // Enable data to be processed as raw input
    options.c_lflag &= ~(ICANON | ECHO | ISIG);

    // Set the new attributes
    tcsetattr(fd, TCSANOW, &options);


    printf("ready\n");
    
    while(1) {
    	
    	(void)read(fd, &ch,1);
		
		c1[0] = c1[1];
		c1[1] = ch;
		
		printf("recv[%d] : %s\n", cnt++, c1);
		
		if(c1[0] == 'G' && c1[1] == 'O') {
			(void)read(fd, &ch,1);
			break;
		}
	}
	fflush(stdin);
	fflush(stdout);
	
    while(1) {
		
		for (i =0 ; i < 10;i++){
			(void)write(fd, &data[i%10], 1);
			r1 = 0x0;
			while( r1 != 0xa ) {
				check_read += read(fd, &r1,1);
				printf("check_Read : (%d), r1 : (%c)(%X) ", check_read, r1, r1);
			}
		}  

		fflush(stdin);
		while( r1 != 0xa ) {
			check_read += read(fd, &r1,1);
			printf("check_Read : (%d), r1 : (%c)(%X) ", check_read, r1, r1);
		}
	
		r1 = 0x0;
	}

    return 0;
}

