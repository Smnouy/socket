#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>a
#include <sys/socket.h>
#define BUFFER_SIZE 1024
int main(){
    char buffer[BUFFER_SIZE];     				//buffer数组用来存放客户端发送的消息
    while(1)
{
	scanf("%s",buffer);					//客户端发送的消息

    	//创建套接字
   	int sock = socket(AF_INET, SOCK_STREAM, 0);

    	//向服务器（特定的IP和端口）发起请求
    	struct sockaddr_in serv_addr;
    	memset(&serv_addr, 0, sizeof(serv_addr));  		//每个字节都用0填充
    	serv_addr.sin_family = AF_INET;  			//使用IPv4地址
    	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  	//具体的IP地址
   	serv_addr.sin_port = htons(1234);  			//端口
    	connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); //向服务器发送连接请求
	write(sock,buffer,sizeof(buffer));				//向服务器发送数据
        if(buffer[0]=='e' && buffer[1]=='x' && buffer[2]=='i' && buffer[3]=='t')
{
                printf("The End.\n");
                break;
}

    	//关闭套接字
    	close(sock);
}
    return 0;
}


