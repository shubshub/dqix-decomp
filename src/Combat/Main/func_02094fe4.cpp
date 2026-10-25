#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"


struct Struct_0201c1c8 {
    int unknown_0_;
    union {
        int unknown_0_;
        float unknown1_0_;
    } unknown_4_;
};

extern "C" void* Scenario_GetInstance(void);

struct Struct_0205faf4_3 {
    unsigned char unknown_0_[0x2CC];
    unsigned char unknown_2cc_[1];
};
extern "C" int func_0206e120(struct Struct_0205faf4_3* arg0, int arg1);

extern "C" void func_0205ec70(SafeAllocator* arg0, int arg1, struct Struct_0201c1c8* arg2, void* arg3, void* arg4);

struct Struct_02109418 { unsigned char unknown_0_[0xa0]; void* unknown_a0_; };
struct Struct_02094d88 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 9;
    unsigned short unknown_3_1_  : 1;
    unsigned short unknown_3_2_ : 1;
    unsigned short unknown_3_3_ : 1;
    unsigned short unknown_3_4_ : 1;
    unsigned short unknown_3_5_ : 1;
    unsigned short unknown_3_6_  : 2;
    unsigned int   unknown_4_0_ : 8;
    unsigned int   unknown_5_0_ : 6;
    unsigned int   unknown_5_6_ : 5;
    unsigned int   unknown_6_3_   : 13;
    int unknown_8_;
    void* unknown_c_;
};
extern "C" void func_020958fc(struct Struct_02109418* arg0, struct Struct_02094d88* arg1);

struct Struct_02109404_2 { unsigned char unknown_0_[0xc]; SafeAllocator* unknown_c_; };
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
        int ok = (GetPackedNibbleField((struct PackedNibbleArray0206e120*)nibbles, p6) == 3);
        if (ok == 0) {
            return 0;
        }
    }

    struct Struct_02094d88* var9 = (struct Struct_02094d88*)data_02109404.unknown_c_->Allocate(0x10);
    var9->unknown_0_ = var1;
    var9->unknown_2_0_ = var0;
    var9->unknown_4_0_ = var2;
    var9->unknown_5_0_ = var3;
    var9->unknown_5_6_ = var4;
    var9->unknown_3_1_ = var5;

    int var10 = ((Script::Parameter*)&arg0[7])->ToInt();
    var9->unknown_3_3_ = var10;
    int var11 = ((Script::Parameter*)&arg0[8])->ToInt();
    var9->unknown_3_2_ = var11;
    int var12 = ((Script::Parameter*)&arg0[9])->ToInt();
    var9->unknown_3_4_ = var12;
    int var13 = ((Script::Parameter*)&arg0[10])->ToInt();
    var9->unknown_3_5_ = var13;

    var9->unknown_8_ = 0;
    var9->unknown_c_ = 0;

    int var14 = 0;
    func_0205ec70(data_02109404.unknown_c_, arg1 - 0xb, &arg0[11], &var9->unknown_8_, &var14);

    func_020958fc(&data_02109418, var9);
    return 1;
}
