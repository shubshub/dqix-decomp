#include <globaldefs.h>

struct Struct_020bded0_2 {
    unsigned long unknown_0_;
    unsigned short unknown_4_[4];
};

struct Struct_020bded0 {
    unsigned long unknown_0_0_ : 24;
    unsigned long flags : 8;
};

extern "C" Struct_020bded0_2* func_020bd51c(int arg0);
extern "C" void* func_020be214(unsigned int arg0, int heap, int arg2);
extern "C" void* func_020bd8ac(unsigned int arg0);
extern "C" Struct_020bded0* func_020bd580(int arg0);
extern "C" int func_020be010(int arg0, unsigned int arg1, int heap, int arg3, int* data);
extern "C" int func_020be604(void* arg0, void* bank, int arg2, int arg3, int heap);
extern "C" void func_020d2b34(void* bank, int index, void* arg2);

// USA: func_020bded0
extern "C" ARM int func_020bded0(int arg0, unsigned long arg1, int heap, int arg3, void** data) {
    const Struct_020bded0_2* var0;
    const Struct_020bded0* var1;
    void* bank = NULL;
    void* var3;
    int result;
    int i;

    var0 = func_020bd51c(arg0);
    if (var0 == NULL)
        return 4;

    if (arg1 & 2) {
        bank = func_020be214(var0->unknown_0_, heap, arg3);
        if (bank == NULL)
            return 8;
    } else {
        bank = func_020bd8ac(var0->unknown_0_);
    }

    for (i = 0; i < 4; i++) {
        if (var0->unknown_4_[i] == 0xffff)
            continue;

        var1 = func_020bd580(var0->unknown_4_[i]);
        if (var1 == NULL)
            return 5;

        result = func_020be010(var0->unknown_4_[i], arg1, heap, arg3, (int*)&var3);
        if (result != 0)
            return result;

        if (var1->flags & 1) {
            if (arg1 & 4) {
                if (!func_020be604(var3, bank, i, var1->unknown_0_0_, heap))
                    return 9;
            }
        }

        if (bank != NULL && var3 != NULL)
            func_020d2b34(bank, i, var3);
    }

    if (data != NULL)
        *data = bank;
    return 0;
}
