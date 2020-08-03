#include <stdio.h>
#include "input.h"
#include "partition_subnet.h"
#include "show_ip.h"
#include "netmask.h"
int calc_mask_number(int mask_number){
	mask_number+=2;
	int tmp=0x1;
	while(tmp<mask_number){
		tmp=tmp<<1;
	}
	return tmp;
}
void part_sub(ip_addr * net_addr,ip_addr * mask,int number){
	unsigned int tmp=0x1;
	while(!(tmp&mask->addr_all)){
		tmp=tmp<<1;
	}
	ip_addr tmp_ip;
	tmp_ip.addr_all=net_addr->addr_all;
	unsigned int subnet=calc_mask_number(number);

	ip_addr sub_netmask;
      	sub_netmask.addr_all=0XFFFFFFFF;
      	while(sub_netmask.addr_all&subnet){
        	sub_netmask.addr_all=sub_netmask.addr_all<<1;                                                                                                                           
 	}
	sub_netmask.addr_all+=subnet;

	net_addr->addr_all=net_addr->addr_all+tmp;
	char tmp_showip[100];
	printf("Network segment:\n");
	printf("##################################\n");
	while (net_addr->addr_all>tmp_ip.addr_all){
		show_ip(&tmp_ip,tmp_showip);
		printf("\t%s\n",tmp_showip);
		tmp_ip.addr_all=subnet+tmp_ip.addr_all;
	}
	 printf("##################################\n");
	
	printf("mask:");
	show_ip(&sub_netmask,tmp_showip);
	printf("%s\n",tmp_showip);

	unsigned int  sub_mask_num;
	mask_to_num(&sub_netmask,&sub_mask_num);
	printf("mask_number:%u\n",sub_mask_num);
}
