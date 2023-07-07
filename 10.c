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
    // socklen_t recv_host_len; /* 端的地址长度，用于 recvfrom */
    // socklen_t send_host_len; /* 端的地址长度，用于 recvfrom */
    //创建套接字
    int server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sock == -1) 
    {
        perror("socket() failed");
        return -1;
    }

    //绑定IP和端口到套接字
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));  //每个字节都用0填充
    server_addr.sin_family = AF_INET;  //使用IPv4地址
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //具体的IP地址
    server_addr.sin_port = htons(6000);  //端口
    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));


    int epollfd = epoll_create(1);
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = server_sock;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, server_sock, &event);

    while (1) 
{
    struct epoll_event events[MAX_EVENTS];
    int nready = epoll_wait(epollfd, events, MAX_EVENTS, 5);//返回值为就绪的文件描述符的数量,错误返回-1

    for (int i = 0; i < nready; i++) 
    {
        // 如果是UDP socket，接收并处理数据
        if (events[i].data.fd == server_sock) 
        {
            struct sockaddr_in client_addr;
            char buf[MAX_BUF_SIZE];
            socklen_t client_addrlen = sizeof(client_addr);

            int recvlen = recvfrom(server_sock, buf, MAX_BUF_SIZE, 0, (struct sockaddr*)&client_addr, &client_addrlen);
            // 处理接收到的数据
            sendto(server_sock,buf,MAX_BUF_SIZE,0,(struct sockaddr*)&client_addr, client_addrlen);
        }
    }
}



    //客户端
    
    //创建套接字
    int client_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_sock == -1) 
    {
        perror("socket() failed");
        return -1;
    }

    //绑定IP和端口到套接字
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));  //每个字节都用0填充
    client_addr.sin_family = AF_INET;  //使用IPv4地址
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //具体的IP地址
    client_addr.sin_port = htons(6001);  //端口
    bind(client_sock, (struct sockaddr*)&client_addr, sizeof(client_addr));
    

    int epollfd = epoll_create(1);
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = server_sock;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, server_sock, &event);

    while (1) 
{
    struct epoll_event events[MAX_EVENTS];
    int nready = epoll_wait(epollfd, events, MAX_EVENTS, 5);//返回值为就绪的文件描述符的数量,错误返回-1

    for (int i = 0; i < nready; i++) 
    {
        // 如果是UDP socket，接收并处理数据
        if (events[i].data.fd == server_sock) 
        {
            struct sockaddr_in client_addr;
            char buf[MAX_BUF_SIZE];
            socklen_t client_addrlen = sizeof(client_addr);

            int recvlen = recvfrom(server_sock, buf, MAX_BUF_SIZE, 0, (struct sockaddr*)&client_addr, &client_addrlen);
            // 处理接收到的数据
            sendto(server_sock,buf,MAX_BUF_SIZE,0,(struct sockaddr*)&client_addr, client_addrlen);
        }
    }
}


  
    //关闭套接字
    close(server_sock);
    return 0;
}