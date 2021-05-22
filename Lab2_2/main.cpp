#include <stdio.h>
#include <iostream>
#include <cctype>
#include "BetaCipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        BetaCipher skey(key);
        wcout<<skey.CoderBetaCipher(key, s)<<endl;
        wstring g=skey.CoderBetaCipher(key, s);
        wcout<<skey.DecoderBetaCipher(key,g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    int k;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"pRograMpROCEsing",8);
    check(L"pRograMpROCEssing",10);
    check(L"TDFOXFCHVMN",3);
    return 0;
}
