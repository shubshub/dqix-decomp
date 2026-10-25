// The field task kinds whose end starts a 12-frame countdown: when the queue's head task finishes and its kind is
// in this list (0xffff ends it), FieldTaskQueue_Update writes 12 to GameResources +0x4354 (jpn +0x4134), which
// DecrementClampCounter354_021a4e48 then counts down a frame at a time (seen in-game: after a talk, kind 5).
// Originally data_ov017_021d6a34 (USA/EUR 0x021d6a34, JPN 0x021d6e58).
const int FieldTaskQueue_countdownKinds[18] = {5, 6, 10, 13, 15, 16, 17, 18, 23, 30, 42, 55, 61, 62, 63, 65, 71, 0xffff};
