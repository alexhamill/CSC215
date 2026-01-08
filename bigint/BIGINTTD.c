#include "BIGINT.H"
#include "BDSCTEST.H"

main() {
    START_TESTING("BIGINTTD.C");

    TEST_CASE("Read and write bigint 1234567") {
        struct bigint bi;
        set_bigint("1234567", &bi);
        ASSERT_STR(get_bigint(bi), "1234567");
    }

    TEST_CASE("Add big int") {
        struct bigint a;
        struct bigint b;
        struct bigint result;
        set_bigint("99999999999999", &a);
        set_bigint("1", &b);
        add(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "100000000000000");
        printf("Addition result: %s\n", get_bigint(&result));
        printf("Expected result: 100000000000000\n");
        printf("first number: %s\n", get_bigint(&a));
        printf("second number: %s\n", get_bigint(&b));
    }

    END_TESTING();
}