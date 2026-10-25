// The pot search's step functions, indexed by the task's SearchPotStep: FieldTask_SearchPot calls the entry for the
// current step and stores the step it returns. Step 6 (SearchPotStep_Done) has a null entry, so nothing more runs:
// the step function that returns it has already set the task's done flag.
// Originally data_ov017_021d6c04 (USA/EUR 0x021d6c04, JPN 0x021d6ffc).
int SearchPotTask_Check(void* task);
int SearchPotTask_PickSprite(void* task);
int SearchPotTask_LoadSprite(void* task);
int SearchPotTask_WaitSprite(void* task);
int SearchPotTask_ShowMessage(void* task);
int SearchPotTask_ShowItem(void* task);

int (*const SearchPotTask_steps[7])(void* task) = {
    SearchPotTask_Check,
    SearchPotTask_PickSprite,
    SearchPotTask_LoadSprite,
    SearchPotTask_WaitSprite,
    SearchPotTask_ShowMessage,
    SearchPotTask_ShowItem,
    0,
};
