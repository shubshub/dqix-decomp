#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"


struct Struct_ov014_02188d48 {
    unsigned short key_;
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
    unsigned int relocated_ : 1;
    Struct_ov014_02188d48* entries_;
    char* unknown_10_;
};

struct Struct_ov014_02188bfc : public Struct_ov014_02188d48_3 {
    short unknown_14_;
    short state_;
    int unknown_18_;
    SafeAllocator* allocator_;
};

struct Struct_ov014_02188d48_4;
struct Obj_0201bb78;

extern "C" unsigned int func_ov014_0218934c(Struct_ov014_02188d48_3* table);
extern "C" bool func_ov014_02188b20(Struct_ov014_02188d48_3* table, bool alreadyRelocated);
extern "C" void func_ov014_02189244(Struct_ov014_02188d48_4* table, Struct_ov014_02188d48_4* file, char* alreadyRelocated, int func);
extern "C" int func_ov014_02188b18(Struct_ov014_02188d48* entry);
extern "C" Struct_ov014_02188d48* func_ov014_021892d4(Struct_ov014_02188d48_3* table, int key, int (*arg2)(Struct_ov014_02188d48* entry));
extern "C" char* func_ov014_02188ba0(Struct_ov014_02188d48_3* table, char* pointer, char* arg2);
extern "C" char* Scenario_GetInstance();
extern "C" bool Scenario_TestFlag(int, unsigned char*, int flag);
extern "C" void* Zone3D_GetInstance();
extern "C" char* func_020da150(SafeAllocator* allocator, const char* string);
extern "C" bool ZoneId_IsGrotto(int zoneID);
extern "C" bool func_0201bb78(Obj_0201bb78* zoneStruct, unsigned int zoneID);

// USA: func_ov014_02188d48
extern "C" ARM bool func_ov014_02188d48(Struct_ov014_02188bfc* self, SafeAllocator* allocator, void* file, unsigned int fileSize, short arg4) {
    if (allocator == NULL || file == NULL || fileSize == 0)
        return false;

    if (arg4 < 0) {
        if (allocator != NULL && file != NULL) {
            unsigned int var0;
            unsigned int dataSize;

            memcpy(self, file, 0xc);
            var0 = func_ov014_0218934c(self);
            dataSize = self->unknown_8_0_;
            if (var0 != 0)
                self->entries_ = (Struct_ov014_02188d48*)allocator->Allocate(var0);
            else
                self->entries_ = NULL;
            if (dataSize != 0)
                self->unknown_10_ = (char*)allocator->Allocate(dataSize);
            else
                self->unknown_10_ = NULL;
            if (self->entries_ != NULL)
                memcpy(self->entries_, (char*)file + 0xc, var0);
            if (self->unknown_10_ != NULL)
                memcpy(self->unknown_10_, (char*)file + (func_ov014_0218934c(self) + 0xc), dataSize);
            self->relocated_ = true;
        }
        func_ov014_02188b20(self, false);
    } else {
        Struct_ov014_02188d48_3 source;
        bool alreadyRelocated;
        Struct_ov014_02188d48* entry;

        memset(&source, 0, sizeof(source));
        func_ov014_02189244((Struct_ov014_02188d48_4*)&source, (Struct_ov014_02188d48_4*)file, (char*)&alreadyRelocated, NULL);
        entry = func_ov014_021892d4(&source, arg4, func_ov014_02188b18);
        if (entry != NULL) {
            char* flags;
            bool grottosKnown;
            void* zoneStruct;
            Struct_ov014_02188d48_2* groups;
            unsigned short* indices;
            char** var10;
            int var11;
            int var12;
            Struct_ov014_02188d48_2* var13;
            Struct_ov014_02188d48_2* var14;
            Struct_ov014_02188d48_3 table;
            char* buffer;

            flags = Scenario_GetInstance();
            grottosKnown = Scenario_TestFlag((int)flags, (unsigned char*)(flags + 0x8c), 0x79d) != false;
            zoneStruct = Zone3D_GetInstance();

            groups = (Struct_ov014_02188d48_2*)(source.entries_ + source.unknown_0_);
            indices = (unsigned short*)(groups + source.unknown_2_);
            var10 = (char**)((char*)source.entries_ + (((char*)(indices + source.unknown_4_) - (char*)source.entries_ + 3) & ~3));
            var11 = entry->unknown_3_4_;
            var13 = groups + entry->unknown_2_0_;
            var12 = 0;
            var14 = var13;
            for (int i = 0; i < var11; i++, var14++)
                var12 += var14->unknown_3_4_;

            table.unknown_0_ = 1;
            table.unknown_2_ = var11;
            table.unknown_4_ = var12;
            table.unknown_6_ = var11;
            table.unknown_8_0_ = 0;
            buffer = (char*)allocator->Allocate(func_ov014_0218934c(&table));
            table.entries_ = (Struct_ov014_02188d48*)buffer;
            table.unknown_10_ = NULL;
            if (buffer != NULL) {
                Struct_ov014_02188d48_2* var18;
                unsigned short* var19;
                Struct_ov014_02188d48_2* group;
                int var21;
                int count;
                int var23;
                unsigned short* zoneID;
                char** var25;
                bool swapped;

                var18 = (Struct_ov014_02188d48_2*)(buffer + sizeof(Struct_ov014_02188d48));
                var19 = (unsigned short*)(var18 + var11);
                var25 = (char**)(buffer + (((char*)(var19 + var12) - buffer + 3) & ~3));
                memcpy(buffer, entry, sizeof(Struct_ov014_02188d48));
                memcpy(var18, var13, var11 * sizeof(Struct_ov014_02188d48_2));
                group = var18;
                ((Struct_ov014_02188d48*)buffer)->unknown_2_0_ = 0;

                var21 = 0;
                var23 = 0;
                for (int i = 0; i < var11; i++) {
                    bool known;

                    count = group->unknown_3_4_;
                    memcpy(var19, indices + group->unknown_2_1_, count * sizeof(unsigned short));
                    memcpy(var25, var10 + group->unknown_0_, sizeof(char*));
                    group->unknown_0_ = var23;
                    group->unknown_2_1_ = var21;
                    *var25 = func_020da150(allocator, func_ov014_02188ba0(&source, *var25, NULL));

                    known = count == 0;
                    zoneID = var19;
                    for (int j = 0; j < count; j++, zoneID++) {
                        known = (ZoneId_IsGrotto(*zoneID) && grottosKnown) || func_0201bb78((Obj_0201bb78*)zoneStruct, *zoneID);
                        if (known)
                            break;
                    }
                    group->unknown_2_0_ = known;

                    var19 += count;
                    var25++;
                    var21 += count;
                    group++;
                    var23++;
                }

                do {
                    swapped = false;
                    group = var18;
                    for (int i = 0; i < var11 - 1; i++, group++) {
                        if (!group[0].unknown_2_0_ && group[1].unknown_2_0_) {
                            Struct_ov014_02188d48_2 var31;
                            memcpy(&var31, &group[0], sizeof(Struct_ov014_02188d48_2));
                            memcpy(&group[0], &group[1], sizeof(Struct_ov014_02188d48_2));
                            memcpy(&group[1], &var31, sizeof(Struct_ov014_02188d48_2));
                            swapped = true;
                        }
                    }
                } while (swapped);
            } else {
                table.unknown_0_ = 0;
                table.unknown_2_ = 0;
                table.unknown_4_ = 0;
                table.unknown_6_ = 0;
            }
            memcpy(self, &table, sizeof(Struct_ov014_02188d48_3));
        }
    }
    return true;
}
