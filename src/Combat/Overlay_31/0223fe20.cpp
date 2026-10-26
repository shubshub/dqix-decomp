struct Struct_ov031_0223fe20 {
    Struct_ov031_0223fe20* previous;
    Struct_ov031_0223fe20* next;
    void* key;
    const char* value;
    int field10;
    int field14;
};
typedef void* (*Type_ov031_0223fe20)(int, int);
extern Type_ov031_0223fe20 data_ov031_02290fc4;
extern int data_ov031_02290fc0;
extern "C" int func_ov031_02242e90(const char*, const char*);

// USA: func_ov031_0223fe20
extern "C" int func_ov031_0223fe20(void* destination, void* key, const char* value, int size) {
    Struct_ov031_0223fe20** head = (Struct_ov031_0223fe20**)destination;
    Struct_ov031_0223fe20* first = *head;
    int found = 0;
    Struct_ov031_0223fe20* node;
    if (first != 0) {
        node = first;
        if (func_ov031_02242e90((const char*)key, (const char*)first->key) != 0) {
            node = first->next;
            if (node != *head) do {
                if (func_ov031_02242e90((const char*)key, (const char*)node->key) == 0) {
                    found = 1;
                    break;
                }
                node = node->next;
            } while (node != *head);
        } else {
            found = 1;
        }
    }
    if (found) {
        node->value = value;
    } else {
        Struct_ov031_0223fe20* var4 = (Struct_ov031_0223fe20*)data_ov031_02290fc4(size, 4);
        switch ((unsigned int)var4) {
        case 0:
            data_ov031_02290fc0 = 1;
            return 0;
        default:
            break;
        }
        var4->key = key;
        var4->value = value;
        var4->field10 = 0;
        var4->field14 = 0;
        if (*head == 0) {
            var4->next = var4;
            var4->previous = var4;
            *head = var4;
        } else {
            var4->previous = (*head)->previous;
            var4->next = *head;
            (*head)->previous->next = var4;
            (*head)->previous = var4;
        }
    }
    return 1;
}
