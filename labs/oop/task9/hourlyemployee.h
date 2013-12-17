#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "employee.h"

class HourlyEmployee : public Employee
{
public:
   static const int hoursPerWeek = 168; // hours in one week

   HourlyEmployee( const string &, const string &,
      const string &, double, double,
      int m, int d, int y);

   void setWage( double ); // set hourly wage
   double getWage() const; // return hourly wage

   void setHours( double ); // set hours worked
   double getHours() const; // return hours worked

   // keyword virtual signals intent to override
   virtual double earnings() const; // calculate earnings
   virtual void print() const; // print HourlyEmployee object
private:
   double wage; // wage per hour
   double hours; // hours worked for week
}; // end class HourlyEmployee

#endif // HOURLYEMPLOYEE_H
