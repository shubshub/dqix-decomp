#include <globaldefs.h>
#include "std_library_functions.h"

struct RingBuffer020457e8;

struct Struct_0204483c {
    unsigned char* cursor;
};

extern "C" ARM const char* func_020449a4(struct RingBuffer020457e8* arg0, const char* msg);
extern "C" ARM void func_02044974(struct Struct_0204483c* stream, int value);
extern "C" ARM int func_020d85dc(const char* str, const char* prefix);
extern "C" ARM int func_02005a94(const char* s);
extern "C" ARM void func_020457e8(struct RingBuffer020457e8* arg0, int value);

extern char data_020f00a3[];

enum Enum_0204483c { Enum_0204483c_65281 = 0xff01, Enum_0204483c_65304 = 0xff18, Enum_0204483c_65306 = 0xff1a };

// USA: func_0204483c
extern "C" ARM void func_0204483c(struct RingBuffer020457e8* arg0, const char* msg, struct Struct_0204483c stream) {
    const char* var0;
    if (msg == 0 || stream.cursor == 0) {
        return;
    }
    msg = func_020449a4(arg0, msg);
    for (;;) {
        Enum_0204483c var1;
        Struct_0204483c* output = &stream;
        var1 = Enum_0204483c_65304;
        signed char c = *msg;
        if (c == 0) {
            break;
        }
        signed char next = msg[1];
        if ((c == '\\' && next == 'n') || (c == '\r' && next == '\n')) {
            func_02044974(output, var1);
            msg += 2;
            continue;
        }
        if (c == '\n') {
            func_02044974(output, var1);
            msg += 1;
            continue;
        }
        if (c == '<') {
            int var5 = 1;
            var0 = strchr(msg, '>');
            if (var0 == 0) {
                break;
            }
            const char* var6 = var0 + 1;
            if (func_020d85dc(msg + 1, data_020f00a3)) {
                int var7 = func_02005a94(msg + 6);
                if (var7 < 0) {
                    var7 = 0;
                }
                func_020457e8(arg0, var7);
                func_02044974(output, Enum_0204483c_65306);
            } else {
                var5 = 0;
            }
            if (var5) {
                msg = var6;
                continue;
            }
        }
        unsigned char* var8 = stream.cursor;
        stream.cursor = var8 + 1;
        *var8 = *msg++;
    }
    func_02044974(&stream, Enum_0204483c_65281);
}
