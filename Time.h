// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>
class Time{
 public:
  //Konstruktor
  Time(int h,int m,int s);
  Time(std::string str);
  Time();
  
  //Medlemsfunktioner
  int hour() const;
  int minute() const;
  int second() const;
  int fromString(std::string str,int index);
  bool is_am()const;
  std::string to_string(bool b=false);
  std::string mini(int val)const;

  //operatorer
  operator std::string();
  Time operator+(int const rhs);
  Time operator-(int const rhs);
  Time& operator++();
  Time& operator--();
  Time operator++(int);
  Time operator--(int);
 private:
  //datamedlemmar
  int timme,minut,sekund;
};
std::ostream& operator<<(std::ostream & lhs, Time const& rhs);
#endif
