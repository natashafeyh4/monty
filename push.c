#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number in the Monty bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	/* Check if the argument is missing or not an integer */
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Create a new node and set its value */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (is_integer(opt.arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new_node);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(opt.arg);
	new_node->prev = NULL;

	/* Link the new node to the current stack */
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
