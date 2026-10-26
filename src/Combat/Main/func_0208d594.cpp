#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/ScriptElementList.h"

struct Struct_0208d51c;
extern "C" void func_0208d51c(struct Struct_0208d51c* p);

struct Struct_0208d594 {
    short id;
    char* unknown_4_;
    char* unknown_8_;
    char** texts;
    char* unknown_10_;
    char* unknown_14_;
};

struct Struct_0208d594_2;
extern "C" void func_0208d928(struct Struct_0208d594_2* l, struct Struct_0208d594* e);

extern const char data_020f1244[];

extern "C" int STD_GetStringLength(const char* s);

// USA: func_0208d594
extern "C" ARM int func_0208d594(Script::Parameter* p) {
    struct Struct_0208d594 elem;
    unsigned short flags = data_02108fc0.header->flags;
    unsigned int mask;
    unsigned char i;
    unsigned char j;
    int found;
    const char* s;
    unsigned int len;
    Script::Parameter* q;
    char* buf;

    func_0208d51c((struct Struct_0208d51c*)&elem);
    elem.id = (short)p->ToInt();
    if (data_02108fc0.header->unknown_c_ != 0) {
        const short* cur = data_02108fc0.header->unknown_8_;
        short count = data_02108fc0.header->unknown_c_;
        found = 0;
        for (short k = 0; k < count; k++) {
            if (elem.id == *cur) {
                found = 1;
            }
            cur++;
        }
        if (!found) {
            return 1;
        }
    }

    s = (p + 1)->ToString();
    if (flags & 1) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.unknown_4_ = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.unknown_4_[len] = 0;
            sprintf(elem.unknown_4_, data_020f1244, s);
        }
    }

    q = p + 2;
    p += 3;
    s = q->ToString();
    if (flags & 2) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.unknown_8_ = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.unknown_8_[len] = 0;
            sprintf(elem.unknown_8_, data_020f1244, s);
        }
    }

    if (flags & 0x3fc) {
        elem.texts = (char**)data_02108fc0.allocator->Allocate(0x20);
        for (j = 0; j < 8; j++) {
            elem.texts[j] = 0;
        }
    }

    mask = 4;
    for (i = 0; i < 8; i++) {
        s = p->ToString();
        p++;
        if (flags & mask) {
            len = STD_GetStringLength(s);
            if (len != 0) {
                elem.texts[i] = (char*)data_02108fc0.allocator->Allocate(len + 1);
                buf = elem.texts[i];
                buf[len] = 0;
                sprintf(buf, data_020f1244, s);
            }
        }
        mask <<= 1;
    }

    s = p->ToString();
    if (flags & 0x400) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.unknown_10_ = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.unknown_10_[len] = 0;
            sprintf(elem.unknown_10_, data_020f1244, s);
        }
    }

    s = (p + 1)->ToString();
    if (flags & 0x800) {
        len = STD_GetStringLength(s);
        if (len != 0) {
            elem.unknown_14_ = (char*)data_02108fc0.allocator->Allocate(len + 1);
            elem.unknown_14_[len] = 0;
            sprintf(elem.unknown_14_, data_020f1244, s);
        }
    }

    func_0208d928((struct Struct_0208d594_2*)data_02108fc0.header, &elem);
    return 1;
}
