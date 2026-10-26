#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_0200ff58(GameState*,int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int func_ov000_021761c8(char*,int);
extern "C" int func_ov000_021761ec(char*,int);
extern "C" void func_ov017_021c6a9c(unsigned short, int, int, unsigned char, unsigned char, signed char);
struct Struct_ov000_02175be4 {
    char p0[0x1d]; signed char selection; char p1[8]; unsigned short key;
    char p2[6]; signed char state;
};
struct Struct_ov000_02175be4_2 {
    unsigned short keys[4]; signed char unknown_8_[4],states[4];
    char p0[0xb]; signed char phase; char p1[8]; unsigned short event;
};
struct Struct_ov000_02175be4_3 { unsigned short key; unsigned char indices[4],count,pad; };
struct Struct_ov000_021833a8 { short v[4]; };
extern "C" {
Struct_ov000_02175be4* func_ov000_02161318(void*,int);
void func_ov000_02170db0(Struct_ov000_02175be4*);
int rand();
extern const Struct_ov000_021833a8 data_ov000_021833a8;
}

static inline short inline_ov000_02175be4(Struct_ov000_02175be4* node) { return (short)node->key; }

// USA: func_ov000_02175be4
extern "C" ARM void func_ov000_02175be4(Struct_ov000_02175be4_2* obj) {
    GameState* gs = GameState::GetInstance();
    for (signed char i=0;i<4;i++) {
        if (!func_0200ff58(gs,i)) func_ov000_02161318(obj,i);
    }
    if (obj->phase != GameState_GetProtagonistIndex(gs)) return;
    unsigned char count = 0;
    short keys[4] = {0};
    Struct_ov000_021833a8 var4(data_ov000_021833a8);
    for (signed char i=0;i<4;i++) {
        if (!func_0200ff58(gs,i)) {
            Struct_ov000_02175be4* node = func_ov000_02161318(obj,i);
            if (node) {
                keys[count] = node->key;
                var4.v[count] = node->selection;
                count++;
            }
        }
    }
    Struct_ov000_02175be4_3 groups[4];
    int choices[4];
    memset(groups,0,sizeof(groups));
    int groupCount=0;
    short* var10=keys;
    for (int i=0;i<count;var10++,i++) {
        Struct_ov000_02175be4_3* group;
        int var13,j;
        int key=*var10;
        if (key>=0) {
            group=groups;
            var13=1;
            for (j=0;j<groupCount;group++,j++) {
                if (group->key==key) {var13=0;break;}
            }
            group->key=key;
            if (var13) groupCount++;
            group->indices[group->count]=i;
            group->count++;
        }
    }
    Struct_ov000_02175be4_3* current;
    int key=-1;
    Struct_ov000_02175be4_3* var18=0;
    int maximum=0;
    current=groups;
    for (int i=0;i<groupCount;current++,i++) {
        if (maximum<current->count) {
            maximum=current->count;
            var18=current;
            key=(short)current->key;
        } else if (maximum==current->count) key=-1;
    }
    if (key==-1) key=0;
    short selected=0;
    if (key && var18) {
        int n=0;
        for (int i=0;i<var18->count;i++) {
            unsigned int index=((unsigned char*)var18+i)[2];
            if (index<4) { choices[n]=var4.v[index]; n++; }
        }
        if (n>0) selected=choices[rand()%n];
    }
    if (selected==-1) selected=var4.v[0];
    if (!key) {
        for (unsigned char i=0;i<4;i++) {
            Struct_ov000_02175be4* node=func_ov000_02161318(obj,i);
            if (node) {
                node->key=obj->keys[i];
                node->selection=obj->unknown_8_[i];
                node->state=obj->states[i];
                func_ov000_02170db0(node);
            }
        }
    } else {
        for (unsigned char i=0;i<4;i++) {
            Struct_ov000_02175be4* node=func_ov000_02161318(obj,i);
            if (node) {
                node->key=(unsigned short)key;
                node->selection=(signed char)selected;
                node->state=-1;
                func_ov000_02170db0(node);
            }
        }
    }
    for (signed char i=0;i<4;i++) {
        Struct_ov000_02175be4* node=func_ov000_02161318(obj,i);
        if (node) {
            unsigned char a=func_ov000_021761c8((char*)obj,node->selection);
            unsigned char b=func_ov000_021761ec((char*)obj,node->selection);
            func_ov017_021c6a9c(obj->event, i, (unsigned short)inline_ov000_02175be4(node), a, b, node->state);
        }
    }
}
