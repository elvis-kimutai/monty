#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being executed from the Monty file.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n /= top->n;
	(*stack)->prev = NULL;
	free(top);
}
