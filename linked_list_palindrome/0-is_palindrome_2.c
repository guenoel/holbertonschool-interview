#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	listint_t *current2;
	listint_t *middle = *head;
	listint_t *tmp;
	listint_t *tmp1;
	listint_t *head_middle;
	listint_t *tail_middle;
	listint_t *rev_middle;

	if (head == NULL || (head != NULL && (*head)->next == NULL))
		return (1);

	while (current)
	{
		tmp1 = middle;
		middle = middle->next;
		current = current->next->next;
	}

	/* liste coupée en 2 */
	tmp = tmp1->next;
	tmp1->next = NULL;
	tmp1 = tmp;
	middle = tmp1;
	printf("head du middle: %d\n", middle->n);

	rev_middle = middle;
	head_middle = rev_middle;
	/* Tant que la node suivante de celle qui fut à l'origine au debut n'est pas null */
	/* ... donc tant que la node du debut n'est pas encore à la fin */
	while (middle->next)
	{
		rev_middle = head_middle;
		while (rev_middle->next->next)
		{
			printf("test: %d\n", rev_middle->n);
			rev_middle = rev_middle->next;
		}
		printf("test: %d\n", rev_middle->n);
		/* detachement de la derniere node */
		tail_middle = rev_middle->next;
		printf("Tail: %d\n", tail_middle->n);
		rev_middle->next = NULL;
		/* attachement de la derniere node au debut */
		tail_middle->next = head_middle;
		/* le debut c'est la node qui était a la fin */
		head_middle = tail_middle;
	}
	rev_middle = head_middle;

	current = *head;
	current2 = rev_middle;
	while (current2)
	{
		/* if (current->n != rev_middle->n)
			return (0); */
		printf("Premier: %d\n", current->n);
		printf("Deuxieme: %d\n", current2->n);
		current = current->next;
		current2 = current2->next;
	}
	return (1);
}