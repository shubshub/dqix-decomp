#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

class Struct_ov004_0215f0c0_5 {
public:
    virtual void v00(); virtual void inline_ov004_0215f0c0_26(); virtual void inline_ov004_0215f0c0_27(); virtual void inline_ov004_0215f0c0_28();
    virtual void v04(); virtual void inline_ov004_0215f0c0_30(); virtual void inline_ov004_0215f0c0_31();
    virtual void inline_ov004_0215f0c0_32(Vector3i* pos);
    virtual Vector3i inline_ov004_0215f0c0_33();
    virtual void inline_ov004_0215f0c0_34(); virtual void v10(); virtual void inline_ov004_0215f0c0_36(); virtual void inline_ov004_0215f0c0_37();
    virtual void inline_ov004_0215f0c0_38(); virtual void v14(); virtual void inline_ov004_0215f0c0_40(); virtual void inline_ov004_0215f0c0_41();
    virtual void inline_ov004_0215f0c0_42(); virtual void v18(); virtual void inline_ov004_0215f0c0_44(); virtual void v20();
    virtual void inline_ov004_0215f0c0_46(); virtual void inline_ov004_0215f0c0_47(); virtual void inline_ov004_0215f0c0_48(); virtual void v24();
    virtual void inline_ov004_0215f0c0_50(); virtual void inline_ov004_0215f0c0_51(); virtual void inline_ov004_0215f0c0_52(); virtual void v28();
    virtual void inline_ov004_0215f0c0_54(); virtual void v30(); virtual void inline_ov004_0215f0c0_56(); virtual void inline_ov004_0215f0c0_57();
    virtual void inline_ov004_0215f0c0(); virtual void v34(); virtual void inline_ov004_0215f0c0_3(); virtual void inline_ov004_0215f0c0_4();
    virtual void inline_ov004_0215f0c0_5(); virtual void v38(); virtual void inline_ov004_0215f0c0_7(); virtual void v40();
    virtual void inline_ov004_0215f0c0_9(); virtual void inline_ov004_0215f0c0_10(); virtual void inline_ov004_0215f0c0_11(); virtual void v44();
    virtual void inline_ov004_0215f0c0_13(); virtual void inline_ov004_0215f0c0_14(); virtual void inline_ov004_0215f0c0_15(); virtual void v48();
    virtual void inline_ov004_0215f0c0_17(); virtual void v50(); virtual void inline_ov004_0215f0c0_19(); virtual void inline_ov004_0215f0c0_20();
    virtual void inline_ov004_0215f0c0_21();
    virtual void inline_ov004_0215f0c0_22(int palette);
    virtual void inline_ov004_0215f0c0_23();
    virtual void inline_ov004_0215f0c0_24(unsigned short icon);

    unsigned char pad4[8];
    unsigned char flags;
    unsigned char unknown_d_[0x13];
    void* data;
    unsigned char pad24[0x14];
    short frame;
    unsigned char unknown_3a_[0xa];
    unsigned char kind : 4;
};

struct Struct_ov004_021707e8 {
    unsigned char pad0[2];
    unsigned char slot;
    unsigned char pad3[0x19];
    int combatantId;
    unsigned char pad20[8];
    char* textBuf;
};

struct Struct_ov004_0215f0c0 {
    unsigned char pad0[4];
    unsigned short hp;
};

struct Struct_ov004_0215f0c0_2 {
    unsigned char pad0[0x130];
    struct Struct_ov004_0215f0c0* stats;
    void* baseStats;
};

struct Struct_ov004_0215f0c0_3 {
    unsigned char pad0[0x950];
    int unknown_950_;
};

struct Struct_ov004_0215f0c0_4 {
    unsigned char pad0[0x150];
    struct Struct_ov004_0215f0c0_3* unknown_150_;
};

struct Struct_ov004_0215f0c0_6 {
    unsigned char pad0[0x16c];
    unsigned short icons[13];
    unsigned char levels[1];
};

struct Struct_ov004_0215f0c0_7 {
    unsigned char pad0[4];
    unsigned short tile;
};

struct Struct_ov004_0215f0c0_8 {
    unsigned char pad0[8];
    struct Struct_ov004_0215f0c0_7* info;
};

struct Struct_ov004_0215f0c0_9 {
    int words[3];
};

struct Struct0200fb08;
struct TableA68;

