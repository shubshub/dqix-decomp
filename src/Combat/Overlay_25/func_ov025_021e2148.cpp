#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov025_021e2148_4 {
    unsigned char id;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char parent;
    unsigned char blocked;
    char pad6[2];
    Struct_ov025_021e2148_4* next;
};

struct Struct_ov025_021e2148 {
    Struct_ov025_021e2148_4* head;
};

struct Struct_ov025_021e2148_2 {
    Struct_ov025_021e2148_4* nodes;
    int count;
    unsigned char unknown_8_[12];
    unsigned char unknown_14_;
};

struct Struct_ov025_021e2148_3 {
    unsigned char b[6];
};

struct Struct_ov000_02171720;
struct Struct_ov000_02171720_2;
struct Struct_ov000_02171738;
struct Struct_ov000_0217179c;
struct Struct_ov000_0217179c_2;

#if defined(jpn)
#define func_ov025_021e23d0 func_ov000_02171720
#define func_ov025_021e23e8 func_ov000_02171738
#define func_ov025_021e244c func_ov000_0217179c
#define func_ov025_021e2494 func_ov000_021717e4
extern "C" void func_ov000_02171720(Struct_ov000_02171720* list, Struct_ov000_02171720_2* node);
extern "C" int func_ov000_021717e4(void* obj);
extern "C" Struct_ov025_021e2148_4* func_ov000_02171738(Struct_ov000_02171738* list);
extern "C" void func_ov000_0217179c(Struct_ov000_0217179c* list, Struct_ov000_0217179c_2* target);
#endif

extern "C" void func_ov025_021e23d0(Struct_ov000_02171720* list, Struct_ov000_02171720_2* node);
extern "C" int func_ov025_021e2494(void* obj);
extern "C" Struct_ov025_021e2148_4* func_ov025_021e23e8(Struct_ov000_02171738* list);
extern "C" void func_ov025_021e244c(Struct_ov000_0217179c* list, Struct_ov000_0217179c_2* target);
extern "C" int func_ov025_021e24a8(Struct_ov025_021e2148* list, Struct_ov025_021e2148_4* node);
extern "C" void func_ov000_0216f82c(Struct_ov025_021e2148_3* out, const int* cell);

// USA: func_ov025_021e2148
extern "C" ARM int func_ov025_021e2148(Struct_ov025_021e2148_2* graph, int start, int arg2, unsigned char* out, int maxLen) {
    if (graph->nodes == NULL) {
        return 0;
    }
    if (graph->count <= start) {
        return 0;
    }
    if (graph->count <= arg2) {
        return 0;
    }
    memset(graph->nodes, 0, graph->count * sizeof(Struct_ov025_021e2148_4));

    Struct_ov025_021e2148 open;
    Struct_ov025_021e2148 closed;
    open.head = NULL;
    closed.head = NULL;

    unsigned char* cells = graph->unknown_8_;
    for (int i = 0; i < graph->unknown_14_; i++) {
        int cell = cells[i];
        if (graph->count <= cell) {
            return 0;
        }
        graph->nodes[cell].blocked = 1;
    }

    Struct_ov025_021e2148_4* node = &graph->nodes[start];
    node->id = start;
    node->unknown_1_ = 0;
    node->unknown_2_ = 0;
    node->unknown_3_ = 0;
    node->parent = 0xff;
    node->next = NULL;
    node->blocked = 0;
    func_ov025_021e23d0((Struct_ov000_02171720*)&open, (Struct_ov000_02171720_2*)node);

    Struct_ov025_021e2148_4* cur;
    while (true) {
        if (func_ov025_021e2494(&open)) {
            return 0;
        }
        cur = func_ov025_021e23e8((Struct_ov000_02171738*)&open);
        if (cur->id == arg2) {
            break;
        }
        func_ov025_021e23d0((Struct_ov000_02171720*)&closed, (Struct_ov000_02171720_2*)cur);

        Struct_ov025_021e2148_3 nb;
        Struct_ov025_021e2148_3 tmp;
        int cell = cur->id;
        func_ov000_0216f82c(&tmp, &cell);
        nb = tmp;

        for (int i = 0; i < 6; i++) {
            int id = nb.b[i];
            if (id == 0xff) {
                continue;
            }
            Struct_ov025_021e2148_4* next = &graph->nodes[id];
            next->id = id;
            if (graph->count <= id) {
                return 0;
            }
            if (next->blocked != 0) {
                continue;
            }
            cur->unknown_2_ = cur->unknown_1_ - cur->unknown_3_;
            int var13 = cur->unknown_2_ + 1;
            if (func_ov025_021e24a8(&open, next)) {
                if (var13 < next->unknown_1_) {
                    next->unknown_1_ = var13;
                    next->parent = cur->id;
                }
            } else if (func_ov025_021e24a8(&closed, next)) {
                if (var13 < next->unknown_1_) {
                    next->unknown_1_ = var13;
                    next->parent = cur->id;
                    func_ov025_021e244c((Struct_ov000_0217179c*)&closed, (Struct_ov000_0217179c_2*)next);
                    func_ov025_021e23d0((Struct_ov000_02171720*)&open, (Struct_ov000_02171720_2*)next);
                }
            } else {
                next->unknown_1_ = var13;
                next->parent = cur->id;
                func_ov025_021e23d0((Struct_ov000_02171720*)&open, (Struct_ov000_02171720_2*)next);
            }
        }
    }

    Struct_ov025_021e2148_4* p = &graph->nodes[arg2];
    int n = 0;
    while (true) {
        out[n] = p->id;
        n++;
        if (maxLen <= n) {
            break;
        }
        int parent = p->parent;
        if (graph->count <= parent) {
            break;
        }
        p = &graph->nodes[parent];
    }
    return n;
}
