#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void reader1(void *);
void reader2(void *);
void reader3(void *);
void reader4(void *);

int main(int argc, char **argv)
{
    (void) argc; 
    (void) argv;
    InitTerminalDriver();
    InitTerminal(1);
    InitTerminal(2);

    sleep(5);

    ThreadCreate(reader1, NULL);
    ThreadCreate(reader2, NULL);
    ThreadCreate(reader3, NULL);
    ThreadCreate(reader4, NULL);


    ThreadWaitAll();

    exit(0);
}

void
reader1(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("1: Doing ReadTerminal...  \n");
    fflush(stdout);
    status = ReadTerminal(1, buf, 10);
    int i;
    for (i = 0; i < status; i++) {
        printf("%c", buf[i]);
    }
    printf("\n");
    printf("'R1 Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader2(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("2: Doing ReadTerminal... \n");
    fflush(stdout);
    status = ReadTerminal(1, buf, 10);
    int i;
    for (i = 0; i < status; i++) {
        printf("%c", buf[i]);
    }
    printf("\n");
    printf("'R2 Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader3(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("3: Doing ReadTerminal... \n");
    fflush(stdout);
    printf("Read Terminal Chars Reader 2\n");

    status = ReadTerminal(2, buf, 10);
    int i;
    for (i = 0; i < status; i++) {

        printf("R3: %c\n", buf[i]);
    }
    printf("\n");
    printf("'R3 Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader4(void *arg)
{
    (void) arg;
    int status;
    char buf[100];

    printf("4: Doing ReadTerminal...\n");
    fflush(stdout);
    status = ReadTerminal(2, buf, 10);
    int i;
    printf("Read Terminal Chars Reader 4\n");
    for (i = 0; i < status; i++) {
        printf("R4: %c\n", buf[i]);
    }
    printf("\n");
    printf("'R4 Done: status = %d.\n", status);
    fflush(stdout);
}