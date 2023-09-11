#include "lists.h"

/**
 * insert_node - adds a new node in the right place
 * in an ordered listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = NULL;
	listint_t *tmp1 = NULL;
	listint_t *tmp2 = NULL;
	listint_t *new = NULL;

	
	new = (listint_t *)malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		if (current->n > number)
		{
			tmp1 = current->next;
			current = new;
			current->next = tmp1;
		} else {
			while (current->n < number)
			{
				tmp1 = current;
				current = current->next;
			}
			tmp2 = tmp1->next;
			tmp1->next = new;
			new->next = tmp2;
		}
	}
	return (new);
}
