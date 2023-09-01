/*
 * STD_TYPES_H_.h
 *
 * Created: 8/21/2023 3:49:22 PM
 *  Author: Ahmed ElSayed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define F_CPU 16000000

typedef unsigned char		UINT8_t;
typedef	unsigned short		UINT16_t;
typedef unsigned long		UINT32_t;
typedef unsigned long long	UINT64_t;		

typedef signed char			INT8_t;
typedef	signed short		INT16_t;
typedef signed long			INT32_t;
typedef signed long long	INT64_t;
typedef float				FLOAT_t;
typedef double				DOUBLE_t;

typedef enum {
	FALSE,
	TRUE
}bool;

#endif /* STD_TYPES_H_ */