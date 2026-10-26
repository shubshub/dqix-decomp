#include <globaldefs.h>

extern void* data_ov031_0224e688;
extern long long data_ov031_0224e68c;
extern long long data_ov031_0224e694;

extern "C" int func_020cf25c(void* a, void* b);
extern "C" long long func_020cf990(int arg0, unsigned char* arg1);
struct Struct_020cfaf4;
extern "C" void func_020cfb74(void* arg0, struct Struct_020cfaf4* arg1, long long arg2);

// USA: func_ov031_0221244c
extern "C" ARM int func_ov031_0221244c(void* date, void* time) {
    if (data_ov031_0224e688 == NULL) return 0;
    if (func_020cf25c(date, time) != 0) return 0;
    long long offset = func_020cf990((int)date, (unsigned char*)time);
    if (offset == -1LL) return 0;
    if (offset < data_ov031_0224e68c) {
        offset += 0xbc191380LL;
    }
    long long var1 = offset - data_ov031_0224e694;
    if (var1 < 0LL || var1 > 0xbc19137fLL) return 0;
    func_020cfb74(date, (struct Struct_020cfaf4*)time, var1);
    return 1;
}
