struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    int count;
    struct ListNode* head;
} Solution;

Solution *get;

/** @param head The linked list's head.
 Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution* solutionCreate(struct ListNode* head) {
    struct ListNode* p = head;
    int number = 1;
    while (p->next != NULL) {
        p = p->next;
        number++;
    }
    get = malloc(sizeof(Solution));
    get->count = number;
    get->head = head;
    return get;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    struct ListNode* p = obj->head;
    int position = obj->count;
    //srand((unsigned)time(NULL));
    int get = rand() % (position);
    for (int index = 0; index < get; index++) {
        p = p->next;
    }
    return p->val;
}

void solutionFree(Solution* obj) {
    struct ListNode *p = obj->head;
    while (p->next != NULL) {
        struct ListNode* tmp = p;
        p = p->next;
        free(tmp);
    }
    free(p);
    free(obj);
}