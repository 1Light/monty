#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Outputs pop error message for void piles.
 * @line_number: Give line number in script file where error happened.
 *
 * Return: Error Exit everytime.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Outputs pint error message for void piles.
 * @line_number: Give line number in Monty bytecodes file where error happened.
 *
 * Return: Error Exit everytime.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Outputs math error message for piles below two items.
 * @line_number: Give line number in Monty bytecodes file where error happened.
 * @op: Operation where error happened.
 *
 * Return: Error Exit everytime.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Outputs division error message when division by 0 occurs.
 * @line_number: Give line number in Monty bytecodes file where error happened.
 *
 * Return: Error Exit everytime.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Outputs pchar error message
 *               for void piles and non-char values.
 * @line_number: Give line number in Monty bytecodes file where error happened.
 * @message: The compatable error message to output.
 *
 * Return: Error Exit everytime.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
