#include <globaldefs.h>

extern "C" int Font_GetTextWidth(const char* str, int flags);
int AppendXTag_02041a28(char* dst, int x);
int Text_Append(char* dst, const char* src);
int AppendWidthTag_02041acc(char* dst, int w);

struct DstHolder0215b8c8 { char* dst; };

// USA: func_ov002_0215b8c8
ARM void AppendTaggedString_0215b8c8(struct DstHolder0215b8c8* holder, const char* str, int value) {
    int width = Font_GetTextWidth(str, value & 0xff);
    int halfWidth = (((width + 0x17) & ~7) - width) >> 1;
    AppendXTag_02041a28(holder->dst, halfWidth);
    Text_Append(holder->dst, str);
    AppendWidthTag_02041acc(holder->dst, halfWidth - 5);
}
