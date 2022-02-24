#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE	  CPU_TYPES_32
#define CPU_BIT_ORDER	  MSB_FIRST
#define CPU_BYTE_ORDER	  HIGH_BYTE_ORDER

       
typedef unsigned char        u8
typedef signed char	       s8

typedef unsigned short       u16
typedef signed short         s16

typedef unsigned int         u32
typedef signed short         s32

typedef unsigned long long   u64
typedef signed long long     s64

typedef float                f32
typedef double      	     f64
typedef long double          f128

typedef volatile u8          vu8
typedef volatile s8          vs8 
typedef volatile u16         vu16 
typedef volatile s16         vs16 
typedef volatile u32         vu32 
typedef volatile s32         vs32
typedef volatile u64         vu64  
typedef volatile s64         vs64
typedef volatile f32         vf32 
typedef volatile f64         vf64 
typedef volatile f128        vf128

#endif    
