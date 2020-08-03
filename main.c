#include <stdio.h>
#include "input.h"
#include "netmask.h"
#include "show_ip.h"
#include "net_addr.h"
#include "subnet_calc.h"
#include "partition_subnet.h"
int main()
{	
	ip_addr ip;
	char * input_ip="ip";
	input(&ip,input_ip);
	
	char * input_class="This is a class %c address,default netmask is %d\n\n";
	char class_name;
	int mask_num;

	if(ip.addr_one[3]<128){
		class_name='A';
		mask_num=8;
	}else if(ip.addr_one[3]<192){
		class_name='B';
		mask_num=16;
	}else if(ip.addr_one[3]<224){
		class_name='C';
		mask_num=24;
	}else if(ip.addr_one[3]<240){
		printf("This is a multicast address,no netmask\n");
		return 1;
	}else{
		printf("The specific address\n");
		return 1;
	}
	
	printf(input_class,class_name,mask_num);
	
	printf("please input netmask ");
	printf("press 1 to enter netmask,press 2 to enter mask_number:");
	int io_mask;
	scanf("%d",&io_mask);
	
	ip_addr netmask;
	mask_num=0;

	if(io_mask==1){
		input(&netmask,"netmask");
		mask_to_num(&netmask,&mask_num);
	}else{
		printf("input netmask_number:");
		do{
			scanf("%d",&mask_num);
		}while(mask_num>32&&mask_num<0);
		num_to_mask(&netmask,&mask_num);
	}

	ip_addr network;
	net_address(&ip,&netmask,&network);
	
	char show_ip_tmp_ret [20]="";
	printf("\n\n");
	printf("ip:        \t%s/%d\n",show_ip(&ip,show_ip_tmp_ret),mask_num);
	printf("netmask:   \t%s\n",show_ip(&netmask,show_ip_tmp_ret));
	printf("netaddress:\t%s\n",show_ip(&network,show_ip_tmp_ret));
	
	printf("\n\n");
	show_bin_ip("bin_ip:      \t",&ip,"\n");
	show_bin_ip("bin_mask:    \t",&netmask,"\n");
	show_bin_ip("bin_netaddr: \t",&network,"\n");

	printf("\n\n");
	ip_addr min_hostaddr=min_host(&network);
	ip_addr max_hostaddr=max_host(&network,&netmask);
	printf("min_hostaddr:%s\n",show_ip(&min_hostaddr,show_ip_tmp_ret));
	printf("max_hostaddr:%s\n",show_ip(&max_hostaddr,show_ip_tmp_ret));

	printf("host_number: ");
	int part_sub_num;
	scanf("%d",&part_sub_num);
	printf("\n\n");
	part_sub(&network,&netmask,part_sub_num);
	return 0;
}
