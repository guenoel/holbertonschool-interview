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
	listint_t *tmp = NULL;
	listint_t *new = NULL;

	for (current = *head; current->next->n < number; current = current->next)
	{
		;
	}
	new = (listint_t *)malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		tmp = current->next;
		current->next = new;
		new->next = tmp;
	}
	return (new);
}
