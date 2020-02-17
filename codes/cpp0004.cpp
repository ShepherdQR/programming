// time 2020013014:48
// class 01

#include<iostream>
#include<stdio.h>
using namespace std;

/*
    class Minion{
    Name:
    Hair_color:
    Eye_number:
    Clothes_type;

    GetMinionName();
    CountEyeNum();
    SetHairColor();
    SelectClothType();
    };
*/


class CreateRectangle{
    public:
        int w, h;
    
    void Init(int w_in, int h_in){
        w = w_in;
        h = h_in;
        cout << "This is a rectangle" << endl;
        cout << "width is: "<< w << endl;
        cout << "height is: "<< h << endl;
    }

    int Area(){
        return w * h;
    }

    int Perimeter(){
        return 2 *(w +h);
    }
};


class CreateRectangle2{
    public:
        int w, h;
        void Init(int w_in, int h_in);
        int Area();
        int Perimeter();
};
void CreateRectangle2::Init(int w_in, int h_in){
    w = w_in;
    h = h_in;
    cout << "This is a rectangle" << endl;
    cout << "width is: "<< w << endl;
    cout << "height is: "<< h << endl;
}
int CreateRectangle2::Area(){
    return w * h;
}
int CreateRectangle2::Perimeter(){
    return 2 *(w +h);
}


/*
    构建内联函数，出错了 ??S
    class CreateRectangle3{
        

            inline void Input3();
        //private:
        public:
            int w, h;    
            int Area3(){
                return w*h;
                cout << w*h << endl;
            };// attention ;
        


    };// attention ;
    void CreateRectangle3::Input3(int w_in, int h_in){
        w = w_in;
        h = h_in;
        cout << "This is a rectangle" << endl;
        cout << "width is: "<< w << endl;
        cout << "height is: "<< h << endl;
    }
*/



class Location20200216{
    private:
        int x, y;

    public:
        void init( int x = 0, int y = 0);

        void valueX(int val){
            x = val;
        }
        int valueX(){
            return x;
        }// overloading

        //void valueX(int val = 0){x = val;}// wrong, 二义性，编译器不知道调用默认值时是选用哪个函数


};// attention ;
void Location20200216::init(int x_in, int y_in){
    x = x_in;
    y = y_in;
}


class Complex20200216{
    private:
        double real, imag;
    public:
        void Set(double r, double i);
};


class Complex20200216_{
    private:
        double real, imag;
    public:
        void Set1(double r, double i);
        //Complex20200216_(double r, double i = 0);//在这里初始化为实数，至少需要一个参数
        Complex20200216_(double r, double i);
        Complex20200216_(double r);
        Complex20200216_(Complex20200216_ c1, Complex20200216_ c2);
        void Out(){
            cout << "( " << real << ", " << imag << " )" << endl;
        }
};
void Complex20200216_::Set1(double r, double i){
    real = r;
    imag = i;
}
Complex20200216_::Complex20200216_(double r, double i){
    real = r;
    imag = i;
}// 构造函数
Complex20200216_::Complex20200216_(double r){
    real = r;
    imag = 0;
}
Complex20200216_::Complex20200216_(Complex20200216_ c1, Complex20200216_ c2){
    real = c1.real + c2.real;
    imag = c1.imag + c2. imag;
}


class CScal{
    private:
        int x;

    public:
        CScal(){
            cout << "constructor 1 is out" << endl;
        }

        CScal(int x_in){
            x = x_in;
            cout << "constructor 2 is out" << endl;
        }
};


class Constructor_{
    public:
        Constructor_(int x){};
        Constructor_(int x, int y){};
        Constructor_(){};
};


class Complex17{
    // 20200217
    private:
        double real, imaginary;
    public:
        Complex17(double r_in, double i_in){
            real = r_in;
            imaginary = i_in;
        }
        Complex17(const Complex17 & complex_in){
            real = complex_in.real;
            imaginary = complex_in.imaginary;
            cout << "2200217-01-ok" << endl;
        }
        void Out(){
            cout << "( " << real << ", " << imaginary << " )" << endl;
        }
};


class Test1{
    private:
    public:
        Test1(){}
        Test1(Test1 & test_1){
            cout << "Copy-constructor is called." << endl;
        }
};
void Function1(Test1 test_2){}// test_2 is initializated by copy-instructor


class Test2{
    public:
        int xx;
        Test2( int xx_in = 0){
            xx = xx_in;
            cout << "ooops" << endl;
        };
        Test2(const Test2 & xx_in2){
            xx = xx_in2.xx;
            cout << "Copy-constructor is called, too." << endl;
        }
};
Test2 Func2(){
    Test2 zz;
    Test2 yy(zz);
    Test2 yy2;
    Test2 yy3;
    return yy;
}// when Func2 is used in main, the output is 
// ooops
// Copy-constructor is called, too.
// ooops
// ooops
// 0
// just like the four Test2 objects in Func2.










void PrintRectangle(CreateRectangle &r6){
    cout << r6.Area()<< endl << r6.Perimeter()<<endl;
}

int main(){
    int w, h;
    CreateRectangle r;
    cin >> w >> h;
    r.Init(w, h);
    cout << r.Area()<< endl << r.Perimeter()<<endl;
    cout << sizeof(r) << endl;// 大小等于所有成员的大小，即2个int=8

    CreateRectangle r1, r2;
    r1.w = 5;
    r2.Init(4,5);

    CreateRectangle r3, r4;
    CreateRectangle *p3 = &r3;
    CreateRectangle *p4 = &r4;
    p3->w = 5;
    p4->Init(4,5);

    CreateRectangle r5;
    CreateRectangle &r5_ = r5;
    r5_.w = 5;
    r5_.Init(4,5);

    CreateRectangle r7;
    r7.Init(5,6);
    PrintRectangle(r7);

    cout << "20200216" << endl;
    // CreateRectangle3 r8;
    // r8.Input3(4,5);
    // r8.Area3();
    Location20200216 l9;
    l9.init(5);
    l9.valueX(5);
    cout << l9.valueX() << endl;

    Complex20200216 c10;
    Complex20200216 *c11 = new Complex20200216;

    Complex20200216_ c12(3);
    Complex20200216_ *c13 = new Complex20200216_(3, 4);

    Complex20200216_ c14(3, 4);
    Complex20200216_ c15(c12, c14);
    Complex20200216_ c16(c14); //省却的复制构造函数
    c16.Out();


    CScal array1[2];//2个无参数初始化
    CScal array2[2] = {4, 5};
    CScal array3[2] = {3};
    CScal *array4 = new CScal[2];
    delete []array4;//2个无参数初始化

    Constructor_ array5[3] = {1, Constructor_(1,2)};
    Constructor_ array6[3] = {Constructor_(2,3), Constructor_(1,2), 1};
    Constructor_ *parray7[3] = {new Constructor_(4), new Constructor_(1,2)};// attention, 这里 是一个指针数组，每个对象都是指针，指针可以不初始化。 如果没有等号右边，不会导致对象生成。 在这里只是生成了2个对象，跟别用的第1和第2个构造函数。

    // 20200217: copy construntor
    Complex17 c17(22,1);
    Complex17 c18(c17);
    c18.Out();

    Test1 c19;
    Function1(c19);// 实参c19的值和形参test_2的值不一定

    //Func2();
    cout << Func2().xx << endl;



    return 0;
}