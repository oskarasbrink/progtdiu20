// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Time::Time(int h,int m,int s): timme{h}, minut{m}, sekund{s}
{
  
  if (h>=24||m>=60||s>=60||h<0||m<0||s<0){
    throw invalid_argument( "input was out of bounds!");
  }
}

Time::Time(): timme{0}, minut{0}, sekund{0}
{}

Time::Time(string str):timme{fromString(str,0)}, minut{fromString(str,1)}, sekund{fromString(str,2) }
{if (timme>=24||minut>=60||sekund>=60||timme<0||minut<0||sekund<0){
    throw invalid_argument( "input was out of bounds!");
  }
}

int Time::hour() const{
  return timme;
}

int Time::minute() const{
  return minut;
}

int Time::second() const{
  return sekund;
}

int Time::fromString(string str,int index){
  stringstream ss{str};
  int ret;
  char c;
  for(int i=0;i<index;i++){
    ss>>ret;
    ss>>c;
  }
  ss>>ret;
  return ret;
}

bool Time::is_am()const{
  return timme<12;
}

string Time::to_string(bool b){
  stringstream ss;
  
  string str{""},s{""};
  if(b==true){
    if(!is_am()){
      timme-=12;
      str =" pm";
    }
    else{
      str =" am";
    }
  }
  ss<<mini(timme); //ss<< mini(str)
  ss<<':';
  
  ss<<mini(minut);
  ss<<':';
  
  ss<<mini(sekund);
  ss>>s;
  s.append(str);
  return s;
}

string Time::mini(int val)const{
  stringstream sss;
  if(val<10){
    sss<<'0';
  }
  sss<<val;
  return sss.str();
}

Time::operator string(){
  return to_string();
}

ostream& operator<<(ostream & lhs,Time const& rhs){
  Time temp = rhs;
  lhs << temp.to_string();

  return lhs;
}
