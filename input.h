#ifndef _INPUT.H__
#define _INPUT.H__
typedef union{
        unsigned int addr_all;
        unsigned char addr_one [sizeof(int)];
}ip_addr;

void input(ip_addr * p,char * str);
#endif
