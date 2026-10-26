#include <globaldefs.h>
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int STD_GetStringLength(const char*);
extern "C" void func_0206aa28(void*);

// JPN: func_0206c570
extern "C" ARM void func_0206c570(void* context, const char* src) {
    MessageSystem* p = static_cast<MessageSystem*>(context);
    if (src == NULL) return;
    {
        void* buffer = p->textBuffer;
        memcpy(buffer, src, (p->tokenLength = STD_GetStringLength(src)));
    }
    {
        unsigned short* buffer = static_cast<unsigned short*>(p->textBuffer);
        p->unknown_24_ = buffer;
        p->unknown_20_ = buffer;
    }
    memset(p->unknown_4c_, 0, 0x140);
    memset(p->unknown_1c_, 0, 0x140);
    func_0206aa28(context);
}
#else

extern "C" int STD_GetStringLength(const char* s);

extern "C" void func_0206aa28(void* p);
extern "C" void func_0206b974(void* p, int a1, void* a2, void* a3, int a4, int a5, int a6, int a7);

struct Struct_0204500c_3 {
    char pad0[0x48];
    void* field48;
    void* field4c;
    void* unknown_50_;
    void* field54;
    void* unknown_58_;
    char unknown_5c_[4];
    void* field60;
    char unknown_64_[4];
    int field68;
};

// USA: func_0206a974
extern "C" ARM void func_0206a974(struct Struct_0204500c_3* p, const char* src, int arg2) {
    if (src == 0) return;
    {
        void* buf = p->field48;
        memcpy(buf, (void*)src, (p->field68 = STD_GetStringLength(src)));
    }
    {
        void* buf2 = p->field48;
        p->unknown_58_ = buf2;
        p->field54 = buf2;
    }
    memset(p->field4c, 0, 0x280);
    memset(p->unknown_50_, 0, 0x280);
    func_0206aa28(p);
    func_0206b974(p, 1, p->unknown_50_, p->field60, arg2, 0, 1, 1);
    {
        int len2 = STD_GetStringLength((const char*)p->field60);
        memcpy(p->unknown_50_, p->field60, len2);
    }
}

#endif
