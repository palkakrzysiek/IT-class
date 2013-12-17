#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // C++ standard string class
#include "date.h"
#include <time.h>

using namespace std;

int getCurrentMonth();

class Employee
{
  public:
    Employee(const string &, const string &, const string &,
             const int &, const int &, const int &);

    void setFirstName( const string & ); // set first name
    string getFirstName() const; // return first name

    void setLastName( const string & ); // set last name
    string getLastName() const; // return last name

    void setSocialSecurityNumber( const string & ); // set SSN
    string getSocialSecurityNumber() const; // return SSN

    int getBonus() const;

    // pure virtual function makes Employee abstract base class
    virtual double earnings() const = 0; // pure virtual
    virtual void print() const; // virtual
  private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    Date birthDate;
}; // end class Employee

#endif // EMPLOYEE_H
