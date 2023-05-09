#include "monty.h"

/**
 * push - insert node at the stack in LIFO
 *
 * @stack: the double pinter to struct
 * @line_number: the line read in the file wih sufix '.m'
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "L%d: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	newNode->n = atoi(token);
	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}

/**
 * pall - print from top all values of the stack
 *
 * @stack: double pinter
 * @line_number: linea read in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	(void)line_number;
	if (*stack == NULL || stack == NULL)
		return;

	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * pint - print in the order of push the node in stack
 *
 * @stack: the double pointer
 * @line_number: read line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 *
 * @stack: the double pointer
 * @line_number: read line
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *del = NULL;

		del = *stack;
		if ((*stack)->next == NULL)
		{
			*stack = NULL;
			free(del);
		}
		else
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			free(del);
		}
	}
}
