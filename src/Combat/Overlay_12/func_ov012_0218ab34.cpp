#include <globaldefs.h>
#include <std_library_functions.h>

struct KeyboardKey {
    short x_;
    short y_;
    const char* text_;
    const char* shiftedText_;
    unsigned char flags_;
    unsigned char unk_d;
    unsigned char size_;
    unsigned char unknown_f_;
    char unk_10[4];
};

struct KeyboardLayout {
    KeyboardKey* unknown_0_;
    short unk_4;
    short count_;
};

struct Keyboard {
    KeyboardKey* key_;
    KeyboardLayout* layout_;
    char* text_;
    int unk_c;
    int size_;
    int unk_14;
    int unknown_18_;
    short unk_1c;
    unsigned char unknown_1e_;
    unsigned char palette_;
    unsigned char unknown_20_;
};

struct Struct_ov012_0218ab34_2 {
    char unk_0[8];
    void* pixels_;
    char unk_c[0xa0 - 0xc];
    int unknown_a0_;
    char unknown_a4_[0xac - 0xa4];
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_0205d81c;
struct TableA68;

struct Struct_ov012_0218ab34_3 {
    Keyboard* keyboard_;
    KeyboardLayout* layout_;
    char unk_8[0xac - 0x8];
    char unknown_ac_[0x133c - 0xac];
    char texts_[4];
};

extern "C" Struct_ov012_0218ab34_2* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" const char* func_02072a68(struct TableA68* table, int key);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" void func_0204f160(unsigned char* obj, int value, int key);
extern "C" void func_0204ecb4(Struct_ov012_0218ab34_2* wnd, int a, int b, int w, int h, signed char* arg5);
extern "C" void func_0204f41c(Struct_ov012_0218ab34_2* ctx, short x, short y, const char* str, int size,
                              unsigned char palette, short* outA, short* outB, int flag);
extern "C" void func_0204f3bc(Struct_ov012_0218ab34_2* ctx, int value);
extern "C" void Keyboard_GetKeySize(int size, short* width, short* height);
extern "C" void func_0204f914(Struct_ov012_0218ab34_2* obj, int mode, short arg2, short arg3, short x1, short arg5);
struct Struct_0204fbf8_2;
extern "C" void func_0204fbf8(struct Struct_0204fbf8_2* obj);

// USA: func_ov012_0218ab34
extern "C" ARM void func_ov012_0218ab34(Struct_ov012_0218ab34_3* self, int arg1)
{
    if (arg1 != 0)
        return;

    Struct_ov012_0218ab34_2* canvas = func_0205d81c((struct Struct_0205d81c*)self->unknown_ac_, 0xe);
    if (canvas == NULL)
        return;

    short originX = canvas->unknown_ac_ * 8;
    short originY = canvas->unknown_ae_ * 8;
    const char* title = func_02072a68((struct TableA68*)self->texts_, 0xe);
    int titleX = (0xf0 - Font_GetTextWidth(title, 1)) >> 1;

    Keyboard* keyboard = self->keyboard_;
    KeyboardLayout* layout = self->layout_;
    unsigned char mask;
    unsigned char var8;
    int count;
    KeyboardKey* key;
    int i;
    int palette;
    palette = keyboard->palette_;
    mask = keyboard->unknown_1e_;
    var8 = keyboard->unknown_20_;
    count = layout->count_;
    key = layout->unknown_0_;

    short outA;
    short outB;
    short width;
    short height;

    if (canvas->pixels_ != NULL)
        memset(canvas->pixels_, 0, 0x7800);
    func_0204f160((unsigned char*)canvas, canvas->unknown_a0_, 0xe);
    func_0204ecb4(canvas, 0, 0, 0x1e, 0x12, 0);
    func_0204f41c(canvas, titleX, 6, title, 0xc, 0xf, &outA, &outB, palette);
    func_0204f3bc(canvas, 0x18);

    for (i = 0; i < count; i++, key++) {
        if ((key->flags_ & mask) == 0)
            continue;

        const char* normal = key->text_;
        const char* text = normal;
        if (var8 != 0 || (mask & 2) != 0)
            text = key->shiftedText_;
        if (key->unk_d != 0)
            text = normal;

        int textWidth = Font_GetTextWidth(text, 1);
        Keyboard_GetKeySize(key->size_, &width, &height);
        short x = key->x_ - originX;
        short y = key->y_ - originY;
        func_0204f914(canvas, 4, x + 1, y + 1, width + x - 1, height + y - 1);
        width = (width - textWidth) >> 1;
        func_0204f41c(canvas, width + x, y + 2, text, 0xc, 0xf, &outA, &outB, palette);
    }

    func_0204fbf8((struct Struct_0204fbf8_2*)canvas);
}
