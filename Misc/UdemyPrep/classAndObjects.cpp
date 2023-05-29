/*
    Object-Oriented Programming
    Class :
        Blueprint from which object are created
        user-defined data type
        has attributes and methods of different visibility
    
    Creating an object: <Class> <user-defined name>
                        <Class> *<user-defined name> = new <Class>();
                        delete <user-defined name> --> when we allocate using the new keyword

    Creating  a class:
    class <user-defined name>
    {
        public:
        private:
        protected:
        // declarations;
    }

    Can use in arrays and vectors also

    static class members
    a single data member that belongs to the class, not the objects
    useful to store class-wide information

    static class functions
    independent of any objects
    can be called using the class name
*/

#include <iostream>
#include <string>
#include <vector>

class Account
{
    private:
        static int num_acc;
        std::string name;
        double balance;
    public:
        Account(): name{"None"}, balance{0}{}; // constructor initializaion list
        Account(std::string _name, double _balance): name{_name}, balance{_balance}{
            num_acc++;
        };
        Account(std::string namey):Account{namey , 0}{
            num_acc++;
        }; // delegating constructor
        ~Account(){
            num_acc--;
        };
        static int get_num_acc(){return num_acc;}

        // Declaring the copy constructor
        //Type::Type(const Type &source); --> const type as we are copying the stuff, no edits is required
        Account(const Account &source):name{source.name}, balance{source.balance}{
            /*
                if we have a pointer as a variable and we are doing a deep copy, we should allocate memory for our new pointer here
                for a shallow copy, we do not need to have this step in our copy constrctors 
                &source is a L-value reference
            */

        /*
            Syntax for r-value reference
            Type::Type(Type &&source)
            Move::Move(Move &&source): data{source.data}{
                source.data = nullptr;
            }
        */

        };
        bool withdraw(double amount){};
        bool deposit(double amount){};

        // Shallow vs Deep Copying for raw pointers
        /*
            Shallow Copy is the dafault, it will copy the pointer to the data and not the actual data
            Will get into trouble when the referenced pointer is deleted

            Doing Deep Copy --> create a copy of the pointed-to data
            used when we have a raw pointer as a class data memeber
        */

       /*
        Move Constructor
        R-values are temp objects holders in move constructor
        L-values are those that can be referred to to obtain a value
        move contructirs rather than copy it --> to prevent performance bottleneck
        copy the address of the resources from source to the current object , nulls pointers in the source --> very efficiennt

        R-value references
        used in moving semantics and perfect forwarding
        used by move semantics and move assignment operator to efficiently move an object rather than copy it
        R-value operator (&&)
        int &&r_ref = 200;
        vs 
        int x{100};
        int &l_ref = x;

        void func(int &num) --> function requires a l-value as a input parameter
        void func(int &&num) --> function requires a l-value as a input parameter
       */

      /*
        Friend of a Class
        a function/ class that has access to private class member  and that function/class is NOT a member of the class it is accessing
        function: can be regular non-member function or member of another class
        class: class can have access to private class members 
      */
};

/*
    Struct vs Classes
    Similiar to classes, whatever we do with classes, we can do with structs
    struct members are public by default, classes members are private by default.

    Use struct for passive objects with punlic access , dont declare methods in struct
    Use class for active objects with private access, getters/setters + member methods
*/


int main()
{
    
    return 0;
}

