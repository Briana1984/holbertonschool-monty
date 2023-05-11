#include "monty.h"
char *token = NULL;

/**
 * main - function
 * description - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *mnty;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	mnty = fopen(argv[1], "r");
	if (mnty == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
	while (getline(&line, &len, mnty) != -1)
	{
		token = strtok(line, " \n\t");
		if (token == NULL)
		{
			line_number++;
			continue; }
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t");
			if (token == NULL || isNumb(token) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, line_number); }
		else
		{
			pick_func(&stack, line_number);
		}
		line_number++; }
	free_stack(stack);
	free(line);
	fclose(mnty);
	return (0); }
