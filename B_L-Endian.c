#include<stdio.h>

void main(void)
{       
	int x = 1;
	if(*(char *)&x == 1)    //change int_t to char_t ,if it is little-endian "1" will be got,else "0" will be got
		printf("little-endian\n");
	else
		printf("big-endian\n");
}
