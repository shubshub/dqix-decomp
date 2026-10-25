#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_020e0028 {
    short unknown_0_;
    char* unknown_4_;
};

struct Struct_0201099c_3;

struct Struct_020e0028_2 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
    struct Struct_020e0028* unknown_4_;
    char* unknown_8_;
};

typedef int (*Type_020e0028)(struct Struct_020e0028*);

struct Element020e0310* BinarySearch020e0310(struct Container020e0310* c, int key, KeyFunc020e0310 fn);
short GetShortAt0x0020dfbd4(short* obj);
char* AllocateStringCopy020da150(SafeAllocator* allocator, const char* src);
extern "C" int KeyTable_LoadInPlaceWithCallback(struct TextTable020e0028* self, void* src, unsigned char* outFlag, void* callback);
extern "C" char* func_020dfbfc(struct TextTable020e0028* c, char* idx, int dflt);

static inline void inline_020e0028_2(struct Struct_020e0028* arg0, struct Struct_020e0028* arg1) {
    arg0->unknown_0_ = arg1->unknown_0_;
    arg0->unknown_4_ = arg1->unknown_4_;
}

static inline void inline_020e0028(struct Struct_020e0028* arg0, struct Struct_020e0028* arg1) {
    struct Struct_020e0028 var0 = *arg0;
    inline_020e0028_2(arg0, arg1);
    inline_020e0028_2(arg1, &var0);
}

// USA: func_020e0028
extern "C" ARM int func_020e0028(struct Struct_020e0028_2* arg0, SafeAllocator* arg1, void* arg2, unsigned int arg3, short* arg4, unsigned short arg5) {
    unsigned char var0;
    struct Struct_020e0028_2 var1;
    short* var2;
    int var3;
    struct Struct_020e0028* var4;
    int var5;
    int var6;

    if (allocator == NULL || file == NULL || size == 0 || ids == NULL || count == 0) return 0;
    memset(self, 0, sizeof(*self));
    memset(&src, 0, sizeof(src));
    KeyTable_LoadInPlaceWithCallback(&src, file, &flag, NULL);

    var3 = 0;
    var2 = arg4;
    var6 = arg5;
    for (var5 = 0; var5 < var6; var5++, var2++) {
        if (func_020e0310((struct Struct_0201099c_3*)&var1, *var2, (Type_020e0028)func_020dfbd4) != NULL) var3++;
    }

    arg0->unknown_4_ = (struct Struct_020e0028*)arg1->Allocate(var3 * sizeof(struct Struct_020e0028));
    if (arg0->unknown_4_ != NULL) {
        arg0->unknown_0_0_ = var3;
        var2 = arg4;
        var4 = arg0->unknown_4_;
        for (var5 = 0; var5 < var6; var5++, var2++) {
            struct Struct_020e0028* var7 = func_020e0310((struct Struct_0201099c_3*)&var1, *var2, (Type_020e0028)func_020dfbd4);
            if (var7 != NULL) {
                char* var8 = func_020dfbfc(&var1, var7->unknown_4_, 0);
                var4->unknown_0_ = var7->unknown_0_;
                var4->unknown_4_ = func_020da150(arg1, var8);
                var4++;
            }
        }
    }

    if (var3 >= 2 && arg0 != NULL) {
        int var9 = arg0->unknown_0_0_;
        if (arg0->unknown_4_ != NULL && var9 != 0) {
            struct Struct_020e0028* var10;
            struct Struct_020e0028* var11;
            int var12;
            int var13;
            struct Struct_020e0028* var14;
            int var15;
            int var16;
            int var17;
            var17 = 0;
            var16 = var9 - 1;
            for (;;) {
                var15 = -1;
                var14 = arg0->unknown_4_ + var17;
                for (var13 = var17; var13 < var16; var13++) {
                    if (var14->unknown_0_ > var14[1].unknown_0_) {
                        var10 = var14 + 1;
                        var15 = var13;
                        inline_020e0028(var14, var10);
                    }
                    var14++;
                }
                if (var15 == -1) break;
                var16 = var15;
                var12 = -1;
                var11 = arg0->unknown_4_ + var16;
                for (; var15 > var17; var15--) {
                    var10 = var11 - 1;
                    if (var10->unknown_0_ > var11->unknown_0_) {
                        var12 = var15;
                        struct Struct_020e0028 var18 = *var11;
                        inline_020e0028_2(var11, var10);
                        inline_020e0028_2(var10, &var18);
                    }
                    var11 = var10;
                }
                if (var12 == -1) break;
                var17 = var12;
            }
        }
    }
    return 1;
}
