#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Util/Random.h"

struct Struct_02052df8;
struct Struct_020a0720;
struct Struct_0209fffc;
struct Struct_020a0750;
struct Struct_020a0038;

struct Struct_ov024_021df924_7 {
    char pad0[0x3d];
    unsigned char rank;
};
struct Struct_ov024_021df924_8 {
    char pad0[0x10];
    unsigned short id;
};
struct Struct_ov024_021df924_9 {
    char pad0[2];
    unsigned char rate[2];
    unsigned short message[2];
};
struct Struct_ov024_021df924_10 {
    char pad0[4];
    unsigned int level : 10;
    unsigned int rest : 22;
};
struct Struct_ov024_021df924_11 : GameObject {
    char unknown_13c_[8];
#if defined(jpn)
    union {
        Struct_ov024_021df924_8* item;
        Struct_ov024_021df924_10* info;
    };
    Struct_ov024_021df924_9* unknown_148_;
#else
    Struct_ov024_021df924_8* item;
    Struct_ov024_021df924_9* unknown_148_;
    char unknown_14c_[4];
    Struct_ov024_021df924_10* info;
#endif
};
struct Struct_ov024_021df924_12 {
    char pad0[4];
    short id;
};
struct Struct_ov024_021df924_13 {
    char pad0[0x1c];
    unsigned char field_1c : 7;
    unsigned char alternate : 1;
};
struct Struct_ov024_021df924 {
    char pad0[0x8e4a];
    short pending;
};
struct Struct_ov024_021df924_2 {
    int field_0;
    Struct_ov024_021df924_12* message;
    int field_8;
    Struct_ov024_021df924_13* flags;
    Struct_ov024_021df924* world;
};
struct Struct_ov024_021df924_3 {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int flags : 2;
};
struct Struct_ov024_021df924_4 {
    char pad0[0x20];
    Struct_ov024_021df924_3 unknown_20_;
    Struct_ov024_021df924_3 unknown_24_;
};
struct Struct_ov024_021df924_5 {
    unsigned int low : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int first : 7;
    unsigned int second : 7;
    unsigned int rest : 7;
};
struct Struct_ov024_021df924_6 {
    SafeAllocator alloc;
    char body[0x2c - sizeof(SafeAllocator)];
    void* source;
    char unknown_30_[8];
};

extern float data_ov024_021fe860[];

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int func_ov000_0215fd24(int world, int id);
extern "C" unsigned short* Zone3D_GetInstance(void);
static inline int GetActionID() { return *Zone3D_GetInstance(); }
extern "C" int func_ov024_021df71c(Struct_ov024_021df924_11* self, unsigned short arg1, int alternate, unsigned short* arg3, unsigned short* arg4, unsigned short* arg5);
extern "C" short func_02052df8(Struct_02052df8* holder, int part);
extern "C" void* func_ov000_02160130();
extern "C" char* func_ov000_02160f08(void* work);
extern "C" void* ItemTable_Construct(void* obj);
extern "C" void func_0207cbe8(char* obj);
extern "C" void func_ov000_0215fa70(void*, short, short, short);
extern "C" int func_0207ccf0(void* buf, int a, int b, int c, int d, int e, int f);
extern "C" int func_020ac020(void* unused, short* indices, int* dest, int count);
extern "C" void func_020abe84(void* unused, short* indices, Struct_ov024_021df924_5* values, int count);
extern "C" void func_020ac4c0(void* block);
extern "C" void func_020a0720(Struct_020a0720* block, unsigned int value);
extern "C" void func_0209fffc(Struct_0209fffc* block, unsigned int value);
extern "C" void func_020a0750(Struct_020a0750* block, unsigned int value);
extern "C" void func_020a0038(Struct_020a0038* block, unsigned int value);
extern "C" void func_020ac494(void* block);
extern "C" void* func_ov000_0215e958(void* world);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int value);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* target, int a, int b, int c, int d);

