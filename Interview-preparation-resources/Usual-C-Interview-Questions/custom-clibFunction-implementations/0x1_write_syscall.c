/*************************************************************************
	Write to the console withot using stdio.h
*************************************************************************/

#include <unistd.h>
#include <string.h>

/*
	1 = std input
	0 = std o/p
	2 = std error

	To understand more on how this program is implemented, visit - https://man7.org/linux/man-pages/man2/write.2.html
*/

int main(void)
{
	size_t len=0;
	int msg_len=0;

	char buffer[100];

	strncpy(buffer, "This is printed using write() syscall instead of printf()\n", 99);

	msg_len = strlen(buffer);

	len = write(1, buffer, msg_len);

	return 0;
}