#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct Struct_0205a658 { unsigned short unknown_0_, unknown_2_, unknown_4_; };
struct Struct_02043368_2 {
    unsigned short unknown_0_, unknown_2_;
    Struct_0205a658* unknown_4_;
    Struct_0205a658* unknown_8_;
    char unknown_c_[0x12];
    unsigned short unknown_1e_;
    char unknown_20_[2];
    unsigned char unknown_22_;
    char unknown_23_[5];
};
struct Struct_0205a658_2 {
    unsigned short unknown_0_, unknown_2_;
    int unknown_4_, unknown_8_;
};
struct Struct_0205a658_3 {
    char unknown_0_[0x38];
    int unknown_38_;
    int unknown_3c_;
    Struct_02043368_2* unknown_40_;
    int unknown_44_;
    unsigned int unknown_48_;
    unsigned short unknown_4c_, unknown_4e_;
};
int GetCellBankBlock_020b00a4(void*, void**);
void* GetEntryVarStride_020b00e0(Hdr02b00e0*, unsigned int);
void Sprite_Init(Struct0205a198*);

// USA: func_0205a658
extern "C" ARM int func_0205a658(Struct_0205a658_3* arg0, void* arg1, unsigned int arg2, SafeAllocator* arg3) {
    void* var0 = arg1;
    Struct_0205a658_2* var1;
    if (!var0) var0 = 0;
    else if (!arg2) var0 = 0;
    else {
        memcpy(var0, arg1, arg2);
        if (!func_020b00a4(var0, (void**)&var1)) var0 = 0;
    }
    if (!buffer) return 1;
    if (allocator && !self->records) {
        self->recordCount = header->count;
        self->records = (Struct0205a198*)allocator->Allocate(self->recordCount * sizeof(Struct0205a198));
        for (unsigned short i = 0; i < self->recordCount; ++i) Sprite_Init(&self->records[i]);
    }
    Struct_02043368_2* var3;
    unsigned short var4 = arg0->unknown_4c_;
    unsigned short var5;
    var3 = arg0->unknown_40_;
    if (var3 && var4 && arg3) {
        Struct_02043368_2* var6;
        Struct_02043368_2* var7;
        unsigned short var8;
        var5 = var1->unknown_0_;
        unsigned short var9 = 0;
        for (var8 = 0; var8 < var5; ++var8) {
            if (var4 <= var8) break;
            var7 = (Struct_02043368_2*)func_020b00e0(var1, var8);
            if (!var7) break;
            unsigned short var10 = var7->unknown_0_;
            var6 = &var3[var8];
            var6->unknown_1e_ = var8;
            var6->unknown_22_ = var9;
            var6->unknown_0_ = var7->unknown_0_;
            var6->unknown_2_ = var7->unknown_2_;
            var6->unknown_4_ = var7->unknown_4_;
            Struct_0205a658* var11 = (Struct_0205a658*)arg3->Allocate(var10 * sizeof(Struct_0205a658));
            var6->unknown_8_ = var11;
            var6->unknown_4_ = var11;
            for (unsigned short var12 = 0; var12 < var7->unknown_0_; ++var12) {
                Struct_0205a658* var13 = &var7->unknown_4_[var12];
                Struct_0205a658* var14 = &var6->unknown_8_[var12];
                var14->unknown_0_ = var13->unknown_0_;
                var14->unknown_2_ = var13->unknown_2_;
                var14->unknown_4_ = var13->unknown_4_;
            }
            var9 += var7->unknown_0_;
        }
    }
    arg0->unknown_4e_ = var1->unknown_0_;
    arg0->unknown_38_ = var1->unknown_8_;
    int var15;
    Struct_02043368_2* var16 = (Struct_02043368_2*)func_020b00e0(var1, (unsigned short)(var1->unknown_0_ - 1));
    if (!var16) return 1;
    struct { int unknown_0_; Struct_0205a658* unknown_4_; } var17;
    var17.unknown_0_ = arg0->unknown_38_;
    var17.unknown_4_ = &var16->unknown_4_[var16->unknown_0_ - 1];
    var15 = var17.unknown_0_;
    Struct_0205a658* var18 = var17.unknown_4_;
    unsigned int var19 = var18->unknown_4_;
    int var20 = var18->unknown_2_;
    int var21 = var18->unknown_0_;
    unsigned int var22 = var15 + 5;
    unsigned int var23 = (var19 & 0x3ff) << var22;
    unsigned int var24 = (var20 & 0xc000) >> 14;
    unsigned int var25 = (var21 & 0xc000) >> 14;
    unsigned int var26 = 5;
    switch (var25) {
    case 0:
        switch (var24) {
        case 0: var26 = 5; break;
        case 1: var26 = 7; break;
        case 2: var26 = 9; break;
        case 3: var26 = 11; break;
        }
        break;
    case 1:
        switch (var24) {
        case 0: var26 = 6; break;
        case 1: var26 = 7; break;
        case 2: var26 = 8; break;
        case 3: var26 = 10; break;
        }
        break;
    case 2:
        switch (var24) {
        case 0: var26 = 6; break;
        case 1: var26 = 7; break;
        case 2: var26 = 8; break;
        case 3: var26 = 10; break;
        }
        break;
    }
    if (var22 < var26) var22 = var26;
    arg0->unknown_48_ = var23 + (1 << var22);
    return 0;
}
