/*
** EPITECH PROJECT, 2021
** ex04
** File description:
** add
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "castmania.h"

void exec_operation_two(division_t *div, instruction_t *inst)
{
    if (inst->output_type == VERBOSE) {
        if (div->div_type == INTEGER) {
            integer_op_t *int_op = div->div_op;
            printf("%d\n", int_op->res);
        }
        if (div->div_type == DECIMALE) {
            decimale_op_t *dec_op = div->div_op;
            printf("%f\n", dec_op->res);
        }
    }
}

void exec_operation(instruction_type_t instruction_type , void *data)
{
    instruction_t *inst = data;
    if (instruction_type == ADD_OPERATION) {
        addition_t *add = inst->operation;
        exec_add(add);
        if (inst->output_type == VERBOSE)
            printf("%d\n", add->add_op.res);
    }
    if (instruction_type == DIV_OPERATION) {
        division_t *div = inst->operation;
        exec_div(div);
        exec_operation_two(div, inst);
    }
}

void exec_instruction(instruction_type_t instruction_type , void *data)
{
    if (instruction_type == PRINT_INT) {
        int *num = data;
        printf("%d\n", *num);
    } else if (instruction_type == PRINT_FLOAT) {
        float *num = data;
        printf("%f\n", *num);
    } else {
        exec_operation(instruction_type, data);
    }
}