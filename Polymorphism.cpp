#include<bits/stdc++.h>
using namespace std;


// abstract class 
/*
A class is made abstract by declaring 
at least one of its functions as pure virtual function. 
A pure virtual function is specified by placing "= 0"
*/

class Animal{
    public:
    
        // has to be overiden by subclass or compilation error
        virtual void speak() = 0;
        virtual void move() = 0;
        
        // will be available to all subclasses without overiding
        
        void eat(){
            cout<<"Eat your food"<<endl;
        }
};


//Classes that can be used to instantiate objects are called concrete classes.
class Cat : public Animal{
    public:
        void speak(){
            cout<<"meow....meow...."<<endl;
        }
        
        void move(){
            cout<<"Moving Cat"<<endl;
        }
};

class Dog : public Animal{
    public:
        void speak(){
            cout<<"woof....woof...."<<endl;
        }
        void move(){
            cout<<"Moving Dog"<<endl;
        }
};

class Lion : public Animal{
    public:
    void speak(){
        cout<<"rooaaarrr...."<<endl;
    }
    void move(){
        cout<<"Lion chases"<<endl;
    }
};

class AnimalUtility{
    public:
        static void makeNoise(vector<Animal*> animals){
            for(int i=0;i<5;i++){
                animals[i]->speak();
            }
        }
};

int main(){
    Animal* an;
    an = new Cat();
    an->speak();    // an working as cat and dog both this is called polymorphism
    an = new Dog();
    an->move();
    an->eat();
    vector<Animal*> animals;
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Lion());
    animals.push_back(new Dog());
    AnimalUtility :: makeNoise(animals);
    
    return 0;
}
