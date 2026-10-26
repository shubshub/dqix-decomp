#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Overlay17DayCycle.h"
#include "Graphics/LightingManager.h"

struct Struct_ov017_0219c774 {
    unsigned char unknown_0_[12];
    unsigned char kind : 4;
    unsigned char flags : 4;
};
extern "C" float func_020103e8(GameState*);
extern "C" void func_020103c8(GameState*, float);
// USA: func_ov017_0219c774
extern "C" ARM int func_ov017_0219c774(Struct_ov017_0219c774* entry, int apply) {
    GameState* game = GameState::GetInstance();
    float time = func_020103e8(game);
    float var2 = time;
    if (apply && entry != 0 && entry->kind == 0) {
        game->SetDayTimer(time);
        func_020103c8(game, time);
        LightingManager* lighting = LightingManager::GetInstance();
        lighting->dayNightTimer_ = game->GetDayTimer();
        lighting->timeOfDayIndex_ = game->GetTimeOfDay();
        return 0;
    }
    int next = TimeOfDay_Night;
    if (time >= data_ov017_021d837c.eveningStart) next = TimeOfDay_Evening;
    else if (time >= data_ov017_021d837c.dayStart) next = TimeOfDay_Day;
    else if (time >= data_ov017_021d837c.morningStart) next = TimeOfDay_Morning;
    int previous = game->GetTimeOfDay();
    if (next == previous) {
        int i;
        float bounds[4] = {data_ov017_021d837c.morningStart, data_ov017_021d837c.dayStart, data_ov017_021d837c.eveningStart, data_ov017_021d837c.eveningStart + data_ov017_021d75b8.unknown_10_};
        float step;
        i = 0;
        for (; i < 4; i++) {
            step = data_ov017_021d75b8.unknown_0_;
            if (bounds[i] - 2.0f * step < time && time < bounds[i]) {
                time = bounds[i] - 2.0f * step;
                var2 = bounds[i];
            }
        }
        if (data_ov017_021d837c.unknown_14_ <= var2) var2 = 0.0f;
        if (entry == 0 || entry->kind != 0) time = var2;
    }
    if ((next + 1) % 4 == previous) {
        float bounds[4] = {data_ov017_021d837c.morningStart, data_ov017_021d837c.dayStart, data_ov017_021d837c.eveningStart, data_ov017_021d837c.eveningStart + data_ov017_021d75b8.unknown_10_};
        float values[4] = {data_ov017_021d837c.nightStart, data_ov017_021d837c.morningStart, data_ov017_021d837c.dayStart, data_ov017_021d837c.eveningStart};
        if (bounds[next] - 2.0f * data_ov017_021d75b8.unknown_0_ < time && time < bounds[next]) {
            time = values[previous];
            var2 = time;
        }
    }
    next = TimeOfDay_Night;
    if (time >= data_ov017_021d837c.eveningStart) next = TimeOfDay_Evening;
    else if (time >= data_ov017_021d837c.dayStart) next = TimeOfDay_Day;
    else if (time >= data_ov017_021d837c.morningStart) next = TimeOfDay_Morning;
    if (next == previous) apply = 1;
    if (apply) {
        game->SetDayTimer(time);
        func_020103c8(game, var2);
        LightingManager* lighting = LightingManager::GetInstance();
        lighting->dayNightTimer_ = game->GetDayTimer();
        lighting->timeOfDayIndex_ = game->GetTimeOfDay();
    }
    return next != previous;
}
