#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov009_0218a9ac[];

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

// USA: func_ov009_0218a8b8
ARM void ResetEntrySkill0218a8b8(void* objRaw) {
    char* obj = (char*)objRaw;
    void** arr = *(void***)(obj + 0xdb0);
    void* entry = arr[*(unsigned char*)(obj + 0xda3)];
    int rem;
    int val;
    int result;
    unsigned char idx;

    memset(entry, 0, 0x48);

    idx = *(unsigned char*)(obj + 0xda3);
    int range = data_ov009_0218a9ac[idx];
    rem = rand() % range;

    idx = *(unsigned char*)(obj + 0xda3);
    int t = idx * 1000;
    t += 0xe20;
    t += 0x4000;
    val = (short)(rem + t);
    result = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xe0), val);

    sprintf((char*)entry, (const char*)(long)result);
}
