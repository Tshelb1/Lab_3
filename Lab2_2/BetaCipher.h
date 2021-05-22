#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <locale>
using namespace std;
class BetaCipher
{
private:
    int k;
    wstring getValidOpenText(const std::wstring & s);
    wstring getValidCipherText(const std::wstring & s);
    int getValidKey(const int k, const std::wstring & s);
public:
    BetaCipher()=delete;
    BetaCipher(int w);
    wstring CoderBetaCipher(BetaCipher w, wstring& s);
    wstring DecoderBetaCipher(BetaCipher w, wstring& s);
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
