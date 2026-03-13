//#include <iostream>
//using namespace std;
//
//class Employee {
//public:
//    virtual float calculateSalary() = 0;
//};
//
//class FullTimeEmployee : public Employee {
//private:
//    float sal;
//
//public:
//    FullTimeEmployee(float s) {
//        sal = s;
//    }
//
//    float calculateSalary() {
//        return sal;
//    }
//};
//
//class PartTimeEmployee : public Employee {
//private:
//    float hoursWorked;
//    float hourlyRate;
//
//public:
//    PartTimeEmployee(float h, float r) {
//        hoursWorked = h;
//        hourlyRate = r;
//    }
//
//    float calculateSalary() {
//        return hoursWorked * hourlyRate;
//    }
//};
//
//int main() {
//    FullTimeEmployee f1(50000);
//    PartTimeEmployee p1(40, 500);
//
//    cout << "Full Time Employee Salary: " << f1.calculateSalary() << endl;
//    cout << "Part Time Employee Salary: " << p1.calculateSalary() << endl;
//
//    return 0;
//}