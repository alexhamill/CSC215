#include "BIGINT.H"
#include "BDSCTEST.H"

main() {
    struct bigint a, b, result;
    
    START_TESTING("BIGINTTD.C");

    TEST_CASE("Read and write bigint 1234567") {
        struct bigint bi;
        set_bigint("1234567", &bi);
        ASSERT_STR(get_bigint(&bi), "1234567");
    }

    TEST_CASE("Add big int") {
        set_bigint("99999999999999", &a);
        set_bigint("1", &b);
        add(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "100000000000000");

        set_bigint("99999999999999", &a);
        set_bigint("99999999999999", &b);
        add(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "199999999999998");

        set_bigint("0", &a);
        set_bigint("123456789", &b);
        add(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "123456789");

        set_bigint("123456789", &a);
        set_bigint("0", &b);
        add(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "123456789");

        set_bigint("0", &a);
        set_bigint("0", &b);
        add(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "0");

        set_bigint("12345", &a);
        set_bigint("67890123456789", &b);
        add(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "67890123469134");
    }
    
    TEST_CASE("Subtract big int") {
        set_bigint("100000000000000", &a);
        set_bigint("1", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "99999999999999");

        set_bigint("199999999999998", &a);
        set_bigint("99999999999999", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "99999999999999");

        set_bigint("123456789", &a);
        set_bigint("0", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "123456789");

        set_bigint("0", &a);
        set_bigint("0", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "0");

        set_bigint("1000", &a);
        set_bigint("1", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "999");

        set_bigint("67890123456789", &a);
        set_bigint("12345", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "67890123444444");

        set_bigint("5000", &a);
        set_bigint("5000", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "0");

        set_bigint("10000000000", &a);
        set_bigint("9999999999", &b);
        sub(&a, &b, &result);
        ASSERT_STR(get_bigint(&result), "1");
    }

    END_TESTING();
}