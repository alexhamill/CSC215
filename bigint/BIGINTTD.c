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
        struct bigint a, b, result;


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
    

    END_TESTING();
}