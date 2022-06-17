#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

//choose the element type
#define element_type uint8_t
//choose FIFO size
#define width 5
//initial buffer
element_type uart_fifo[width];

typedef struct{
    uint32_t Length;
    uint32_t Count;
    element_type* Head;
    element_type* Base;
    element_type* Tail;
}FIFO_t;

typedef enum{
    fifo_no_error,
    fifo_full,
    fifo_emty,
    fifo_null
}FIFO_status;
//APIs
FIFO_status fifo_init(FIFO_t* f, element_type* buffer,uint32_t length);
FIFO_status fifo_enqueue(FIFO_t* f,element_type item);
FIFO_status fifo_dequeue(FIFO_t* f,element_type* item);
FIFO_status fifo_is_full(FIFO_t* f);
void fifo_print(FIFO_t* f);

#endif
