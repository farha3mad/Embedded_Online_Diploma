#include "lifo.h"

lifo_status lifo_init(lifo_buff_t* lbuff, unsigned int* buffer, unsigned int length)
{
	//check if buffer exists
	if(buffer == NULL)
		return lifo_null;
	
	//initializing LIFO
	lbuff->base = buffer;
	lbuff->head = lbuff->base;
	lbuff->count = 0;
	lbuff->length = length;
	
	return lifo_no_error;
	
}
lifo_status lifo_push(lifo_buff_t* lbuff, unsigned int item)
{
	//check if LIFO valid
	if(!lbuff->head || !lbuff->base)
		return lifo_null;
	
	//check if LIFO is full
	if(lbuff->count >= lbuff->length)
		return lifo_full;
	
	//adding item
	*(lbuff->head) = item;
	lbuff->head++;
	lbuff->count++;
	
	return lifo_no_error;

}
lifo_status lifo_pop(lifo_buff_t* lbuff, unsigned int* item)
{
	//check if LIFO valid
	if(!lbuff->head || !lbuff->base)
		return lifo_null;
	
	//check if LIFO is empty
	if(lbuff->head == lbuff->base)
		return lifo_empty;
	
	//popping item
	lbuff->head--;
	lbuff->count--;
	*item = *(lbuff->head);
	
	return lifo_no_error;
}
