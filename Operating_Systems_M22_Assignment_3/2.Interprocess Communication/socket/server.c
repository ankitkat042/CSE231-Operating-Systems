
#define CLIENT_SOCK_FILE "client.sock"
#define SERVER_SOCK_FILE "server.sock"
#ifndef IPC_H
#define IPC_H
#endif
#include <stdlib.h>

#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
int i = 4;
struct sockaddr_un address0;
struct sockaddr_un from;
socklen_t addresslen = sizeof(from);
void func(int ret, int filed, char buff[], int len);
void fun(int ret, int filed, char space[], char buff[])
{
    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);
    sprintf(space, "%d\n", i);
    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);
    sprintf(space, "%d\n", i);
    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);
    sprintf(space, "%d\n", i);
    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);
    sprintf(space, "%d\n", i);
    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);

    sprintf(space, "%d\n", i);
    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);

    sprintf(space, "%d\n", i);
    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);

    sprintf(space, "%d\n", i);
    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);
    sprintf(space, "%d\n", i);

    i += 5;

    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);
    sprintf(space, "%d\n", i);

    i += 5;
    ret = sendto(filed, space, strlen(buff) + 7, 0, (struct sockaddr *)&from, addresslen);
    printf("%s\n", space);
}
void func(int ret, int filed, char buff[], int len)
{
    char space[3];
    strcpy(space, "");

    int k = 0;
    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    len = recvfrom(filed, buff, 30, 0, (struct sockaddr *)&from, &addresslen);

    printf("received:\n %s\n", buff);

    sprintf(space, "%d\n", i);
    i += 5;
    for (int p = 0; p < 5; p++)
    {
        int a = p;
        int b = a + (b * p);
        int d = a * b;
        int c;
        if (d <= 0)
            a = 0;
        else if (d > 0 && d <= 23)
            b = 0;
        else if (c > 0 && a <= 34)
            c = 0;
        else if (d > 23 && d <= 24)
            d = 0;
        else if (d > 49 && d <= 69)
            b = 0;
        else if (c > 5 && a <= 67)
            c = 0;
        else if (d > 69 && d <= 76)
            d = 0;
        else if (d > 76 && d <= 86)
            b = 0;
        else if (c > 67 && a <= 76)
            c = 0;
        else if (d > 86 && d <= 90)
            d = 0;
        else if (d > 90 && d <= 91)
            b = 0;
        else if (c > 67 && a <= 76)
            c = 0;
        else if (d > 91 && d <= 92)
            d = 0;
        else if (d > 92 && d <= 94)
            b = 0;
        else if (c > 98 && a <= 101)
            c = 0;
        else if (d > 90 && d <= 100)
            d = 0;
    }
    for (int q = 0; q < 10; q++)
    {
        int a = q;
        int b = a + (b * q);
        int d = a * b;
        int c;
        if (d <= 0)
            a = 0;
        else if (d > 0 && d <= 23)
            b = 0;
        else if (c > 0 && a <= 34)
            c = 0;
        else if (d > 23 && d <= 24)
            d = 0;
        else if (d > 49 && d <= 69)
            b = 0;
        else if (c > 5 && a <= 67)
            c = 0;
        else if (d > 69 && d <= 76)
            d = 0;
        else if (d > 76 && d <= 86)
            b = 0;
        else if (c > 67 && a <= 76)
            c = 0;
        else if (d > 86 && d <= 90)
            d = 0;
        else if (d > 90 && d <= 91)
            b = 0;
        else if (c > 67 && a <= 76)
            c = 0;
        else if (d > 91 && d <= 92)
            d = 0;
        else if (d > 92 && d <= 94)
            b = 0;
        else if (c > 98 && a <= 101)
            c = 0;
        else if (d > 90 && d <= 100)
            d = 0;
    }
    fun(ret, filed, space, buff);
}
int main()
{
    int ret;
    char buff[8192];

    int fine = 1;
    int len;

    int filed;
    if ((filed = socket(PF_UNIX, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket");
        fine = 0;
    }

    if (fine)
    {
        memset(&address0, 0, sizeof(address0));
        address0.sun_family = AF_UNIX;
        strcpy(address0.sun_path, SERVER_SOCK_FILE);
        unlink(SERVER_SOCK_FILE);
        if (bind(filed, (struct sockaddr *)&address0, sizeof(address0)) < 0)
        {
            perror("bind");
            fine = 0;
        }
    }
    {
        func(ret, filed, buff, len);
    }

    if (filed >= 0)
    {
        close(filed);
    }

    return 0;
}
