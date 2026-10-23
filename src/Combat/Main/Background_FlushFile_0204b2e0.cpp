#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int func_02001aec(void* a, void* b, int n);

void CopyFieldsAndFlushCache0204a8f4(char* dst, char* src);

struct HeaderAt0204ab4c;
struct BufferAt0204ab4c;
void InvalidateDirtyCacheBlocks(struct HeaderAt0204ab4c* header, struct BufferAt0204ab4c* buffer);

struct Record0204acb0 {
    int w0;
    int w4;
    int w8;
    int wc;
};
void ClearRecordFields(struct Record0204acb0* rec);
void CopyWordAndFlushCache0204ad88(void* a, void* b);

extern char data_020f0238;
extern char data_020f023d;
extern char data_020f0242;

// Main, originally DispatchByTag0204b2e0 (USA 0x0204b2e0, EUR 0x0204b2f0, JPN 0x0204c100)
ARM void Background_FlushFile(void* obj, char* str) {
    char buf[5];

    if (str == 0) {
        return;
    }

    __clear(buf, 5);
    memcpy(buf, str, 5);

    if (func_02001aec(buf, &data_020f0238, 4) == 0) {
        CopyFieldsAndFlushCache0204a8f4((char*)obj, str);
        return;
    }

    if (func_02001aec(buf, &data_020f023d, 4) == 0) {
        InvalidateDirtyCacheBlocks((struct HeaderAt0204ab4c*)((char*)obj + 0xc), (struct BufferAt0204ab4c*)str);
        return;
    }

    if (func_02001aec(buf, &data_020f0242, 4) == 0) {
        struct Record0204acb0 rec;
        ClearRecordFields(&rec);
        CopyWordAndFlushCache0204ad88(&rec, str);
    }
}
