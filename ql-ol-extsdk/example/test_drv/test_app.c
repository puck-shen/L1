//test_app.c
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd =0;
	int val = 1;

	if (argc != 2)
	{
		printf("Usage :\n");
		printf("%s <on|off>\n", argv[0]);
		return 0;
	}

	fd = open("/dev/led1", O_RDWR);
	if (fd < 0)
	{
		printf("open failed!\n");
        return -1;
	}

    printf("open /dev/led1 successed,using device...\n");

	if (strcmp(argv[1], "on") == 0)
	{
		val  = 1;
	}
	else
	{
		val = 0;
	}
	
	write(fd, &val, 4);

    sleep(5);

    printf("end of using device,closing device\n");
    close(fd);
    printf("exit from main\n");

	return 0;
}