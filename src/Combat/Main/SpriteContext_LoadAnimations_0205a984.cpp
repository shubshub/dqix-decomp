#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct Struct_0205a984_5 {
    unsigned short* unknown_0_;
    unsigned short frames;
    unsigned short pad;
};
struct Struct_0205a984 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    int unknown_4_;
    int unknown_8_;
    Struct_0205a984_5* frames;
};
struct Struct_0205a984_2 {
    unsigned short count;
    unsigned short pad;
    Struct_0205a984* entries;
};
struct Struct_0205a984_3 {
    unsigned short frames;
    unsigned short index;
};
struct Struct_0205a984_4 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short index;
    unsigned short unknown_a_;
    Struct_0205a984_3* frames;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char unknown_14_;
    unsigned char unknown_15_;
};
struct Struct_0205a984_6 {
    Struct_0205a984_4* unknown_0_;
    unsigned short count;
};
struct AnimScript0205a984 {
    char unknown_0_[0x3c];
    Struct_0205a984_6* bank;
};

extern "C" int func_020aff00(void*, void**);
extern "C" Struct_0205a984* func_020b005c(Struct_0205a984_2*, unsigned int);

// Main, originally func_0205a984 (USA 0x0205a984, EUR 0x0205a994, JPN 0x0205bd20)
extern "C" ARM int SpriteContext_LoadAnimations(AnimScript0205a984* self, void* data, unsigned int length, SafeAllocator* allocator) {
    void* buffer = data;
    Struct_0205a984_2* header;
    if (!buffer) buffer = 0;
    else if (!length) buffer = 0;
    else if (!func_020aff00(buffer, (void**)&header)) buffer = 0;
    if (!buffer) return 1;
    Struct_0205a984_4* var2;
    Struct_0205a984* var3;
    unsigned short i;
    unsigned short count;
    Struct_0205a984_4* var6;
    Struct_0205a984_6* bank = self->bank;
    if (bank && allocator) {
        count = header->count;
        var6 = (Struct_0205a984_4*)allocator->Allocate(count * sizeof(Struct_0205a984_4));
        bank->unknown_0_ = var6;
        bank->count = count;
        for (i = 0; i < count; ++i) {
            var3 = func_020b005c(header, i);
            if (var3) {
                var2 = &var6[i];
                var2->unknown_0_ = 0;
                var2->unknown_6_ = 0;
                var2->unknown_4_ = 0;
                var2->index = 0;
                var2->unknown_a_ = 0;
                var2->frames = 0;
                var2->unknown_10_ = 0;
                var2->unknown_12_ = 0;
                var2->unknown_14_ = 0xff;
                var2->unknown_15_ = 1;
                var2->unknown_0_ = var3->unknown_8_;
                var2->unknown_a_ = var3->unknown_0_;
                var2->index = i;
                Struct_0205a984_3* frames = (Struct_0205a984_3*)allocator->Allocate(var2->unknown_a_ * sizeof(Struct_0205a984_3));
                var2->frames = frames;
                for (unsigned short j = 0; j < var2->unknown_a_; ++j) {
                    Struct_0205a984_5* frame = &var3->frames[j];
                    if (frame) {
                        Struct_0205a984_3* info = &frames[j];
                        info->frames = 0;
                        info->index = 0;
                        info->frames = frame->frames;
                        info->index = *frame->unknown_0_;
                    }
                }
            }
        }
    }
    return 0;
}
