#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"

struct Obj020bda58;

int NitroVM_ReadSync(NitroVM* vm, void* dst, int capacity);
int NitroVM_Seek(NitroVM* vm, int position, int whence);
typedef void (*Type_020bbf84)(void* mem, unsigned int size, unsigned int data1, unsigned int data2);
extern "C" void* func_020bda58(Obj020bda58* heap, unsigned int size, Type_020bbf84 callback, int data1, int data2);
extern "C" void func_020bd8f0(void*, void*, void*);
extern "C" void func_020bd8fc(void*, void*, void*);
extern "C" void func_020bd908(void*, void*, void*);

struct Struct_020bd190 {
    char unknown_0_[0x10];
    unsigned long unknown_10_;
    unsigned long unknown_14_;
    unsigned long unknown_18_;
    unsigned long unknown_1c_;
    unsigned long unknown_20_;
    unsigned long unknown_24_;
    unsigned long unknown_28_;
    unsigned long unknown_2c_;
};

struct Struct_020bd190_2 {
    Struct_020bd190 header;
    int unknown_30_;
    NitroVM file;
    char unknown_7c_[8];
    void* unknown_84_;
    void* symbol;
    void* info;
    long unknown_90_;
};

// USA: func_020bd190
extern "C" ARM int func_020bd190(Struct_020bd190_2* arg0, Obj020bda58* heap, int arg2) {
    int result;
    long var1;

    result = NitroVM_Seek(&arg0->file, 0, 0);
    if (!result)
        return 0;

    var1 = NitroVM_ReadSync(&arg0->file, &arg0->header, sizeof(arg0->header));
    if (var1 != sizeof(arg0->header))
        return 0;

    if (heap != NULL) {
        arg0->info = func_020bda58(heap, arg0->header.unknown_1c_, (Type_020bbf84)func_020bd8f0, (int)arg0, 0);
        if (arg0->info == NULL)
            return 0;

        result = NitroVM_Seek(&arg0->file, (long)arg0->header.unknown_18_, 0);
        if (!result)
            return 0;

        var1 = NitroVM_ReadSync(&arg0->file, arg0->info, (long)arg0->header.unknown_1c_);
        if (var1 != arg0->header.unknown_1c_)
            return 0;

        arg0->unknown_84_ = func_020bda58(heap, arg0->header.unknown_24_, (Type_020bbf84)func_020bd8fc, (int)arg0, 0);
        if (arg0->unknown_84_ == NULL)
            return 0;

        result = NitroVM_Seek(&arg0->file, (long)arg0->header.unknown_20_, 0);
        if (!result)
            return 0;

        var1 = NitroVM_ReadSync(&arg0->file, arg0->unknown_84_, (long)arg0->header.unknown_24_);
        if (var1 != arg0->header.unknown_24_)
            return 0;

        if (arg2 && arg0->header.unknown_14_ > 0) {
            arg0->symbol = func_020bda58(heap, arg0->header.unknown_14_, (Type_020bbf84)func_020bd908,
                                                       (int)arg0, 0);
            if (arg0->symbol == NULL)
                return 0;

            result = NitroVM_Seek(&arg0->file, (long)arg0->header.unknown_10_, 0);
            if (!result)
                return 0;

            var1 = NitroVM_ReadSync(&arg0->file, arg0->symbol, (long)arg0->header.unknown_14_);
            if (var1 != arg0->header.unknown_14_)
                return 0;
        }
    }
    return 1;
}
