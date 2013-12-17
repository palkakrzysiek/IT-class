#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "employee.h"
#include "salariedemployee.h"
#include "hourlyemployee.h"
#include "commissionemployee.h"
#include "basepluscommissionemployee.h"
using namespace std;

int main()
{
  // set floating-point output formatting
  cout << fixed << setprecision( 2 );

  // create derived-class objects
  SalariedEmployee salariedEmployee( "John", "Smith",
      "111-11-1111", 800, 1, 2, 1980 );
  HourlyEmployee hourlyEmployee("Karen", "Price",
      "222-22-2222", 16.75, 40, 2, 3, 1981);
  CommissionEmployee commissionEmployee( "Sue", "Jones",
      "333-33-3333", 10000, .06, 3, 10, 1972);
  BasePlusCommissionEmployee basePlusCommissionEmployee(
      "Bob", "December", "444-44-4444", 5000, .04, 300, 12, 12, 1962);
  BasePlusCommissionEmployee basePlusCommissionEmployee2(
      "Bob", "January", "444-44-4444", 5000, .04, 300, 1, 12, 1962);

  vector < Employee * > employees( 5 );

  // initialize vector with Employees
  employees[ 0 ] = &salariedEmployee;
  employees[ 1 ] = &hourlyEmployee;
  employees[ 2 ] = &commissionEmployee;
  employees[ 3 ] = &basePlusCommissionEmployee;
  employees[ 4 ] = &basePlusCommissionEmployee2;

  cout << "Payroll:\n\n";

  for ( size_t i = 0; i < employees.size(); i++ ) {
    employees[i]->print();
    cout << "\nearned $" << employees[i]->earnings() << "\n\n";
  }

} // end main

