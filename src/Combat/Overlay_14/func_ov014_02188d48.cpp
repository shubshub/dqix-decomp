#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"


struct Struct_ov014_02188d48 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 12;
    unsigned short unknown_3_4_ : 4;
};

struct Struct_ov014_02188d48_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 11;
    unsigned short unknown_3_4_ : 4;
};

struct Struct_ov014_02188d48_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned int unknown_8_0_ : 31;
    unsigned int unknown_b_7_ : 1;
    Struct_ov014_02188d48* unknown_c_;
    char* unknown_10_;
};

struct Struct_ov014_02188bfc : public Struct_ov014_02188d48_3 {
    short unknown_14_;
    short unknown_16_;
    int unknown_18_;
    SafeAllocator* unknown_1c_;
};

struct Struct_ov014_02188d48_4;
struct Struct_0201bb78;

extern "C" unsigned int func_ov014_0218934c(NatTable* table);
extern "C" bool func_ov014_02188b20(NatTable* table, bool alreadyRelocated);
void InitEntryFromSource_02189244(S02189244* table, S02189244* file, char* alreadyRelocated, int func);
extern "C" int func_ov014_02188b18(NatEntry* entry);
extern "C" NatEntry* func_ov014_021892d4(NatTable* table, int key, int (*getKey)(NatEntry* entry));
extern "C" char* func_ov014_02188ba0(NatTable* table, char* pointer, char* defaultValue);
extern "C" char* Scenario_GetInstance();
bool Scenario_TestFlag(int, unsigned char*, int flag);
extern "C" void* Zone3D_GetInstance();
char* AllocateStringCopy020da150(SafeAllocator* allocator, const char* string);
bool ZoneId_IsGrotto(int zoneID);
bool LookupBitFromValueRange0201bb78(Obj_0201bb78* zoneStruct, unsigned int zoneID);

