/*
 * Utils.h
 *
 * Created: 22/05/2022 07:16:01 م
 *  Author: WIN 10
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define set_bit(reg,bit) (reg = reg| (1<<bit))
#define reset_bit(reg,bit) (reg = reg & ~(1<<bit))
#define toggle_bit(reg,bit) (reg = reg ^ (1<<bit))
#define read_bit(reg,bit) ((reg = reg & (1<<bit))>>bit)


#endif /* UTILS_H_ */