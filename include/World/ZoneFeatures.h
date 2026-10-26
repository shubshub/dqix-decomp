#pragma once

#include "../Graphics/Vector.h"
#include "../Memory/SafeAllocator.h"
#include "../NitroSDK/Memory.h"
#include "../Grotto/Main/TileFeatures.h"

union Struct_02014900
{
    fix32_t unknown_0_[3];
    Vector3fix unknown1_0_;
};

// I don't know what this is, but in practice it gets populated from a pair
// of vector3s (a, b). The resulting vector component is b - a normalized, and
// the scalar is the inner product of a with said normalized vector. The only
// thing I can think of that looks like this is a representation of a plane
// in 3D space...?
struct Struct_0201d044
{
    Struct_02014900 unknown_0_;
    fix32_t unknown_c_;

    // copy assignment operator, but it's explicitly defined?!
    // if we make it implicit, it gets placed too early in the TU
    // defining as operator= works but causes trouble on other compilers
    // when put in a union
    MaybeVector4fix& CopyFrom(const MaybeVector4fix& other);
};

// ZoneFeatures::Opcode6aEntry type2 (a door) flags. 0x4, 0x8, 0x80 and 0x100 are not named yet.
enum DoorFlag {
    DoorFlag_Open = 0x1,            // Zone3D_OpenDoor sets it on the door and every entry with its node and element
    DoorFlag_TurnBackward = 0x2,    // it turns to angle - turn instead of angle + turn (opening and closing)
    DoorFlag_Slides = 0x20,         // it slides by slideDistance instead of turning
    DoorFlag_QuarterTurn = 0x40,    // it turns a quarter turn (FIX_2PI / 4) instead of FIX_2PI / 5
    DoorFlag_NotSaved = 0x200,      // Zone3D_OpenDoor skips ZoneRecord_SetDoorOpened
};

class ZoneFeatures
{
public:
    struct Struct_020146fc
    {
        int unknown_0_;
        Struct_02014900 unknown_4_;
        char unknown_10_[0x10];
        char unknown_20_[0x10];
        char unknown_30_[0x10];
        int unknown_40_[6];
    };

    struct Struct_0201c96c
    {
        fix32_t unknown_0_[6];
        int unknown_18_[2];
        fix16_t unknown_20_; 
    };

    struct Struct_0201cb60_3
    {
        int unknown_0_;
        int unknown_4_[6];
        int unknown_1c_;
        Vector3fix unknown_20_[4];
        short unknown_50_;
        short unknown_52_;
        int unknown_54_;
        int unknown_58_[3];
        int unknown_64_[2];
        int unknown_6c_;

        void func_0201ce10();
    };

    // Used by opcodes 6a, 6b, 73, 74
    struct Struct_02018300
    {
        unsigned short unk_0;
        int maybeType;
        WrappedVector3fix unk_8;
        WrappedVector3fix unk_14;
        short angle;                // a door's angle (Zone3D_OpenDoor), a chest's angleY (func_0201afd0), a path
                                    // node's heading (GameObject_PlaceInZone)
        short unk_22;
        int unk_24;
        int unk_28;
        union
        {
            struct {
                unsigned char unknown_0_;
            } unknown_0_;
            struct {
                unsigned char nodeId;       // the BMDJ script node holding the door (Zone3D_FindDoorElement)
                unsigned char elementId;    // the door's scene element in that node
                unsigned short soundIndex : 4;  // which Zone3D_doorSounds entry opening it plays
                unsigned short flags : 12;      // DoorFlag
                unsigned short maybeZone;
                unsigned short unk_6;
                unsigned short unk_8;
                char padding_a[2];
                Vector3fix vectors_c[4];
                fix16_t unk_3c;
                fix16_t unk_3e;
                fix32_t slideDistance;      // how far a DoorFlag_Slides door moves (Zone3D_OpenDoor, func_02018918)
            } type2;
            struct {
                unsigned char unknown_0_;
            } unknown2_0_;
            struct {
                unsigned char unknown_0_0_ : 7;
                unsigned char unknown_0_7_ : 1;
                char unknown_1_;
                char unknown_2_[2];
                Struct_0201d044 unknown_4_;
                fix32_t unknown_14_;
                Vector3fix unknown_18_;
                Vector3fix unknown_24_;
                Vector3fix unknown_30_;
            } unknown3_0_;
            struct {
                unsigned short unk_0;
                unsigned short unk_2;
                unsigned short cupboardContainerId; // the uniqueID of the cupboard container placed at this
                                                    // feature (Zone3D_SetUpContainers)
            } type5;
            struct {
                unsigned short unknown_0_;
                unsigned short unknown_2_;
                unsigned char unknown_4_;
                unsigned char unknown_5_;
                unsigned short unknown_6_;
                unsigned short unknown_8_;
                unsigned short unknown_a_;
                Vector3fix unknown_c_;
                Vector3fix unknown_18_;
                Vector3fix unknown_24_;
                Vector3fix unknown_30_;
                fix16_t unknown_3c_;
                fix16_t unknown_3e_;
                fix16_t unknown_40_;
                unsigned short unknown_42_;
            } unknown5_0_;
            struct {
                unsigned short unknown_0_;
                fix16_t unknown_2_;
                Vector3fix unknown_4_;
                fix32_t unknown_10_;
                Vector3fix unknown_14_;
                fix16_t unknown_20_;
            } unknown6_0_;
            struct {
                unsigned char unknown_0_;
                unsigned char unknown_1_;
                unsigned char unknown_2_;
                char unknown_3_;
                union
                {
                    struct {
                        unsigned char unknown_0_;
                        unsigned char unknown_1_;
                        unsigned char unknown_2_;
                        unsigned char unknown_3_;
                        unsigned char unknown_4_;
                        unsigned char unknown_5_;
                    } unknown_4_;
                    struct {
                        unsigned char unknown_0_;
                        fix32_t unknown_4_;
                        fix32_t unknown_8_;
                        fix32_t unknown_c_;
                        unsigned char unknown_10_;
                    } unknown1_4_;
                    struct {
                        unsigned char unknown_0_;
                        unsigned char unknown_1_;
                        fix32_t unknown_4_;
                        fix32_t unknown_8_;
                        fix32_t unknown_c_;
                        fix32_t unknown_10_;
                    } unknown2_4_;
                };
            } unknown7_0_;
        } unknown_2c_;
        Struct_02018300* unknown_70_;

