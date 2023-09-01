#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(port, bit) port |= (1<<bit)
#define CLEAR_BIT(port, bit) port &= ~(1<<bit)
#define TOGGLE_BIT(port, bit) port ^= (1<<bit)
#define READ_BIT(port, bit) (port>>bit) & 1

#endif