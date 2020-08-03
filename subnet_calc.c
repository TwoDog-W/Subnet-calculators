#include <stdio.h>
#include "input.h"
#include "subnet_calc.h"
ip_addr min_host(ip_addr * p){
	ip_addr tmp=*p;
	tmp.addr_all++;
	return tmp;
}
ip_addr max_host(ip_addr * net_addr,ip_addr * mask_addr){
	unsigned int tmp=~mask_addr->addr_all;
	ip_addr ret;
	ret.addr_all=net_addr->addr_all+tmp-1;
	return ret;
}
