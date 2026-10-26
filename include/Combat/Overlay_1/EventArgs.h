#pragma once

// 12-byte value payload passed by-value to the EnqueueEvent / MakeEntry family.
// mwcc marshals it into r1-r3 via a single ldmia, matching the retail idiom.
struct EventVec3 {
    int a, b, c;
};
