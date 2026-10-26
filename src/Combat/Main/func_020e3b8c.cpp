#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020e3b8c_15364 = 0x39e4, kListOffset = 0x34f4 };
#else
enum { Enum_020e3b8c_15364 = 0x3c04, kListOffset = 0x3704 };
#endif


struct ListNode02046b38 {
    char pad[4];
    struct ListNode02046b38* next;
};
struct ListHead02046b38 {
    struct ListNode02046b38* head;
};
extern "C" int func_02046b38(struct ListHead02046b38* list, struct ListNode02046b38* target);

struct Struct_020e3b8c {
    char pad[0x14];
    int arr[2];
};
extern "C" void func_020e3ed8(struct Struct_020e3b8c* p);

struct CombatState020e3c34 {
    unsigned char header;
    unsigned char pad1[7];
    unsigned char byte8;
    unsigned char byte9;
    unsigned short unknown_a_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_[2];
    int unknown_1c_;
    int word_20;
    unsigned char unknown_24_;
};
extern "C" void func_020e3c34(struct CombatState020e3c34* obj);

struct TailNode020469b4 {
    char unk0[2];
    unsigned char inList;
    char unknown_3_;
    struct TailNode020469b4* next;
};
struct TailList020469b4 {
    struct TailNode020469b4* head;
    struct TailNode020469b4* tail;
};
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

extern "C" void func_02046a8c(void* list, void* node);

// USA: func_020e3b8c
extern "C" ARM void func_020e3b8c(char* mgr, int index, int p3, int p4, int p5, int p6, int p7, unsigned char p8)
{
    struct CombatState020e3c34* e = (struct CombatState020e3c34*)(mgr + Enum_020e3b8c_15364 + index * (int)sizeof(struct CombatState020e3c34));

    if (func_02046b38(*(struct ListHead02046b38**)(mgr + kListOffset), (struct ListNode02046b38*)e)) {
        func_020e3ed8((struct Struct_020e3b8c*)e);
        func_02046a8c(*(void**)(mgr + kListOffset), e);
    }

    func_020e3c34(e);

    e->byte9 = (unsigned char)index;
    e->unknown_a_ = (unsigned short)p3;
    e->unknown_c_ = p4;
    e->byte8 = (p5 != 0) ? 1 : 0;
    e->word_20 = p6;
    e->unknown_10_ = p7;
    e->unknown_24_ = p8;

    func_020469b4(*(struct TailList020469b4**)(mgr + kListOffset), (struct TailNode020469b4*)e);
}
