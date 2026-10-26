#include <globaldefs.h>

struct BackgroundScreen;
extern "C" void ClearRecordFields(struct BackgroundScreen* rec);

// USA: Forward0204acd0
extern "C" ARM void Forward0204acd0(struct BackgroundScreen* rec) {
    ClearRecordFields(rec);
}
