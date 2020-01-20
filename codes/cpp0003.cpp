// 定义常量,常量指针

#include <iostream>
#include <sstream>
using namespace std;

void MyPrintf( const char *p){
    //strcpy(p," by QR");
    //printf("%s\n",p);
    std::stringstream ss;
    ss << p << " by QR";

    cout << ss.str() << endl;
}

void MyPrintfcan( char *p){
    std::stringstream ss;
    ss << p << " by QR";
    cout << ss.str() << endl;
}



int
main(int argc, char * argv[]){
    int m,n;
    const int *p = &m;
    //*p = 5; 编译出错，不能通过常量指针修改其所指内容
    m = 4;
    n = 5;
    p = &n;// 可修改常量指针指向
    cout << *p << endl;

    const int *p1;
    int *p2;
    p1 = p2;
    //p2 = p1; //error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
    p2 = (int *)p1;

    // 自己造的，没有成功的说服力。
    char sen[] = "new year";
    MyPrintf(sen);
    MyPrintfcan(sen);
    
    return(0);
}