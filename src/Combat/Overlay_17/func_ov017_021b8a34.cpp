#include <globaldefs.h>

struct Struct_0209afd4_5 { unsigned short id; char pad[0x4a]; };

struct Struct_ov017_021b8a34_2 { unsigned int keyLow : 12; unsigned int keyHigh : 20; };
struct Struct_ov017_021b8a34 { unsigned short value : 8; unsigned short unknown_1_0_ : 8; };

int GetBTRandom(void);
extern "C" Struct_0209afd4_5* func_0209b9e4(Struct_0209afd4_5* base, int key);
extern "C" int RandomIntBelow(int max);

// USA: func_ov017_021b8a34
extern "C" ARM int func_ov017_021b8a34(Struct_0209afd4_5* table, int id, int arg2) {
    GetBTRandom();
    Struct_0209afd4_5* row = func_0209b9e4(table, id);
    if (row != NULL) {
        int i;
        for (i = 0; i < *(unsigned char*)((char*)row + 2); i++) {
            struct Struct_ov017_021b8a34_2* var2 = (struct Struct_ov017_021b8a34_2*)((char*)row + (i << 3) + 4);
            if (arg2 == (int)var2->keyLow) {
                struct Struct_ov017_021b8a34* weight = (struct Struct_ov017_021b8a34*)((char*)row + 8 + (i << 3));
                int roll = RandomIntBelow(0x64);
                if (roll < weight->unknown_1_0_) {
                    return weight->value;
                }
                break;
            }
        }
    }
    return -1;
}
