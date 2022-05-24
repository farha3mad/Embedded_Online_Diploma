/*
 * MemoryMap1.h
 *
 * Created: 22/05/2022 07:08:24 م
 *  Author: WIN 10
 */ 


#ifndef MEMORYMAP1_H_
#define MEMORYMAP1_H_

#define PORTA *(volatile unsigned int*)(0x3B)
#define DDRA *(volatile unsigned int*)(0x3A)
#define PINA *(volatile unsigned int*)(0x39)

#define PORTD *(volatile unsigned int*)(0x32)
#define DDRD *(volatile unsigned int*)(0x31)
#define PIND *(volatile unsigned int*)(0x30)




#endif /* MEMORYMAP1_H_ */