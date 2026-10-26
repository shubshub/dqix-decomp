#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);

struct Struct_0208ab34_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_020e30f0 {
    char unknown_0_[0xfc0];
    int unknown_fc0_;
};

extern "C" Struct_0208ab34_2* func_020e3054(Struct_0208ab34_2* arg0, int arg1);
extern "C" void func_020e3428(void* arg0, int arg1);
extern "C" void func_020e3328(void* arg0, int arg1);

// USA: func_020e30f0
extern "C" ARM void func_020e30f0(Entry020e3054* list) {
    void* ctx = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)ctx)) return;

    Struct_0208ab34_2* var1 = arg0;
    int var2;
    for (var2 = 0; var2 < 8; var2++, var1++) {
        if (var1->unknown_2_ == 2 && ((Struct_020e30f0*)var0)->unknown_fc0_ == 0) {
            if (var1->unknown_3_ <= 0x1e) {
                var1->unknown_3_ = var1->unknown_3_ + 1;
            } else {
                unsigned char var3 = var1->unknown_0_;
                unsigned char var4 = var1->unknown_1_;
                func_020e3428(arg0, var4);
                var1->unknown_1_ = var4;
                var1->unknown_0_ = var3;
                var1->unknown_2_ = 4;
            }
        }
    }

    unsigned char* ids = (unsigned char*)list + 0x20;
    int j;
    for (j = 0; j < 8; j++, ids++) {
        int id = *ids;
        if (id == 0) continue;
        Entry020e3054* found = FindEntryByField1(list, id);
        if (found != NULL) {
            unsigned char state = found->f2;
            int cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)ctx);
            if (found->f0 != cur && state == 1) state = 3;
            if (state == 1 || state == 4 || state == 5) {
                *ids = 0;
            } else if (state != 2) {
                Dispatch020e3328(list, id);
            }
        } else {
            func_020e3328(arg0, var7);
        }
    }
}
