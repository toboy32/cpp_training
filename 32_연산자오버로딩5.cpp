// 32_연산자오버로딩5.cpp
#include <iostream>
using namespace std;

// 정수의 역활을 수행하는 클래스 타입입니다.
class Integer {
    int value;

public:
    Integer(int n = 0)
        : value { n }
    {
    }

    // ++v;
    Integer& operator++()
    {
        ++value;
        return *this;
    }

    // v++;
    Integer operator++(int)
    {
        Integer temp { *this }; // 복사본
        ++value;

        return temp;
    }

    friend ostream& operator<<(ostream& os, const Integer& i);
};

ostream& operator<<(ostream& os, const Integer& i)
{
    return os << i.value;
}

int main()
{
    Integer n = 42; // 생성자 호출
    ++n;
    // n.operator++()

    cout << n << endl;

    // Integer
    /*
        sub     rsp, 24
        mov     DWORD PTR n$[rsp], 42           ; 0000002aH
        mov     eax, DWORD PTR n$[rsp]
        inc     eax
        mov     DWORD PTR n$[rsp], eax
        xor     eax, eax
        add     rsp, 24
        ret     0

    */

    // int
    /*
        sub     rsp, 24
        mov     DWORD PTR n$[rsp], 42           ; 0000002aH
        mov     eax, DWORD PTR n$[rsp]
        inc     eax
        mov     DWORD PTR n$[rsp], eax
        xor     eax, eax
        add     rsp, 24
        ret     0
    */
}

#if 0
// ++n;
//   C: 증가된 n의 값
// C++: 증가된 n의 참조
int main()
{
    //   C: for (int i = 0 ; i < n; i++) {}
    // C++: for (int i = 0 ; i < n; ++i) {}

    Integer v = 42;
    cout << ++v << endl;
    // v.operator++(); // ++v;

    cout << v++ << endl;
    // C++: 내부의 값이 증가하고, 증가되기 이전의 복사본(값)

    // v.operator++(int); // v++;

    cout << v << endl;

    int n = 42;
    ++ ++ ++n;
    n++;

    cout << n << endl;
}
#endif
