#include <globaldefs.h>
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" unsigned short* func_0206c730(void*, unsigned short, unsigned short*);
extern "C" void MessageSystem_Reset(char*);
extern "C" void MessageSystem_Stop(void*);
extern "C" void func_0206b104(void*);
extern "C" void func_0206aa28(void*);

// JPN: func_0206cbe8
extern "C" ARM void func_0206cbe8(void* context, unsigned short token, unsigned short* cursor) {
    MessageSystem* self = static_cast<MessageSystem*>(context);
    char* obj = static_cast<char*>(context);
    unsigned short* found = func_0206c730(context, token, cursor);
    if (found == NULL) {
        MessageSystem_Reset(obj);
        MessageSystem_Stop(context);
        return;
    }
    func_0206b104(context);
    memset(self->unknown_4c_, 0, 0x140);
    memset(self->unknown_1c_, 0, 0x140);
    self->unknown_24_ = found;
    self->unknown_20_ = found;
    func_0206aa28(context);
    self->mode = 5;
}
#else

extern "C" void* func_0206ac94(void* obj);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);
extern "C" void func_0206b104(void* obj);
extern "C" void func_0206aa28(void* p);
extern "C" void func_0206b974(void* p, int a1, void* a2, void* a3, int a4, int a5, int a6, int a7);
extern "C" int STD_GetStringLength(const char* s);

struct Struct_020678bc {
    char pad0[0x4c];
    void* field4c;
    void* unknown_50_;
    void* field54;
    void* unknown_58_;
    char unknown_5c_[4];
    void* field60;
    char unknown_64_[0x93c];
    int unknown_9a0_;
};

// USA: func_0206b2c8
extern "C" ARM void func_0206b2c8(Struct_020678bc* obj, int, void*) {
    void* r = func_0206ac94(obj);
    if (r == NULL) {
        MessageSystem_Reset((char*)obj);
        MessageSystem_Stop(obj);
        return;
    }

    func_0206b104(obj);
    memset(obj->field4c, 0, 0x280);
    memset(obj->unknown_50_, 0, 0x280);
    obj->unknown_58_ = r;
    obj->field54 = r;
    obj->unknown_9a0_ = 5;
    func_0206aa28(obj);
    func_0206b974(obj, 1, obj->unknown_50_, obj->field60, 0xe3, 0, 1, 1);
    int len = STD_GetStringLength((const char*)obj->field60);
    memcpy(obj->unknown_50_, obj->field60, len);
}

#endif
