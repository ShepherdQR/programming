// time 2020021823:18
// class 02

//$ g++ cpp0006.cpp
//$ ./a.out

// Enclosing

#include<iostream>
#include<stdio.h>
using namespace std;

class CTyre{
    private:
        int radius;
        int width;
    public:
        CTyre(int r_in=0, int w_in=0):radius(r_in), width(w_in){
            cout << "Tyre: Normal Constructor called, and the information is: ( " << "0" << ", " << radius << ", " << width << " )." << endl;
        };// 初始化列表
        ~CTyre(){
            cout << "Tyre: Normal Destructor called." << endl;
        }
};

class CEngine{
    public:
        CEngine(){
            cout << "Engine: Normal Constructor called, and the information is: (  -  )." << endl;
        }
        ~CEngine(){
            cout << "Engine: Destructor called." << endl;
        }
    
};

class CCar;
class CDriver{
    // CDriver 要用到CCar，先写driver再写car。首先提前声明ccar
    public:
        void ModifyCar(CCar *pCar);
};

class CCar{
    private:
        int price;
        CTyre tyre;
        CEngine engine;
        
    public:
        CCar(){
            price = 1;
            cout << "Car: None Destructor called." << endl;
        }
        CCar(int pr_in, int ty_radius, int ty_width);
        ~CCar(){
            cout << "Car: Destructor called." << endl;
        }

    friend int MostExpensiveCar(CCar cars[], int total);//friend 放在 public或private里面都可以
    friend void CDriver::ModifyCar(CCar *pCar);
    friend class CDriver2;

    public:
        void setPrice(int price_in);
        
};
CCar::CCar(int pr_in, int ty_radius, int ty_width):price(pr_in), tyre(ty_radius, ty_width){
    cout << "Car: Normal Constructor called, and the information is: ( " << price << ", " << ty_radius << ", " << ty_width << " )." << endl;
};
void CCar::setPrice(int price_in){
    price = price_in;
}


void CDriver::ModifyCar(CCar *pCar){
    pCar->price += 1000;
}

int MostExpensiveCar(CCar cars[], int total){
    int tmpMax = -1;
    for (size_t i=0; i<total; ++i){
        if(cars[i].price > tmpMax)
            tmpMax = cars[i].price;
    }
    return tmpMax;
}


class CDriver2{
    public:
    CCar myCar;
        void ModifyCar(){
            myCar.price += 1000;
        }
};





class A{
    public:
        void function();
};

class B{
    friend void A::function();
};









int main(){
    CCar car(20000, 17, 225);

    CCar car2;
    car2.setPrice(66666);




    return 0;
}







/*
// in c++

class CCar{
    public:
        int price;
        void setPrice(int p);
};
void CCar::setPrice(int p){
    price = p;
}

int main(){
    CCar car;
    car.setPrice(20000);
    return 0;
}


// in c
struct CCar{
    int price;
};
void setPrice(struct CCar *this, int p){
    this->price = p;
}

int main(){
    struct CCar car1;
    setPrice(&car, 20000);
    return 0;
}
*/