#include "monty.h"

/**
 * rotr - Rotate the stack to the bottom
 * @stack: A Double pointer to the top of the stack
 *
 * Description: The rotr function rotates the stack to the bottom.
 * The last element of the stack becomes the first element of the stack.
 *
 * Usage: rotr
 * The function does nothing if the stack is empty or has only one element.
 * The function never fail.
 */
void rotr(stack_t **stack)
{
	stack_t *las_t;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	las_t = *stack;
	while (las_t->next != NULL)
		las_t = las_t->next;

	las_t->next = *stack;
	(*stack)->prev = las_t;
	*stack = las_t;
	las_t->prev->next = NULL;
	las_t->prev = NULL;
}
