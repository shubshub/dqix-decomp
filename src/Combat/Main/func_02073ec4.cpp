#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0209bd80;
struct Struct_02073ec4;
extern "C" struct Struct_0209bd80* func_0209bd80(struct Struct_02073ec4* c, int index);

extern "C" int func_0209bd38(char* obj);


extern "C" int RandomIntBelow(int n);

struct Struct_02073ec4_2;
struct Struct_02073ec4_3;
extern "C" struct Struct_02073ec4_3* func_0209bd94(struct Struct_02073ec4_2* table, int key);

struct Struct_02073ec4_4 {
    unsigned short field0;
    unsigned short pad2;
    unsigned int type : 3;
    unsigned int unknown_4_3_ : 10;
    unsigned int unknown_5_5_ : 8;
    unsigned int unknown_6_5_ : 11;
    unsigned char pad8[0x20 - 8];
};

// USA: func_02073ec4
extern "C" ARM struct Struct_02073ec4_3* func_02073ec4(int mask, void* list) {
    GameState* battleStruct = GameState::GetInstance();
    int arr2[6];
    int arr1[6];
    int count2 = 0;
    int count1 = 0;
    int i;

    for (i = 0; i < func_0209bd38((char*)list); i++) {
        struct Struct_02073ec4_4* entry = (struct Struct_02073ec4_4*)func_0209bd80((struct Struct_02073ec4*)list, i);
        if (!entry) continue;

        if (entry->type == 0 && battleStruct->GetTimeOfDay() == 0) continue;
        if (entry->type == 1 && battleStruct->GetTimeOfDay() != 0) continue;

        {
            int var7 = entry->unknown_5_5_;
            int field0 = entry->field0;
            arr1[count1++] = field0;
            if (var7 != 0 && (var7 & mask) == 0) continue;
            arr2[count2++] = field0;
        }
    }

    if (count2 == 0) {
        int key;
        if (count1 == 0) return NULL;
        key = arr1[RandomIntBelow(count1)];
        return func_0209bd94((struct Struct_02073ec4_2*)list, key);
    } else {
        int key = arr2[RandomIntBelow(count2)];
        return func_0209bd94((struct Struct_02073ec4_2*)list, key);
    }
}
