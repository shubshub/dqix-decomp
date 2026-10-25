#include <globaldefs.h>

extern "C" void __clear(void* dst, int count);
int IsPrefixMatch020d857c(signed char* a, signed char* b);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void* memcpy(void* dst, void* src, unsigned int length);
int STD_GetStringLength(const char* s);

struct Struct_ov003_0217f600 {
    signed char* unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov003_0217f608 {
    const char* unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

extern Struct_ov003_0217f600 data_ov003_0217f600[];
extern Struct_ov003_0217f600 data_ov003_0217f604[];
extern Struct_ov003_0217f608 data_ov003_0217f608[];

// USA: func_ov003_02170a7c
extern "C" ARM void func_ov003_02170a7c(signed char* str, void* outBuf) {
    if (outBuf != 0 && str != 0) {
        char localBuf[16];
        int rawLen = STD_GetStringLength((const char*)str) + 1;
        unsigned char remaining = rawLen;
        unsigned char index = 0;
        __clear(localBuf, 0x10);
        int cursor = index;
        while (data_ov003_0217f600[index].value != 0 && remaining != 0) {
            int matched = 0;
            if (IsPrefixMatch020d857c(str, data_ov003_0217f600[index].value) != 0) {
                matched = 1;
            } else if (IsPrefixMatch020d857c(str, data_ov003_0217f604[index].value) != 0) {
                matched = 1;
            }
            if (var5 == 0) {
                var3 = var3 + 1;
                continue;
            }
            const char* repl = *(const char* const*)((char*)data_ov003_0217f608 + (int)index * 12);
            strcpy(localBuf + cursor, repl);
            cursor += STD_GetStringLength(repl);
            remaining = remaining - 2;
            str += 2;
            index = 0;
        }
        memcpy(arg1, var0, 8);
    }
}
