
#include <iostream>

using namespace std;

class Person {
    // simple person class with attribues
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
    void setNID(string id) {
        n_id = id;
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

void mainScreen(){
    cout<<"-----------------------\n";
    cout<<"1- Show Company name.\n";
    cout<<"2- Change Company name.\n";
    cout<<"3- Hire new employee.\n";
    cout<<"4- Fire employee.\n";
    cout<<"5- Show all employesa.\n";
    cout<<"6- Exit.\n";
    cout<<"-----------------------\n";
    cout<<"Choice: ";
}

int main(int argc, const char * argv[]) {
    // making objects from classes
    Employee e1;
    Employee e2;
    Company ccs;
    int choice = 0;
    string name;
    string ename, ephone, eid;
    int esalary, eage;
    string n;
    
    // inserting employees to the Company object
    
    
    // setting the name of the company
    ccs.setCompanyName("CCS");
    
    e1.setNID("2980615");
    e1.setName("Maher");
    e1.setAge(22);
    e1.setPhone("012206450");
    e1.setSalary(25000);
    
    e2.setNID("2970101");
    e2.setName("Ahmed Mokhtar");
    e2.setAge(21);
    e2.setPhone("01285742060");
    e2.setSalary(10000);
    
    ccs.hireEmployee(e1);
    ccs.hireEmployee(e2);
    cout<<"Welcome to Employees Management System!\n"<<endl;
    mainScreen();
    while(choice != 6){
    cin>>choice;
        cout<<"--------------------\n";
    switch (choice) {
        case 1:
            cout<<"Company current name: "<<ccs.getCompanyName()<<endl;
            mainScreen();
            break;
        case 2:
            cout<<"Enter new name: ";
            cin>>name;
            ccs.setCompanyName(name);
            cout<<"Name have been changed successfully!"<<endl;
            mainScreen();
            break;
        case 3:
            cout<<"Name: ";
            cin>>ename;
            cout<<"Age: ";
            cin>>eage;
            cout<<"Salary: ";
            cin>>esalary;
            cout<<"National ID: ";
            cin>>eid;
            cout<<"Phone: ";
            cin>>ephone;
            
            e1.setSalary(esalary);e1.setPhone(ephone);
            e1.setAge(eage);e1.setName(ename);
            e1.setNID(eid);
            ccs.hireEmployee(e1);
            cout<<"Employee hired Successfully!"<<endl;
            mainScreen();
            break;
        case 4:
            cout<<"Enter the National ID of the employee who you want to fire: ";
            cin>>n;
            if(ccs.fireEmployee(n)){
                cout<<"Employee fired successfully!\n";
            }else{
                cout<<"Couldn't find the employee!";
            }
            mainScreen();
            
            break;
        case 5:
            cout<<"Employees: \n";
            cout<<ccs.showAllEmployees()<<endl;
            mainScreen();
            break;
        case 6:
            cout<<"Thanks for using the program!"<<endl;
            break;
            
        default:
            break;
    }
    
    }
    return 0;
}