extern "C" int STD_GetStringLength(const char*);
extern "C" unsigned char* func_02053c6c(unsigned char* obj);
extern "C" Struct_ov004_0215f0c0_5* func_ov004_0215e47c(void* a, int key);
extern "C" void* func_ov023_021fad18(void* node);
extern "C" struct Struct_ov004_0215f0c0_8* func_ov004_0215e438(void* arr, int idx);
extern "C" int func_ov017_021bdbcc(void* obj);
extern "C" void* func_020421b0(int idx);
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" Struct_ov004_0215f0c0_5* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(Struct_ov004_0215f0c0_5* node);
extern "C" int func_02042190(int x);
extern "C" int Font_GetTextWidth(void* p, int flag);
extern "C" int StandardStrings_Get(int value);
extern "C" int func_ov004_0215e460(void);
extern "C" void func_ov004_0215e49c(void*, int, int);
extern "C" struct TableA68* func_ov023_021fa598(Struct_ov004_0215f0c0_5* node);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* global);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void MessageSystem_FormatText(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
extern "C" void* func_ov004_0215e4c0(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

extern struct Struct_ov004_021707e8 data_ov004_021707e8;
extern int data_ov004_0216fe04[];
extern unsigned short data_ov004_0216fdd0[];

// JPN: func_ov004_0215f0c0 (0215fbc8)
// USA: func_ov004_0215f0c0
extern "C" ARM void func_ov004_0215f0c0(void* self) {
    GameState* gs = GameState::GetInstance();
    struct Struct_ov004_0215f0c0_2* combatant = (struct Struct_ov004_0215f0c0_2*)func_0200ff1c(gs, data_ov004_021707e8.combatantId);
    struct Struct_ov004_0215f0c0_6* field150 = (struct Struct_ov004_0215f0c0_6*)func_02053c6c((unsigned char*)combatant);
    int var3 = 0;
    int palette = 0xf;
    if ((int)combatant->stats->hp <= 0) {
        var3 = 1;
    }
    if (var3) {
        palette = 9;
    }
#if !defined(jpn)
    Struct_ov004_0215f0c0_5* marker = func_ov004_0215e47c(self, 0x1f5);
    if (!var3) {
        void* var6 = func_ov004_0215e47c(self, 0x1f4);
        if (var6 != 0) {
            int bank;
            void* arr = func_ov023_021fad18(var6);
            int var9 = data_ov004_021707e8.combatantId;
            if (var9 >= 0) {
                struct Struct_ov004_0215f0c0_4* member = (struct Struct_ov004_0215f0c0_4*)GameState::GetInstance()->GetPartyMemberByIndex(var9);
                if (arr != 0 && member != 0) {
                    struct Struct_ov004_0215f0c0_8* entry = func_ov004_0215e438(arr, 0);
                    struct Struct_ov004_0215f0c0_7* info;
                    if (entry != 0 && (info = entry->info) != 0) {
                        bank = member->unknown_150_->unknown_950_;
                        int var13 = func_ov017_021bdbcc(GetGameResources());
                        if (var13 != 0) {
                            bank = 0;
                        }
                        int i;
                        unsigned int offset;
                        unsigned char tableIdx = bank * 4 + 0x28;
                        offset = (unsigned short)(info->tile & 0x3ff) << 5;
                        for (i = 0; i < 4; i++, tableIdx++) {
                            void* tile = func_020421b0(tableIdx);
                            CleanInvalidateCacheRange(tile, 0x20);
                            LoadToMainObjVRAM(tile, offset, 0x20);
                            CleanCacheRange(tile, 0x20);
                            offset += 0x20;
                        }
                    }
                }
            }
        }
        if (marker != 0) {
            marker->flags &= ~8;
        }
    } else {
        if (marker != 0) {
            marker->flags |= 8;
        }
    }

    unsigned char level = GameState_GetLanguage((struct Struct0200fb08*)gs);
#endif
    void* list = func_ov011_021849c8(self);
    Struct_ov004_0215f0c0_5* node = func_ov023_021f6880(list, 0x7f);
    if (node == 0) {
        return;
    }
    node->inline_ov004_0215f0c0_24(field150->icons[data_ov004_021707e8.slot]);

    {
        Struct_ov004_0215f0c0_5* node = func_ov023_021f6880(list, 0x7b);
        if (func_ov023_021f6f10(node) == 8) {
            void* baseStats = node->data = combatant->baseStats;
            int width = 0;
            if (baseStats != 0) {
#if defined(jpn)
                width = STD_GetStringLength((const char*)baseStats);
                width = (width * node->kind) >> 1;
#else
                width = Font_GetTextWidth(baseStats, func_02042190(node->kind));
#endif
            }
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = (0x23 - (width >> 1)) << 12;
#if !defined(jpn)
            pos.y = 0x2000;
#endif
            node->inline_ov004_0215f0c0_32(&pos);
            node->inline_ov004_0215f0c0_22(palette);
        }
    }
    int lv = field150->levels[data_ov004_021707e8.slot];
    if (lv != 0) {
        node = func_ov023_021f6880(list, 0x7e);
        if (node == 0) {
            return;
        }
        if (func_ov023_021f6f10(node) == 8) {
            node->frame = lv + 0x1d3;
#if defined(jpn)
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
#endif
            if (lv == 10) {
                node->inline_ov004_0215f0c0_22(0xd);
#if defined(jpn)
                pos.y = 0x6000;
#endif
            } else {
                node->inline_ov004_0215f0c0_22(5);
#if defined(jpn)
                pos.y = 0x7000;
#endif
            }
#if defined(jpn)
            node->inline_ov004_0215f0c0_32(&pos);
#endif
        }
#if defined(jpn)
        node = func_ov023_021f6880(list, 0x7c);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = 0x42000;
            node->inline_ov004_0215f0c0_32(&pos);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = 0x5f000;
            node->inline_ov004_0215f0c0_32(&pos);
        }
        node = func_ov023_021f6880(list, 0x7f);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = 0x68000;
            node->inline_ov004_0215f0c0_32(&pos);
        }
#else
        node = func_ov023_021f6880(list, 0x7f);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = (data_ov004_0216fe04[level] + 0x72) << 12;
            node->inline_ov004_0215f0c0_32(&pos);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            node->data = (void*)StandardStrings_Get(0x3f3);
        }
#endif
    } else {
        node = func_ov023_021f6880(list, 0x7e);
        if (node != 0) {
            if (func_ov023_021f6f10(node) == 8) {
                node->frame = 0x3a;
            }
        }
#if defined(jpn)
        node = func_ov023_021f6880(list, 0x7c);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = 0x46000;
            node->inline_ov004_0215f0c0_32(&pos);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = 0x5c000;
            node->inline_ov004_0215f0c0_32(&pos);
        }
        node = func_ov023_021f6880(list, 0x7f);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = 0x65000;
            node->inline_ov004_0215f0c0_32(&pos);
        }
