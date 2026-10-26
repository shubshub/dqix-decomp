#include <globaldefs.h>

extern "C" void func_0207dcf0(int a);
extern "C" int memcmp(void* a, void* b, int c);
extern "C" void func_ov017_021c9c64(int a, int b);

struct Struct_0207d798;
extern "C" void func_0207d7c0(struct Struct_0207d798* o);

extern int data_020e8a4c;

struct Struct_0207da94 {
    unsigned short h0;
    short pad2;
    signed char unknown_4_;
    char pad5[3];
    signed char arr8[4];
};

// USA: func_0207da94
extern "C" ARM void func_0207da94(struct Struct_0207da94* list, int idx) {
    int i = 0;
    int var1 = i;
    int var2 = 1;
    int var3 = i;
    int var4 = -1;
    for (; i < 4; list++, i++) {
        signed char v = list->arr8[idx];
        if (v == 0) continue;
        if (list->unknown_4_ < 0) {
            list->arr8[idx] = (signed char)var4;
            continue;
        }
        {
            int flag = (v == var4) ? var2 : var1;
            list->arr8[idx] = (signed char)var3;
            if (flag) {
                func_0207dcf0(list->h0);
            }
        }
        if (list->unknown_4_ == idx) list->unknown_4_ = (signed char)var4;
        {
            int found = (memcmp(list->arr8, &data_020e8a4c, 4) == 0);
            if (found) {
                func_ov017_021c9c64(list->h0, 0);
                func_0207d7c0((struct Struct_0207d798*)list);
            }
        }
    }
}
