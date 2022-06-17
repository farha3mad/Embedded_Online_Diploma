#include "fifo.h"
FIFO_status fifo_init(FIFO_t* f, element_type* buffer,uint32_t length)
{
    if(buffer == NULL)
        return fifo_null;

    f->Base = buffer;
    f->Tail = buffer;
    f->Head = buffer;
    f->Count = 0;
    f->Length = length;

    return fifo_no_error;
}
FIFO_status fifo_enqueue(FIFO_t* f,element_type item)
{
    if(!f->Base || !f->Head || !f->Tail)
        return fifo_null;

    if(fifo_is_full(&f) == fifo_full)
        return fifo_full;

    *(f->Head) = item;
    f->Count++;
    if(f->Head == (f->Base + (f->Length*sizeof(element_type))))
       f->Head = f->Base;
    else
        f->Head++;

    return fifo_no_error;
}
FIFO_status fifo_dequeue(FIFO_t* f,element_type* item)
{
    if(!f->Base || !f->Head || !f->Tail)
        return fifo_null;

    if(f->Count == 0)
        return fifo_emty;

    *item = *(f->Tail);
    f->Count--;
    if(f->Tail == (f->Base + (f->Length*sizeof(element_type))))
       f->Tail = f->Base;
    else
        f->Tail++;

    return fifo_no_error;
}
FIFO_status fifo_is_full(FIFO_t* f)
{
    if(!f->Base || !f->Head || !f->Tail)
        return fifo_null;
    if(f->Count == f->Length)
        return fifo_full;
  return fifo_no_error;
}
void fifo_print(FIFO_t* f)
{
    element_type* temp = f->Tail;
    uint32_t i;
    if(f->Count == 0)
        return fifo_emty;
    else
        printf("=========FIFO PRINT==========\n");
        for(i=0 ; i<f->Count ; i++)
        {
            printf("%d\n",*temp);
            temp++;
        }
}
