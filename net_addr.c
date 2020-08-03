#include <stdio.h>
#include "input.h"
#include "net_addr.h"
void net_address(ip_addr * host,ip_addr * mask,ip_addr * net){
	net->addr_all=host->addr_all&mask->addr_all;
}
