CC = arm-none-linux-gnueabi-gcc
CFLAGS = -Wall
-OPTIONS = -g

cli_object = client.c

serv_object = server.c

all: cli serv

cli: $(cli_object)
		$(CC) -o cli $(OPTIONS) $(cli_object)

serv: $(serv_object)
		$(CC) -o serv $(OPTIONS) $(serv_object)

clean:
		rm -rf *.o cli serv *~
