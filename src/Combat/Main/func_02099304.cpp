#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_02099304 {
    unsigned int lo : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int hi : 5;
#if defined(jpn)
    unsigned int rest : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 5;
#else
    unsigned int rest : 10;
#endif
    unsigned int top : 1;
    int offset : 9;
    signed char mode;
};

struct StoreStruct;
struct Obj02046574;

struct Struct_021098e8_2 {
    unsigned char flags;
#if defined(jpn)
    Struct_02099304* request;
    void* buffer;
#else
    void* buffer;
    Struct_02099304* request;
#endif
};

extern Struct_021098e8_2 data_021098e8;
extern Script::OpcodeLookupEntry data_020f1504[];

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* gs);
extern "C" void func_02046380(StoreStruct* store);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void func_020cf0fc(int out);
extern "C" StoreStruct* MessageSystem_GetInstance(void);
extern "C" void func_020465c0(StoreStruct* store, int index, int value);
extern "C" int func_02098f20(int a, int b, int c);
extern "C" void MessageSystem_SetStringArgument(Obj02046574* obj, int index, char* name);

// USA: func_02099304
extern "C" ARM int func_02099304(Struct_02099304* request, char* name, const void* data, unsigned int size, void* buffer, int arg5, unsigned char flags, char* nameA, char* nameB) {
    void* gs = LinkSession_GetInstance();
    int slot[4];
    Script script;

    if (request == 0 || name == 0) {
        return 0;
    }
    if (arg5 < 0x190) {
        return 0;
    }
    memset(buffer, 0, arg5);
    data_021098e8.request = request;
    data_021098e8.buffer = buffer;
    data_021098e8.flags = 0;
    if (flags == 0) {
        data_021098e8.flags |= 0x10;
    } else {
        if (flags & 2) {
            if (LinkSession_IsHostOrSolo(gs)) {
                func_020cf0fc((int)slot);
                if (slot[1] == request->unknown_1_4_ && slot[2] == request->hi) {
                    data_021098e8.flags |= 1;
                }
                if (slot[1] == 1 && slot[2] == 1) {
                    data_021098e8.flags |= 2;
                } else if (slot[1] == 0xc && slot[2] == 0x19) {
                    data_021098e8.flags |= 8;
#if defined(jpn)
                } else if (request->unknown_3_1_ == 1 && slot[1] == 2 && slot[2] == 0xe) {
                    data_021098e8.flags |= 4;
                } else if (request->unknown_3_1_ == 0 && slot[1] == 3 && slot[2] == 0xe) {
                    data_021098e8.flags |= 4;
                }
#else
                } else if (slot[1] == 2 && slot[2] == 0xe) {
                    data_021098e8.flags |= 4;
                }
#endif
            }
        }
        if ((flags & 1) && request->mode != 0) {
            data_021098e8.flags |= 0x20;
        }
    }

    StoreStruct* store = MessageSystem_GetInstance();
    func_02046380(store);
    unsigned int hi = request->hi;
    func_020465c0(store, 1, request->unknown_1_4_);
    func_020465c0(store, 2, hi);
    if (request->top) {
        int age;
        if (request->offset < 0) {
            age = 0;
        } else {
            age = func_02098f20(request->lo, request->unknown_1_4_, request->hi);
            if (age < 0) {
                age = 0;
            }
        }
        func_020465c0(store, 0, age);
    }
    MessageSystem_SetStringArgument((Obj02046574*)store, 0, name);
    MessageSystem_SetStringArgument((Obj02046574*)store, 1, nameA);
    MessageSystem_SetStringArgument((Obj02046574*)store, 2, nameB);

    script.Initialize();
    script.SetOpcodeLookup(data_020f1504);
    script.Load(data, size);
    script.Execute();
    return 1;
}
