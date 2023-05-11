#include "monty.h"

/**
 * free_stack - function
 * description - this function freedom the stack
 * @top: the pointer
 * Return: void
 */

void free_stack(stack_t *top)
{
	stack_t *current, *temporal;

	if (top == NULL)
		return;

	current = top;

	while (current != NULL)
	{
		temperol = current->next;
		free(current);
		current = temporal;
	}
}
