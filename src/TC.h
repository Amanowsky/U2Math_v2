#ifndef TC_H_
#define TC_H_
#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <cstdlib>
#include <time.h>
#include <fstream>

extern "C" void vectorAdd(uint8_t * a, uint8_t * b, unsigned int c);
extern "C" void vectorSub(uint8_t * a, uint8_t * b, unsigned int c);
extern "C" void vectorMul(uint8_t * a, uint8_t * b, uint8_t * c, unsigned int d, unsigned int e);


using std::vector;

class TC {
private:
    vector<uint8_t> _number;
    int _position;
    static void setNegative(uint8_t& byt, int n); //ustawia na indeksie 0 jedynki gdy ujemna (wypadek przy przesuwaniu)
    static void printVector(const vector<uint8_t>& number); //wypisywanie vectora
    static uint8_t rightShift(const uint8_t& number, int n); //przesuniecie w prawo
    static uint8_t leftShift(const uint8_t& number, int n); //przesuniecie w lewo
    static void moveComma(TC& number1, TC&number2, unsigned int& comma, bool& numbsign1, bool& numbsign2); //funkcja pozbywajaca sie przecinka

public:

    TC(); //konstruktor domyślny
    TC(vector<uint8_t>& number, int position); //konstruktor 
    static vector<uint8_t> getNumber(TC number); //zwraca liczba do vectora
    static bool isNumberZero(TC number); //sprawdza czy jest 0
    static bool isNumberZero(vector<uint8_t> number); //sprawdza czy wektor jest 0
    static std::string printTC(TC number); //wypisuje liczbe
    static void negateBits(vector<uint8_t>& number); //neguje nam w vektorze i dodaje 1
    static void negateBits(TC& number); //neguje nam liczbe i dodaje 1
    static TC add(TC number1, TC number2); //dodawanie
    static TC sub(TC number1, TC number2); //odejmowanie
    static TC mul(TC number1, TC number2); //mnozenie
    static TC div(TC number1, TC number2); //dzielenie
    static void changeIndex(int& a, int& b); //zmienia pozycje
    static void changeIndex2(int& a); //zmienia pozycje
    static void shorterString(TC& number); //skraca liczbe o niepotrzebne 1 i 0
    static void shiftDiv(vector<uint8_t>& a, uint8_t& b); //przesuniecie liczby do dzielenia
    TC& operator=(const TC& other) { //operator przypisania
        _number = other._number;
        _position = other._position;
        return *this;
    }
    bool operator==(const TC& other){ //operator rownosci
        if(_position != other._position) return false;
        for(int i=0;i<_number.size();i++){
            if(_number[i]!=other._number[i]) return false;
        }
        return true;
    }

};





#endif