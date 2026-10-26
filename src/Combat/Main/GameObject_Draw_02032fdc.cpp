#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct GameObjectTimerBits {
    unsigned short sinkTimer : 15;
    unsigned short turningInPlace : 1;
};

struct GameObjectFields : Object3D {
    char unknown_ac_[0xe];
    short shakeAmplitude;
    unsigned short shakeTimeLeft;
    char unknown_be_[6];
    struct GameObjectTimerBits timerBits;
    char unknown_c6_[0x5e];
    int fallY;
};

extern int data_0210a05c[];

// Main, originally func_02032fdc (USA 0x02032fdc, EUR 0x02032fec, JPN 0x02032b14)
extern "C" ARM bool GameObject_Draw(GameObjectFields* self, bool applyClipping, Vector3fix* drawnPosition) {
    int sink;
    int savedY;
    unsigned int sinkTimer = self->timerBits.sinkTimer;
    int sinking = sinkTimer != 0;
    savedY = self->position_.y;
    if (sinking) {
        sink = 0x1000;
        if (sinkTimer > 5000 - 100) {
            sink = (int)(4096.0f * ((float)(int)(5000 - sinkTimer) / 100.0f));
        } else if (sinkTimer < 100) {
            sink = (int)(4096.0f * ((float)sinkTimer / 100.0f));
        }
        Vector3fix lowered = self->position_;
        int twoThirdsHeight = (self->GetHeight() / 3) * 2;
        sink = (int)((((long long)twoThirdsHeight) * sink + 0x800) >> 12);
        lowered.y -= sink;
        self->position_ = lowered;
    }
    if (self->fallY != 0) {
        Vector3fix raised = self->position_;
        raised.y = self->fallY;
        self->position_ = raised;
    }
    bool drawn;
    if (self->shakeTimeLeft != 0) {
        GameState* game = GameState::GetInstance();
        unsigned int elapsed = game->GetEffectiveDeltaTime();
        Vector3fix shakeOffset = {data_0210a05c[0], data_0210a05c[3], data_0210a05c[6]};
        Vector3fixMultiplyScalar(&shakeOffset, self->shakeAmplitude, &shakeOffset);
        Vector3fix shakenPosition;
        Vector3fix_Add(&self->position_, &shakeOffset, &shakenPosition);
        self->position_ = shakenPosition;
        if (drawnPosition) *drawnPosition = shakenPosition;
        drawn = self->Draw(applyClipping);
        self->position_ = self->position_;
        if (self->shakeTimeLeft < elapsed) {
            self->shakeTimeLeft = 0;
            self->shakeAmplitude = 0;
        } else {
            short amplitude = (short)fix32abs(self->shakeAmplitude);
            float decay = (float)elapsed * (((float)amplitude / 4096.0f) / (float)self->shakeTimeLeft);
            int decayFixed = (int)(4096.0f * decay);
            short nextAmplitude = (short)(amplitude - decayFixed);
            if (self->shakeAmplitude > 0) {
                self->shakeAmplitude = -nextAmplitude;
            } else {
                self->shakeAmplitude = nextAmplitude;
            }
            self->shakeTimeLeft = self->shakeTimeLeft - elapsed;
        }
    } else {
        drawn = self->Draw(applyClipping);
        if (drawnPosition) *drawnPosition = self->position_;
    }
    int stillSinking = self->timerBits.sinkTimer != 0;
    if (stillSinking || self->fallY != 0) {
        Vector3fix restored = self->position_;
        restored.y = savedY;
        self->position_ = restored;
    }
    return drawn;
}
