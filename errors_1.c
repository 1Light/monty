#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error - Outputs a usage error message.
 *
 * Return: Error Exit everytime.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Outputs a malloc error message.
 *
 * Return: Error Exit everytime.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Outputs file launching error message without file name.
 * @filename: File name failed to launch.
 *
 * Return: Error Exit everytime.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - outputs unspecified command error messages.
 * @opcode: Opcode when error happens.
 * @line_number: Show line number in Monty bytecodes file where error happened.
 *
 * Return: Error Exit everytime.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Outputs unsupported monty_push input error messages.
 * @line_number: Show line number in Monty bytecodes file where error happened.
 *
 * Return: Error Exit everytime.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
