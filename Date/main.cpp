#include <iostream>
#include "Date.h"
using namespace std;
// Driver Program to check your implementation
 
int main()
{
    Date date1(1, 1, 2017);
    Date date2 = date1.DateAfter(1000);
    Date date3 = date1.DateBefore(2000);

    date1.setDay(19);
    date2.setMonth(12);
    date3.setYear(2015);

    cout << date1.numberOfDays() << endl;
    cout << date2.dayOfWeek() <<endl;
    cout <<  date1.getDay()<<" "<<date1.getMonth()<<" "<<date1.getYear()<<" "<<endl;
	cout <<  date2.getDay()<<" "<<date2.getMonth()<<" "<<date2.getYear()<<" "<<endl;
    cout <<  date3.getDay()<<" "<<date3.getMonth()<<" "<<date3.getYear()<<" "<<endl;
    date3.printMonthCalendar();
    
    return 0;
}
