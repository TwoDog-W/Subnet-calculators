#include <stdio.h>
#include "input.h"

void input(ip_addr * p,char * str){
	error_input:
	printf("please input %s(x.x.x.x):",str);
	for(int i=3;i>=0;i--){
		int tmp=0;
		scanf("%u",&tmp);
	        if(tmp<=255&&tmp>=0){
			p->addr_one[i]=tmp;
			if(i>0){
				scanf(".");
	                }
		}else{
			printf("error number!resume input!\n");
			char tmp;
			do{
				tmp=getchar();
                	}while(tmp!='\n');
				goto error_input;
        	        }
		}
}
