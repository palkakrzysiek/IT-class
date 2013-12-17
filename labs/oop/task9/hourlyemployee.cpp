#include <iostream>
#include "hourlyemployee.h" // HourlyEmployee class definition
using namespace std;

// constructor
HourlyEmployee::HourlyEmployee( const string &first, const string &last,
   const string &ssn, double hourlyWage, double hoursWorked,
   int m, int d, int y)
   : Employee( first, last, ssn, m, d, y )
{
   setWage( hourlyWage ); // validate hourly wage
   setHours( hoursWorked ); // validate hours worked
} // end HourlyEmployee constructor

// set wage
void HourlyEmployee::setWage( double hourlyWage )
{
   wage = ( hourlyWage < 0.0 ? 0.0 : hourlyWage );
} // end function setWage

// return wage
double HourlyEmployee::getWage() const
{
   return wage;
} // end function getWage

// set hours worked
void HourlyEmployee::setHours( double hoursWorked )
{
   hours = ( ( ( hoursWorked >= 0.0 ) &&
      ( hoursWorked <= hoursPerWeek ) ) ? hoursWorked : 0.0 );
} // end function setHours

// return hours worked
double HourlyEmployee::getHours() const
{
   return hours;
} // end function getHours

// calculate earnings;
// override pure virtual function earnings in Employee
double HourlyEmployee::earnings() const
{
   if ( getHours() <= 40 ) // no overtime
      return getWage() * getHours() + Employee::getBonus();
   else
      return 40 * getWage() + ( ( getHours() - 40 ) * getWage() * 1.5 ) +
         Employee::getBonus();
} // end function earnings

// print HourlyEmployee's information
void HourlyEmployee::print() const
{
   cout << "hourly employee: ";
   Employee::print(); // code reuse
   cout << "\nhourly wage: " << getWage() <<
      "; hours worked: " << getHours();
} // end function print
