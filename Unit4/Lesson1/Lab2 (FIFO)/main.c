#include "fifo.h"

int main()
{
    FIFO_t fifo;
    uint32_t i,temp =0;

    if(fifo_init(&fifo,uart_fifo,width) == fifo_no_error)
      printf("========FIFO INITIALIZED========\n");

    for(i=0 ; i<width ; i++)
    {
        printf("Enqueue %d",i);
        if(fifo_enqueue(&fifo,i) == fifo_no_error)
            printf("\tEnqueue done\n");
        else
            printf("\tEnqueue failed\n");
    }

    fifo_print(&fifo);
    if(fifo_dequeue(&fifo,&temp) == fifo_no_error)
            printf("Dequeue element %d\n",temp);
    if(fifo_dequeue(&fifo,&temp) == fifo_no_error)
            printf("Dequeue element %d\n",temp);
    fifo_print(&fifo);

    return 0;
}
