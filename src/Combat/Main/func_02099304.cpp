#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_02099304 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
#if defined(jpn)
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 5;
#else
    unsigned int unknown1_2_5_ : 10;
#endif
    unsigned int unknown_3_7_ : 1;
    int unknown_4_0_ : 9;
    signed char unknown_6_;
};

struct Struct_020465c0;
struct Struct_02046574_2;

struct Struct_021098e8_2 {
    unsigned char unknown_0_;
#if defined(jpn)
    Struct_02099304* unknown_8_;
    void* unknown_4_;
#else
    void* unknown_4_;
    Struct_02099304* unknown_8_;
#endif
};

extern Struct_021098e8_2 data_021098e8;
extern Script::OpcodeLookupEntry data_020f1504[];

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* gs);
extern "C" void func_02046380(StoreStruct* store);
extern "C" void* memset(void* dst, int value, unsigned int length);
void RegisterSlotA020cf0fc(int out);
StoreStruct* MessageSystem_GetInstance(void);
void StoreInArray0x8b0_020465c0(StoreStruct* store, int index, int value);
int CalculateAge_02098f20(int a, int b, int c);
void MessageSystem_SetStringArgument(Obj02046574* obj, int index, char* name);

// USA: func_02099304
extern "C" ARM int func_02099304(Struct_02099304* arg0, char* arg1, const void* arg2, unsigned int arg3, void* arg4, int arg5, unsigned char arg6, char* arg7, char* arg8) {
    void* var0 = func_0202ae18();
    int var1[4];
    Script var2;

    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    if (arg5 < 0x190) {
        return 0;
    }
    memset(arg4, 0, arg5);
    data_021098e8.unknown_8_ = arg0;
    data_021098e8.unknown_4_ = arg4;
    data_021098e8.unknown_0_ = 0;
    if (arg6 == 0) {
        data_021098e8.unknown_0_ |= 0x10;
    } else {
        if (arg6 & 2) {
            if (func_0202c508(var0)) {
                func_020cf0fc((int)var1);
                if (var1[1] == arg0->unknown_1_4_ && var1[2] == arg0->unknown_2_0_) {
                    data_021098e8.unknown_0_ |= 1;
                }
                if (var1[1] == 1 && var1[2] == 1) {
                    data_021098e8.unknown_0_ |= 2;
                } else if (var1[1] == 0xc && var1[2] == 0x19) {
                    data_021098e8.unknown_0_ |= 8;
#if defined(jpn)
                } else if (arg0->unknown_3_1_ == 1 && var1[1] == 2 && var1[2] == 0xe) {
                    data_021098e8.unknown_0_ |= 4;
                } else if (arg0->unknown_3_1_ == 0 && var1[1] == 3 && var1[2] == 0xe) {
                    data_021098e8.unknown_0_ |= 4;
                }
#else
                } else if (var1[1] == 2 && var1[2] == 0xe) {
                    data_021098e8.unknown_0_ |= 4;
                }
#endif
            }
        }
        if ((arg6 & 1) && arg0->unknown_6_ != 0) {
            data_021098e8.unknown_0_ |= 0x20;
        }
    }

    StoreStruct* store = MessageSystem_GetInstance();
    func_02046380(store);
    unsigned int hi = request->hi;
    StoreInArray0x8b0_020465c0(store, 1, request->mid);
    StoreInArray0x8b0_020465c0(store, 2, hi);
    if (request->top) {
        int age;
        if (request->offset < 0) {
            age = 0;
        } else {
            var5 = func_02098f20(arg0->unknown_0_0_, arg0->unknown_1_4_, arg0->unknown_2_0_);
            if (var5 < 0) {
                var5 = 0;
            }
        }
        func_020465c0(var3, 0, var5);
    }
    MessageSystem_SetStringArgument((Obj02046574*)store, 0, name);
    MessageSystem_SetStringArgument((Obj02046574*)store, 1, nameA);
    MessageSystem_SetStringArgument((Obj02046574*)store, 2, nameB);

    var2.Initialize();
    var2.SetOpcodeLookup(data_020f1504);
    var2.Load(arg2, arg3);
    var2.Execute();
    return 1;
}