// USA: func_ov014_02188d48
extern "C" ARM bool func_ov014_02188d48(Struct_ov014_02188bfc* arg0, SafeAllocator* arg1, void* arg2, unsigned int arg3, short arg4) {
    if (arg1 == NULL || arg2 == NULL || arg3 == 0)
        return false;

    if (arg4 < 0) {
        if (arg1 != NULL && arg2 != NULL) {
            unsigned int var0;
            unsigned int var1;

            memcpy(arg0, arg2, 0xc);
            var0 = func_ov014_0218934c(arg0);
            var1 = arg0->unknown_8_0_;
            if (var0 != 0)
                arg0->unknown_c_ = (Struct_ov014_02188d48*)arg1->Allocate(var0);
            else
                arg0->unknown_c_ = NULL;
            if (var1 != 0)
                arg0->unknown_10_ = (char*)arg1->Allocate(var1);
            else
                arg0->unknown_10_ = NULL;
            if (arg0->unknown_c_ != NULL)
                memcpy(arg0->unknown_c_, (char*)arg2 + 0xc, var0);
            if (arg0->unknown_10_ != NULL)
                memcpy(arg0->unknown_10_, (char*)arg2 + (func_ov014_0218934c(arg0) + 0xc), var1);
            arg0->unknown_b_7_ = true;
        }
        func_ov014_02188b20(arg0, false);
    } else {
        Struct_ov014_02188d48_3 var2;
        bool var3;
        Struct_ov014_02188d48* var4;

        memset(&var2, 0, sizeof(var2));
        func_ov014_02189244((Struct_ov014_02188d48_4*)&var2, (Struct_ov014_02188d48_4*)arg2, (char*)&var3, NULL);
        var4 = func_ov014_021892d4(&var2, arg4, func_ov014_02188b18);
        if (var4 != NULL) {
            char* var5;
            bool var6;
            void* var7;
            Struct_ov014_02188d48_2* var8;
            unsigned short* var9;
            char** var10;
            int var11;
            int var12;
            Struct_ov014_02188d48_2* var13;
            Struct_ov014_02188d48_2* var14;
            Struct_ov014_02188d48_3 var15;
            char* var16;

            flags = Scenario_GetInstance();
            grottosKnown = Scenario_TestFlag((int)flags, (unsigned char*)(flags + 0x8c), 0x79d) != false;
            zoneStruct = Zone3D_GetInstance();

            var8 = (Struct_ov014_02188d48_2*)(var2.unknown_c_ + var2.unknown_0_);
            var9 = (unsigned short*)(var8 + var2.unknown_2_);
            var10 = (char**)((char*)var2.unknown_c_ + (((char*)(var9 + var2.unknown_4_) - (char*)var2.unknown_c_ + 3) & ~3));
            var11 = var4->unknown_3_4_;
            var13 = var8 + var4->unknown_2_0_;
            var12 = 0;
            var14 = var13;
            for (int var17 = 0; var17 < var11; var17++, var14++)
                var12 += var14->unknown_3_4_;

            var15.unknown_0_ = 1;
            var15.unknown_2_ = var11;
            var15.unknown_4_ = var12;
            var15.unknown_6_ = var11;
            var15.unknown_8_0_ = 0;
            var16 = (char*)arg1->Allocate(func_ov014_0218934c(&var15));
            var15.unknown_c_ = (Struct_ov014_02188d48*)var16;
            var15.unknown_10_ = NULL;
            if (var16 != NULL) {
                Struct_ov014_02188d48_2* var18;
                unsigned short* var19;
                Struct_ov014_02188d48_2* var20;
                int var21;
                int var22;
                int var23;
                unsigned short* var24;
                char** var25;
                bool var26;

                var18 = (Struct_ov014_02188d48_2*)(var16 + sizeof(Struct_ov014_02188d48));
                var19 = (unsigned short*)(var18 + var11);
                var25 = (char**)(var16 + (((char*)(var19 + var12) - var16 + 3) & ~3));
                memcpy(var16, var4, sizeof(Struct_ov014_02188d48));
                memcpy(var18, var13, var11 * sizeof(Struct_ov014_02188d48_2));
                var20 = var18;
                ((Struct_ov014_02188d48*)var16)->unknown_2_0_ = 0;

                var21 = 0;
                var23 = 0;
                for (int var27 = 0; var27 < var11; var27++) {
                    bool var28;

                    var22 = var20->unknown_3_4_;
                    memcpy(var19, var9 + var20->unknown_2_1_, var22 * sizeof(unsigned short));
                    memcpy(var25, var10 + var20->unknown_0_, sizeof(char*));
                    var20->unknown_0_ = var23;
                    var20->unknown_2_1_ = var21;
                    *var25 = func_020da150(arg1, func_ov014_02188ba0(&var2, *var25, NULL));

                    known = count == 0;
                    zoneID = newIndices;
                    for (int j = 0; j < count; j++, zoneID++) {
                        known = (ZoneId_IsGrotto(*zoneID) && grottosKnown) || LookupBitFromValueRange0201bb78((Obj_0201bb78*)zoneStruct, *zoneID);
                        if (known)
                            break;
                    }
                    var20->unknown_2_0_ = var28;

                    var19 += var22;
                    var25++;
                    var21 += var22;
                    var20++;
                    var23++;
                }

                do {
                    var26 = false;
                    var20 = var18;
                    for (int var30 = 0; var30 < var11 - 1; var30++, var20++) {
                        if (!var20[0].unknown_2_0_ && var20[1].unknown_2_0_) {
                            Struct_ov014_02188d48_2 var31;
                            memcpy(&var31, &var20[0], sizeof(Struct_ov014_02188d48_2));
                            memcpy(&var20[0], &var20[1], sizeof(Struct_ov014_02188d48_2));
                            memcpy(&var20[1], &var31, sizeof(Struct_ov014_02188d48_2));
                            var26 = true;
                        }
                    }
                } while (var26);
            } else {
                var15.unknown_0_ = 0;
                var15.unknown_2_ = 0;
                var15.unknown_4_ = 0;
                var15.unknown_6_ = 0;
            }
            memcpy(arg0, &var15, sizeof(Struct_ov014_02188d48_3));
        }
    }
    return true;
}
