#include <globaldefs.h>
#include "Resource/GameResources.h"
#include <GameState/GameState.h>

enum Enum_ov005_0215c530
{
    Enum_ov005_0215c530_m1 = -1,
    Enum_ov005_0215c530_32767 = 0x7fff
};

struct Struct_ov005_0215c530_4
{
    unsigned int a : 7;
    unsigned int b : 4;
    unsigned int pad0 : 18;
    unsigned int d : 1;
    unsigned int e : 2;
    unsigned int c : 12;
    unsigned int pad1 : 15;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int pad2 : 2;
    char pad3[0x20 - 8];
};

struct Struct_ov005_0215c530_6
{
    Struct_ov005_0215c530_4* unknown_0_;
    int f4;
    unsigned int unknown_8_0_ : 4;
    unsigned int pad0 : 28;
    char pad1[0x18 - 0xc];
    short id;
    char pad2[0x20 - 0x1a];
};

struct Struct_ov005_0215c530_7
{
    short id;
    unsigned short unknown_2_0_ : 4;
    unsigned short pad0 : 12;
    unsigned int a : 7;
    unsigned int b : 4;
    unsigned int c : 12;
    unsigned int d : 1;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int pad1 : 3;
};

struct Struct_ov005_0215c530
{
    Struct_ov005_0215c530* next;
    char pad[4];
    short id;
};

struct Struct_ov005_0215c530_2
{
    short item;
    char pad[0x1c - 2];
};

struct ItemTable;
struct Element020de650;
struct Struct_ov003_02178910 {
    char pad0[0x48];
    ItemTable* field48;
    Element020de650* field4c;
#if defined(jpn)
    char unknown_50_[0x680];
#else
    char unknown1_50_[0x704];
#endif
    int field754;
    char unknown_758_[0x18];
    short field770;
    unsigned short unknown_772_;
    unsigned short field774;
    unsigned char unknown_776_;
};

struct Struct_01ff8b48_22 {
    Struct_ov005_0215c530_7* entries;
    unsigned short unknown4;
    unsigned short count;
};

struct Struct_ov005_0215c530_3
{
#if defined(jpn)
    char pad0[0x1240];
#else
    char pad0[0x1244];
#endif
    Struct_ov003_02178910 container;
#if defined(jpn)
    char unknown_1934_[0x1958 - 0x1240 - sizeof(Struct_ov003_02178910)];
#else
    char unknown_19bc_[0x19e0 - 0x1244 - sizeof(Struct_ov003_02178910)];
#endif
    Struct_ov005_0215c530* head;
    char pad1[8];
    Struct_01ff8b48_22 entryList;
    char cursor[0x2d90 - 0x19f4];
    Struct_ov005_0215c530_2 slots[24];
    char pad2[0x3d98 - 0x3030];
    short counts[8];
    char pad3[2];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db9 - 0x3dab];
    unsigned char unknown_3db9_;
    char pad4[0x3dbb - 0x3dba];
    signed char selected;
    unsigned char tab;
    signed char page;
    char pad5;
    signed char unknown_3dbf_;
    char pad6[0x3dcc - 0x3dc0];
    unsigned int dirty;
    char unknown_3dd0_[0x3dd4 - 0x3dd0];
    unsigned char unknown_3dd4_[8];
};

struct Struct_ov005_0215c530_5
{
#if defined(jpn)
    char pad[0x4f8];
#else
    char pad[0x4fc];
#endif
    int member;
};

struct StructDE1D4;
struct SePlayer;

