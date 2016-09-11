/*************************************************************************
	> File Name: setreuid_test.c
	> Author:Kylin 
	> Mail:Dqiyue@foxmail.com
	> Created Time: 2016年09月07日 星期三 16时17分28秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    char* shell[2];
    setreuid(0,0);
    shell[0] = "/bin/sh";
    shell[1] = 0;
    execve(shell[0],shell,NULL);
    return 0;
}
