
#include <iostream>

using namespace std;

class Person {       // simple person class with attribues
  protected:
    // fields are protected so that
    //only classes which inheret
    //this class can use them
    string n_id;
    string name;
    string phone;
    int age;
};

class Employee : public Person {
    // class Employee inherts class Person
  private:             // attributes encabsulated
    int salary;
    
public:
    // these are setters and getters
    // setters used to modify object value
    //getters are only used to get
    //the attribute value
    
    // Setter
    void setSalary(int s) {
      salary = s;
    }
    // Getter
    int getSalary() {
      return salary;
    }
    // Setter
    void setName(string n) {
        name = n;
    }
    // Getter
    string getName() {
      return name;
    }
    // Setter
    void setNID(string n_id) {
        n_id = n_id;
    }
    // Getter
    string getNID() {
      return n_id;
    }
    
    void setAge(int a) {
        age = a;
    }
    // Getter
    int getAge() {
      return age;
    }
    
    void setPhone(string p) {
        phone = p;
    }
    // Getter
    string getPhone() {
      return phone;
    }
};

class Company {
  private:
    string name;
    // Implementing polymorphism to shape
    //the class Employee in form of variable
    // identifier and making an array from it

    Employee employees[1000];
    
    private:int employeesNumber = 0;
    
public:
    void setCompanyName(string n) {
      name = n;
    }
    // Getter
    string getCompanyName() {
      return name;
    }
     // inserting employees
public:void hireEmployee(Employee e){
        employees[employeesNumber] = e;
        employeesNumber++;
    }
    //deleting employees
public:bool fireEmployee(string n_id){
        int i;
        for(i = 0 ; i < employeesNumber ; i++){
            if(employees[i].getNID() == n_id){
                break;
            }
        }
        if(i == employeesNumber){
            return false;
        }else{
            employeesNumber--;
            for(int j = i ; j < employeesNumber ; j++){
                employees[j] = employees[j+1];
            }
            return true;
        }
    }
    // getting array length
public:int getEmployeesNumber(){
        return employeesNumber;
    }
    // getting all employees
public:string showAllEmployees(){
        string result = "", temp = "";
        for(int i = 0 ; i < employeesNumber ; i++){
            temp = "NID: " + employees[i].getNID()
            + "\nName: " + employees[i].getName()
            + "\nAge: " + to_string(employees[i].getAge())
            + "\nSalary: " + to_string(employees[i].getSalary())
            + "$\n---------------\n";
            
            result += temp;
        }
    return result;
    }
};

int main(int argc, const char * argv[]) {
    // making objects from classes
    Employee e1;
    Employee e2;
    Company ccs;
    // Assigning values to object attributes
    // using the class setters
    e1.setNID("2980615");
    e1.setName("Abdelreheem Samy");
    e1.setAge(22);
    e1.setPhone("01115951169");
    e1.setSalary(25000);
    
    e2.setNID("2970101");
    e2.setName("Ahmed Mokhtar");
    e2.setAge(21);
    e2.setPhone("01285742060");
    e2.setSalary(10000);
    
    // inserting employees to the Company object
    ccs.hireEmployee(e1);
    ccs.hireEmployee(e2);
    
    // setting the name of the company
    ccs.setCompanyName("CCS");
    
    // getting values of object attributes
    // using the class getters
    cout<<"Welcome to "<<ccs.getCompanyName()<<"!\n";
    
    cout<<"Number of employees is: "<<ccs.getEmployeesNumber()<<"\n";
    
    cout<<ccs.showAllEmployees();
    
    cout<<"Employee "<<e1.getName()<<"was fired today! \n";
    //deleting an employee
    ccs.fireEmployee(e1.getNID());
    
    return 0;
}


