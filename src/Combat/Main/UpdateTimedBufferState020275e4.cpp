#include <globaldefs.h>
#include "Resource/Brightness.h"

void* GlobalFlags_GetInstance(void);

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

int InitAndCopyBuffer02023330(void* arg0, int flag1);
int InitAndCopyBuffer020233b8(void* arg0, int flag1);

struct Obj020275e4 {
    char pad0[0x9c1];
    unsigned char mode;      // 0x9c1
    char pad1[0xbe4 - 0x9c2];
    int limit;                // 0xbe4
    int count;                 // 0xbe8
    short state;               // 0xbec
    short counter;             // 0xbee
};

// USA: func_020275e4
ARM void UpdateTimedBufferState020275e4(struct Obj020275e4* obj) {
    if (TestFlags02046708((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) {
        return;
    }

    int len = 0;
    if (obj->mode == 0) {
        len = 0x90;
    } else if (obj->mode == 1) {
        len = 0x98;
    }
    if (len == 0) {
        return;
    }
    if (len >= obj->limit) {
        return;
    }
    if (GetBrightness(GetGameResources(), true)) {
        return;
    }

    switch (obj->state) {
    case 0:
        obj->counter++;
        if (obj->counter >= 0x10) {
            obj->counter = 0;
            obj->state = 1;
        }
        return;
    case 1:
        obj->count++;
        if (obj->limit < obj->count) {
            obj->count = -len;
        }
        if (obj->mode == 0) {
            InitAndCopyBuffer02023330(obj, 0);
        } else {
            InitAndCopyBuffer020233b8(obj, 0);
        }
        if (obj->count == 0) {
            obj->state = 2;
        }
        return;
    }
}
