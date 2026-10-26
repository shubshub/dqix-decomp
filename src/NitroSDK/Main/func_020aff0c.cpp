#include <globaldefs.h>
struct Struct_020aff0c_3 {
    unsigned char* data;
    unsigned int unknown_4_;
};
struct Struct_020aff0c {
    unsigned short count;
    unsigned short field_0x2;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    Struct_020aff0c_3* frames;
};
struct Struct_020aff0c_2 {
    unsigned short count;
    unsigned short field_0x2;
    void* data;
    void** items;
};
struct Struct_020aff0c_4 {
    unsigned short count;
    unsigned short field_0x2;
    Struct_020aff0c_2* unknown_4_;
};
struct Struct_020aff0c_5 {
    unsigned int field_0x0;
    unsigned int unknown_4_;
    Struct_020aff0c_4 extra;
};
struct Struct_020aff0c_6 {
    unsigned short count;
    unsigned short field_0x2;
    Struct_020aff0c* unknown_4_;
    Struct_020aff0c_3* frames;
    unsigned char* data;
    unsigned int field_0x10;
    Struct_020aff0c_5* extension;
};
// USA: func_020aff0c
extern "C" ARM void func_020aff0c(Struct_020aff0c_6* bank) {
    bank->unknown_4_ = (Struct_020aff0c*)((unsigned int)bank->unknown_4_ + (unsigned int)bank);
    bank->frames = (Struct_020aff0c_3*)((unsigned int)bank->frames + (unsigned int)bank);
    bank->data = (unsigned char*)((unsigned int)bank->data + (unsigned int)bank);
    unsigned short i;
    unsigned short var1;
    Struct_020aff0c* var2;
    Struct_020aff0c_3* frames;
    unsigned char* data;
    data = bank->data;
    i = 0;
    var2 = bank->unknown_4_;
    frames = bank->frames;
    if ((unsigned int)bank->count > i) do {
        var2[i].frames = (Struct_020aff0c_3*)((unsigned int)var2[i].frames + (unsigned int)frames);
        var1 = 0;
        if ((unsigned int)var2[i].count > var1) do {
            var2[i].frames[var1].data = (unsigned char*)((unsigned int)var2[i].frames[var1].data + (unsigned int)data);
            var1++;
        } while (var2[i].count > var1);
        i++;
    } while (bank->count > i);
    if (!bank->extension) return;
    bank->extension = (Struct_020aff0c_5*)((unsigned int)bank->extension + (unsigned int)bank);
    Struct_020aff0c_4* extra = &bank->extension->extra;
    extra->unknown_4_ = (Struct_020aff0c_2*)((unsigned int)extra->unknown_4_ + (unsigned int)extra);
    unsigned int index = 0;
    unsigned int var7;
    Struct_020aff0c_2* var8;
    if (extra->count > index) {
        unsigned int var9 = 0;
        do {
            var8 = (Struct_020aff0c_2*)((unsigned char*)extra->unknown_4_ + var9);
            var8->data = (void*)((unsigned int)var8->data + (unsigned int)extra);
            var8->items = (void**)((unsigned int)var8->items + (unsigned int)extra);
            var7 = 0;
            if (var8->count > var7) {
                unsigned int var10 = 0;
                do {
                    var7++;
                    *(unsigned int*)((unsigned char*)var8->items + var10) += (unsigned int)extra;
                    var10 += 4;
                } while (var7 < var8->count);
            }
            index++;
            var9 += 12;
        } while (index < extra->count);
    }
}
