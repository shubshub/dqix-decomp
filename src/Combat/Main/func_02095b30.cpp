#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_0205faf4_3;
struct Struct_0205faf4_13;
struct Struct_0202c1a4;
struct Struct_02064490_3;
struct Struct_0206dee8;
struct Struct_02095924 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 9;
    unsigned short unknown_3_1_ : 1;
    unsigned short unknown_3_2_ : 1;
    unsigned short unknown_3_3_ : 1;
    unsigned short unknown_3_4_ : 4;
    unsigned int unknown_4_0_ : 8;
    unsigned int unknown_5_0_ : 6;
    unsigned int unknown_5_6_ : 5;
    unsigned int unknown_6_3_ : 13;
    Struct_02064490_3* unknown_8_;
    Struct_02095924* unknown_c_;
};
struct SearchTable { char padding0[0xa0]; SearchNode* first; };
struct SearchArguments { char padding0[0xc]; int category; char padding10[0x24]; };
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
extern "C" SearchStruct0202c1a4* func_0202ae18();
extern "C" unsigned short* Zone3D_GetInstance();
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
int CheckField0NonZero_0202b7d8(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
int ForEachNodeUntilFalse02064704(void*, Node02064704*, void*);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int IsNibbleFieldZeroOrOne_02095ae0(PackedNibbleArray0206e120*, int);
void GetEntry3Bytes_0206dee8(EntryDEE8*, unsigned char, unsigned char*, unsigned char*, unsigned char*);
extern "C" void func_0206e164(PackedNibbleArray0206e120*, int, int);

static inline int inline_02095924(Struct_0205faf4_3* arg0, int arg1, int arg2) {
    return func_0206e120(arg0, arg1) == arg2;
}

// USA: func_02095b30
extern "C" ARM void func_02095b30(Struct_02095924_2* arg0, int arg1) {
    GameState::GetInstance();
    PackedNibbleArray0206e120* values = Scenario_GetInstance();
    SearchStruct0202c1a4* search = func_0202ae18();
    unsigned char components[3];
    SearchArguments arguments;
    for (SearchNode* node = table->first; node; node = node->next) {
        if (node->enabled && !GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)values, node->index)) continue;
        if (CheckField0NonZero_0202b7d8((int*)search) && GetSearchStructCurrentArrEntry(search) && !node->allowDuringSearch) continue;
        if (checkThreshold) {
            GetEntry3Bytes_0206dee8((EntryDEE8*)values, 0, &components[2], &components[1], &components[0]);
            if (!node->enabled) continue;
            if (node->whole * 100 + node->fraction > (unsigned int)(components[2] * 100 + components[1])) continue;
        }
        arguments.category = *Zone3D_GetInstance();
        if (!ForEachNodeUntilFalse02064704(values, node->conditions, &arguments)) continue;
        if (IsSearchState(values, node->index, 3) && !node->allowDuringSearch) continue;
        if (!IsNibbleFieldZeroOrOne_02095ae0(values, node->index)) {
            if (!IsSearchState(values, node->index, 3) || !node->blocked) continue;
        }
        func_0206e164(var0, var4->unknown_2_0_, 1);
    }
}
