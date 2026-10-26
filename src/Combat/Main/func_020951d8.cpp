#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    int val;
};

struct Struct_02109404_2 {
    unsigned char f0;
    unsigned char pad1[0xb];
    SafeAllocator* alloc;
};
extern Struct_02109404_2 data_02109404;

struct Struct_0210941c {
    unsigned int id : 9;
    unsigned int rest : 23;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
};
extern struct Struct_0210941c data_0210941c[];
extern unsigned char data_02109418[];

struct Struct_020951d8 {
    unsigned short unknown_0_0_ : 9;
    unsigned short unknown_1_1_ : 1;
    unsigned short unknown_1_2_ : 1;
    unsigned short count : 5;
    unsigned short unknown_2_[13];
    unsigned short unknown_1c_;
    unsigned short big[5];
    void* link;
};
struct Struct_020951d8_2 {
    unsigned char pad[0xa4];
    void* slot;
};
extern "C" void func_02095910(struct Struct_020951d8_2* owner, struct Struct_020951d8* node);

// USA: func_020951d8
extern "C" ARM int func_020951d8(struct Variant02030b0c* arr, int b) {
    struct Struct_020951d8* node;
    int p0 = ((Script::Parameter*)&arr[0])->ToInt();
    int p1 = ((Script::Parameter*)&arr[1])->ToInt();
    struct Variant02030b0c* q = &arr[2];
    arr += 3;
    int p2 = ((Script::Parameter*)q)->ToInt();
    int n = data_02109418[0];
    struct Struct_0210941c* tbl = data_0210941c;
    if (data_02109404.f0 == 0) {
        int i;
        for (i = 0; i < n; i++) {
            if (tbl[i].id == p0) {
                break;
            }
        }
        if (i == n) {
            return 0;
        }
    }
    node = (struct Struct_020951d8*)data_02109404.alloc->Allocate(0x2c);
    node->unknown_0_0_ = p0;
    node->unknown_1_1_ = p1;
    node->unknown_1_2_ = p2;
    int var8 = 0;
    int var9 = 0;
    int i;
    node->link = 0;
    for (i = 0; i < b - 3; i++) {
        int v = ((Script::Parameter*)arr)->ToInt();
        arr++;
        if ((v >> 16) == 1000) {
            if (var9 <= 5) {
                node->big[var9] = v;
                var9++;
            }
        } else {
            if (var8 <= 13) {
                node->unknown_2_[var8] = v;
                var8++;
            }
        }
    }
    node->count = var8;
    node->unknown_1c_ = var9;
    func_02095910((struct Struct_020951d8_2*)&data_02109418, node);
    return 1;
}
