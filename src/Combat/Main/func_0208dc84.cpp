#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
extern "C" int STD_GetStringLength(char const*);
extern "C" char* strcpy(char* dst, const char* src);

struct Struct_0208dc84;
struct Struct_0208dc84_2;
extern "C" void func_0208df94(struct Struct_0208dc84* list, SafeAllocator* alloc, struct Struct_0208dc84_2* src);

struct Struct_02108fd4 {
    unsigned short* field0;
    unsigned short* field4;
    void* field8;
    void* fieldC;
};
extern struct Struct_02108fd4 data_02108fd4;

struct Struct_0208dc84_3 {
    unsigned short b0 : 2;
    unsigned short b2 : 7;
#if defined(jpn)
    unsigned short unknown_1_1_ : 7;
#else
    unsigned short unknown_1_1_ : 6;
    unsigned short unknown_1_7_ : 1;
#endif
};

struct Struct_0208dc84_4 {
    short field0;
    struct Struct_0208dc84_3 field2;
    int field4;
    int field8;
#if defined(jpn)
    int fieldC;
#endif
};

// USA: func_0208dc84
extern "C" ARM int func_0208dc84(char* p
#if defined(jpn)
    , int arg1
#endif
) {
    struct Struct_0208dc84_4 c;
#if defined(jpn)
    char* extra;
#endif
    char* s;
    void* dst;

    c.field0 = -1;
    c.field2.b0 = 0;
    c.field2.b2 = 0;
    c.field2.unknown_1_1_ = 0;
#if !defined(jpn)
    c.field2.unknown_1_7_ = 0;
#endif
    c.field4 = 0;
    c.field8 = 0;
#if defined(jpn)
    c.fieldC = 0;
#endif

    if (data_02108fd4.field4 != 0) {
        unsigned short i;
        c.field0 = (short)((Script::Parameter*)((struct Variant02030b0c*)p))->ToInt();
        s = (char*)(void*)((Script::Parameter*)((struct Variant02030b0c*)(p + 8)))->ToString();
        c.field2.b0 = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x10)))->ToInt();
        c.field2.unknown_1_1_ = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x18)))->ToInt();
        c.field2.b2 = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x20)))->ToInt();
#if defined(jpn)
        extra = 0;
        if (arg1 - 5) {
            extra = (char*)(void*)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x28)))->ToString();
        }
#else
        c.field2.unknown_1_7_ = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x28)))->ToInt();
#endif
        for (i = 0; i < *data_02108fd4.field0; i++) {
            if (data_02108fd4.field4[i] == c.field2.unknown_1_1_) {
                if (s != 0) {
                    dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(STD_GetStringLength(s) + 1));
                    c.field4 = (int)dst;
                    if (dst != 0) {
                        strcpy((char*)dst, s);
                    }
                }
#if defined(jpn)
                if (extra != 0) {
                    dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(STD_GetStringLength(extra) + 1));
                    c.field8 = (int)dst;
                    if (dst != 0) {
                        strcpy((char*)dst, extra);
                    }
                }
#endif
                func_0208df94((struct Struct_0208dc84*)data_02108fd4.field8,
                                                (SafeAllocator*)data_02108fd4.fieldC,
                                                (struct Struct_0208dc84_2*)&c);
                break;
            }
        }
    } else {
        c.field0 = (short)((Script::Parameter*)((struct Variant02030b0c*)p))->ToInt();
        s = (char*)(void*)((Script::Parameter*)((struct Variant02030b0c*)(p + 8)))->ToString();
        if (s != 0) {
            dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(STD_GetStringLength(s) + 1));
            c.field4 = (int)dst;
            if (dst != 0) {
                strcpy((char*)dst, s);
            }
        }
        c.field2.b0 = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x10)))->ToInt();
        c.field2.unknown_1_1_ = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x18)))->ToInt();
        c.field2.b2 = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x20)))->ToInt();
#if defined(jpn)
        extra = 0;
        if (arg1 - 5) {
            extra = (char*)(void*)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x28)))->ToString();
        }
#else
        c.field2.unknown_1_7_ = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)(p + 0x28)))->ToInt();
#endif
#if defined(jpn)
        if (extra != 0) {
            dst = ((SafeAllocator*)data_02108fd4.fieldC)->Allocate((unsigned int)(STD_GetStringLength(extra) + 1));
            c.field8 = (int)dst;
            if (dst != 0) {
                strcpy((char*)dst, extra);
            }
        }
#endif
        func_0208df94((struct Struct_0208dc84*)data_02108fd4.field8,
                                        (SafeAllocator*)data_02108fd4.fieldC,
                                        (struct Struct_0208dc84_2*)&c);
    }
    return 1;
}
