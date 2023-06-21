#include "monty.h"

/**
 * queue - Sets the format of the stack to a queue (FIFO)
 * @stack: Double pointer to the stack
 *
 * Description: The queue function sets the format of the stack to a queue
 * by reversing the order of the stack elements. If the stack is already
 * in queue format (i.e., the stack has no prev pointer), no changes are made.
 */
void queue(stack_t **stack)
{
	stack_t *current, *prev, *next;

	if (*stack && (*stack)->prev == NULL)
		return;

	current = *stack;
	prev = NULL;
	next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}

	*stack = prev;
}

/**
 * set_stack - Sets the format of the stack to a stack (LIFO)
 * @stack: Double pointer to the stack
 *
 * Description: The stack function sets the format of the stack to a stack
 * by reversing the order of the stack elements. If the stack is already
 * in stack format (i.e., the stack has no prev pointer), no changes are made.
 */
/*void set_stack(stack_t **stack)
{
	stack_t *current, *prev, *next;

	if (*stack && (*stack)->prev != NULL)
		return;

	current = *stack;
	prev = NULL;
	next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}

	*stack = prev;
}*/
