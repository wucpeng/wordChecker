#ifndef _DEFINES_H
#define _DEFINES_H

typedef   long long         int64;
//typedef long               int32;
typedef int                 int32;
typedef short               int16;
typedef signed char         int8;
typedef unsigned long long   uint64;
typedef unsigned int        uint32;
typedef unsigned short      uint16;
typedef unsigned char       uint8;


#define READER_INT(value) \
	do{\
	value = atoi(reader.cell(i, j++).c_str());\		
	}while(0)

#define READER_FLOAT(value) \
	do{\
	value = atof(reader.cell(i, j++).c_str());\		
	}while(0)

#define READER_STR(value) \
	do{\
	value = reader.cell(i, j++);\
	}while(0)

#endif