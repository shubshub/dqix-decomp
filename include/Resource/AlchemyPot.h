#pragma once

#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_02000c9c_5 {
    char unk_0[0x10];
    int state_;
    unsigned char unk_14;
};

struct Struct_02000c9c {
#if defined(jpn)
    char unk_0[0x6f0];
#else
    char unk_0[0x774];
#endif
    unsigned short flags_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_02000c9c_2 {
    char unk_0[0x7c];
};

struct Struct_02000c9c_3 {
    short id_;
};

struct Struct_02000c9c_4 {
    short id_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char names_[3][0x80];
#endif
    SafeAllocator* allocators_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* previousCamera_;
    void* canvasBuffer_;
    unsigned char* unknown_1a8_;
    void* itemNames_;
    void* texts_;
    Struct_02000c9c_3* unknown_1b4_;
    Struct_02000c9c_3* nextRecipe_;
    int unknown_1bc_;
    Struct_02000c9c_4* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* layout_;
    void* backgrounds_;
    void* canvases_;
    void* menu_;
    void* item_;
    void* nextItem_;
    void* sprites_;
    char renderer_[0x54];
    Object3D unknown_238_;
    Object3D pot_;
    Object3D unknown_390_;
    Object3D effect_;
    Object3D steam_;
    char unknown_594_[0x38];
    char camera_[0x2c8];
    Struct_02000c9c_2 ingredients_[4];
    SafeAllocator unknown_a84_[4];
    int task_;
    int unknown_ad8_;
    unsigned char state_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short flags_;
    Struct_02000c9c window_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char partNames_[0x18];
    Struct_02000c9c_5 unknown_12a0_;
    short itemId_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};
