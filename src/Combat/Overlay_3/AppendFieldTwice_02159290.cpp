#include <globaldefs.h>

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);

// USA: func_ov003_02159290
ARM void AppendFieldTwice_02159290(void* self, unsigned short a, int b) {
    int v1 = KeyTable_Get((struct Container020e0310*)((char*)self + 0x64), (int)(short)a);
    Text_Append(*(char**)((char*)self + 0x7c), (const char*)v1);
    int v2 = KeyTable_Get((struct Container020e0310*)((char*)self + 0x64), (int)(short)b);
    Text_Append(*(char**)((char*)self + 0x7c), (const char*)v2);
}
