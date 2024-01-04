#include <stdio.h>
#include "monty.h"

#include "monty.h"
/**
 *pop - function that removes the top element of the stack
 *@stack: head of list
 *@line_number: line number of the file
 *@line: string from lines
 *@file: file set as upstream of getline
 */
void pop(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *temp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		clean_up(line, stack, file);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * push - Add node to the start of stack double list
 *
 * @stack: head of stack_t list
 * @line_number: number of line from file
 * @args: arguments of get_tokens
 * @line: line from fgets from file
 * @file: monty.m file
 */

void push(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	int copy_n, i;
	char *op_code = NULL;
	stack_t *new_node;

	op_code = strtok(NULL, " ");
	if (op_code == NULL)
		op_code = "null";
	for (i = 0; op_code[i]; i++)
	{
		if (!isdigit(op_code[i]) && (op_code[i] != '-' && op_code[i] != '+'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			clean_up(line, stack, file);
			exit(EXIT_FAILURE);
		}
	}

	copy_n = atoi(op_code);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_up(line, stack, file);
		exit(EXIT_FAILURE);
	}
	new_node->n = copy_n;
	new_node->next = *stack;
	new_node->prev = NULL; /* new node always prev = null */
	if (*stack != NULL) /* list not empty, old node must change ->prev */
		(*stack)->prev = new_node; /* change prev from old node */
	*stack = new_node; /* move head to new node */
}

/**
 * pall - Print all nodes of stack
 *
 * @stack: head of stack_t list
 * @line_number: number of line from file
 * @args: arguments of get_tokens
 * @line: line from fgets from file
 * @file: monty.m file
 */

void pall(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	(void)line_number;
	(void)file;
	(void)line;

	stack_t *temp = NULL;
	int n = 0;

	if (*stack == NULL)
		return;

	temp = *stack;

	while (temp)
	{
		n = temp->n;
		printf("%d\n", n);
		temp = temp->next;
	}
}
