
void reverseSLLPrint(struct node *head) {
    if (head != NULL) {
        reverseSLLPrint(head->next);
        printf("%d ", head->data);
    }
}
