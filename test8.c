
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void reader(void *);

int main(int argc, char **argv)
{
    (void) argc; 
    (void) argv;
    InitTerminalDriver();
    InitTerminal(1);
    sleep(5);

    ThreadCreate(reader, NULL);

    ThreadWaitAll();

    exit(0);
}

void
reader(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(1, buf, 100);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}