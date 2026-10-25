#include <globaldefs.h>
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" unsigned short* func_0206c730(void*, unsigned short, unsigned short*);
void MessageSystem_Reset(char*);
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
    memset(self->firstLineBuffer, 0, 0x140);
    memset(self->secondLineBuffer, 0, 0x140);
    self->tokenCursor = found;
    self->tokenStart = found;
    func_0206aa28(context);
    self->mode = 5;
}
#else

extern "C" void* func_0206ac94(void* obj);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);
extern "C" void func_0206b104(void* obj);
extern "C" void func_0206aa28(void* p);
extern "C" void func_0206b974(void* p, int a1, void* a2, void* a3, int a4, int a5, int a6, int a7);
int STD_GetStringLength(const char* s);

struct Ctx0206b2c8 {
    char pad0[0x4c];
    void* field4c;
    void* field50;
    void* field54;
    void* field58;
    char pad5c[4];
    void* field60;
    char pad64[0x93c];
    int field9a0;
};

// USA: func_0206b2c8
ARM void InitOrReinitContext0206b2c8(Ctx0206b2c8* obj, int, void*) {
    void* r = func_0206ac94(obj);
    if (r == NULL) {
        MessageSystem_Reset((char*)obj);
        MessageSystem_Stop(obj);
        return;
    }

    func_0206b104(obj);
    memset(obj->field4c, 0, 0x280);
    memset(obj->field50, 0, 0x280);
    obj->field58 = r;
    obj->field54 = r;
    obj->field9a0 = 5;
    func_0206aa28(obj);
    func_0206b974(obj, 1, obj->field50, obj->field60, 0xe3, 0, 1, 1);
    int len = STD_GetStringLength((const char*)obj->field60);
    memcpy(obj->field50, obj->field60, len);
}

#endif
