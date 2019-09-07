#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

Date::Date(int dd, int mm, int yy){
	day= dd;
	month = mm;
	year = yy;
}

Date::~Date(){
}

int Date::daysOfMonth[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};


bool Date::is_leap(int year){
	if(((year%4==0) && (year%100!=0) )||year%400==0){
		return true;
	}
	else{
		return false;
	}
}
void Date::dayOfFeb(){
	if(is_leap(year)){
		daysOfMonth[1]=29;
	}
}

int Date::getDay(){
	return day;
}

int Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}

void Date::setYear(int y){
	year = (y>=0) ? y:2000;
}

void Date::setMonth(int m){
	month = (m>=1 && m<=12 ) ? m:1;
}

void Date::setDay(int d){
	if(month == 2 && is_leap(year)){
		day = (d>=1 && d<=29) ?d :1;
	}
	else{
		day = (d>=1 && d<=daysOfMonth[month-1]) ? d :1;
	}
}

Date Date::DateAfter(int days){
	if(is_leap(year)){
		daysOfMonth[1]=29;
	}
	int copy_day, copy_month, copy_year;
	copy_day = day;
	copy_month = month;
	copy_year = year;
	
	copy_day = copy_day + days;
	if(copy_day<daysOfMonth[copy_month-1]){
		return Date(copy_day, copy_month, copy_year);
	}
	while(copy_day>daysOfMonth[copy_month-1]){
		copy_day = copy_day - daysOfMonth[copy_month-1];
		copy_month++;
		while(copy_month>12){
			copy_month-=12;
			copy_year++;
		}
	}
	return Date(copy_day, copy_month, copy_year);
}

Date Date::DateBefore(int days){
	if(is_leap(year)){
		daysOfMonth[1]=29;
	}
	int copy_day, copy_month, copy_year;
	copy_day = day;
	copy_month = month;
	copy_year = year;
	
	copy_day = copy_day - days;
	if(copy_day>1){
		return Date(copy_day, copy_month, copy_year); 
	}
	
	while(copy_day<1 ){
		if(is_leap(copy_year)){
    		daysOfMonth[1]=29;
    	}
    	if(!is_leap(copy_year)){
    		daysOfMonth[1]=28;
		}
		if((copy_month-2)>=0){
			copy_day = copy_day + daysOfMonth[copy_month-2];
			copy_month--;
		}
		if((copy_month-2)<0 && copy_day<1){
			copy_month = copy_month + 11;
			copy_day = copy_day + daysOfMonth[copy_month-1];
			copy_year = copy_year -1 ;
		}


	}	
		return Date(copy_day, copy_month, copy_year);

}

string Date::dayOfWeek(){
	if(is_leap(year)){
		daysOfMonth[1]=29;
	}
	int copy_month , copy_year;
	copy_month = month;
	copy_year = year;
	if (month == 1 || month == 2) {
        copy_month = copy_month + 12;  
        copy_year--;
    }
    int DAY = (getDay() + 2 *copy_month + 3 * (copy_month + 1) / 5 +copy_year +copy_year / 4 - copy_year / 100 + copy_year / 400) % 7;  
    switch (DAY)  
    {  
    case 0: return  "Monday" ; 
    case 1: return  "Tuesday"  ;
    case 2: return  "Wednesday"  ;
    case 3: return  "Thursday" ;
    case 4: return  "Friday" ;
    case 5: return  "Saturday" ;
    case 6: return  "Sunday" ;

    }
}

int Date::numberOfDays(){
	if(is_leap(year)){
		daysOfMonth[1]=29;
	}
	return daysOfMonth[month-1];
}

void Date::printMonthCalendar(){
		if(is_leap(year)){
		daysOfMonth[1]=29;
	}

	int DayArray[6][7]={0};
	int i , j , x=1, count=1;

	int copy_month , copy_year;
		copy_month = month;
		copy_year = year;
	if (month == 1 || month == 2) {
        copy_month = copy_month + 12;  
        copy_year--;
    }
	int DAY = (1 + 2 * copy_month + 3 * (copy_month + 1) / 5 + copy_year + copy_year / 4 - copy_year / 100 + copy_year / 400) % 7 +1; 
	DAY %=7;
	for(i=0, j=DAY; j<7; j++ ){
		DayArray[i][j]=x;
		x++;
}
	for(i=1; i<6; i++){
		for(j=0; j<7; j++){
			DayArray[i][j]=x;
			x++;
			if(x==daysOfMonth[month-1]+1){
				break;
			}
		}
		if(x==daysOfMonth[month-1]+1){
			break;
		}
	}
	switch(month){
		case 1 : 	cout<<"----------"<<"January"<<"----------"<<endl; break;
		case 2 : 	cout<<"----------"<<"February"<<"----------"<<endl; break;
		case 3 : 	cout<<"----------"<<"March"<<"----------"<<endl; break;
		case 4 : 	cout<<"----------"<<"April"<<"----------"<<endl; break;
		case 5 : 	cout<<"----------"<<"May"<<"----------"<<endl; break;
		case 6 : 	cout<<"----------"<<"June"<<"----------"<<endl; break;
		case 7 : 	cout<<"----------"<<"July"<<"----------"<<endl; break;
		case 8 : 	cout<<"----------"<<"August"<<"----------"<<endl; break;
		case 9 : 	cout<<"----------"<<"September"<<"----------"<<endl; break;
		case 10: 	cout<<"----------"<<"October"<<"----------"<<endl; break;
		case 11: 	cout<<"----------"<<"November"<<"----------"<<endl; break;
		case 12: 	cout<<"----------"<<"December"<<"----------"<<endl; break;		
	}

	cout<<setw(3)<<"Sun"<<setw(4)<<"Mon"<<setw(4)<<"Tue"<<setw(4)<<"Wed"<<setw(4)<<"Thu"<<setw(4)<<"Fri"<<setw(4)<<"Sat"<<endl;
	
	for(i=0; i<6; i++){
		for(j=0; j<7; j++){
			if(DayArray[i][j]==0){
				cout<<setw(4)<<" ";	
			}
			else if(DayArray!=0){
				cout<<setw(2)<<DayArray[i][j]<<setw(2)<<" ";
			}
		}
		cout<<endl;
	}
	
}

