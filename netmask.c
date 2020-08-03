#include <stdio.h>
#include "input.h"
void num_to_mask(ip_addr * p,int * num){
	unsigned int tmp;
	tmp=0xFFFFFFFF;
	tmp=tmp<<(32-*num);
	p->addr_all=tmp;
}
void mask_to_num(ip_addr * p,int * num){
	unsigned int tmp;
	tmp=p->addr_all;
	int count=0;
	while(tmp>0){
		tmp=tmp<<1;
		count++;
	}
	*num=count;
}
