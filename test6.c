#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>

void writer1(void *);
void writer2(void *);
void writer3(void *);

char string2[] = "abcdefghijklmnopqrstuvwxyz\n";
int length2 = sizeof(string2) - 1;

char string1[] = "0123456789\n";
int length1 = sizeof(string1) - 1;

int
main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    InitTerminalDriver();
    InitTerminal(1);

    ThreadCreate(writer1, NULL);
    ThreadCreate(writer2, NULL);
    ThreadCreate(writer3, NULL);

    ThreadWaitAll();

    exit(0);
}

void
writer1(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(1, string1, length1);
    if (status != length1)
	fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
	    status, length1);
}

void
writer2(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(1, string2, length2);
    if (status != length2)
	fprintf(stderr, "Error: writer2 status = %d, length2 = %d\n",
	    status, length2);
}

void
writer3(void *arg)
{
    (void) arg;
    int status;

    status = WriteTerminal(1, string1, length1);
    if (status != length1)
	fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
	    status, length1);
}
