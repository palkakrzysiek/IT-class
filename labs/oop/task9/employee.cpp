#include <iostream>
#include "employee.h" // Employee class definition

using namespace std;

// constructor
Employee::Employee(const string &first, const string &last,
   const string &ssn, const int & m, const int & d, const int & y)
   : firstName( first ), lastName( last ), socialSecurityNumber( ssn ), birthDate(Date(m, d, y))
{
   // empty body
} // end Employee constructor

// set first name
void Employee::setFirstName( const string &first )
{
   firstName = first;
} // end function setFirstName

// return first name
string Employee::getFirstName() const
{
   return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName( const string &last )
{
   lastName = last;
} // end function setLastName


// return last name
string Employee::getLastName() const
{
   return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber( const string &ssn )
{
   socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getSocialSecurityNumber() const
{
   return socialSecurityNumber;
} // end function getSocialSecurityNumber

int Employee::getBonus() const {
   if (birthDate.getMonth() == getCurrentMonth())
      return 100;
   else
      return 0;
}

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const
{
   cout << getFirstName() << ' ' << getLastName()
      << "\nsocial security number: " << getSocialSecurityNumber();
} // end function print

int getCurrentMonth() {
   time_t theTime = time(NULL);
   struct tm *aTime = localtime(&theTime);
   return aTime->tm_mon + 1;
}
