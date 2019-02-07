// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
#include <ios>
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
  s.append(str); //?
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

Time::operator string(){ //??
  return to_string();
}

Time Time::operator+(int const rhs){
  sekund+=rhs;
  if (sekund>=60){
    minut+=sekund/60;
    sekund=sekund%60;
    if(minut>=60){
      timme+=minut/60;
      minut=minut%60;
      timme=timme%24;
    }
  }
  return *this;
}

Time Time::operator-(int const rhs){
  sekund-=rhs;
  
   if(sekund<0){
    minut--;
    minut+=sekund/60;
    sekund=60+sekund%60;
      if(minut<0){
	timme--;
	timme+=minut/60;
       	cout<<timme<<"<t";
	timme=24+timme%24;
	minut=60+minut%60;
      }
  }
  return *this;
}

Time& Time::operator++(){
    *this = *this + 1; 

   return *this;
}

Time& Time::operator--(){
  *this=*this - 1;

  return *this;
}

Time Time::operator++(int){ // ??
  Time tmp{*this};
  *this=*this + 1;
  return tmp;
}
Time Time::operator--(int){ // ??
  Time tmp{*this};
  *this=*this - 1;
  return tmp;
}

 bool operator<(Time const& lhs, Time const& rhs){
  
    if((lhs.hour()*3600+lhs.minute()*60+lhs.second())<(rhs.hour()*3600+rhs.minute()*60+rhs.second())){
          cout << "asd";
        return true;
      
    }else{
        cout <<" asd2";
        return false;
    }
}
bool operator>(Time const& lhs, Time const& rhs){
    return (rhs<lhs);
}

bool operator==(Time const& lhs, Time const& rhs){
    return (!(lhs<rhs) && !(lhs>rhs));
}

bool operator!=(Time const& lhs, Time const& rhs){
    return !(lhs==rhs);
}

bool operator>=(Time const& lhs, Time const& rhs){
    return lhs>rhs||lhs==rhs;
}
bool operator<=(Time const& lhs,Time const& rhs){
    return lhs<rhs||lhs==rhs;
}

ostream& operator<<(ostream & lhs,Time const& rhs){
  Time temp = rhs;
  lhs << temp.to_string();

  return lhs;
}
 istream& operator>>(istream & lhs,Time & rhs){
    int temph,tempm,temps;
    char c;
    lhs>>temph>>c>>tempm>>c>>temps;
     try {
          rhs=Time(temph,tempm,temps);
     }
     catch(invalid_argument){
         lhs.setstate(ios::failbit);
     }
    
    return lhs;
}

    //

    
   


