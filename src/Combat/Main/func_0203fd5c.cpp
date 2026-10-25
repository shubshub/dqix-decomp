#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int NNS_GfdAllocFrmPlttVram(unsigned int size, int a, int b);

extern unsigned short data_020e7a0c[];

struct Struct_0203fd5c {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    int unknown_8_;
    char* unknown_c_;
};

struct Struct_0203fd5c_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    Struct_0203fd5c* unknown_8_;
    unsigned int unknown_c_;
    char* unknown_10_;
};

struct Struct_0203fd5c_3 {
    char* unknown_0_;
    unsigned int unknown_4_;
    void* unknown_8_;
    void* unknown_c_;
    void* unknown_10_;
};

struct Struct_0203fd5c_4 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    Struct_0203fd5c_2* unknown_8_;
    int unknown_c_;
    unsigned short* unknown_10_;
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    Struct_0203fd5c_3* unknown_1c_;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
};

// USA: func_0203fd5c
extern "C" ARM void func_0203fd5c(Struct_0203fd5c_4* arg0, char* arg1, SafeAllocator* arg2, char* arg3) {
    char* var0 = arg1 + strlen(arg1);
    if (var0[-1] == 'r') {
        int var1 = 0;
        Struct_0203fd5c_2* var2;
        Struct_0203fd5c* var3;
        unsigned int var4;
        int var5;
        unsigned int var6;
        unsigned int var7;
        int var8;
        unsigned int var9;
        char var10[0x1e];

        memcpy(&arg0->unknown_6_, arg3 + var1, 2);
        memcpy(&arg0->unknown_4_, arg3 + (var1 + 2), 2);
        var1 += 4;
        arg0->unknown_8_ = (Struct_0203fd5c_2*)arg2->Allocate(arg0->unknown_6_ * sizeof(Struct_0203fd5c_2));
        var5 = 0;
        arg0->unknown_20_ = 0;
        arg0->unknown_24_ = 0;
        var2 = arg0->unknown_8_;
        for (; var5 < arg0->unknown_6_; var5++, var2++) {
            memcpy(&var2->unknown_0_, arg3 + var1, 2);
            memcpy(&var2->unknown_2_, arg3 + (var1 + 2), 2);
            memcpy(&var7, arg3 + (var1 + 4), 4);
            var1 += 8;
            var2->unknown_4_ = var7;
            if (arg0->unknown_20_ < var7)
                arg0->unknown_20_ = var7;
            var2->unknown_8_ = (Struct_0203fd5c*)arg2->Allocate(var7 * sizeof(Struct_0203fd5c));
            var4 = 0;
            var2->unknown_c_ = 0;
            var3 = var2->unknown_8_;
            for (; var4 < var7; var4++, var3++) {
                memcpy(&var3->unknown_0_, arg3 + var1, 2);
                memcpy(&var3->unknown_2_, arg3 + (var1 + 2), 2);
                memcpy(&var3->unknown_4_, arg3 + (var1 + 4), 2);
                memcpy(&var3->unknown_6_, arg3 + (var1 + 6), 2);
                var1 += 8;
                int var11 = data_020e7a0c[var3->unknown_4_] * data_020e7a0c[var3->unknown_6_];
                if (arg0->unknown_4_ == 3)
                    var3->unknown_8_ = var11 / 2;
                else
                    var3->unknown_8_ = var11;
                var3->unknown_c_ = arg3 + var1;
                var1 += var3->unknown_8_;
                var2->unknown_c_ += var3->unknown_8_;
            }
            if (arg0->unknown_24_ < var2->unknown_c_)
                arg0->unknown_24_ = var2->unknown_c_;
            var2->unknown_10_ = (char*)arg2->Allocate(var2->unknown_c_);
            var4 = 0;
            var9 = 0;
            var3 = var2->unknown_8_;
            for (; var4 < var7; var4++, var3++) {
                char* var12 = var3->unknown_c_;
                var3->unknown_c_ = var2->unknown_10_ + var9;
                memcpy(var3->unknown_c_, var12, var3->unknown_8_);
                var9 += var3->unknown_8_;
            }
        }

        memcpy(&tableCount, src + off, 4);
        off += 4;
        hdr->tableCount = tableCount;
        if (hdr->tableCount <= 0x10)
            hdr->tableCount = 0x10;
        else if (hdr->tableCount <= 0x100)
            hdr->tableCount = 0x100;
        hdr->tableShift = (unsigned short)NNS_GfdAllocFrmPlttVram(hdr->tableCount * 2, 0, 0) << 3;
        hdr->table = (unsigned short*)alloc->Allocate(hdr->tableCount * 2);
        memcpy(hdr->table, src + off, hdr->tableCount * 2);
        off += tableCount * 2;
        memcpy(&hdr->entryCount, src + (off + 0x1e), 4);
        off += 0x22;
        hdr->entries = (ResEntry*)alloc->Allocate(hdr->entryCount * sizeof(ResEntry));
        for (j = 0; j < hdr->entryCount; j++) {
            ResEntry* entry = &hdr->entries[j];
            memcpy(name, src + off, 0x1e);
            off += 0x1e;
            int len = strlen(name) + 1;
            if (len % 4 != 0)
                len = (len / 4 + 1) * 4;
            char* str = (char*)alloc->Allocate(len);
            entry->name = str;
            strcpy(str, name);
        }
        for (var6 = 0; var6 < arg0->unknown_18_; var6++) {
            Struct_0203fd5c_3* var16 = &arg0->unknown_1c_[var6];
            memcpy(&var16->unknown_4_, arg3 + var1, 4);
            unsigned int var17 = var16->unknown_4_;
            unsigned int var18 = var17 * 4;
            var1 += 4;
            var16->unknown_8_ = arg2->Allocate(var18);
            var16->unknown_c_ = arg2->Allocate(var18);
            var16->unknown_10_ = arg2->Allocate(var18);
            memcpy(var16->unknown_8_, arg3 + var1, var18);
            var1 += var17 * 4;
            memcpy(var16->unknown_c_, arg3 + var1, var18);
            var1 += var17 * 4;
            memcpy(var16->unknown_10_, arg3 + var1, var18);
            var1 += var17 * 4;
        }
        arg0->unknown_0_ = 1;
    }
}