#else
        node = func_ov023_021f6880(list, 0x7f);
        if (node != 0) {
            Vector3i pos;
            pos = node->inline_ov004_0215f0c0_33();
            pos.x = (data_ov004_0216fe04[level] + 0x72) << 12;
            node->inline_ov004_0215f0c0_32(&pos);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            node->data = (void*)StandardStrings_Get(0x3f3);
        }
#endif
    }

    if (func_ov004_0215e460() != 0) {
        func_ov004_0215e49c(self, 0x7c, 0x201);
    } else {
        func_ov004_0215e49c(self, 0x7c, data_ov004_021707e8.slot + 0x1e4);
    }

#if !defined(jpn)
    char* text = data_ov004_021707e8.textBuf;
    memset(text, 0, 0x80);
#endif
    unsigned short ids[3];
#if defined(jpn)
    ids[0] = data_ov004_0216fdd0[13];
    ids[1] = data_ov004_0216fdd0[14];
    ids[2] = data_ov004_0216fdd0[15];
#else
    ids[0] = data_ov004_0216fdd0[15];
    ids[1] = data_ov004_0216fdd0[16];
    ids[2] = data_ov004_0216fdd0[17];
#endif

    if (var3) {
        Struct_ov004_0215f0c0_5* label = func_ov023_021f6880(list, 0x7c);
        if (label != 0) {
            Vector3i pos;
            pos = label->inline_ov004_0215f0c0_33();
            pos.x = 0x53000;
#if !defined(jpn)
            pos.y = 0x2000;
#endif
            label->inline_ov004_0215f0c0_32(&pos);
            label->inline_ov004_0215f0c0_22(palette);
        }
#if defined(jpn)
        func_ov004_0215e49c(self, 0x7c, 0x202);
#else
        Struct_ov004_0215f0c0_5* msg = func_ov023_021f6880(list, 6);
        if (msg != 0 && func_ov023_021f6f10(msg) == 4) {
            struct TableA68* table = func_ov023_021fa598(msg);
            struct Struct_ov004_0215f0c0_9 name;
            NameText_InitFromPartyMember(&name, data_ov004_021707e8.combatantId);
            int g = MessageSystem_GetInstance();
            func_02046380((void*)g);
            *(struct Struct_ov004_0215f0c0_9**)g = &name;
            MessageSystem_FormatText(g, 0, func_02072a68(table, 0x202), text, 0x1e, 0, 0);
            label->data = text;
        }
#endif
        for (int i = 0; i < 3; i++) {
            Struct_ov004_0215f0c0_5* n = func_ov023_021f6880(list, ids[i]);
            if (n != 0) {
                n->flags |= 8;
            }
        }
    } else {
        Struct_ov004_0215f0c0_5* label = func_ov023_021f6880(list, 0x7c);
        if (label != 0) {
            label->inline_ov004_0215f0c0_22(palette);
        }
        for (int i = 0; i < 3; i++) {
            Struct_ov004_0215f0c0_5* n = func_ov023_021f6880(list, ids[i]);
            if (n != 0) {
                n->flags &= ~8;
            }
        }
    }

    func_ov023_021f809c(func_ov004_0215e4c0(self, 5), self);
}
