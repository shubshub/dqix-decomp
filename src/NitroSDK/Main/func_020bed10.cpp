#include <globaldefs.h>

extern "C" void func_020bf1a0(void* entry);
struct Struct_020bcb70;
extern "C" void func_020bcb70(Struct_020bcb70*);
struct Struct_020bcbe0;
extern "C" void func_020bcbe0(Struct_020bcbe0*, void*);
struct Struct_020bc180_2;
extern "C" void func_020c0260(Struct_020bc180_2*);
extern "C" int func_020c022c(Struct_020bc180_2*);
struct Struct_020bc2f0;
extern "C" int func_020c0278(Struct_020bc2f0*);

struct Struct_02110a4c_3 { unsigned char unknown_0_[0x174]; };
extern struct Struct_02110a4c_3 data_02110a4c[];
extern short data_020ed82c[];

// USA: func_020bed10
extern "C" ARM void func_020bed10(void) {
    int index = 0;
    int a;
    unsigned char* entry = (unsigned char*)data_02110a4c;
LOOP_START:;
    {
        int flags = *(int*)(entry + 0x110);
        if (((flags << 31) >> 31) == 0) {
            goto LOOP_CONTINUE;
        }
        if (*(int*)(entry + 0x114) == 0) {
            func_020bf1a0(entry);
            goto LOOP_CONTINUE;
        }

        if (((flags << 29) >> 31) != 0 && *(int*)(entry + 0x118) != 0) {
            func_020bcb70((Struct_020bcb70*)entry);
            int f2 = *(int*)(entry + 0x110);
            f2 = (f2 | 2) & ~4;
            *(int*)(entry + 0x110) = f2;
        }

        int flags2 = *(int*)(entry + 0x110);
        if (((flags2 << 30) >> 31) == 0) {
            goto LOOP_CONTINUE;
        }
        func_020c0260((Struct_020bc180_2*)(entry + 0xe8));
        a = data_020ed82c[*(int*)(entry + 0x154)];
        int var6 = func_020c022c((Struct_020bc180_2*)(entry + 0xe8));
        int b = data_020ed82c[var6 >> 8];
        int c = data_020ed82c[*(int*)(entry + 0x158)];
        int newVal = c + (b + a);
        if (newVal != *(int*)(entry + 0x15c)) {
            func_020bcbe0((Struct_020bcbe0*)entry, (void*)newVal);
            *(int*)(entry + 0x15c) = newVal;
        }

        int var10 = *(int*)(entry + 0x110);
        if (((var10 << 28) >> 31) == 0) {
            goto LOOP_CONTINUE;
        }
        if (func_020c0278((Struct_020bc2f0*)(entry + 0xe8)) == 0) {
            goto LOOP_CONTINUE;
        }
        func_020bf1a0(entry);
    }
LOOP_CONTINUE:;
    index++;
    entry += 0x174;
    if (index < 4) {
        goto LOOP_START;
    }
}
