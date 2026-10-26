#include <globaldefs.h>
#if defined(jpn)
extern "C" int STD_GetStringLength(const char*);
#endif

struct Container02080f8c;
struct Struct_02080fa8;
struct Struct_02080cc0;

extern "C" int StandardStrings_Get(int value);
extern "C" void func_02080f8c(struct Container02080f8c* obj, int id, int value);
extern "C" void func_02080798(void* obj, int id, int value);
extern "C" void func_0208103c(void* obj, int id, int value);
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
extern "C" char* func_02081010(void* obj, int id);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" void func_02080828(void* obj, int id, short* x, short* y);
extern "C" void func_02080854(void* obj, int id, int x, int y);
extern "C" int func_02080b2c(void* obj, int id);
extern "C" int func_02080b40(void* obj, int id);
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);

struct Struct_ov003_02167e28 {
    char pad[0x10];
    void* layout;
};

// USA: func_ov003_02167e28
extern "C" ARM void func_ov003_02167e28(struct Struct_ov003_02167e28* self, char* name, int flag, unsigned char index,
                                        unsigned char arg4, int arg5, int arg6) {
    void* obj = self->layout;
#if !defined(jpn)
    func_02080f8c((struct Container02080f8c*)obj, 3, StandardStrings_Get(0x3f3));
    func_02080798(obj, 3, 1);
#endif
    func_02080f8c((struct Container02080f8c*)obj, 0, (int)name);
#if !defined(jpn)
    func_02080798(obj, 0, 1);
#endif
    func_0208103c(obj, 1, (short)flag);
    func_02080fa8((struct Struct_02080fa8*)obj, 5, arg5);
    func_02080fa8((struct Struct_02080fa8*)obj, 6, arg6);
    func_0208103c(obj, 2, (short)(index + 2));
#if defined(jpn)
    int width = (STD_GetStringLength(func_02081010(obj, 2)) >> 1) * 10;
#else
    int width = Font_GetTextWidth(func_02081010(obj, 2), 0);
#endif
    short x;
    short y;
    func_02080828(obj, 2, &x, &y);
    x = 0x40;
    x -= width >> 1;
    func_02080854(obj, 2, x, y);
    func_02080b2c(obj, 0x2c);
    if (arg4 == 0) {
        return;
    }
    func_02080b40(obj, 0x2c);
#if defined(jpn)
    func_02080854(obj, 0x2c, (short)(x + width + 1), (short)(y + 2));
#else
    func_02080854(obj, 0x2c, (short)(x + width + 1), y);
#endif
    func_0208103c(obj, 0x2c, (short)(arg4 + 0x1c));
    int nibble = 5;
    if (arg4 == 10) {
        nibble = 0xd;
    }
    func_02080cc0((struct Struct_02080cc0*)obj, 0x2c, nibble);
}
