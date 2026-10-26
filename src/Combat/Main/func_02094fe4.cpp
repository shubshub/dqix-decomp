#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"


struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern "C" void* Scenario_GetInstance(void);

struct PackedNibbleArray0206e120 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};
extern "C" int func_0206e120(struct PackedNibbleArray0206e120* obj, int index);

extern "C" void func_0205ec70(SafeAllocator* alloc, int limit, struct Variant02030b0c* arr, void* arg3, void* arg4);

struct Struct_02109418 { unsigned char pad[0xa0]; void* slot; };
struct Struct_02094d88 {
    unsigned short f0;
    unsigned short unknown_2_0_ : 9;
    unsigned short unknown_3_1_  : 1;
    unsigned short unknown_3_2_ : 1;
    unsigned short bit11 : 1;
    unsigned short unknown_3_4_ : 1;
    unsigned short bit13 : 1;
    unsigned short pad2  : 2;
    unsigned int   unknown_4_0_ : 8;
    unsigned int   unknown_5_0_ : 6;
    unsigned int   unknown_5_6_ : 5;
    unsigned int   pad4   : 13;
    int f8;
    void* link;
};
extern "C" void func_020958fc(struct Struct_02109418* owner, struct Struct_02094d88* node);

struct Struct_02109404_2 { unsigned char pad[0xc]; SafeAllocator* alloc; };
extern Struct_02109404_2 data_02109404;
extern Struct_02109418 data_02109418;

// USA: func_02094fe4
extern "C" ARM int func_02094fe4(struct Variant02030b0c* arr, int b) {
    int p0 = ((Script::Parameter*)&arr[0])->ToInt();
    int p1 = ((Script::Parameter*)&arr[1])->ToInt();
    int p2 = ((Script::Parameter*)&arr[2])->ToInt();
    int p3 = ((Script::Parameter*)&arr[3])->ToInt();
    int p4 = ((Script::Parameter*)&arr[4])->ToInt();
    int p5 = ((Script::Parameter*)&arr[5])->ToInt();
    void* nibbles = Scenario_GetInstance();
    int p6 = ((Script::Parameter*)&arr[6])->ToInt();
    if (p6 >= 0) {
        int ok = (func_0206e120((struct PackedNibbleArray0206e120*)nibbles, p6) == 3);
        if (ok == 0) {
            return 0;
        }
    }

    struct Struct_02094d88* node = (struct Struct_02094d88*)data_02109404.alloc->Allocate(0x10);
    node->f0 = p1;
    node->unknown_2_0_ = p0;
    node->unknown_4_0_ = p2;
    node->unknown_5_0_ = p3;
    node->unknown_5_6_ = p4;
    node->unknown_3_1_ = p5;

    int p7 = ((Script::Parameter*)&arr[7])->ToInt();
    node->bit11 = p7;
    int p8 = ((Script::Parameter*)&arr[8])->ToInt();
    node->unknown_3_2_ = p8;
    int p9 = ((Script::Parameter*)&arr[9])->ToInt();
    node->unknown_3_4_ = p9;
    int p10 = ((Script::Parameter*)&arr[10])->ToInt();
    node->bit13 = p10;

    node->f8 = 0;
    node->link = 0;

    int var14 = 0;
    func_0205ec70(data_02109404.alloc, b - 0xb, &arr[11], &node->f8, &var14);

    func_020958fc(&data_02109418, node);
    return 1;
}
