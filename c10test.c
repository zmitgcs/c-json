#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <time.h>
#define UNIX_UDP_SOCKET_ADDR "unixUDP.socket"
#define UNIX_TCP_SOCKET_ADDR "unixTCP.socket"
#define BUF_SIZE 100

void UdpServerThread()
{
    int server_sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (server_sockfd < 0)
    {
        printf("create socket fail\n");
        return;
    }
    printf("create socketfd:%d\n", server_sockfd);

    //绑定IP和端口到套接字,初始化服务器地址
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));  //每个字节都用0填充
    server_addr.sin_family = AF_INET;  //使用IPv4地址
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //具体的IP地址
    server_addr.sin_port = htons(6000);  //端口
    if(bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind server socket error!");
        close(server_sockfd);
        return -1;
    }

    size_t size = 0;
    char buf[BUF_SIZE] = {0};
    while(1)
    {
        size = recvfrom(server_sockfd, buf, BUF_SIZE, 0, NULL, NULL);
        //size = read(sockfd, buf, BUF_SIZE);
        if (size > 0)
        {
            PRINT("recv:%s\n", buf);
        }
    }
}

void UdpClientThread()
{
    int sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("create socket fail\n");
        return;
    }
    printf("create socketfd:%d\n", sockfd);

    struct sockaddr_in client_addr;
    memset (&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_UNIX;
    strcpy(addr.sun_path, UNIX_UDP_SOCKET_ADDR);


   
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //具体的IP地址
    client_addr.sin_port = htons(6000);  //端口
    bind(sock, (struct sockaddr*)&recv_host, sizeof(recv_host));

    while(1)
    {
        static int i = 0;
        printf("hello world!");
        std::string str("helloUDP" + std::to_string(++i));
        sendto(sockfd, str.c_str(), str.length(), 0, (struct sockaddr *)&addr, sizeof(addr));
        sleep(1);
    }
}

int main()
{
    unlink(UNIX_UDP_SOCKET_ADDR);
    unlink(UNIX_TCP_SOCKET_ADDR);

    // thread th1(UdpServerThread);
    // thread th2(UdpClientThread);

    // thread th3(TcpServerThread);
    // thread th4(TcpClientThread);

    // th1.join();
    // th2.join();

    // th3.join();
    // th4.join();

    PRINT("hello\n");
}


