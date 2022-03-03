

void reverse_SLL( )
{
    INFO * qtemp, *gtemp, *rtemp;
    qtemp = start;
    rtemp = NULL;
    while (qtemp != NULL)
    {
        gtemp = qtemp;
        qtemp = qtemp->next;
        gtemp->next = rtemp;
        rtemp = gtemp;
    }
    start = gtemp;
}
