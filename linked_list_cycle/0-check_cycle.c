#include "lists.h"

int check_cycle(listint_t *list)
{
    listint_t *tortoise = list;
    listint_t *hare = list;
    int are_met = 0;

    while(hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare)
        {
            are_met = 1;
            break;
        }
    }
    return are_met;
}