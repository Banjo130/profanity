#include <stdlib.h>
#include <string.h>
#include <head-unit.h>
#include "parser.h"

void
parse_null_returns_null(void)
{
    char *inp = NULL;
    int num = 0;
    gchar **result = parse_args(inp, 1, 2, &num);

    assert_is_null(result);
    g_strfreev(result);
}

void
parse_empty_returns_null(void)
{
    char *inp = "";
    int num = 0;
    gchar **result = parse_args(inp, 1, 2, &num);

    assert_is_null(result);
    g_strfreev(result);
}

void
parse_space_returns_null(void)
{
    char *inp = "   ";
    int num = 0;
    gchar **result = parse_args(inp, 1, 2, &num);

    assert_is_null(result);
    g_strfreev(result);
}

void
parse_cmd_no_args_returns_null(void)
{
    char *inp = "/cmd";
    int num = 0;
    gchar **result = parse_args(inp, 1, 2, &num);

    assert_is_null(result);
    g_strfreev(result);
}

void
parse_cmd_with_space_returns_null(void)
{
    char *inp = "/cmd   ";
    int num = 0;
    gchar **result = parse_args(inp, 1, 2, &num);

    assert_is_null(result);
    g_strfreev(result);
}

void
parse_cmd_one_arg(void)
{
    char *inp = "/cmd arg1";
    int num = 0;
    gchar **result = parse_args(inp, 1, 2, &num);

    assert_int_equals(1, num);
    assert_string_equals("arg1", result[0]);
    g_strfreev(result);
}

void
parse_cmd_two_args(void)
{
    char *inp = "/cmd arg1 arg2";
    int num = 0;
    gchar **result = parse_args(inp, 1, 2, &num);

    assert_int_equals(2, num);
    assert_string_equals("arg1", result[0]);
    assert_string_equals("arg2", result[1]);
    g_strfreev(result);
}

void
parse_cmd_three_args(void)
{
    char *inp = "/cmd arg1 arg2 arg3";
    int num = 0;
    gchar **result = parse_args(inp, 3, 3, &num);

    assert_int_equals(3, num);
    assert_string_equals("arg1", result[0]);
    assert_string_equals("arg2", result[1]);
    assert_string_equals("arg3", result[2]);
    g_strfreev(result);
}

void
parse_cmd_three_args_with_spaces(void)
{
    char *inp = "  /cmd    arg1  arg2     arg3 ";
    int num = 0;
    gchar **result = parse_args(inp, 3, 3, &num);

    assert_int_equals(3, num);
    assert_string_equals("arg1", result[0]);
    assert_string_equals("arg2", result[1]);
    assert_string_equals("arg3", result[2]);
    g_strfreev(result);
}

void
register_parser_tests(void)
{
    TEST_MODULE("parser tests");
    TEST(parse_null_returns_null);
    TEST(parse_empty_returns_null);
    TEST(parse_space_returns_null);
    TEST(parse_cmd_no_args_returns_null);
    TEST(parse_cmd_with_space_returns_null);
    TEST(parse_cmd_one_arg);
    TEST(parse_cmd_two_args);
    TEST(parse_cmd_three_args);
    TEST(parse_cmd_three_args_with_spaces);
}
