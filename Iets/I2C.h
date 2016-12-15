#ifndef I2C_H
#define I2C_H




/*
PUSHB1 0xCC
PUSHB2 0x8C
BEDS   0xAC
MOV1   0xFC
MOV2   0xBC
MOV3   0xEC
*/

//int i2cfile;

extern int i2c_GetValue (int hex);

extern void i2c_open();

extern void i2c_close();
#endif
