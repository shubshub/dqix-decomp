#include <globaldefs.h>
#include <Graphics/Vector.h>
#include <std_library_functions.h>

struct Struct_ov004_021561b0 {
    virtual void inline_ov004_021561b0_14();
    virtual void inline_ov004_021561b0_24();
    virtual void inline_ov004_021561b0_26();
    virtual void inline_ov004_021561b0_27();
    virtual void inline_ov004_021561b0_28();
    virtual void inline_ov004_021561b0_29();
    virtual void inline_ov004_021561b0_30();
    virtual void inline_ov004_021561b0_31(const Vector3fix*);
    virtual Vector3fix inline_ov004_021561b0_32();
    virtual void inline_ov004_021561b0_33();
    virtual void inline_ov004_021561b0_34();
    virtual void inline_ov004_021561b0_35();
    virtual void inline_ov004_021561b0_36();
    virtual void inline_ov004_021561b0_37();
    virtual void inline_ov004_021561b0_38();
    virtual void inline_ov004_021561b0_39();
    virtual void inline_ov004_021561b0_40();
    virtual void inline_ov004_021561b0_41();
    virtual void inline_ov004_021561b0_42();
    virtual void inline_ov004_021561b0_43();
    virtual void inline_ov004_021561b0_44();
    virtual void inline_ov004_021561b0_45();
    virtual void inline_ov004_021561b0_46();
    virtual void inline_ov004_021561b0_47();
    virtual void inline_ov004_021561b0_48();
    virtual void inline_ov004_021561b0_49();
    virtual void inline_ov004_021561b0_50();
    virtual void inline_ov004_021561b0_51();
    virtual void inline_ov004_021561b0_52();
    virtual void inline_ov004_021561b0();
    virtual void inline_ov004_021561b0_2();
    virtual void inline_ov004_021561b0_3();
    virtual void inline_ov004_021561b0_4();
    virtual void inline_ov004_021561b0_5();
    virtual void inline_ov004_021561b0_6();
    virtual void inline_ov004_021561b0_7();
    virtual void inline_ov004_021561b0_8();
    virtual void inline_ov004_021561b0_9();
    virtual void inline_ov004_021561b0_10();
    virtual void inline_ov004_021561b0_11();
    virtual void inline_ov004_021561b0_12();
    virtual void inline_ov004_021561b0_13();
    virtual void inline_ov004_021561b0_15();
    virtual void inline_ov004_021561b0_16();
    virtual void inline_ov004_021561b0_17();
    virtual void inline_ov004_021561b0_18();
    virtual void inline_ov004_021561b0_19();
    virtual void inline_ov004_021561b0_20();
    virtual void inline_ov004_021561b0_21();
    virtual void inline_ov004_021561b0_22();
    virtual void inline_ov004_021561b0_23(const Vector3fix*);
    virtual Vector3fix inline_ov004_021561b0_25();
    char unknown_4[8];
    unsigned char flags;
    char unknown_d_[0x20 - 0xd];
    char* text;
    char unknown_24_[0x104 - 0x24];
    short page, column;
};
struct Struct_ov004_02153e20 {
    char unknown_0[0x5c];
    short page, column;
    unsigned char unknown_60_;
    unsigned char unknown_61_;
};
struct Struct_ov004_021561b0_2 { char bytes[0x100]; };
struct Struct_ov004_021561b0_3 {
    Struct_ov004_021561b0_2 pages[15];
    Struct_ov004_021561b0_2 scratch;
};
struct Struct_ov004_021707c8 {
    Struct_ov004_021561b0_3* buffers;
    void* unknown_4_;
    short* keys;
    void* entries;
};
struct TableA68;
extern Struct_ov004_021707c8 data_ov004_021707c8;
extern char data_ov004_02170398[];
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" TableA68* func_ov023_021fa598(void*);
extern "C" void* MessageSystem_GetInstance();
extern "C" void* func_02072a68(TableA68*, int);
extern "C" void MessageSystem_FormatText(void*, int, void*, char*, int, int, int);
extern "C" char* func_020d2f88(char*, char*);
extern "C" void func_ov023_021f9b30(Struct_ov004_02153e20*, short, unsigned int, unsigned int);
typedef void (*Type_ov004_021561b0)(Struct_ov004_02153e20*, unsigned short, unsigned int, unsigned int);
typedef void (*Type_ov004_021561b0_2)(char*, unsigned short, unsigned short);
extern "C" void func_ov023_021f9d14(Struct_ov004_02153e20*, void*);
extern "C" void func_ov023_021f8960(char*, short, unsigned short);
extern "C" void func_ov023_021f809c(void*, void*);
extern "C" int func_ov004_021560e8(void*);

