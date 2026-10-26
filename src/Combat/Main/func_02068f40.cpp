#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void __clear(void*, int);
extern "C" char* func_020424ac(char* str);
extern "C" int func_020d85dc(const char* str, const char* prefix);
extern "C" char* func_02068e1c(char* dst, char* first, char* second, char* third);
extern "C" ARM void func_02068ea0(signed char* ids, char* dest);

extern char data_020e833c[];
extern char data_020f08ff[];

struct Struct_02068f40 {
    signed char unknown_0_[4];
    signed char unknown_4_[4];
    signed char unknown_8_[4];
    signed char unknown_c_[4];
    int (*fn)(void*, void*, int);
};

// USA: func_02068f40
extern "C" ARM int func_02068f40(void* obj, char* p, char* out, int flag) {
    char b0[0x30];
    char b1[0x30];
    char b2[0x30];
    char b3[0x30];
    void* gs = GameState::GetInstance();
    for (;;) {
        char c = *p;
        if (c == 0) {
            break;
        }
        if (c == '<' && func_020d85dc(p, data_020f08ff) != 0
            && func_020424ac(p) != 0) {
            char* start = p;
            Struct_02068f40* e = (Struct_02068f40*)data_020e833c;
            while (e->fn != 0) {
                __clear(b0, 0x30);
                func_02068ea0(e->unknown_0_, b0);
                if (func_020d85dc(p, b0) != 0) {
                    int k = e->fn(gs, obj, flag);
                    __clear(b1, 0x30);
                    __clear(b2, 0x30);
                    __clear(b3, 0x30);
                    func_02068ea0(e->unknown_4_, b1);
                    func_02068ea0(e->unknown_8_, b2);
                    func_02068ea0(e->unknown_c_, b3);
                    switch (k) {
                    case 0:
                        p = func_02068e1c(p, b0, b1, b3);
                        break;
                    case 1:
                        if (b2[0] != 0) {
                            p = func_02068e1c(p, b1, b2, b3);
                        } else {
                            p = func_02068e1c(p, b1, b3, b3);
                        }
                        break;
                    case 2:
                        p = func_02068e1c(p, b2, b3, b3);
                        break;
                    default:
                        p = func_02068e1c(p, b0, b1, b3);
                        break;
                    }
                    break;
                }
                ++e;
            }
            if (p != start) {
                continue;
            }
        }
        *out++ = c;
        ++p;
    }
    *out = 0;
    return 0;
}
