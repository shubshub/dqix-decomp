#include <globaldefs.h>

#include "Resource/TextEncoding.h"

// Main, originally LookupKeyTable02032e24 (USA 0x02032e24, EUR 0x02032e34, JPN 0x0203295c)
extern "C" ARM unsigned short ShiftJis_LookupUtf16(unsigned short unicode, struct KeyValue02032e24* entries, int lastIndex) {
    lastIndex++;
    while (lastIndex-- != 0) {
        if (entries->key == unicode) return entries->value;
        entries++;
    }
    return 0x8140;
}
