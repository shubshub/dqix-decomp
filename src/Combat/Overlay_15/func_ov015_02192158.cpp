#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov015_0218ffa8;
struct Struct_ov015_0218ffd0;
struct Struct_ov015_0218fff8;
struct Struct_ov015_02190020;
struct Struct_ov015_0218ff7c;
struct Struct_ov015_0219005c;
struct ItemTable;
struct Fields020deda4;
struct Struct_ov015_021900dc;

struct Struct_ov015_0218b828_3
{
    char* name_;
    char* file_;
    unsigned short id_;
    unsigned char page_;
    unsigned char unknown_b_;
};

struct PartEntry
{
    char unk_0[0x18];
    short unknown_18_;
};

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x20];
    int* parts_;
    char unk_24[0x38 - 0x24];
    short motion_;
    unsigned char unknown_3a_;
    unsigned char female_;
};

struct Struct_ov015_02190e88
{
    Struct_ov015_0218c03c_2* object_;
    Struct_ov015_02190e88* unknown_4_;
};

struct Struct_ov015_02190acc
{
    char unk_0[0x2c];
    Struct_ov015_02190e88* objects_;
    Struct_ov015_0218c03c_2* current_;
    char unknown_34_[0x4c - 0x34];
    char parts_[0x194 - 0x4c];
    int menu_;
    char unknown_198_[0x1a4 - 0x198];
    int page_;
};

extern "C" Struct_ov015_0218b828_3* func_ov015_02193160(Struct_ov015_02190acc* self, int page, int* index);
extern "C" void func_ov015_0218ffa8(Struct_ov015_0218ffa8* object, int female);
extern "C" void func_ov015_0218f308(Struct_ov015_0218c03c_2* object, const char* event);
extern "C" void func_ov015_02192700(Struct_ov015_02190acc* self, int unk);
extern "C" void func_ov015_021900dc(Struct_ov015_021900dc* object);
extern "C" void func_ov015_0218ffd0(Struct_ov015_0218ffd0* object, int color);
extern "C" void func_ov015_0218fff8(Struct_ov015_0218fff8* object, int color);
extern "C" void func_ov015_02190020(Struct_ov015_02190020* object, unsigned char color);
extern "C" void func_ov015_0218ff7c(Struct_ov015_0218ff7c* object, int part, int id);
extern "C" PartEntry* ItemTable_Find(ItemTable* names, int id);
extern "C" PartEntry* func_020deda4(int names, int category, Fields020deda4* entry);
extern "C" void func_ov015_0219005c(Struct_ov015_0219005c* object, short width, short height);

// USA: func_ov015_02192158
extern "C" ARM void func_ov015_02192158(Struct_ov015_02190acc* self, int index)
{
    if (self->current_ == NULL)
        return;
    int position = index;
    int var1;
    int part;
    Struct_ov015_0218b828_3* entry = func_ov015_02193160(self, self->page_, &position);
    var1 = 0;
    part = 0;
    switch (self->page_)
    {
    case 15:
        func_ov015_0218ffa8((Struct_ov015_0218ffa8*)self->current_, (unsigned char)entry->id_);
        break;
    case 17:
        part = 2;
        var1 = 1;
        break;
    case 18:
        var1 = 1;
        break;
    case 19:
        var1 = 1;
        break;
    case 21:
        var1 = 1;
        break;
    case 25:
        part = 1;
        var1 = 1;
        break;
    case 27:
        part = 8;
        var1 = 1;
        break;
    case 28:
        part = 9;
        var1 = 1;
        break;
    case 22:
        part = 7;
        var1 = 1;
        break;
    case 20:
        part = 3;
        var1 = 1;
        break;
    case 24:
        part = 5;
        var1 = 1;
        break;
    case 26:
        part = 6;
        var1 = 1;
        break;
    case 23:
        var1 = 1;
        break;
    case 16:
        var1 = 1;
        break;
    case 30:
    case 31:
    case 32:
        func_ov015_0218f308(self->current_, entry->file_);
        self->menu_ = 1;
        func_ov015_02192700(self, 0);
        self->current_->motion_ = 0;
        func_ov015_021900dc((Struct_ov015_021900dc*)self->current_);
        break;
    }
    if (!var1)
        return;
    for (Struct_ov015_02190e88* node = self->objects_; node != NULL; node = node->unknown_4_)
    {
        if (self->page_ == 18)
        {
            func_ov015_0218ffd0((Struct_ov015_0218ffd0*)node->object_, (unsigned char)entry->id_);
        }
        else if (self->page_ == 19)
        {
            func_ov015_0218fff8((Struct_ov015_0218fff8*)node->object_, (unsigned char)entry->id_);
        }
        else if (self->page_ == 21)
        {
            func_ov015_02190020((Struct_ov015_02190020*)node->object_, entry->id_);
        }
        else if (self->page_ == 20)
        {
            func_ov015_0218ff7c((Struct_ov015_0218ff7c*)node->object_, (unsigned char)part, entry->id_);
            func_ov015_0218ff7c((Struct_ov015_0218ff7c*)node->object_, 4, entry->id_);
        }
        else if (self->page_ == 23)
        {
            func_ov015_0218ff7c((Struct_ov015_0218ff7c*)node->object_, (unsigned char)part, entry->id_);
            PartEntry* skin = func_020deda4((int)&self->parts_, 0x61,
                (Fields020deda4*)ItemTable_Find((ItemTable*)&self->parts_, (short)node->object_->parts_[0]));
            if (skin != NULL)
                func_ov015_0218ff7c((Struct_ov015_0218ff7c*)node->object_, 5, skin->unknown_18_);
            else
                func_ov015_0218ff7c((Struct_ov015_0218ff7c*)node->object_, 5, 0x36b0);
        }
        else if (self->page_ == 16)
        {
            if (self->current_->female_ == 0)
            {
                switch (entry->id_)
                {
                case 0:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xeb8, 0x109f);
                    break;
                case 1:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xe35, 0x1028);
                    break;
                case 2:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xf0a, 0xfae);
                    break;
                case 3:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0x1024, 0xf33);
                    break;
                case 4:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xf1e, 0xeb4);
                    break;
                }
            }
            else
            {
                switch (entry->id_)
                {
                case 0:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xeb8, 0x1051);
                    break;
                case 1:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xe39, 0xffb);
                    break;
                case 2:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xee1, 0xf85);
                    break;
                case 3:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0x1024, 0xf33);
                    break;
                case 4:
                    func_ov015_0219005c((Struct_ov015_0219005c*)node->object_, 0xeb8, 0xeb4);
                    break;
                }
            }
        }
        else
        {
            func_ov015_0218ff7c((Struct_ov015_0218ff7c*)node->object_, (unsigned char)part, entry->id_);
        }
    }
}
