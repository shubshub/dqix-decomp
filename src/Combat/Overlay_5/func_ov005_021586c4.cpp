#include <globaldefs.h>
#include "GameState/Field3b0.h"

#if defined(jpn)
enum { Enum_ov005_021586c4_1276 = 0x4f8 };
#else
enum { Enum_ov005_021586c4_1276 = 0x4fc };
#endif

#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include "Resource/GameResources.h"


struct Obj021e4e20 { char pad[kMember]; int member; };
struct Body { char pad[0x50]; Vector3fix rotation; };
struct Vec3copy0202ec84;
struct SlotDepth { int depth; int padding[2]; };
Obj021e4e20* GetField1c_021a193c(int*);
Body* RunIfPtr_021e4e20(Obj021e4e20*);
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" double sqrt(double);
extern const Vector3fix data_ov005_0215cc24[8];
extern const Struct_ov005_0215cc2c data_ov005_0215cc2c[8];
extern const unsigned char data_ov005_0215cbf4[8];

// USA: func_ov005_021586c4
extern "C" ARM int func_ov005_021586c4(void*, int x, int y) {
    GameState* game = GameState::GetInstance();
    void* camera;
    int i;
    Obj021e4e20* screen = GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    int member = screen->member;
    if (x > 0 && x < 128) {
        int screenX[8];
        int screenY[8];
        camera = game->GetCamera();
        Matrix4x3 matrix;
        Vector3fix positions[8];
        matrix = RotationMatrixY(RunIfPtr_021e4e20(screen)->rotation.y);
        for (i = 0; i < 8; i++) {
            Mat4x3_ApplyToVector(&data_ov005_0215cc24[i], &matrix, &positions[i]);
            Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&positions[i], &screenX[i], &screenY[i]);
        }
        GetCombatantWithFlag0x100_0200ff1c(game, member);
        int count = 0;
        float radii[8];
        int touched[8];
        for (int i = 0; i < 8; i++) {
            radii[i] = 20.0f;
            int dy = y - screenY[i];
            int dx = x - screenX[i];
            if ((float)sqrt(dx * dx + dy * dy) < radii[i]) touched[count++] = i;
        }
        if (var9 > 0) {
            int var15 = var11[0];
            int var16 = data_ov005_0215cc2c[var15].unknown_0_;
            for (int var17 = 1; var17 < var9; var17++) {
                int var18 = var11[var17];
                if (var16 < data_ov005_0215cc2c[var18].unknown_0_) {
                    var15 = var18;
                    var16 = data_ov005_0215cc2c[var18].unknown_0_;
                }
            }
            return data_ov005_0215cbf4[var15];
        }
    }
    return 255;
}
