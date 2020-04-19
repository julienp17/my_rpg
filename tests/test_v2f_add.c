/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Unit tests for v2f_add
*/

#include <criterion/criterion.h>
#include "graphical_def.h"

Test(v2f_add, both_zero)
{
    v2f vector1 = v2f(0, 0);
    v2f vector2 = v2f(0, 0);
    v2f const expected = v2f(vector1.x + vector2.x, vector1.y + vector2.y);
    v2f actual = v2f(0, 0);

    actual = v2f_add(vector1, vector2);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_add, normal_usage)
{
    v2f vector1 = v2f(4, 5);
    v2f vector2 = v2f(7, 8);
    v2f const expected = v2f(vector1.x + vector2.x, vector1.y + vector2.y);
    v2f actual = v2f(0, 0);

    actual = v2f_add(vector1, vector2);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_add, negative)
{
    v2f vector1 = v2f(-2, 18);
    v2f vector2 = v2f(-7, -8);
    v2f const expected = v2f(vector1.x + vector2.x, vector1.y + vector2.y);
    v2f actual = v2f(0, 0);

    actual = v2f_add(vector1, vector2);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}