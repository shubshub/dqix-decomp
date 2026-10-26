#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char* buf, int a, int b);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

extern "C" void func_020dc4d0(signed char* out, signed char* outCount);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int func_02041fac(char* buf, int a, int b);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int StandardStrings_Get(int value);
extern "C" int func_ov002_02159774(void* base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215e250
extern "C" ARM void func_ov002_0215e250(unsigned char* base, char* dst, int flag) {
    if (dst == NULL) return;

    GameState* bs = GameState::GetInstance();
    int cursor = *(short*)(base + RG(0x1bf6, 0x1abe));

    signed char idArr[7];
    signed char count;
    func_020dc4d0(idArr, &count);

    signed char matched = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = func_0200ff1c(bs, idArr[i]);
        if (c != NULL) {
            if (func_02061bd8((struct Struct_0205faf4_11*)c) != 0) {
                matched++;
            }
        }
    }
    count = count - matched;

    int idx = 0;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    int field = KeyTable_Get((struct Container020e0310*)(base + RG(0x20, 0x8)), 2);
    func_02041fac(dst, field, 0x16);

    for (int i2 = 0; i2 < count; i2++) {
        GameObject* c800 = bs->GetPartyMemberByIndex(idArr[idx]);
        if (c800 != NULL) {
            GameObject* var11 = func_0200ff1c(bs, idArr[idx]);
            if (func_02061bd8((struct Struct_0205faf4_11*)var11) != 0) {
                for (int var12 = 0; var12 < 4; var12++) {
                    idx = (idx + 1) % 4;
                    if (idx == 0) break;
                    GameObject* c3 = func_0200ff1c(bs, idArr[idx]);
                    if (c3 == NULL) continue;
                    if (func_02061bd8((struct Struct_0205faf4_11*)c3) != 0) continue;
                    bs->GetPartyMemberByIndex(idArr[idx]);
                    break;
                }
            }

            int pal = func_ov002_02159774(base, idArr[idx], 0, 1, 1);
            Text_AppendPaletteTag(dst, pal);
            Text_AppendNTag(dst, i2, (const char*)(base + RG(0x1ab0, 0x1a08) + idArr[idx] * RG(0x3c, 0x18)));
            Text_AppendPaletteTag(dst, 0xf);
            Text_Append(dst, *(const char**)(base + 0x1000 + RG(0xbdc, 0xaa4)));

            idx++;
        }
    }

#if defined(jpn)
    Text_AppendNTag(dst, count, (const char*)KeyTable_Get((struct Container020e0310*)(base + 0x8), 0x76d));
#else
    Text_AppendNTag(dst, count, (const char*)StandardStrings_Get(0x1a));
#endif
}
