#include "monty.h"

/**
 * rotl - Rotate the stack to top
 * @stack: Double pointer to stack
 *
 * Description: The top element of the stack becomes the last, and the
 * second top element of stack becomes the first.
 * rotl never fails.
 */
void rotl(stack_t **stack)
{
	stack_t *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->next = NULL;
}
