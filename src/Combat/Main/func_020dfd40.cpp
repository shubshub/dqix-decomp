#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_0201099c_14 {
    unsigned char unknown_0_[0xc];
    short unknown_c_;
    short unknown_e_;
    int unknown_10_;
    void* unknown_14_;
};

struct SafeAllocator;
struct Obj020dfe88;
int ResetHandleState020dfe88(Obj020dfe88*);
extern "C" void KeyTable_Load(void* p, void* a, void* b, unsigned int c);
extern "C" void func_020e0028(void* p, void* a, void* b, unsigned int c, short* e, int f);
extern "C" int func_020dfd40(void* self, void* a, void* b);

// USA: func_020dfd40
extern "C" ARM int func_020dfd40(void* arg0, void* arg1, void* arg2) {
    Struct_0201099c_14* var0 = (Struct_0201099c_14*)arg0;
    void* var1 = BackgroundLoader::GetInstance();

    switch (var0->unknown_e_) {
    case 1:
        if (arg1 == 0) {
            func_020dfe88((Struct_020dfc40*)var0);
            return 1;
        }
        if (arg2 != 0) {
            var0->unknown_10_ = ((BackgroundLoader*)var1)->QueueLoadFileInGP2((const char*)arg1, (const char*)arg2, (SafeAllocator*)0);
        } else {
            var0->unknown_10_ = ((BackgroundLoader*)var1)->QueueLoadFile((const char*)arg1, (SafeAllocator*)0);
        }
        var0->unknown_e_ = 2;
        return func_020dfd40(var0, 0, 0);
    case 2:
        if (((BackgroundLoader*)var1)->GetTaskStatus(var0->unknown_10_) == 0) {
            return 0;
        }
        var0->unknown_e_ = 3;
        return func_020dfd40(var0, 0, 0);
    case 3: {
        void* data = 0;
        unsigned int size = 0;
        short idx;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(p->field_10, &data, &size);
        if (p->field_c < 0) {
            KeyTable_Load(p, p->field_14, data, size);
        } else {
            var4 = var0->unknown_c_;
            func_020e0028(var0, var0->unknown_14_, var2, var3, &var4, 1);
        }
        func_020dfe88((Struct_020dfc40*)var0);
        return 1;
    }
    default:
        return 1;
    }
}
