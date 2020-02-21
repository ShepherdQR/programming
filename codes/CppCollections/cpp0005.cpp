// time 2020021723:03
// class 02

//$ g++ cpp0005.cpp
//$ ./a.out

// constructor and destructor
// static

#include<iostream>
#include<stdio.h>
using namespace std;



class Complex{
    

    private:
        double real, imagination;
        char *p;
        static int complexNumber;
        static int sumTotal[2];

    public:
        Complex(double r_in, double i_in){
            // constructor
            real = r_in;
            imagination = i_in;
            cout << "Complex: Normal Constructor called, and the number is: ( " << real << ", " << imagination << " )." << endl;
            //p = new char[10];
            complexNumber += 1;
            sumTotal[0] += real;
            sumTotal[1] += imagination;
        }
        Complex(){
            real = 0;
            imagination = 0;
            cout << "Zero: Normal Constructor called, and the number is: ( " << real << ", " << imagination << " )." << endl;
            complexNumber += 1;
            sumTotal[0] += real;
            sumTotal[1] += imagination;
        }
        Complex(double r);
        Complex(Complex c1, Complex c2);

        Complex(const Complex & copy_in){
            // copy constructor
            // attention: const
            real = copy_in.real;
            imagination = copy_in.imagination;
            cout << "Copy Constructor called, and the number is: ( " << real << ", " << imagination << " )." << endl;
            complexNumber  += 1;
            sumTotal[0] += real;
            sumTotal[1] += imagination;
        }
        
         ~Complex(){
        //     delete [] p;
            cout << "Destructor called, and the number is: ( " << real << ", " << imagination << " )." << endl;
            complexNumber -= 1;
            sumTotal[0] -= real;
            sumTotal[1] -= imagination;
         }//有问题

        Complex(int r_in){
            // 类型转换构造函数
            // 只有一个参数
            real = r_in;
            imagination = 0;
            cout << "Int Constructor called, and the number is: ( " << real << ", " << imagination << " )." << endl;
        }
        
        void Out(){
            cout << "( " << real << ", " << imagination << " )" << endl;
        }
        
        static void PrintTotal();
};
int Complex::complexNumber = 0;//静态变量需要在类的文件中，在类外进行一次说明或初始化；
int Complex::sumTotal[2]={0,0};

Complex::Complex(double r){
    real = r;
    imagination = 0;
    cout << "Real: Normal Constructor called, and the number is: ( " << real << ", " << imagination << " )." << endl;
    complexNumber += 1;
    sumTotal[0] += real;
    sumTotal[1] += imagination;
}
Complex::Complex(Complex c1, Complex c2){
    real = c1.real + c2.real;
    imagination = c1.imagination + c2. imagination;
    cout << "Combine: Normal Constructor called, and the number is: ( " << real << ", " << imagination << " )."  << endl;
    complexNumber += 1;
    sumTotal[0] += real;
    sumTotal[1] += imagination;
}
void Complex::PrintTotal(){
    cout << "There lived " << complexNumber << " complex numbers, the sum is: ( " << sumTotal[0] << " , " << sumTotal[1] << " )." << endl;
}






Complex c4(1);
void Func(){
    static Complex c5(2);//静态变量在程序结束时消亡
    Complex c6(3,4);
    cout << "Func initialization." << endl;
}//注意到程序调用后，出作用域c6(3,4)立即消亡



void PrintVector(int x_in[], int n){
    cout << "( ";
    for(int i=0; i < n, ++i;){
        cout << x_in[i] << ", ";
    }
    cout << " )" << endl;
}



int main(){
    cout << "main test starts ..." << endl;
    Complex c1(6,5);
    Complex c2 = 12;//对c2初始化，不生成临时对象，
    c1 = 9;// 赋值语句，自动调用类型转换构造函数，生成临时的Complex对象 //Int Constructor called, and the number is: ( 9, 0 ).
    c1.Out();
    Complex array[2];//每个数组元素都初始化，都析构

    Complex *c3;
    c3 = new Complex;//Zero: Normal Constructor called
    delete c3;//Destructor called
    cout << "c3 out.." << endl;
    c3 = new Complex[3];
    delete [] c3;

    cout << "Func test starts ..." << endl;
    {Complex c7(7);} // 对象离开作用域会析构，在这里是Int Constructor called, and the number is: ( 7, 0 ). 立即 Destructor called, and the number is: ( 7, 0 ).
    Func();
    // 接下来如果是 return 0}；则变量的消亡从定义变量的倒序开始，先从下向上析构main中的变量，然后向上走析构（函数内的static 和 全局变量 地位一样）

    Complex::PrintTotal();
    int s[3]={6,6,6};
    //PrintVector(s, 2);
    //PrintVector(Complex::sumTotal[2], 2);// wrong, because: int Complex::sumTotal [2]’ is private

    return 0;
}