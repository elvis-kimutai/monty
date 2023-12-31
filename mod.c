#include "monty.h"

void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n %= top->n;
	(*stack)->prev = NULL;
	free(top);
}
