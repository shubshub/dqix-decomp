#include <globaldefs.h>


struct PackedNibbleArray0206e120;
struct Struct_0205faf4_13;
struct SearchStruct0202c1a4;
struct Node02064704;
struct Struct_02095924 {
    unsigned short field0;
    unsigned short index : 9;
    unsigned short allowDuringSearch : 1;
    unsigned short enabled : 1;
    unsigned short blocked : 1;
    unsigned short reserved : 4;
    unsigned int category : 8;
    unsigned int flags : 24;
    Node02064704* unknown_8_;
    Struct_02095924* next;
};
struct SearchTable { char padding0[0xa0]; Struct_02095924* first; };
struct Struct_02095924_3 { int category; char padding4[0x30]; };
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance();
extern "C" int func_0206e2dc(Struct_0205faf4_13*, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" int func_02064704(void*, Node02064704*, void*);
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" int func_02095ae0(PackedNibbleArray0206e120*, int);
extern "C" void func_0206e164(PackedNibbleArray0206e120*, int, int);

static inline int inline_02095924(PackedNibbleArray0206e120* values, int index, int state) {
    return func_0206e120(values, index) == state;
}

// USA: func_02095924
extern "C" ARM int func_02095924(SearchTable* table, int category) {
    PackedNibbleArray0206e120* values = Scenario_GetInstance();
    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    Struct_02095924_3 arguments;
    for (Struct_02095924* node = table->first; node; node = node->next) {
        if (node->category != category) continue;
        if (node->enabled && !func_0206e2dc((Struct_0205faf4_13*)values, node->index)) continue;
        if (LinkSession_IsActive((int*)search) && LinkSession_GetOwnSlot(search) && !node->allowDuringSearch) continue;
        arguments.category = category;
        if (func_02064704(values, node->unknown_8_, &arguments)) {
            if (inline_02095924(values, node->index, 3)) {
                if (!node->allowDuringSearch || node->blocked) continue;
            }
            if (!func_02095ae0(values, node->index)) continue;
            func_0206e164(values, node->index, 1);
            return node->index;
        } else {
            if (inline_02095924(values, node->index, 3)) continue;
            if (inline_02095924(values, node->index, 2)) continue;
            func_0206e164(values, node->index, 0);
        }
    }
    return -1;
}
