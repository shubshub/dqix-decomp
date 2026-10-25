#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
int STD_GetStringLength(char const*);
extern "C" char* strcpy(char* dst, const char* src);

struct Struct_0208dc84;
struct Struct_0208dc84_2;
extern "C" void func_0208df94(struct Struct_0208dc84* arg0, SafeAllocator* arg1, struct Struct_0208dc84_2* arg2);

struct Struct_02108fd4 {
    unsigned short* unknown_0_;
    unsigned short* unknown_4_;
    void* unknown_8_;
    void* unknown_c_;
};
extern struct Struct_02108fd4 data_02108fd4;

struct Struct_0208dc84_3 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 7;
#if defined(jpn)
    unsigned short unknown_1_1_ : 7;
#else
    unsigned short unknown_1_1_ : 6;
    unsigned short unknown_1_7_ : 1;
#endif
};

struct Struct_0208dc84_4 {
    short unknown_0_;
    struct Struct_0208dc84_3 unknown_2_;
    int unknown_4_;
    int unknown_8_;
#if defined(jpn)
    int unknown_c_;
#endif
};

// USA: func_0208dc84
extern "C" ARM int func_0208dc84(char* arg0
#if defined(jpn)
    , int arg1
#endif
) {
    struct Struct_0208dc84_4 var0;
#if defined(jpn)
    char* var1;
#endif
    char* var2;
    void* var3;

    var0.unknown_0_ = -1;
    var0.unknown_2_.unknown_0_0_ = 0;
    var0.unknown_2_.unknown_0_2_ = 0;
    var0.unknown_2_.unknown_1_1_ = 0;
#if !defined(jpn)
    var0.unknown_2_.unknown_1_7_ = 0;
#endif
    var0.unknown_4_ = 0;
    var0.unknown_8_ = 0;
#if defined(jpn)
    var0.unknown_c_ = 0;
#endif

    if (data_02108fd4.unknown_4_ != 0) {
        unsigned short var4;
        var0.unknown_0_ = (short)((Script::Parameter*)((struct Struct_0201c1c8*)arg0))->ToInt();
        var2 = (char*)(void*)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 8)))->ToString();
        var0.unknown_2_.unknown_0_0_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x10)))->ToInt();
        var0.unknown_2_.unknown_1_1_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x18)))->ToInt();
        var0.unknown_2_.unknown_0_2_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x20)))->ToInt();
#if defined(jpn)
        var1 = 0;
        if (arg1 - 5) {
            var1 = (char*)(void*)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x28)))->ToString();
        }
#else
        var0.unknown_2_.unknown_1_7_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x28)))->ToInt();
#endif
        for (i = 0; i < *data_02108fd4.field0; i++) {
            if (data_02108fd4.field4[i] == c.field2.b9) {
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
                func_0208df94((struct Struct_0208dc84*)data_02108fd4.unknown_8_,
                                                (SafeAllocator*)data_02108fd4.unknown_c_,
                                                (struct Struct_0208dc84_2*)&var0);
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
        var0.unknown_2_.unknown_0_0_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x10)))->ToInt();
        var0.unknown_2_.unknown_1_1_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x18)))->ToInt();
        var0.unknown_2_.unknown_0_2_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x20)))->ToInt();
#if defined(jpn)
        var1 = 0;
        if (arg1 - 5) {
            var1 = (char*)(void*)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x28)))->ToString();
        }
#else
        var0.unknown_2_.unknown_1_7_ = (unsigned short)((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x28)))->ToInt();
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
        func_0208df94((struct Struct_0208dc84*)data_02108fd4.unknown_8_,
                                        (SafeAllocator*)data_02108fd4.unknown_c_,
                                        (struct Struct_0208dc84_2*)&var0);
    }
    return 1;
}
