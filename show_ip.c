#include <stdio.h>
#include "input.h"
#include "show_ip.h"
#include "string.h"
char * show_ip(ip_addr * p,char * ret){
	ret[0]='\0';
	char tmp[10]="";
	for(int i=3;i>=0;i--){
		sprintf(tmp,"%u",p->addr_one[i]);
		strcat(ret,tmp);
		if(i>0){
			strcat(ret,".");
		}
	}
	return ret;
}

void show_bin_ip(char * head,ip_addr * p,char * tail){
	printf("%s",head);
	unsigned int tmp=0x80000000;
	for(int i=0,n=sizeof(int)*8;i<n;i++){
		if(tmp&p->addr_all){
			printf("1");
		}else{
			printf("0");
		}
		if((i+1)%8==0){
			printf("  ");
		}
		tmp=tmp>>1;
	}
	printf("%s",tail);
}
