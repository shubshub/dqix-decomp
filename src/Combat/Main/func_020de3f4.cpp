#include <globaldefs.h>

struct Struct_020de34c;
extern "C" int func_020de34c(struct Struct_020de34c* s, int lo, int hi);

struct Struct_020de334;
extern "C" int func_020de334(struct Struct_020de334* obj, int a1, int a2, int value);

struct Struct_020de31c;
extern "C" int func_020de31c(struct Struct_020de31c* obj, int value);

struct Struct_020de36c;
extern "C" int func_020de36c(struct Struct_020de36c* obj, int a, int unused, int b);

// USA: func_020de3f4
#pragma optimize_for_size off
extern "C" ARM void func_020de3f4(int a, int b, int c, int d, char* outA, char* outB, char* arg6, void** arg7) {
    *outA = (char)c;
    *outB = (char)-1;
    *arg6 = (char)d;
    *arg7 = 0;

    if (a != 0) {
        switch (b) {
            case 0:
                *outA = 0;
                *outB = 7;
                break;
            case 1:
                *outA = 0;
                break;
            case 2:
                *outA = 1;
                *outB = 6;
                break;
            case 3:
                *outA = 7;
                break;
        }
    } else {
        switch (b) {
            case 0:
                *outA = 8;
                *outB = 9;
                break;
            case 1:
                *outA = 8;
                break;
            case 2:
                *outA = 9;
                break;
        }
    }

    if (*outA == -1) {
        if (*arg6 == -1) {
            *arg7 = 0;
        } else {
            *arg7 = (void*)&func_020de334;
        }
    } else {
        if (*arg6 == -1) {
            if (*outB == -1) {
                *arg7 = (void*)&func_020de31c;
            } else {
                *arg7 = (void*)&func_020de34c;
            }
        } else {
            *arg7 = (void*)&func_020de36c;
        }
    }
}
