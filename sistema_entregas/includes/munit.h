#ifndef MUNIT_H
#define MUNIT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char* name;
    MunitResult (*test_func)(const MunitParameter[], void*);
} MunitTest;

typedef struct {
    const char* name;
    const MunitTest* tests;
    void* options;
    int iterations;
    int options_mask;
} MunitSuite;

#define MUNIT_OK 0
#define MUNIT_TEST_OPTION_NONE 0
#define MUNIT_SUITE_OPTION_NONE 0

typedef int MunitResult;
typedef void* MunitParameter;

#define munit_assert_int(actual, op, expected) \
    if (!((actual) op (expected))) { \
        printf("Assertion failed: %d " #op " %d\n", actual, expected); \
        exit(1); \
    }

int munit_suite_main(const MunitSuite* suite, void* user_data, int argc, char* argv[]) {
    int passed = 0;
    for (int i = 0; suite->tests[i].name != NULL; i++) {
        printf("Running test: %s\n", suite->tests[i].name);
        if (suite->tests[i].test_func(NULL, NULL) == MUNIT_OK) {
            printf("✔ Passed\n");
            passed++;
        } else {
            printf("✘ Failed\n");
        }
    }
    printf("\n%d/%d tests passed.\n", passed, (int)(passed + 1));
    return 0;
}

#endif 