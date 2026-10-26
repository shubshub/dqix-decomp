#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct {
    int unknown_0_;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    char pad[0x400];
    unsigned char unknown_42c_;
};

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);

extern int data_020f05bc;

struct Obj02064574 {
    char pad[0x480];
    int unknown_480_;
    int unknown_484_;
    int unknown_488_;
    int unknown_48c_;
};

struct Struct_02064574 {
    char pad0[0xc];
    int fieldC;
    char pad2[0x24];
};

// Main, originally SomeInit02064574 (USA 0x02064574, EUR 0x02064584, JPN 0x02065860)
extern "C" ARM void Scenario_LoadTriggers(struct Obj02064574* obj, int p1, struct StreamHeader* p2, int p3, int p4, int p5, int p6) {
    if (p1 != 0 && p2 != 0 && p3 != 0) {
        obj->unknown_480_ = p1;
        obj->unknown_484_ = p4;
        obj->unknown_488_ = p5;
        obj->unknown_48c_ = p6;
        struct ResetStruct local;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f05bc);
        ((Script*)((struct StreamState*)&local))->Load(p2, p3);
        ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
        struct Struct_02064574 c;
        c.fieldC = p4;
        if (Scenario_RunTrigger(obj, 0x14, &c)) {
            EventQuery_RunQueuedCommands(&c);
        }
    }
}
