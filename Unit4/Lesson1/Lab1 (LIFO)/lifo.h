#ifndef Lifo_H_
#define Lifo_H_
#include <stdio.h>
#include <stdlib.h>
/***defintions***/
//LIFO structure
typedef struct lifo{
	unsigned int length; 
	unsigned int* head; 
	unsigned int* base;
	unsigned int count;
}lifo_buff_t;	

typedef enum{
	lifo_no_error,
	lifo_full,
	lifo_empty,
	lifo_null
}lifo_status;

/***APIs***/
lifo_status lifo_init(lifo_buff_t* lbuff, unsigned int* buffer, unsigned int length);
lifo_status lifo_push(lifo_buff_t* lbuff, unsigned int item);
lifo_status lifo_pop(lifo_buff_t* lbuff, unsigned int* item);



#endif