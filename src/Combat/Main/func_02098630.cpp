#include <globaldefs.h>

struct Struct_02098630
{
    unsigned char name[11];
    unsigned char slot : 7;
    unsigned char unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 4;
    unsigned int category : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int priority : 4;
    unsigned int level : 5;
    unsigned int unknown_f_0_ : 6;
    unsigned int dirty : 1;
    unsigned int unknown_f_7_ : 1;
    unsigned int used : 2;
    unsigned int unknown_10_2_ : 30;
    unsigned char key[6];
    unsigned char unknown_1a_[0x6c - 0x1a];
    unsigned int unknown_6c_0_ : 26;
    unsigned int unknown_6f_2_ : 1;
    unsigned int unknown_6f_3_ : 5;
    unsigned char unknown_70_[0xe8 - 0x70];
};

struct Struct_02097cac_2
{
    Struct_02098630 records[30];
    int unknown_1b30_;
    unsigned int unknown_1b34_;
    unsigned int count;
    unsigned char unknown_1b3c_[0x1b68 - 0x1b3c];
    unsigned int unknown_1b68_[3];
    int unknown_1b74_;
};

struct Struct_02098630_2
{
    int slot;
    int priority;
    int level;
    int unknown_c_;
};

extern "C" int memcmp(const void*, const void*, int);
extern "C" int func_02098a84(Struct_02097cac_2*);
extern "C" Struct_02098630* func_02098834(Struct_02098630*, Struct_02098630*);
extern "C" void func_020989cc(Struct_02097cac_2*);
extern "C" int func_020cf0fc(int);

// USA: func_02098630
extern "C" ARM int func_02098630(Struct_02097cac_2* self, Struct_02098630* source, int arg2, int arg3)
{
    if (!source->unknown_6f_2_)
        return 0;
    for (int i = 0; i < 30; i++)
    {
        if (memcmp(self->records[i].key, source->key, 6) == 0)
            return 0;
    }
    int index = func_02098a84(self);
    if (arg2)
        self->unknown_1b34_++;
    self->count = 0;
    Struct_02098630* cursor = self->records;
    for (int i = 0; i < 30; i++, cursor++)
    {
        if (cursor->unknown_10_2_)
            self->count++;
    }
    if (++self->count > 30)
        self->count = 30;
    Struct_02098630* record = &self->records[index];
    func_02098834(record, source);
    record->category = 2;
    record->used = 2;
    record->dirty = 1;
    record->unknown_10_2_ = self->unknown_1b34_;
    Struct_02098630_2 var5;
    if (func_020cf0fc((int)&var5) == 0)
    {
        self->records[index].slot = (unsigned char)var5.slot;
        self->records[index].priority = var5.priority;
        self->records[index].level = var5.level;
    }
    if (arg3)
        func_020989cc(self);
    unsigned int var6 = record->unknown_10_2_;
    for (int i = 0; i < 3; i++)
    {
        if (self->unknown_1b68_[i] == 0xffffffff)
        {
            self->unknown_1b68_[i] = var6;
            self->unknown_1b74_++;
            break;
        }
    }
    return 1;
}
