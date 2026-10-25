#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char* arg0, int arg1, int arg2);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

extern "C" void func_020dc4d0(signed char* arg0, signed char* arg1);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* arg0);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int AppendFormatted02041fac(char* buf, int a, int b);
int Text_AppendPaletteTag(char* dst, int palette);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);
int StandardStrings_Get(int value);
extern "C" int func_ov002_02159774(void* base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215e250
extern "C" ARM void func_ov002_0215e250(unsigned char* arg0, char* arg1, int arg2) {
    if (arg1 == NULL) return;

    GameState* var0 = GameState::GetInstance();
    int var1 = *(short*)(arg0 + RG(0x1bf6, 0x1abe));

    signed char var2[7];
    signed char var3;
    func_020dc4d0(var2, &var3);

    signed char var4 = 0;
    for (int var5 = 0; var5 < var3; var5++) {
        GameObject* var6 = func_0200ff1c(var0, var2[var5]);
        if (var6 != NULL) {
            if (func_02061bd8((struct Struct_0205faf4_11*)var6) != 0) {
                var4++;
            }
        }
    }
    var3 = var3 - var4;

    int idx = 0;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    int field = KeyTable_Get((struct Container020e0310*)(base + RG(0x20, 0x8)), 2);
    AppendFormatted02041fac(dst, field, 0x16);

    for (int var9 = 0; var9 < var3; var9++) {
        GameObject* var10 = var0->GetPartyMemberByIndex(var2[var7]);
        if (var10 != NULL) {
            GameObject* var11 = func_0200ff1c(var0, var2[var7]);
            if (func_02061bd8((struct Struct_0205faf4_11*)var11) != 0) {
                for (int var12 = 0; var12 < 4; var12++) {
                    var7 = (var7 + 1) % 4;
                    if (var7 == 0) break;
                    GameObject* var13 = func_0200ff1c(var0, var2[var7]);
                    if (var13 == NULL) continue;
                    if (func_02061bd8((struct Struct_0205faf4_11*)var13) != 0) continue;
                    var0->GetPartyMemberByIndex(var2[var7]);
                    break;
                }
            }

            int pal = func_ov002_02159774(base, idArr[idx], 0, 1, 1);
            Text_AppendPaletteTag(dst, pal);
            Text_AppendNTag(dst, i2, (const char*)(base + RG(0x1ab0, 0x1a08) + idArr[idx] * RG(0x3c, 0x18)));
            Text_AppendPaletteTag(dst, 0xf);
            Text_Append(dst, *(const char**)(base + 0x1000 + RG(0xbdc, 0xaa4)));

            var7++;
        }
    }

#if defined(jpn)
    Text_AppendNTag(dst, count, (const char*)KeyTable_Get((struct Container020e0310*)(base + 0x8), 0x76d));
#else
    Text_AppendNTag(dst, count, (const char*)StandardStrings_Get(0x1a));
#endif
}
