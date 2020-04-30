/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Unit tests for v2f_to_grid
*/

#include <criterion/criterion.h>
#include "graphical_def.h"

Test(v2f_to_grid, zero)
{
    v2f pos = v2f(0, 0);
    v2i const expected = v2i(0, 0);
    v2i actual = v2i(0, 0);

    actual = v2f_to_grid(pos);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_to_grid, test_1)
{
    v2f pos = v2f(1280, 388);
    v2i const expected = v2i(40, 12);
    v2i actual = v2i(0, 0);

    actual = v2f_to_grid(pos);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_to_grid, test_2)
{
    v2f pos = v2f(768, 222);
    v2i const expected = v2i(24, 6);
    v2i actual = v2i(0, 0);

    actual = v2f_to_grid(pos);
    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}

Test(v2f_to_grid, test_3)
{
    v2f pos = v2f(2224, 1668);
    v2i const expected = v2i(69, 52);
    v2i actual = v2i(0, 0);
    int const tile_size = 32;

    cr_assert_eq(actual.x, expected.x);
    cr_assert_eq(actual.y, expected.y);
}