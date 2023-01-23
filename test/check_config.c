#include "../src/config.h"
#include <check.h>
#include <stdlib.h>

START_TEST(check_config_create) {
    config_t *config = config_new();

    ck_assert_ptr_nonnull(config);
    ck_assert_ptr_null(config->method);
    ck_assert_ptr_nonnull(config->config);
    ck_assert_ptr_nonnull(config->local);
    ck_assert_ptr_nonnull(config->home);

    config_free(config);
}
END_TEST

START_TEST(check_config_set_method) {
    config_t *config = config_new();

    config_set_method(config, "link");

    ck_assert_str_eq(config->method, "link");

    config_free(config);
}
END_TEST

START_TEST(check_config_add_config) {
    config_t *config = config_new();

    config_add(&config->config, "nvim");
    config_add(&config->config, "bspwm");
    config_add(&config->config, "alacritty");

    ck_assert_str_eq(config->config[0], "nvim");
    ck_assert_str_eq(config->config[1], "bspwm");
    ck_assert_str_eq(config->config[2], "alacritty");
    ck_assert_ptr_null(config->config[3]);

    config_free(config);
}
END_TEST

Suite *
config_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("config");
    
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, check_config_create);
    tcase_add_test(tc_core, check_config_set_method);
    tcase_add_test(tc_core, check_config_add_config);
    suite_add_tcase(s, tc_core);

    return s;
}

int
main(void) {
    int number_failed = 0;
    Suite *s;
    SRunner *sr;

    s = config_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
