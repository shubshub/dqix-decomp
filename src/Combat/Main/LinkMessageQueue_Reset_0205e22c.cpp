#include <globaldefs.h>
#include "Combat/SearchEntry.h"

extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);

struct Struct0205e16c;
ARM void LinkMessageList_Clear(struct Struct0205e16c* p);

struct Struct_0205e18c_2 {
    char unknown_0_[0x18];
    struct Struct_0205e18c_2* unknown_18_;
};
struct Struct_0205e18c {
    struct Struct_0205e18c_2* unknown_0_;
    struct Struct_0205e18c_2* unknown_4_;
    int unknown_8_;
};
extern "C" void func_0205e18c(struct Struct_0205e18c* arg0, struct Struct_0205e18c_2* arg1);

extern "C" void* LinkSession_GetInstance(void);
extern "C" void LinkSession_UpdateMemberCount(void);
void* LinkSession_GetOwnRecord(void* base);

struct Struct_0202b2f0;

struct Struct_0205e22c {
    unsigned char unknown_0_[0x10];
    unsigned char unknown_10_;
    unsigned char unknown_11_[0x14 - 0x11];
};

// Main, originally func_0205e22c (USA 0x0205e22c, EUR 0x0205e23c, JPN 0x0205f518)
extern "C" ARM void LinkMessageQueue_Reset(void* obj) {
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)obj + 0x1500));
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)obj + 0x150c));
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)obj + 0x1518));

    memset(arg0, 0, 0x1500);

    struct Struct_0205e18c_2* var0 = (struct Struct_0205e18c_2*)arg0;
    for (int var1 = 0; var1 < 0xc0; var1++) {
        func_0205e18c((struct Struct_0205e18c*)((char*)arg0 + 0x1500), &var0[var1]);
    }

    void* base = LinkSession_GetInstance();
    LinkSession_UpdateMemberCount();

    struct Elem0205e22c* arr = (struct Elem0205e22c*)LinkSession_GetOwnRecord(base);
    memset(arr, 0, 0x74);

    for (int var4 = 0; var4 < 5; var4++) {
        var3[var4].unknown_10_ = 0xff;
    }

    int idx = 0;
    int off = 0;
    int size = 0x74;
    for (; idx < 4; idx++) {
        void* entry = LinkSession_GetReceivedRecord((struct SearchStruct*)base, idx);
        if (entry != NULL) {
            memset(entry, off, size);
        }
    }

    memset((char*)arg0 + 0x1524, 0xff, 0x20);
}
