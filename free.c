#include "monty.h"

/**
 * free_stack - this function freedom the stack
 * @top: the pointer
 * Return: void
 */

void free_stack(stack_t *top)
{
	stack_t *current, *temp;

	if (top == NULL)
		return;

	current = top;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
