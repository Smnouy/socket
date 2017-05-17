#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define BUFFER_SIZE 1024

int main()
{
    char buffer[BUFFER_SIZE];  					//数据接收缓冲区

    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  			//每个字节都用0填充
    serv_addr.sin_family = AF_INET;  				//使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  	//具体的IP地址
    serv_addr.sin_port = htons(1234);  				//端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));	//将套接字和IP地址、端口号绑定
    printf("Server Socket Port:%d\n",ntohs(serv_addr.sin_port));

    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);

    //接收客户端请求
    while(1)
{
    struct sockaddr_in cli_addr;				//建新的套接字用于接受accept()的返回值，即表示接受了客户端的连接
    socklen_t cli_addr_size = sizeof(cli_addr);
    int cli_sock = accept(serv_sock,(struct sockaddr*)&cli_addr, &cli_addr_size);
    memset(buffer,0,sizeof(buffer));
    read(cli_sock,buffer,sizeof(buffer)-1);   			//接受客户端发送的数据
    if(buffer[0]=='e' && buffer[1]=='x' && buffer[2]=='i' && buffer[3]=='t')
    {
		printf("The End.\n");
		break;
    }
    else
    printf("%s\n",buffer);
    close(cli_sock);
}
    close(serv_sock);						//关闭套接字
   // printf("The End.\n");
    return 0;
}
