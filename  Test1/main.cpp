#include <UnitTest++/UnitTest++.h>
#include "/home/kirill/timp/3_1111/modAlphaCipher.h"
#include "/home/kirill/timp/3_1111/modAlphaCipher.cpp"

using namespace std;
SUITE(TestKey) 
{

    TEST( Capital_letters) {
        modAlphaCipher test(L"АОРЫЛДРПЛПОЫ");
        CHECK(true);
    }
    TEST( Uppercase_and_lowercase_letters)  {
        modAlphaCipher test(L"РЕНОлоган");
        CHECK(true);
    }

    TEST(KeyEmpty) {
        CHECK_THROW(modAlphaCipher test(L""), cipher_error);
    }
    TEST(Space) {
        CHECK_THROW(modAlphaCipher test(L"пр пррыгпа"), cipher_error);
    }
    TEST(Number) {
        CHECK_THROW(modAlphaCipher test(L"впагвар3огпар"), cipher_error);
    }
    TEST( Forbidden_symbols) {
        CHECK_THROW(modAlphaCipher test(L"РОТ;"), cipher_error);
    }
}

struct KeyAB_fixture { 
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"АВ");
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};

SUITE(TestEncrypt) 
{
    TEST_FIXTURE(KeyAB_fixture,  Capital_letters) {
        wstring open_text = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        wstring result_correct = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, Small_Letters) {
        wstring open_text = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        wstring result_correct = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }

    TEST_FIXTURE(KeyAB_fixture, Empty) {
        wstring open_text = L"";
        CHECK_THROW(pointer->encrypt(open_text),cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture, Invalid_Numbers ) {
        wstring open_text = L"АПВ7ПАРАЫ";
        CHECK_THROW(pointer->encrypt(open_text),cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture,  Forbidden_symbols) {
        wstring open_text = L"ОЫПА/АЫР";
        CHECK_THROW(pointer->encrypt(open_text),cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture, Space ) {
        wstring open_text = L"КУ КУ";
        CHECK_THROW(pointer->encrypt(open_text),cipher_error);
    }

}
SUITE(DecryptTest) 
{
    TEST_FIXTURE(KeyAB_fixture,  Capital_letters) {
        wstring cipher_text = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        wstring result_correct = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, Small_Letters) {
        wstring cipher_text = L"агведжёизкймлонрптсфуцхшчъщьыюэая";
        wstring result_correct = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture,  Uppercase_and_lowercase_letters) {
        wstring cipher_text = L"ХЕЛлоуВОрЛД";
        wstring result_correct = L"ХЖЛНОХВРРНД";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }

    TEST_FIXTURE(KeyAB_fixture, Empty) {
        wstring cipher_text = L"";
        CHECK_THROW(pointer->decrypt(cipher_text),cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture,Invalid_Numbers ) {
        wstring cipher_text = L"ПРА77РАП";
        CHECK_THROW(pointer->decrypt(cipher_text),cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture, Forbidden_symbols) {
        wstring cipher_text = L"КУ*КУ";
        CHECK_THROW(pointer->decrypt(cipher_text),cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture,Space ) {
        wstring cipher_text = L"ПРОА РАОА";
        CHECK_THROW(pointer->decrypt(cipher_text),cipher_error);
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
