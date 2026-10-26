#include <globaldefs.h>
#include "GameState/GameState.h"

struct GetElementByIndex0209bd80Element;
struct GetElementByIndex0209bd80Container;
struct GetElementByIndex0209bd80Element* GetElementByIndex0209bd80(struct GetElementByIndex0209bd80Container* c, int index);

int GetEntryCount0209bd38(char* obj);


extern "C" int RandomIntBelow(int n);

struct EntryTable0209bd94;
struct Entry0209bd94;
struct Entry0209bd94* FindEntryByHalfword0209bd94(struct EntryTable0209bd94* table, int key);

struct Entry02073ec4 {
    unsigned short field0;
    unsigned short pad2;
    unsigned int type : 3;
    unsigned int rsvd1 : 10;
    unsigned int flags8 : 8;
    unsigned int rsvd2 : 11;
    unsigned char pad8[0x20 - 8];
};

// USA: func_02073ec4
ARM struct Entry0209bd94* FindMatchingEntryByMask02073ec4(int mask, void* list) {
    GameState* battleStruct = GameState::GetInstance();
    int arr2[6];
    int arr1[6];
    int count2 = 0;
    int count1 = 0;
    int i;

    for (i = 0; i < GetEntryCount0209bd38((char*)list); i++) {
        struct Entry02073ec4* entry = (struct Entry02073ec4*)GetElementByIndex0209bd80((struct GetElementByIndex0209bd80Container*)list, i);
        if (!entry) continue;

        if (entry->type == 0 && battleStruct->GetTimeOfDay() == 0) continue;
        if (entry->type == 1 && battleStruct->GetTimeOfDay() != 0) continue;

        {
            int flags8 = entry->flags8;
            int field0 = entry->field0;
            arr1[count1++] = field0;
            if (flags8 != 0 && (flags8 & mask) == 0) continue;
            arr2[count2++] = field0;
        }
    }

    if (count2 == 0) {
        int key;
        if (count1 == 0) return NULL;
        key = arr1[RandomIntBelow(count1)];
        return FindEntryByHalfword0209bd94((struct EntryTable0209bd94*)list, key);
    } else {
        int key = arr2[RandomIntBelow(count2)];
        return FindEntryByHalfword0209bd94((struct EntryTable0209bd94*)list, key);
    }
}
