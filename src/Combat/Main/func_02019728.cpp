#include <globaldefs.h>
#include "World/Zone3D.h"

struct Struct_02019728 {
    unsigned char unknown_0_;
};

extern "C" {
void __clear(void* arg0, int arg1);
int sprintf(char* arg0, const char* arg1, ...);
}

extern const char data_020ef26f[];
extern const char data_020ef274[];
extern const char data_020ef279[];
extern const char data_020ef27e[];
extern const char data_020ef283[];
extern const char data_020ef288[];
extern const char data_020ef28d[];
extern const char data_020ef292[];
extern const char data_020ef297[];
extern const char data_020ef29c[];
extern const char data_020ef2a1[];
extern const char data_020ef2a6[];
extern const char data_020ef2ab[];
extern const char data_020ef2b0[];
extern const char data_020ef2b5[];

extern "C" void func_02019f6c(void* arg0, unsigned char* arg1, int arg2);

static inline Struct_02019728 inline_02019728(const FloorMap* arg0, int arg1, int arg2) {
    Struct_02019728 var0;
    var0.unknown_0_ = arg0->GetAdjacencyBits(arg1, arg2);
    return var0;
}

// USA: func_02019728
extern "C" ARM int func_02019728(Zone3D* arg0, int arg1, Struct_020134e0* arg2, TileFeaturePlacementData* arg3, FloorMap* arg4)
{
    char var0[8];
    Struct_020134e0* var1 = arg2 ? arg2 : &arg0->substruct_6c_;
    FloorMap* var2 = arg4 ? arg4 : &arg0->grotto_.floorMap_;
    int var3;
    int var4;

    __clear(var0, 8);
    var3 = 0;

    for (var4 = 0; var4 < 16; var4++) {
        int var5;
        for (var5 = 0; var5 < 16; var5++) {
            Struct_02019728 var6;
            Matrix3x3 var7;
            Struct_02013490* var8;
            TileFeaturePlacementData* var9;
            int var10;
            int var11;

            var6 = inline_02019728(var2, var5, var4);
            var8 = &arg0->grottoTileMapData_420_[var4 * 16];
            var8 = &var8[var5];
            Mat3x3_WriteIdentity(&var7);

            switch (var6.unknown_0_) {
            case 0xff:
                var3 = 0xc;
                sprintf(var0, data_020ef26f);
                break;
            case 0xbb: case 0xee:
                var3 = 3;
                sprintf(var0, data_020ef274);
                break;
            case 0xaf: case 0xbe: case 0xeb: case 0xfa:
                var3 = 2;
                sprintf(var0, data_020ef279);
                break;
            case 0xaa:
                var3 = 1;
                sprintf(var0, data_020ef27e);
                break;
            case 0xab: case 0xae: case 0xba: case 0xea:
                var3 = 0;
                sprintf(var0, data_020ef283);
                break;
            case 0xbf: case 0xef: case 0xfb: case 0xfe:
                var3 = 0xd;
                sprintf(var0, data_020ef288);
                break;
            case 0x0e: case 0x38: case 0x83: case 0xe0:
                var3 = 0xa;
                sprintf(var0, data_020ef28d);
                break;
            case 0x3e: case 0x8f: case 0xe3: case 0xf8:
                var3 = 9;
                sprintf(var0, data_020ef292);
                break;
            case 0x02: case 0x08: case 0x20: case 0x80:
                var3 = 8;
                sprintf(var0, data_020ef297);
                break;
            case 0x00:
                var3 = 7;
                sprintf(var0, data_020ef29c);
                break;
            case 0x22: case 0x88:
                var3 = 6;
                sprintf(var0, data_020ef2a1);
                break;
            case 0x0a: case 0x28: case 0x82: case 0xa0:
                var3 = 0x11;
                sprintf(var0, data_020ef2a6);
                break;
            case 0x3a: case 0x8e: case 0xa3: case 0xe8:
                var3 = 0x10;
                sprintf(var0, data_020ef2ab);
                break;
            case 0x2e: case 0x8b: case 0xb8: case 0xe2:
                var3 = 0xf;
                sprintf(var0, data_020ef2b0);
                break;
            case 0x2a: case 0x8a: case 0xa2: case 0xa8:
                var3 = 0xe;
                sprintf(var0, data_020ef2b5);
                break;
            }

            if (grid == 0) {
                cell->node = Zone3D_GetScriptNode(obj, n);
                entry = FindEntryByNameSubstr0201e434(list, name);
                if (entry != 0) {
                    CopyStruct02019f24(&cell->info, entry);
                }
            } else {
                var9 = func_0201e434(var1, var0);
                if (var9 != 0 && arg3 != 0) {
                    func_02019f24(&(arg3 + var4 * 16)[var5], var9);
                }
            }

            var10 = 0;
            var11 = 0;
            switch (var6.unknown_0_) {
            case 0x02: case 0x82: case 0x83: case 0x88: case 0x8a: case 0x8e:
            case 0x8f: case 0xab: case 0xaf: case 0xe2: case 0xee: case 0xef:
                var10 = 0x3243 >> 1;
                Mat3x3_WriteRotationY(&var7, 0x1000, 0);
                var11 = 1;
                break;
            case 0x08: case 0x0a: case 0x0e: case 0x2a: case 0x3a: case 0x3e:
            case 0x8b: case 0xae: case 0xbe: case 0xbf:
                var10 = 0x3243;
                Mat3x3_WriteRotationY(&var7, 0, -0x1000);
                var11 = 2;
                break;
            case 0x20: case 0x28: case 0x2e: case 0x38: case 0xa8: case 0xba:
            case 0xe8: case 0xf8: case 0xfa: case 0xfe:
                var10 = 0x4b65;
                Mat3x3_WriteRotationY(&var7, -0x1000, 0);
                var11 = 3;
                break;
            case 0xff:
                break;
            default:
                var10 = 0;
                break;
            }

            if (arg3 == 0) {
                var8->unknown_38_ = var10;
                func_02019f6c(arg0, var8->unknown_4_.directionBitmasks, var11);
                var8->unknown_3c_.x = (int)(4096.0f * (8.0f * (float)var5));
                var8->unknown_3c_.y = 0;
                var8->unknown_3c_.z = (int)(4096.0f * (8.0f * (float)var4));
                var8->unknown_14_ = var7;
            } else {
                func_02019f6c(arg0, (arg3 + var4 * 16)[var5].directionBitmasks, var11);
            }
        }
    }
    return 1;
}
