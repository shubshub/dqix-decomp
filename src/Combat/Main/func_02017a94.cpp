#include <globaldefs.h>

#include <World/Zone3D.h>
#include <GameState/GameState.h>


extern "C" void* Scenario_GetInstance(void);
void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);
int GetBitmapPixel_0206eaec(unsigned char* base, int row, int col);
void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
int Scenario_RunTriggerCommandsById(void* a, int mode, unsigned short id, void* c);

struct Struct_02017a94;
struct Struct_0201b600;
struct Struct_02017a94_2;
extern "C" struct Struct_02017a94_2* func_0201b600(Struct_02017a94*, int, unsigned short);

struct Struct_02017a94_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned char unknown_4_[0x2b];
};

struct Struct_02017a94_3 {
    unsigned char unknown_0_[0x2d];
    unsigned char unknown_2d_;
    unsigned short unknown_2e_;
    unsigned char unknown_30_[0x70 - 0x30];
    struct Struct_02017a94_3* unknown_70_;
};

struct Struct_02017a94_4 {
    unsigned char unknown_0_[0x0c];
    unsigned int unknown_c_;
    unsigned char unknown_10_[0x30 - 0x10];
    unsigned int unknown_30_;
};

// USA: func_02017a94
extern "C" ARM void func_02017a94(Zone3D* arg0) {
    GameState* var0 = GameState::GetInstance();
    if (var0 == NULL) {
        return;
    }
    if (func_0200fd0c(var0) == NULL) {
        return;
    }
#if defined(jpn)
    enum { Enum_02017a94_10269 = 0x285d };
#else
    enum { Enum_02017a94_10269 = 0x281d };
#endif
    unsigned char* bmp = (unsigned char*)Scenario_GetInstance();
    int row;
    int colLow;
    int colHigh;
    if (bmp != NULL && *(unsigned char*)((char*)zone + BitmapFlagOffset) != 0) {
        for (row = 0; row < 2; row++) {
            for (colLow = 0; colLow < 0x7f; colLow++) {
                if (GetBitmapPixel_0206eaec(bmp, (unsigned char)row, (short)colLow)) {
                    struct FeatureElem02017a94* e =
                        FindElemByKeys((struct Obj0201b600*)zone, row, colLow);
                    if (e != NULL) {
                        e->flags &= ~4;
                    }
                }
            }
            for (colHigh = 0x80; colHigh < 0xff; colHigh++) {
                if (GetBitmapPixel_0206eaec(bmp, (unsigned char)row, (short)colHigh)) {
                    struct FeatureElem02017a94* e =
                        FindElemByKeys((struct Obj0201b600*)zone, row, colHigh - 0x80);
                    struct FeatureNode02017a94* n;
                    if (e != NULL) {
                        e->flags |= 4;
                        if ((e->flags & 8) != 0) {
                            unsigned int cur;
                            unsigned short mask;
                            e->flags |= 1;
                            n = (struct FeatureNode02017a94*)
                                ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, 2);
                            while (n != NULL) {
                                if (n->id2d == e->key) {
                                    cur = n->field2e;
                                    mask = (unsigned short)(((cur << 16) >> 20) | 1);
                                    n->field2e = (cur & 0xffff000f) | ((unsigned int)(mask << 20) >> 16);
                                    break;
                                }
                                var7 = var7->unknown_70_;
                            }
                        }
                    }
                }
            }
        }
        struct AppendContext02017a94 ctx;
        ctx.zoneId = zone->currentZoneID_;
        Scenario_RunTriggerCommandsById(bmp, 3, 0x6c, &ctx);
        Scenario_RunTriggerCommandsById(bmp, 0x14, 0x6c, &ctx);
        zone->unk_276c[0x281d - 0x276c] = 0;
    }
}