        void func_0201d424();
    };

    struct Struct_0201dfcc
    {
        Struct_02014900 unknown_0_;
        Struct_02014900 unknown_c_;
        fix16_t unknown_18_;
        char unknown_1a_[2];
        fix32_t unknown_1c_;
        fix32_t unknown_20_;
        fix32_t unknown_24_;
        fix32_t unknown_28_;
    };

    Struct_020146fc* unknown_0_;
    int unknown_4_;
    int unknown_8_;

    Struct_0201c96c* unknown_c_;
    int unknown_10_;
    int unknown_14_;

    Struct_0201cb60_3* unknown_18_;
    int unknown_1c_;
    int unknown_20_;

    Struct_02018300* unknown_24_;
    int unknown_28_;
    int unknown_2c_;

    TileFeaturePlacementData* unknown_30_;
    int unknown_34_;
    int unknown_38_;

    Struct_02018300* unknown_3c_[13];

    Vector3fix unknown_70_;
    fix16_t unknown_7c_;
    // not sure what this is used for. In outdoor areas it tends to be blue
    // (0, 5, 30) but in caves it's black. It isn't background color though
    uint16_t unknown_7e_;

    unsigned short unknown_80_;
    unsigned short unknown_82_;
    Struct_0201dfcc* unknown_84_;

    void Reset();

    void AllocateOpcode64Entries(int count, SafeAllocator* alloc);
    void AllocateGrottoTileFeaturePlacementEntries_0201e288(int count, SafeAllocator* alloc);

    void LoadFromScript(SafeAllocator* alloc, const void* script, unsigned int length);
    Opcode64Entry* GetOpcode64Entry(int index);

    void CreateOpcode64Entry(const Opcode64Entry& data);
    void CreateGrottoTileFeaturePlacementEntry_0201e3c4(const TileFeaturePlacementData& data);

    void AllocateOpcode66Entries(int count, SafeAllocator* alloc);
    void CreateOpcode66Entry(const Opcode66Entry& data);

    void AllocateExits(int count, SafeAllocator* alloc);
    void CreateExit(const Opcode68Entry& data);

    void AllocateOpcode6aEntries(int count, SafeAllocator* alloc);
    Opcode6aEntry* CreateOpcode6aEntry(const Opcode6aEntry& data);
    // not real, just here for testing purposes
    Opcode6aEntry* CreateOpcode6aEntry(const Opcode6aEntry& data, int fakeArg);

    void SetHeadingLockAreas(Opcode7bEntry* array, unsigned short capacity);
    void CreateOpcode7bEntry_0201e88c(const Opcode7bEntry& data);
};

ZoneFeatures::Opcode6aEntry* ZoneFeatures_FindEntry(void* features, int type, int id);
ZoneFeatures::Opcode6aEntry* ZoneFeatures_FindLadderNode(ZoneFeatures* features, int id);
ZoneFeatures::Opcode6aEntry* ZoneFeatures_GetEntry(ZoneFeatures* features, int index);
void* ZoneFeatures_GetExit(ZoneFeatures* features, int index);
