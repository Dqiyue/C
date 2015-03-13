#include<stdio.h>

int main()
{
	unsigned int T;
	int N,num;
	int maxsum,temp,sum,p1,pend;
	int a = scanf("%d",&T);
	int i;
	if(a && T<=20 && T>=1){
		for(i=1;i<=T;i++){
			sum = 0;
			maxsum = -1001;
			p1 = 1;
			temp = 1;
			scanf("%d",&N);
			int j;
			for(j=1;j<=N;j++){
				scanf("%d",&num);
					sum += num;
				if(sum > maxsum){
					maxsum = sum;
					p1 = temp;
					pend = j;
				}
				if(sum < 0){
					sum = 0;
					temp = j + 1;
				}
					
			}
			printf("Case %d:\n",i);
			printf("%d %d %d\n",maxsum,p1,pend);
			if(i!=T){
				printf("\n");
			}
		}
	}
	return 0;
}
