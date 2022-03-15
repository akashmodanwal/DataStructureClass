#include<bits/stdc++.h>
using namespace std;

class Property{
    private:
       
    public:
        const int investments;
        const int savings;
        Property(int investments, int savings) : investments(investments), savings(savings){
        }
        
        int getInvestments(){
            return this->investments;
        }
         int getSavings(){
             return this->savings;
         }
};

class Person{
  
  //hide data
    private:
        int age;
        string name;
        double weight;
        Property* property;
    
    public:
        Person(int age,string name,double weight ,Property* property){
            this->age = age;
            this->name = name;
            this->weight = weight;
            this->property = property;
        }
        
        void setAge(int age){
            if(age>0)
                this->age = age;
        }
        
        void setWeight(double weight){
            if(weight>0)
                this->weight = weight;
        }
        
        void setName(string name){
            if(name.size() > 3)
                this->name = name;
        }
        
        void setProperty(Property* property){
            this->property = property;
        }
        
        int getAge(){
            return this->age;
        }
        
        double getWeight(){
            return this->weight;
        }
        
        string getName(){
            return this->name;
        }
        
        Property* getProperty(){
            return this->property;
        }
};


int main(){
    Property* p = new Property(12000,7500);
    Person* p1 = new Person(22,"Akash",66.5,p);
    cout<<p1->getName()<<endl;
    cout<<p1->getAge()<<endl;
    cout<<p1->getProperty()->getInvestments()<<endl;
    //p1->name = 'a';    Person::name’ is private within this context
    p1->setName("a");  // not changed
    cout<<p1->getName()<<endl;
    //p1->getProperty()->investments = 12;  /// assignment of read-only member ‘Property::investments’  const
    return 0;
}