// USA: func_ov024_021df924
extern "C" ARM void* func_ov024_021df924(Struct_ov024_021df924_2* self, short id, int targetId, Struct_ov024_021df924_4* data) {
    Struct_ov024_021df924_11* actor = (Struct_ov024_021df924_11*)func_0200ff1c(GameState::GetInstance(), id);
    if (!actor) return 0;
    Struct_ov024_021df924_11* target = (Struct_ov024_021df924_11*)func_ov000_021536f8((int)self->world, targetId);
    if (!target) return 0;
    Struct_ov024_021df924_9* var2 = target->unknown_148_;
    if (!var2) return 0;
    int var3 = 0;
    unsigned char* rate;
    unsigned short* msg;
    rate = var2->rate;
    msg = var2->message;
    short level = (unsigned short)actor->info->level;
    Random* rng = (Random*)self->world;
    float var8[2];
    var8[0] = NextRandomFloatBetween(rng, 0.0f, 100.0f);
    var8[1] = NextRandomFloatBetween(rng, 0.0f, 100.0f);
    int var9 = 0;
    unsigned short var10;
    unsigned short var11;
    unsigned short var12;
    Struct_ov024_021df924_5 counts;
    Struct_ov024_021df924_6 loader;
    int i;
    for (i = 0; i < 2; i++, rate++, msg++) {
        if (*rate == 0) continue;
        var10 = 0;
        var11 = 0;
        var12 = 0;
        int found = 0;
        void* scene = LinkSession_GetInstance();
        if (self->world->pending == 0 && LinkSession_IsHostOrSolo(scene) && func_ov000_0215fd24((int)self->world, id)) {
            found = func_ov024_021df71c(target, GetActionID(), i != 0, &var10, &var12, &var11);
        }
        if (((Struct_ov024_021df924_7*)target->currentStats_)->rank != 0 && !found) continue;
        if (data_ov024_021fe860[*rate] > 0.0f) var9 = 1;
        float low = 2.0f * (100.0f * data_ov024_021fe860[*rate]);
        float high = 6.0f * (100.0f * data_ov024_021fe860[*rate]);
        if (func_02052df8((Struct_02052df8*)actor, 9) == 0x467f) {
            low = 2.0f * low;
            high = 2.0f * high;
        }
        if (low > 50.0f) low = 50.0f;
        if (high > 50.0f) high = 50.0f;
        if (level > 0x33) {
            if (level >= 999) low = high;
            else low = low + (float)(level - 0x33) * ((high - low) / 948.0f);
        }
        if (!(var8[i] < low)) continue;
        self->message->id = *msg;
        var3 = 1;
        ((Struct_ov024_021df924_7*)target->currentStats_)->rank = i + 1;
        if (func_ov000_0215fd24((int)self->world, id)) {
            char* work = func_ov000_02160f08(func_ov000_02160130());
            char* special = work + 0xd0;
            char* normal = work + 0xe8;
            loader.alloc.ResetAllocatorPointer();
            ItemTable_Construct(loader.body);
            func_0207cbe8((char*)&loader);
            func_0207cbe8((char*)&loader);
            if (found) {
                self->message->id = var10;
                func_ov000_0215fa70(self->world, var11, var12, var10);
                loader.source = special;
            } else {
                loader.source = normal;
                func_0207ccf0(&loader, self->message->id, 1, id, 1, 0, 0);
                counts.low = 0;
                counts.unknown_1_2_ = 0;
                counts.first = 0;
                counts.second = 0;
                if (target->item) {
                    short item = target->item->id;
                    if (func_020ac020(0, &item, (int*)&counts, 1)) {
                        if (i == 0) {
                            unsigned int count = counts.first + 1;
                            if (count > 99) count = 99;
                            counts.first = count;
                        }
                        if (i == 1) {
                            unsigned int count = counts.second + 1;
                            if (count > 99) count = 99;
                            counts.second = count;
                        }
                        func_020abe84(0, &item, &counts, 1);
                    }
                }
            }
        }
        break;
    }
    char block[0xb0];
    func_020ac4c0(block);
    char* tail = block + 0x68;
    func_020a0720((Struct_020a0720*)block, 1);
    func_0209fffc((Struct_0209fffc*)tail, 1);
    unsigned short message;
    if (var3) {
        func_020a0750((Struct_020a0750*)block, 1);
        func_020a0038((Struct_020a0038*)tail, 1);
        message = data->unknown_24_.first;
    } else if (!var9) {
        message = 0x25a;
    } else {
        message = data->unknown_24_.third;
    }
    func_020ac494(block);
    void* entry = func_ov000_0215e958(self->world);
    if (!entry) return 0;
    if (message) func_ov000_0215a88c(self->world, entry, message);
    func_ov000_0215cd44(self->world, entry, target, 0, 0, 0, self->flags->alternate != 0);
    return entry;
}
