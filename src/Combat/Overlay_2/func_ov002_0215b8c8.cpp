#include <globaldefs.h>

extern "C" int Font_GetTextWidth(const char* str, int flags);
extern "C" int func_02041a28(char* dst, int x);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int func_02041acc(char* dst, int w);

struct Struct_ov002_0215b8c8 { char* dst; };

// USA: func_ov002_0215b8c8
extern "C" ARM void func_ov002_0215b8c8(struct Struct_ov002_0215b8c8* holder, const char* str, int value) {
    int width = Font_GetTextWidth(str, value & 0xff);
    int halfWidth = (((width + 0x17) & ~7) - width) >> 1;
    func_02041a28(holder->dst, halfWidth);
    Text_Append(holder->dst, str);
    func_02041acc(holder->dst, halfWidth - 5);
}
