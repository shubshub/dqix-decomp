#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void* a0);
extern "C" int Font_GetTextWidth(int a, int b);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
int StandardStrings_Get(int value);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int Text_AppendPaletteTag(char* dst, int palette);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);
int AppendXTag_02041a28(char* dst, int x);

extern short data_ov002_0216ca04[];
extern int data_ov002_0216ca58[];
extern char data_ov002_0216d26e;

#if defined(jpn)
extern int data_ov002_0216d09c[];
extern const char* data_ov002_0216d600[];
extern char data_ov002_0216d92a;

ARM void BuildStatusString_0215c178(void* a0, char* dst, int flag) {
    if (dst == NULL) return;
    char* sub = (char*)a0 + 0x1a00;
    short cursor = *(short*)(sub + 0xa8);
    void* p = Scenario_GetInstance(sub);
    int hasBit = Scenario_TestFlag((int)(long)p, (unsigned char*)p + 0x8c, 4506) != 0;
    if (flag != 0) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    for (int i = 0; i < 6; i++) {
        if (i == 3 && hasBit == 0) {
            Text_AppendPaletteTag(dst, 3);
        }
        int n = data_ov002_0216d09c[i];
        Text_AppendNTag(dst, n, data_ov002_0216d600[n]);
        if (i == 1 || i == 3) {
            Text_Append(dst, &data_ov002_0216d92a);
        } else {
            AppendXTag_02041a28(dst, 0x3e);
        }
        if (i == 3 && hasBit == 0) {
            Text_AppendPaletteTag(dst, 15);
        }
    }
}
#else
// USA: func_ov002_0215c178
ARM void BuildStatusString_0215c178(void* a0, char* dst, int flag) {
    if (dst == NULL) return;
    char* sub = (char*)a0 + 0x1b00;
    short cursor = *(short*)(sub + 0xe0);
    void* p = Scenario_GetInstance(sub);
    int hasBit = Scenario_TestFlag((int)(long)p, (unsigned char*)p + 0x8c, 4506) != 0;
    int maxVal = 0;
    for (int i = 0; i < 3; i++) {
        int v = Font_GetTextWidth(StandardStrings_Get(data_ov002_0216ca04[i]), 0);
        if (maxVal < v) maxVal = v;
    }
    if (flag != 0) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    for (int i = 0; i < 6; i++) {
        if (i == 3 && hasBit == 0) {
            Text_AppendPaletteTag(dst, 3);
        }
        int n = data_ov002_0216ca58[i];
        int name = StandardStrings_Get(data_ov002_0216ca04[n]);
        Text_AppendNTag(dst, n, (const char*)(long)name);
        if (i == 1 || i == 3) {
            Text_Append(dst, &data_ov002_0216d26e);
        } else {
            AppendXTag_02041a28(dst, maxVal + 0x20);
        }
        if (i == 3 && hasBit == 0) {
            Text_AppendPaletteTag(dst, 15);
        }
    }
}
#endif
