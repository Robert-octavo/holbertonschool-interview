#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: address of the node where the loop starts, or NULL if there is no
 * loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
		return (NULL);

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;		 /* 1 hop */
		fast = fast->next->next; /* 2 hops */

		if (slow == fast) /* fast caught up to slow, so there is a loop */
		{
			slow = head; /* move slow to head */

			while (slow != fast) /* both now move at same speed */
			{
				slow = slow->next;
				fast = fast->next;
			}

			return (slow); /* both now point to the start of the loop */
		}
	}

	return (NULL); /* fast reached NULL, so the list terminates */
}
