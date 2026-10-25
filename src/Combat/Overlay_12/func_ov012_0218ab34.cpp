#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_ov003_0215f4e4_2 {
    short unknown_0_;
    short unknown_2_;
    const char* unknown_4_;
    const char* unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    char unknown_10_[4];
};

struct Struct_ov012_0218ab34 {
    Struct_ov003_0215f4e4_2* unknown_0_;
    short unknown_4_;
    short unknown_6_;
};

struct Struct_ov003_0215f4e4 {
    Struct_ov003_0215f4e4_2* unknown_0_;
    Struct_ov012_0218ab34* unknown_4_;
    char* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    short unknown_1c_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unknown_20_;
};

struct Struct_ov012_0218ab34_2 {
    char unknown_0_[8];
    void* unknown_8_;
    char unknown_c_[0xa0 - 0xc];
    int unknown_a0_;
    char unknown_a4_[0xac - 0xa4];
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_0205d81c;
struct Struct_02072a68_2;

struct Struct_ov012_0218ab34_3 {
    Struct_ov003_0215f4e4* unknown_0_;
    Struct_ov012_0218ab34* unknown_4_;
    char unknown_8_[0xac - 0x8];
    char unknown_ac_[0x133c - 0xac];
    char unknown_133c_[4];
};

KeyboardCanvas* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
const char* FindEntryByKey_02072a68(struct TableA68* table, int key);
extern "C" int Font_GetTextWidth(const char* text, int large);
void SetField0xa0AndByte0xc4IfFlag0x1Clear_0204f160(unsigned char* obj, int value, int key);
extern "C" void func_0204ecb4(KeyboardCanvas* wnd, int a, int b, int w, int h, signed char* margins);
extern "C" void func_0204f41c(KeyboardCanvas* ctx, short x, short y, const char* str, int size,
                              unsigned char palette, short* outA, short* outB, int flag);
extern "C" void func_0204f3bc(KeyboardCanvas* ctx, int value);
extern "C" void Keyboard_GetKeySize(int size, short* width, short* height);
extern "C" void func_0204f914(KeyboardCanvas* obj, int mode, short x0, short y0, short x1, short y1);
struct Obj0204fbf8;
void InvokeHandlerAfterCacheFlush0204fbf8(struct Obj0204fbf8* obj);

// USA: func_ov012_0218ab34
extern "C" ARM void func_ov012_0218ab34(Struct_ov012_0218ab34_3* arg0, int arg1)
{
    if (arg1 != 0)
        return;

    Struct_ov012_0218ab34_2* var0 = func_0205d81c((struct Struct_0205d81c*)arg0->unknown_ac_, 0xe);
    if (var0 == NULL)
        return;

    short originX = canvas->originX_ * 8;
    short originY = canvas->originY_ * 8;
    const char* title = FindEntryByKey_02072a68((struct TableA68*)self->texts_, 0xe);
    int titleX = (0xf0 - Font_GetTextWidth(title, 1)) >> 1;

    Struct_ov003_0215f4e4* var5 = arg0->unknown_0_;
    Struct_ov012_0218ab34* var6 = arg0->unknown_4_;
    unsigned char var7;
    unsigned char var8;
    int var9;
    Struct_ov003_0215f4e4_2* var10;
    int var11;
    int var12;
    var12 = var5->unknown_1f_;
    var7 = var5->unknown_1e_;
    var8 = var5->unknown_20_;
    var9 = var6->unknown_6_;
    var10 = var6->unknown_0_;

    short var13;
    short var14;
    short var15;
    short var16;

    if (var0->unknown_8_ != NULL)
        memset(var0->unknown_8_, 0, 0x7800);
    func_0204f160((unsigned char*)var0, var0->unknown_a0_, 0xe);
    func_0204ecb4(var0, 0, 0, 0x1e, 0x12, 0);
    func_0204f41c(var0, var4, 6, var3, 0xc, 0xf, &var13, &var14, var12);
    func_0204f3bc(var0, 0x18);

    for (var11 = 0; var11 < var9; var11++, var10++) {
        if ((var10->unknown_c_ & var7) == 0)
            continue;

        const char* var17 = var10->unknown_4_;
        const char* var18 = var17;
        if (var8 != 0 || (var7 & 2) != 0)
            var18 = var10->unknown_8_;
        if (var10->unknown_d_ != 0)
            var18 = var17;

        int textWidth = Font_GetTextWidth(text, 1);
        Keyboard_GetKeySize(key->size_, &width, &height);
        short x = key->x_ - originX;
        short y = key->y_ - originY;
        func_0204f914(canvas, 4, x + 1, y + 1, width + x - 1, height + y - 1);
        width = (width - textWidth) >> 1;
        func_0204f41c(canvas, width + x, y + 2, text, 0xc, 0xf, &outA, &outB, palette);
    }

    func_0204fbf8((struct Struct_0204fbf8_2*)var0);
}
