#include <globaldefs.h>

struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int func_02042190(int x);

struct Struct_ov004_0216af24 {
    char pad0[0x20];
    void* field20;
    char pad1[0x36 - 0x24];
    unsigned short unknown_36_;
    short field38;
    char pad2[0x44 - 0x3a];
    unsigned char field44 : 4;
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Struct_ov004_0216af24* func_ov023_021f6880(void* obj, int key);
extern "C" int func_ov024_021f6f10(void* self);
extern "C" void* func_ov023_021fa598(void* p);
extern "C" int Font_GetTextWidth(void* value, int flag);

// USA: func_ov004_0216af24
extern "C" ARM int func_ov004_0216af24(void* a, int key) {
    void* obj = func_ov011_021849c8(a);
    Struct_ov004_0216af24* node = func_ov023_021f6880(obj, key);
    if (!node) {
        return 0;
    }
    void* entry = node->field20;
    if (!entry) {
        Struct_ov004_0216af24* node2 = func_ov023_021f6880(obj, node->unknown_36_);
        if (func_ov024_021f6f10(node2) == 4) {
            struct TableA68* table = (struct TableA68*)func_ov023_021fa598(node2);
            entry = func_02072a68(table, node->field38);
        }
    }
    int result = 0;
    if (entry) {
        result = Font_GetTextWidth(entry, func_02042190(node->field44));
    }
    return result;
}
