#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6d50 {
    unsigned short fieldA : 2;
    unsigned short fieldB : 4;
    unsigned short fieldC : 3;
    unsigned short state : 3;
    unsigned short : 4;
};

struct Struct_ov017_021c6d50_2 {
    unsigned short unknown_0_;
    unsigned short index;
    struct Struct_ov017_021c6d50 bits;
    unsigned char field6;
    unsigned char unknown_7_;
    unsigned short maxHP;
    unsigned short maxMP;
    unsigned int fieldC;
};

struct Struct_ov017_021c6d50_3 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021c6d50_2 fields;
};

static inline struct Struct_ov017_021c6d50* inline_ov017_021c6d50_5(GameObject* c) {
    return (struct Struct_ov017_021c6d50*)((unsigned char*)c->currentStats_ + 0x22);
}
static inline unsigned char inline_ov017_021c6d50(GameObject* c) { SDK_NULL_ASSERT(c); return inline_ov017_021c6d50_5(c)->fieldA; }
static inline unsigned char inline_ov017_021c6d50_2(GameObject* c) { SDK_NULL_ASSERT(c); return inline_ov017_021c6d50_5(c)->fieldB; }
static inline unsigned char inline_ov017_021c6d50_3(GameObject* c) { SDK_NULL_ASSERT(c); return inline_ov017_021c6d50_5(c)->fieldC; }
static inline unsigned char inline_ov017_021c6d50_4(GameObject* c) { SDK_NULL_ASSERT(c); return inline_ov017_021c6d50_5(c)->state; }

// USA: func_ov017_021c6d50
extern "C" ARM void func_ov017_021c6d50() {
#if defined(jpn)
 enum { regionalOffset=0x508 };
#else
 enum { regionalOffset=0x718 };
#endif
    GameState* bs = GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + regionalOffset);
    unsigned char* search = (unsigned char*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c6d50_3 msg;
    msg.tag = 0x6f;
    struct Struct_ov017_021c6d50_2* fp = &msg.fields;

    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(search, i)) {
            continue;
        }
        GameObject* c = bs->GetCombatantByIndex(i);
        if (*((unsigned char*)c->currentStats_ + 0x26) == 0) {
            continue;
        }
        fp->unknown_0_ = *(unsigned short*)(search + 0x8);
        fp->index = (unsigned short)i;
        fp->bits.fieldA = inline_ov017_021c6d50(c);
        fp->bits.fieldB = inline_ov017_021c6d50_2(c);
        fp->bits.fieldC = inline_ov017_021c6d50_3(c);
        fp->bits.state = inline_ov017_021c6d50_4(c);
        fp->field6 = *((unsigned char*)c->currentStats_ + 0x24);
        fp->maxHP = c->baseStats_->primaryStats.maxHP;
        fp->maxMP = c->baseStats_->primaryStats.maxMP;
        func_0205e330(data, &msg, 0);
    }
}
