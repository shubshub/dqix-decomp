#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern unsigned char data_ov031_022460c4[];
extern unsigned char data_ov031_022460cc[];

// USA: func_ov031_0221be64
extern "C" ARM unsigned long long func_ov031_0221be64(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
	union { unsigned long long v; unsigned char b[8]; } u;
	unsigned char tmp[8];
	unsigned char* p;
	unsigned char* q;
	unsigned char* r;
	unsigned char* s;
	unsigned char* t;
	int i;
	int j;
	int k;
	int m;

	u.v = ((unsigned long long)d & 3) | (((unsigned long long)c & 1) << 2) |
	    (((unsigned long long)b & 0xffffff) << 3) | (((unsigned long long)a & 0xffff) << 27);
	p = u.b;
	i = 0;
	do {
		*p ^= 0xd6;
		p++;
		i++;
	} while (i < 6);
	q = u.b;
	j = 0;
	do {
		*q = (data_ov031_022460cc[(*q >> 4) & 0xf] << 4) | data_ov031_022460cc[*q & 0xf];
		q++;
		j++;
	} while (j < 5);
	VectorizedInvertedMemcpy(u.b, tmp, 8);
	s = tmp;
	t = data_ov031_022460c4;
	k = 0;
	do {
		u.b[*t] = *s;
		s++;
		t++;
		k++;
	} while (k < 5);
	u.b[7] = 0;
	u.b[6] = 0;
	u.b[5] &= 7;
	u.v <<= 1;
	u.b[0] |= (u.b[5] >> 3) & 1;
	r = u.b;
	m = 0;
	do {
		*r ^= 0x67;
		r++;
		m++;
	} while (m < 6);
	u.b[7] = 0;
	u.b[6] = 0;
	u.b[5] &= 7;
	return u.v;
}
