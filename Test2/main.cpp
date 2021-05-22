#include <UnitTest++/UnitTest++.h>
#include "/home/kirill/timp/Lab2_2/BetaCipher.h"
#include "/home/kirill/timp/Lab2_2/BetaCipher.cpp"

using namespace std;

string pt (int n, wstring pt1)
{
    BetaCipher w(n);
    wstring ws=w.CoderBetaCipher(w,pt1);
    const string y1(ws.begin(), ws.end());
    return y1;
}

string pt1 (int n, wstring pt1)
{
    BetaCipher w(n);
    wstring ws=w.DecoderBetaCipher(n, pt1);
    const string y1 (ws.begin(), ws.end() );
    return y1;
}

char n;
wstring test = L"PROGRAMPROCESING";
SUITE (KeyTest)
{
    TEST (ValidKey) {
        CHECK_EQUAL(pt(n=8,test),"PROGRAMPROCESING");
    }

    TEST(Empty_key) {
        CHECK_THROW(pt(n=0,test), cipher_error);
    }
    TEST(the_key_is_less_than_zero) {
        CHECK_THROW(pt(n=-4,test), cipher_error);
    }
    TEST(the_key_is_larger_than_the_string) {
        CHECK_THROW(pt(n=15,test), cipher_error);
    }

}


SUITE (Encrypt)
{

    TEST (ValidKey) {
        CHECK_EQUAL(pt(n=8,test),"PROGRAMPROCESING");
    }
    TEST (SPACE) {
        CHECK_EQUAL(pt(n=8,L"PROGRAM PROCESING"),"PROGRAMPROCESING");
    }
    TEST (Low_characters) {
        CHECK_EQUAL(pt(n=8,L"programprocesing"),"PROGRAMPROCESING");
    }
    TEST (Numbers) {
        CHECK_THROW(pt(n=8,L"35678"),cipher_error);
    }
    TEST (Empty) {
        CHECK_THROW(pt(n=8,L" "),cipher_error);
    }
    TEST (letters_and_numbers) {
        CHECK_THROW(pt(n=8,L"123awfawAWF45"),cipher_error);
    }
}

SUITE(DecryptText)
{
    TEST(ValidTEXT) {
        CHECK_EQUAL(pt1(8,L"PRROOCGERSAIMNPG"),"PROGRAMPROCESING");
    }
    TEST(Low_characters) {
        CHECK_EQUAL(pt1(8,L"PRROOCGERSAIMNPG"),"PROGRAMPROCESING");
    }
    TEST(SPACE) {
        CHECK_EQUAL(pt1(8,L"PRROOC GERSAIMNPG"),"PROGRAMPROCESING");
    }
    TEST(Empty) {
        CHECK_THROW(pt1(8,L" "),cipher_error);
    }
    TEST (Numbers) {
        CHECK_THROW(pt1(n=8,L"35678"),cipher_error);
    }
    TEST (letters_and_numbers) {
        CHECK_THROW(pt1(n=8,L"123awfawAWF45"),cipher_error);
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
