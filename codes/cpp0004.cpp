// time 2020013014:48
// class

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

    return 0;
}