#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <time.h>
#define MAX_EVENTS 20
#define MAX_BUF_SIZE 100
#define GET_MAX 1000

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("usage: %s port", argv[0]);
        return -1;
    }

    char mess[15];
    char get_mess[GET_MAX]; /* 后续版本使用 */

    socklen_t recv_host_len; /* 端的地址长度，用于 recvfrom */
    socklen_t send_host_len; /* 端的地址长度，用于 recvfrom */
    
    //将套接字和IP、端口绑定
    struct sockaddr_in recv_host, send_host;

    //创建套接字
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) 
    {
        perror("socket() failed");
        return -1;
    }
    //绑定IP和端口到套接字
    memset(&recv_host, 0, sizeof(recv_host));  //每个字节都用0填充
    recv_host.sin_family = AF_INET;  //使用IPv4地址
    recv_host.sin_addr.s_addr = htonl(INADDR_ANY);  //具体的IP地址
    recv_host.sin_port = htons(6000);  //端口
    bind(sock, (struct sockaddr*)&recv_host, sizeof(recv_host));



    /* 进入接收信息的状态 */
    socklen_t send_host_len = sizeof(send_host);
    recvfrom(sock, mess, 15, 0, (struct sockaddr *)&send_host, &send_host_len);

    /* 接收完成，关闭套接字 */
    close(sock);



    //发送端
    int sock;
    const char* mess = "Hello Server!";
    char get_mess[GET_MAX]; /* 后续版本使用 */
  

    socklen_t addr_len;

    /* 创建套接字 */
    sock = socket(PF_INET, SOCK_DGRAM, 0);

    /* 绑定 */
    memset(&recv_host, 0, sizeof(recv_host));
    recv_host.sin_family = AF_INET;
    recv_host.sin_addr.s_addr = inet_addr("127.0.0.1");
    recv_host.sin_port = htons(6000);

    /* 发送信息 */
    /* 在此处，发送端的IP地址和端口号等各类信息，随着这个函数的调用，自动绑定在了套接字上 */
    sendto(sock, mess, strlen(mess), 0, (struct sockaddr *)&recv_host, sizeof(recv_host));
    /* 完成，关闭 */
    close(sock);
  







    //关闭套接字
    close(sockfd);
    return 0;
}