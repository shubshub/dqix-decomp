#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/ScriptElementList.h"

struct Struct_0208d51c;
extern "C" void func_0208d51c(struct Struct_0208d51c* arg0);

struct Struct_0208d594 {
    short unknown_0_;
    char* unknown_4_;
    char* unknown_8_;
    char** unknown_c_;
    char* unknown_10_;
    char* unknown_14_;
};

struct Struct_0208d594_2;
extern "C" void func_0208d928(struct Struct_0208d594_2* arg0, struct Struct_0208d594* arg1);

extern const char data_020f1244[];

int STD_GetStringLength(const char* s);

// USA: func_0208d594
extern "C" ARM int func_0208d594(Script::Parameter* arg0) {
    struct Struct_0208d594 var0;
    unsigned short var1 = data_02108fc0.unknown_4_->unknown_e_;
    unsigned int var2;
    unsigned char var3;
    unsigned char var4;
    int var5;
    const char* var6;
    unsigned int var7;
    Script::Parameter* var8;
    char* var9;

    func_0208d51c((struct Struct_0208d51c*)&var0);
    var0.unknown_0_ = (short)arg0->ToInt();
    if (data_02108fc0.unknown_4_->unknown_c_ != 0) {
        const short* var10 = data_02108fc0.unknown_4_->unknown_8_;
        short var11 = data_02108fc0.unknown_4_->unknown_c_;
        var5 = 0;
        for (short var12 = 0; var12 < var11; var12++) {
            if (var0.unknown_0_ == *var10) {
                var5 = 1;
            }
            var10++;
        }
        if (!var5) {
            return 1;
        }
    }

    s = (p + 1)->ToString();
    if (flags & 1) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.text4 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text4[len] = 0;
            sprintf(elem.text4, data_020f1244, s);
        }
    }

    q = p + 2;
    p += 3;
    s = q->ToString();
    if (flags & 2) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.text8 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text8[len] = 0;
            sprintf(elem.text8, data_020f1244, s);
        }
    }

    if (var1 & 0x3fc) {
        var0.unknown_c_ = (char**)data_02108fc0.unknown_0_->Allocate(0x20);
        for (var4 = 0; var4 < 8; var4++) {
            var0.unknown_c_[var4] = 0;
        }
    }

    mask = 4;
    for (i = 0; i < 8; i++) {
        s = p->ToString();
        p++;
        if (flags & mask) {
            len = STD_GetStringLength(s);
            if (len != 0) {
                elem.texts[i] = (char*)data_02108fc0.allocator->Allocate(len + 1);
                buf = elem.texts[i];
                buf[len] = 0;
                sprintf(buf, data_020f1244, s);
            }
        }
        var2 <<= 1;
    }

    s = p->ToString();
    if (flags & 0x400) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.text10 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text10[len] = 0;
            sprintf(elem.text10, data_020f1244, s);
        }
    }

    s = (p + 1)->ToString();
    if (flags & 0x800) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.text14 = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.text14[len] = 0;
            sprintf(elem.text14, data_020f1244, s);
        }
    }

    func_0208d928((struct Struct_0208d594_2*)data_02108fc0.unknown_4_, &var0);
    return 1;
}