// USA: func_ov004_021561b0
extern "C" ARM int func_ov004_021561b0(void* object) {
    void* base = func_ov011_021849c8(object);
    short page;
    Struct_ov004_02153e20* grid = (Struct_ov004_02153e20*)func_ov023_021f6880(base, 3);
    if (!grid) return 0;
    if (func_ov023_021f6f10(grid) != 7) return 0;
    page = grid->page;
    short column = grid->column;
    void* var4 = func_ov023_021f6880(base, 11);
    if (!var4) return 0;
    if (func_ov023_021f6f10(var4) != 4) return 0;
    TableA68* table = func_ov023_021fa598(var4);
    memset(data_ov004_021707c8.buffers, 0, 0x1000);
    short var6 = page * 12;
    int count = 0;
    Struct_ov004_021561b0_3* buffers = data_ov004_021707c8.buffers;
    int padding;
    for (short i = 0; i < 12; i++) {
        int id = i + 0x6e;
        Struct_ov004_021561b0* node = (Struct_ov004_021561b0*)func_ov023_021f6880(base, id);
        if (!node || func_ov023_021f6f10(node) != 8) continue;
        node->text = NULL;
        node->flags &= ~8;
        int index = i + var6;
        if (data_ov004_021707c8.keys[index] > 0) {
            void* context = MessageSystem_GetInstance();
            memset(buffers->scratch.bytes, 0, 0x100);
            void* entry = func_02072a68(table, data_ov004_021707c8.keys[index]);
            MessageSystem_FormatText(context, 0, entry, buffers->scratch.bytes, 0x60, 0, 0);
            Vector3fix position = node->inline_ov004_021561b0_32();
            Vector3fix offset = node->inline_ov004_021561b0_25();
            int y = (i / 2 * 20) << 12;
            padding = 0;
            if (func_020d2f88(buffers->scratch.bytes, data_ov004_02170398)) {
                y -= 0x5000;
                padding = 0x5000;
            }
            position.y = y + 0x8000;
            node->inline_ov004_021561b0_31(&position);
            offset.y = padding - 0x3000;
            node->inline_ov004_021561b0_23(&offset);
            char* text = data_ov004_021707c8.buffers->pages[i].bytes;
            memcpy(text, buffers->scratch.bytes, 0x100);
            ((Type_ov004_021561b0)func_ov023_021f9b30)(grid, (unsigned short)id, (unsigned short)(i >> 1), i & 1);
            node->text = text;
            count++;
        } else {
            func_ov023_021f9b30(grid, 0, (unsigned short)(i >> 1), i & 1);
            node->flags |= 8;
        }
    }
    if (count == 0) func_ov023_021f9b30(grid, 0x6e, 0, 0);
    func_ov023_021f9d14(grid, object);
    grid->unknown_61_ = 0;
    Struct_ov004_021561b0* node = (Struct_ov004_021561b0*)func_ov023_021f6880(base, 0x33);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 6) return 0;
    ((Type_ov004_021561b0_2)func_ov023_021f8960)((char*)node, 0, 0xffff);
    node->page = page;
    node->column = column;
    func_ov023_021f809c(node, object);
    func_ov004_021560e8(object);
    return 0;
}
