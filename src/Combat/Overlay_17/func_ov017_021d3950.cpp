#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021d3950_3 {
    unsigned char unknown_0_;
    signed char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov017_021d3950 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 8;
    unsigned int unknown_2_1_ : 8;
    unsigned int unknown_3_1_ : 4;
    unsigned int unknown_3_5_ : 2;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_ov017_021d3950_2 {
    unsigned int unknown_0_0_ : 16;
    unsigned int unknown_2_0_ : 7;
    unsigned int unknown_2_7_ : 9;
    unsigned int unknown_4_0_ : 21;
    unsigned int unknown_6_5_ : 8;
    unsigned int unknown_7_5_ : 3;
    char unknown_8_[0x6c - 8];
    struct Struct_ov017_021d3950_2* unknown_6c_;
};

struct Struct_0208e7a4 {
    char unknown_0_[4];
    struct Struct_ov017_021d3950_2* unknown_4_;
};

struct Struct_0208f3b4;

extern "C" Head0208e7a4* LootPointList_GetInstance(void);
Entry021d3950* GetNegativeEntry_020120b8(char* obj, int index);
Node021d3950* FindNodeByPackedId0208e7a4(Head0208e7a4* owner, unsigned int key);
Cont0208f3b4* GetData02109020_0208e9e8(void);
void RemoveNodeByKey0208f3b4(Cont0208f3b4* c, int key);

// USA: func_ov017_021d3950
extern "C" ARM int func_ov017_021d3950(Request021d3950* req) {
    GameState* gs = GameState::GetInstance();
    Head0208e7a4* list = LootPointList_GetInstance();
    Entry021d3950* entry = GetNegativeEntry_020120b8((char*)gs, req->id);
    if (entry != NULL && (req->mask & entry->flags) != 0) {
        entry->flags = ~req->mask & entry->flags;
        entry->timer = entry->count * 30;
        Node021d3950* node = FindNodeByPackedId0208e7a4(list, req->id);
        if (node == NULL) {
            return 1;
        }
        var3->unknown_6_5_ = ~arg0->unknown_2_ & var3->unknown_6_5_;
        Struct_ov017_021d3950_2* var4;
        int var5 = 0;
        for (var4 = var1->unknown_4_; var4 != NULL; var4 = var4->unknown_6c_, var5++) {
            if (var4->unknown_2_0_ == arg0->unknown_3_) {
                break;
            }
        }
        if (var4 == NULL) {
            return 1;
        }
        int var6;
        for (var6 = 0; var6 < 8; var6++) {
            if (arg0->unknown_2_ & (1 << var6)) {
                break;
            }
        }
        if (var4 != NULL && var6 < 8) {
            func_0208f3b4(func_0208e9e8(), var6 + var5 * 8);
        }
        return 1;
    }
    return 0;
}
