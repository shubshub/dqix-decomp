#pragma once



struct Struct_020fe6fc {
#if defined(jpn)
    int unknown_4_;
    void* buffer;
#else
    void* buffer;
    int unknown_4_;
#endif
};

#if defined(jpn)
extern Struct_020fe6fc data_020fe6fc;
#define glyphBitmapContext data_020fe6fc
#else
extern Struct_020fe6fc data_020fe9a4;
#define glyphBitmapContext data_020fe9a4
#endif
