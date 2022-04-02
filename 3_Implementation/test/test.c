#include "Bank_Function.h"
#include <unity.c>
#include<sys/stat.h>
void setUp(void){}
void tearDown(void){}
void bank_function(){
    TEST_ASSERT_EQUAL(1,check_Name("ABC"));
    TEST_ASSERT_EQUAL(1,check_Name("ABC ABC"));
    TEST_ASSERT_EQUAL(0,check_Name("123"));
    TEST_ASSERT_EQUAL(0,check_Name("ABC@"));
    TEST_ASSERT_EQUAL(1,check_Acc_no("123456789010"));
    TEST_ASSERT_EQUAL(0,check_Acc_no("123"));
    TEST_ASSERT_EQUAL(0,check_Acc_no("1234567890101123"));
    TEST_ASSERT_EQUAL(0,check_Acc_no("123Abc"));
    TEST_ASSERT_EQUAL(1,check_Ph_no(1234567890));
    TEST_ASSERT_EQUAL(0,check_Ph_no(12345));
    TEST_ASSERT_EQUAL(0,check_Ph_no(1234567890123));
    TEST_ASSERT_EQUAL(1,check_amount(1000));
    TEST_ASSERT_EQUAL(0,check_amount(500));
    TEST_ASSERT_EQUAL(1,check_amount(2000));
}
int main(){
    UnityBegin(NULL);
    RUN_TEST(bank_function);
    return (UnityEnd());
}
