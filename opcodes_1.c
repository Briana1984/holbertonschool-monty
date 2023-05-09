#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: the double pointer
 * @line_number: read line
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	if (tmp->next != NULL)
	{
		(*stack)->next = tmp->next;
		(*stack)->next->prev = *stack;
	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
}

/**
 * add - adds the top two elements of the stack
 *
 * @stack: the double pointer
 * @line_number: line read
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - doesn’t do anything
 *
 * @stack: the double pointer
 * @line_number: read line
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
