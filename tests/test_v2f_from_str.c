/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Unit tests for v2f_from_str
*/

#include <criterion/criterion.h>
#include "graphical_def.h"

Test(v2f_from_str, space_sep)
{
    char const vec_str[] = "2 4";
    char const sep = ' ';
    v2f const expected = v2f(2, 4);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, csv_sep)
{
    char const vec_str[] = "2,4";
    char const sep = ',';
    v2f const expected = v2f(2, 4);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, dollar_sep)
{
    char const vec_str[] = "2$4";
    char const sep = '$';
    v2f const expected = v2f(2, 4);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, negative_x)
{
    char const vec_str[] = "-2 4";
    char const sep = ' ';
    v2f const expected = v2f(-2, 4);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, negative_y)
{
    char const vec_str[] = "2 -4";
    char const sep = ' ';
    v2f const expected = v2f(2, -4);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, negative_x_and_y)
{
    char const vec_str[] = "-2 -4";
    char const sep = ' ';
    v2f const expected = v2f(-2, -4);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, too_much_fields)
{
    char const vec_str[] = "2 4 a";
    char const sep = ' ';
    v2f const expected = v2f(0, 0);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, x_not_a_number)
{
    char const vec_str[] = "a -4";
    char const sep = ' ';
    v2f const expected = v2f(0, 0);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_from_str, y_not_a_number)
{
    char const vec_str[] = "2 b";
    char const sep = ' ';
    v2f const expected = v2f(0, 0);
    v2f actual = v2f(0, 0);

    actual = v2f_from_str(vec_str, sep);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}