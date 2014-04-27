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

int send_msg(int fd, char *wmsg){

	int i;
	char wBuf[100];

    strcpy(wBuf, wmsg);


    for (i=0; i<strlen(wBuf); i++)
    {
    	//if ( wBuf[i] == 0 )
        (void)write(fd, &wBuf[i], 1);
        //printf("send %d %c %d\n",i,wBuf[i],wBuf[i]);
        
    }
    sleep(2);
	return 1;
	
}

int recv_msg(int fd){

	int i;
	char rBuf[100];

	for (i=0; i<50; i++)
	{
		if( rBuf[2*i] == '\r' && i > 0 )
			break;
		(void)read(fd, &rBuf[2*i],1);
//		printf("read : [%d]\n", 2*i);
		
//		printf("read : %d : %c\n",rBuf[2*i],rBuf[2*i]);
		
		
		(void)read(fd, &rBuf[2*i+1],1);
//		printf("read : [%d]\n", 2*i+1);
//		printf("read : %d : %c\n",rBuf[2*i+1],rBuf[2*i+1]);


	}
	rBuf[2*i+2] = '\0';
	printf("Read\n");
	printf("msg : %s\n",rBuf);
	
	
	return i;
	
	sleep(2);
}


int main(void)
{
    int fd;
    char w1[100];
    char r1[100];
    char buf[255];
    int i=0;
    int check_read;
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
    	printf("enter msg : ");
    
		scanf("%s", &w1);

		send_msg(fd, w1);
		printf("send msg : %s\n", w1);
		
		
		check_read = recv_msg(fd);
		printf("check read : %d\n", check_read);
		
	}


/*
    strcpy(w1, "AT+MODE,0");
    //strcpy(w1, "AT+SECDEVICE?");
    for (i=0; i<strlen(w1); i++)
    {
        (void)write(fd, &w1[i], 1);
        printf("send %d %c %d\n",i,w1[i],w1[i]);
    }

    sleep(2);

    strcpy(w1, "AT+NAMEqwerqwer");
    //strcpy(w1, "AT+SECDEVICE?");
    for (i=0; i<strlen(w1); i++)
    {
        (void)write(fd, &w1[i], 1);
        printf("send %d %c %d\n",i,w1[i],w1[i]);
    }

    sleep(2);
    strcpy(w1, "AT+PINCODE8888\r");
    for (i=0; i<strlen(w1); i++)
    {
        (void)write(fd, &w1[i], 1);
        printf("send %d %c %d\n",i,w1[i],w1[i]);
    }
    sleep(2);


    strcpy(w1, "ATZ");
    //strcpy(w1, "AT+SECDEVICE?");
    for (i=0; i<strlen(w1); i++)
    {
        (void)write(fd, &w1[i], 1);
        printf("send %d %c %d\n",i,w1[i],w1[i]);
    }


    sleep(2);


    printf("Sended\n");

    for (i=0; i<90; i++)
    {
        (void)read(fd, &w2[i],1);
        printf("read : [%d]\n", i);
        printf("read : %d : %c\n",w2[i],w2[i]);
    }
    w2[i+1] = '\0';
    printf("Read\n");
    printf("msg : %s\n",w2);*/

    return 0;
}

