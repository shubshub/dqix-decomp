#include <globaldefs.h>


struct Struct_0205faf4_3;
struct Struct_0205faf4_13;
struct Struct_0202c1a4;
struct Struct_02064490_3;
struct Struct_02095924 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 9;
    unsigned short unknown_3_1_ : 1;
    unsigned short unknown_3_2_ : 1;
    unsigned short unknown_3_3_ : 1;
    unsigned short unknown_3_4_ : 4;
    unsigned int unknown_4_0_ : 8;
    unsigned int unknown_5_0_ : 24;
    Struct_02064490_3* unknown_8_;
    Struct_02095924* unknown_c_;
};
struct SearchTable { char padding0[0xa0]; SearchNode* first; };
struct SearchArguments { int category; char padding4[0x30]; };
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
extern "C" SearchStruct0202c1a4* func_0202ae18();
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
int CheckField0NonZero_0202b7d8(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
int ForEachNodeUntilFalse02064704(void*, Node02064704*, void*);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int IsNibbleFieldZeroOrOne_02095ae0(PackedNibbleArray0206e120*, int);
extern "C" void func_0206e164(PackedNibbleArray0206e120*, int, int);

static inline int inline_02095924(Struct_0205faf4_3* arg0, int arg1, int arg2) {
    return func_0206e120(arg0, arg1) == arg2;
}

// USA: func_02095924
extern "C" ARM int func_02095924(SearchTable* table, int category) {
    PackedNibbleArray0206e120* values = Scenario_GetInstance();
    SearchStruct0202c1a4* search = func_0202ae18();
    SearchArguments arguments;
    for (SearchNode* node = table->first; node; node = node->next) {
        if (node->category != category) continue;
        if (node->enabled && !GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)values, node->index)) continue;
        if (CheckField0NonZero_0202b7d8((int*)search) && GetSearchStructCurrentArrEntry(search) && !node->allowDuringSearch) continue;
        arguments.category = category;
        if (ForEachNodeUntilFalse02064704(values, node->conditions, &arguments)) {
            if (IsSearchState(values, node->index, 3)) {
                if (!node->allowDuringSearch || node->blocked) continue;
            }
            if (!func_02095ae0(var0, var3->unknown_2_0_)) continue;
            func_0206e164(var0, var3->unknown_2_0_, 1);
            return var3->unknown_2_0_;
        } else {
            if (inline_02095924(var0, var3->unknown_2_0_, 3)) continue;
            if (inline_02095924(var0, var3->unknown_2_0_, 2)) continue;
            func_0206e164(var0, var3->unknown_2_0_, 0);
        }
    }
    return -1;
}
