#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217193c_1841 = 0x62d };
enum { Enum_ov003_0217193c_1843 = 0x62f };
enum { Enum_ov003_0217193c_1848 = 0x634 };
#else
enum { Enum_ov003_0217193c_1841 = 0x731 };
enum { Enum_ov003_0217193c_1843 = 0x733 };
enum { Enum_ov003_0217193c_1848 = 0x738 };
#endif
#include "GameState/GameState.h"

struct Struct_0202bad4;
struct Struct_0202bad4_2;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void LinkSession_End(void* ptr);
extern "C" int func_ov003_02171d78(void* list, unsigned char* key);
extern "C" int func_0202bae4(void* obj);
extern "C" struct Struct_0202bad4* func_0202bad4(struct Struct_0202bad4_2* base, int index);
extern "C" int func_0202b840(int* state, int id);

struct Struct_ov003_0217193c_2 { unsigned char data[0x14]; };
struct Struct_ov003_0217193c_3 { unsigned char data[6]; };

struct Struct_ov003_0217193c_4 {
    unsigned char low : 3;
    unsigned char available : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov003_0217193c_5 {
    char pad0[0x50];
    Struct_ov003_0217193c_2 name;
    unsigned char unknown_64_;
    Struct_ov003_0217193c_4 flags;
    unsigned short field66;
    Struct_ov003_0217193c_3 key;
    char unknown_6e_[2];
    int unknown_70_;
};

struct Struct_ov003_0217193c {
    unsigned char state;
    char pad1[3];
    unsigned int timer;
    char pad8[0x199 - 8];
    signed char selected;
    char unknown_19a_[2];
    Struct_ov003_0217193c_2 name;
    unsigned char unknown_1b0_;
    Struct_ov003_0217193c_4 flags;
    unsigned short field1b2;
    Struct_ov003_0217193c_3 key;
    char unknown_1ba_[2];
    int unknown_1bc_;
    char unknown_1c0_[Enum_ov003_0217193c_1841 - 0x1c0];
    signed char unknown_731_;
    signed char unknown_732_;
    char unknown_733_[Enum_ov003_0217193c_1848 - Enum_ov003_0217193c_1843];
    int unknown_738_;
};

// USA: func_ov003_0217193c
extern "C" ARM void func_ov003_0217193c(struct Struct_ov003_0217193c* obj) {
    Struct_ov003_0217193c_5* entry;
    GameState* battle;
    void* search;
    unsigned int var3;
    unsigned int count;
    int found;
    unsigned int i;

    battle = GameState::GetInstance();
    search = LinkSession_GetInstance();
    var3 = battle->GetEffectiveDeltaTime();

    if (var3 < obj->timer && obj->unknown_732_ > 0) {
        obj->timer -= var3;
        count = func_0202bae4(search);
        if (count == 0) return;
        found = 0;
        for (i = 0; i < count; i++) {
            entry = (Struct_ov003_0217193c_5*)func_0202bad4((struct Struct_0202bad4_2*)search, i);
            if (func_ov003_02171d78(obj, entry->key.data) == 0 && entry->flags.available) {
#if !defined(jpn)
                if (found > 0 && obj->flags.unknown_0_6_ != entry->flags.unknown_0_6_) break;
#endif
                func_0202b840((int*)search, i);
                obj->selected = 0;
#if !defined(jpn)
                obj->name = entry->name;
                obj->unknown_1b0_ = entry->unknown_64_;
                obj->flags = entry->flags;
                obj->field1b2 = entry->field66;
                obj->key = entry->key;
                obj->unknown_1bc_ = entry->unknown_70_;
#endif
                obj->state = 6;
                found++;
            } else if (entry->flags.unknown_0_4_) {
                obj->unknown_738_ = entry->unknown_70_;
            }
        }
        if (found <= 0) return;
        obj->timer = 0;
        obj->unknown_732_ = obj->unknown_732_ - 1;
    } else {
        obj->timer = 0;
        LinkSession_End(search);
        obj->unknown_731_--;
        if (obj->unknown_731_ > 0) {
            obj->state = 0;
        } else {
            obj->state = 8;
        }
    }
}
