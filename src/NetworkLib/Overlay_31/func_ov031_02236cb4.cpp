#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2* h, int index, unsigned int* arg2, unsigned int* arg3);

struct Struct_ov031_0224926a_4 { unsigned short lo; unsigned short hi; };
extern Struct_ov031_0224926a_4 data_ov031_0224926a[];

struct Struct_ov031_02236cb4 { void* items[5]; int f14; };
struct Struct_ov031_02290d04_5 { char pad[4]; Struct_ov031_02236cb4* p; };
extern Struct_ov031_02290d04_5 data_ov031_02290d04;

extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_02236d98(void*);

// USA: func_ov031_02236cb4
extern "C" ARM void func_ov031_02236cb4(void* obj) {
    int hi;
    unsigned int lo;
    func_ov031_0223bd28((Struct_ov031_02222f44_2*)data_ov031_02290d04.p->items[3], 0, (unsigned int*)&hi, &lo);
    hi += 8;
    if (hi < 0x98 || hi > 0x100) {
        int i = 3;
        do {
            Struct_ov031_0224926a_4* p = &data_ov031_0224926a[i];
            void* item = data_ov031_02290d04.p->items[i];
            unsigned short v = p->hi;
            func_ov031_0223bbd8(item, -1, hi, v);
            i++;
        } while (i < 5);
        return;
    }
    hi = 0x98;
    int i = 3;
    do {
        Struct_ov031_0224926a_4* p = &data_ov031_0224926a[i];
        void* item = data_ov031_02290d04.p->items[i];
        unsigned short v = p->hi;
        func_ov031_0223bbd8(item, -1, hi, v);
        i++;
    } while (i < 5);
    func_ov031_0223e2b8(obj, (int)func_ov031_02236d98);
}