extern "C" short* func_0207c5f8(unsigned char*, unsigned int);
extern "C" signed char* func_0207c60c(void*, unsigned int);
extern "C" void func_0207c51c(unsigned char*, int);
extern "C" void func_ov023_021e1518(void*);
extern "C" void func_ov023_021e1b5c(void*, int, int, int);
extern "C" void func_ov023_021e1b0c(void*, int, int, int);
extern "C" Struct_ov005_0215c530_5* func_ov017_021a193c(int*);
extern "C" void ItemRecord_Clear(StructDE1D4*);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" Struct_ov005_0215c530_7* func_ov023_021db08c(void*, int);
extern "C" int func_020dd4c4(int, Struct_ov005_0215c530_6*);
extern "C" void func_ov005_021579ec(Struct_ov005_0215c530_3*, unsigned int, unsigned char);
extern "C" void GridCursor_SetSelectedIndex(void*, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov005_021555c0(Struct_ov005_0215c530_3*);
extern "C" void func_ov023_021dcae0(Struct_ov003_02178910*, int);
extern "C" void func_ov005_0215792c(Struct_ov005_0215c530_3*, unsigned char);

#if defined(jpn)
#define data_ov005_0215cd08 data_ov005_0215e0e8
#define data_ov005_0215cd00 data_ov005_0215e0e0
#endif
extern unsigned char data_ov005_0215cd08[];
extern unsigned char data_ov005_0215cd00[];
extern char g_sePlayer[];

// USA: func_ov005_0215c530
extern "C" ARM void func_ov005_0215c530(Struct_ov005_0215c530_3* self)
{
    unsigned char* bag = (unsigned char*)GameState_GetParty(GameState::GetInstance());
    int count = self->counts[self->tab];
    short* ids = func_0207c5f8(bag + 0x1d4, data_ov005_0215cd08[self->tab]);
    signed char* var3 = func_0207c60c(bag + 0x1d4, data_ov005_0215cd08[self->tab]);
    func_0207c51c(bag + 0x1d4, data_ov005_0215cd00[self->tab]);

    int var4 = 0;
    int var5 = 0;
    if (self->unknown_3dd4_[self->tab] == 0 || self->unknown_3dd4_[self->tab] == 1)
    {
        func_ov023_021e1518(&self->head);
        func_ov023_021e1b5c(&self->head, -1, data_ov005_0215cd00[self->tab], -1);
        var4 = 1;
    }
    else if (self->unknown_3dd4_[self->tab] == 3)
    {
        func_ov023_021e1518(&self->head);
        func_ov023_021e1b0c(&self->head, -1, data_ov005_0215cd00[self->tab], -1);
        var4 = 1;
    }
    else if (self->unknown_3dd4_[self->tab] == 2)
    {
        var5 = 1;
        var4 = 1;
    }

    if (var4)
    {
        int target = self->slots[self->selected].item;
        short outIds[0x110];
        unsigned char var8[0x110];
        for (int i = 0; i < 0x110; i++)
        {
            outIds[i] = Enum_ov005_0215c530_m1;
            var8[i] = 0;
        }
        if (!var5)
        {
            Struct_ov005_0215c530* node = self->head;
            int n = 0;
            while (node)
            {
                for (int i = 0; i < count; i++)
                {
                    if (node->id == ids[i])
                    {
                        outIds[n] = ids[i];
                        var8[n] = var3[i];
                        n++;
                        node = node->next;
                        break;
                    }
                    if (i == count - 1)
                        node = node->next;
                }
            }
        }
        else
        {
            signed char member = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->member;
            Struct_ov005_0215c530_6 item;
            Struct_ov005_0215c530_4 var15;
            ItemRecord_Clear((StructDE1D4*)&item);
            memset(&var15, 0, 0x20);
            item.unknown_0_ = &var15;
            int n = 0;
            int rejected = 0;
            for (int i = 0; i < count; i++)
            {
                short id = ids[i];
                if (id > 0)
                {
                    ItemRecord_Clear((StructDE1D4*)&item);
                    memset(&var15, 0, 0x20);
                    Struct_ov005_0215c530_7* entry;
                    item.unknown_0_ = &var15;
                    entry = func_ov023_021db08c(&self->entryList, id);
                    if (entry)
                    {
                        item.id = entry->id;
                        item.unknown_8_0_ = entry->unknown_2_0_;
                        var15.a = entry->a;
                        var15.b = entry->b;
                        var15.c = entry->c;
                        var15.d = entry->d;
                        var15.e = entry->e;
                        var15.f = entry->f;
                        var15.g = entry->g;
                        var15.h = entry->h;
                    }
                    if (func_020dd4c4(member, &item))
                    {
                        rejected++;
                    }
                    else
                    {
                        outIds[n] = ids[i];
                        var8[n] = var3[i];
                        n++;
                        ids[i] = Enum_ov005_0215c530_m1;
                        var3[i] = 0;
                    }
                }
            }
            func_0207c51c(bag + 0x1d4, data_ov005_0215cd00[self->tab]);
            memcpy(outIds + n, ids, rejected * 2);
            memcpy(var8 + n, var3, rejected);
        }
        memcpy(ids, outIds, count * 2);
        memcpy(var3, var8, count);

        int sel = self->selected;
        if (sel >= 8 && sel < 0x18)
        {
            int idx = -1;
            for (int i = 0; i < count; i++)
            {
                if (target == ids[i])
                {
                    idx = (short)i;
                    break;
                }
            }
            if (idx >= 0)
            {
                self->unknown_3dbf_ = self->page;
                self->page = idx / 16;
                int old = self->selected;
                self->selected = idx % 16 + 8;
                if (old != self->selected)
                {
                    func_ov005_021579ec(self, 4, (unsigned char)self->selected);
                    GridCursor_SetSelectedIndex(self->cursor, self->selected - 8);
                }
            }
        }
        SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
    }

    if (self->unknown_3dd4_[self->tab] == 0 || self->unknown_3dd4_[self->tab] == 1)
    {
        self->unknown_3dd4_[self->tab] = 3;
        self->dirty |= 0x800;
    }
    else if (self->unknown_3dd4_[self->tab] == 3)
    {
        self->unknown_3dd4_[self->tab] = 2;
        self->dirty |= 0x800;
    }
    else if (self->unknown_3dd4_[self->tab] == 2)
    {
        self->unknown_3dd4_[self->tab] = 1;
        self->dirty |= 0x800;
    }
    func_ov005_021555c0(self);
    Enum_ov005_0215c530 item = (Enum_ov005_0215c530)self->slots[self->selected].item;
    func_ov023_021dcae0(&self->container, item);
    self->dirty |= 0x40;
    self->unknown_3daa_ = 0;
    func_ov005_0215792c(self, self->unknown_3db9_);
}
