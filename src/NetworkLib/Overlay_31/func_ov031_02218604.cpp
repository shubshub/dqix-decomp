#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov031_0221aae4(unsigned char* source, unsigned int length, char* out, unsigned int capacity);
extern "C" int func_ov031_0221883c(void* self, void* buf, int extra);
extern "C" int func_020c7170(char* destination, unsigned long capacity, const char* format, ...);

extern const char data_ov031_02249edc[];
extern const char data_ov031_02249ee0[];

struct Struct_ov031_02218604 {
    char* start;
    char* cur;
    char* end;
    int capacity;
};

struct Struct_ov031_02218604_2 {
    char pad[0x19f4];
    int depth;
    Struct_ov031_02218604 buf;
};

// USA: func_ov031_02218604
extern "C" ARM int func_ov031_02218604(Struct_ov031_02218604_2* self, const char* name, void* value, int length) {
    int len;
    Struct_ov031_02218604* buf = &self->buf;
    const char* fmt = self->depth == 0 ? data_ov031_02249edc : data_ov031_02249ee0;
    int var3;
    int var4;
    int var5;
    int var6;
    char* cur;

    self->depth = self->depth + 1;
    len = func_ov031_0221aae4(static_cast<unsigned char*>(value), length, 0, 0);
    var3 = (int)strlen(fmt);
    var4 = len + (var3 - 2 + (int)strlen(name));
    cur = buf->cur;
    var5 = buf->end - cur;
    if (var4 > var5) {
        if (func_ov031_0221883c(self, buf, var4 - var5 + 1) == 0) {
            return 1;
        }
        cur = buf->cur;
        var5 = buf->end - cur;
    }
    var6 = func_020c7170(cur, var5, fmt, name);
    buf->cur = buf->cur + var6;
    if (func_ov031_0221aae4(static_cast<unsigned char*>(value), length, buf->cur, buf->end - buf->cur - 1) >= 0) {
        buf->cur = buf->cur + len;
        *buf->cur = 0;
        return 0;
    }
    return 1;
}
