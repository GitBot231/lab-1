#include <iostream>
#include <windows.h>
using namespace std;

void flip_bit(void* data, size_t total_bits, size_t pos, char mode) {
    if (pos >= total_bits) return;

    size_t byte_idx = pos / 8;
    size_t bit_idx  = pos % 8;

    unsigned char* bytes = static_cast<unsigned char*>(data);
    unsigned char mask = 1u << bit_idx;

    if (mode == 's') bytes[byte_idx] |= mask;
    else if (mode == 'c') bytes[byte_idx] &= ~mask;
    else if (mode == 't') bytes[byte_idx] ^= mask;
}

///Задание 1
int main() {
   SetConsoleOutputCP(CP_UTF8);
    cout << "Задание 1" << endl;
    cout << "bool:" << sizeof(bool) << endl
     << "char:" << sizeof(char) << endl
     << "short int:" << sizeof(short int) << endl
     << "int:" << sizeof(int) << endl
     << "long int:" << sizeof(long int) << endl
     << "long long int:" << sizeof(long long int) << endl
     << "float:" << sizeof(float) << endl
     << "double:" << sizeof(double) << endl
     << "long double:" << sizeof(long double) << endl;
///Задание 2
    cout << endl;
    cout << "Задание 2" << endl;
    int a = -2278;
    cout << "int: " << a << " &int: " << &a << endl;
    cout <<endl;

    int order_i = sizeof(int) * 8;
    unsigned int mask_i = 1 << (order_i - 1);

    for (int i = 0; i < order_i; ++i) {
    if (i == 0) {
        cout << "[";
    }

    int bit = (a & (mask_i >> i)) ? 1 : 0;
    cout << bit;

    if (i == 0) {
        cout << "] ";
    }

    if ((i + 1) % 8 == 0 && i != order_i - 1) {
        cout << " ";
    }
}
cout << endl;
cout << endl;
///Задание 3
    cout << "Задание 3" << endl;
    union {
    float f = - 19.6;
    int pi_f;
    };
    cout << "float: " << f << " &float: " << &f << endl;
    cout <<endl;
    int order_f = sizeof(float) * 8;
    unsigned int mask_f = 1 << (order_f - 1);
    cout << '[';
    int sign_bit = (pi_f & mask_f) ? 1 : 0;
    cout << sign_bit;

    cout << "] ";
    
    for (int i = 30; i >= 23; --i) {
        unsigned int bit_mask = 1 << i;
        cout << ((pi_f & bit_mask) ? '1' : '0');
    }

    cout << " ";

    for (int i = 22; i >= 0; --i) {
        unsigned int bit_mask = 1 << i;
        cout << ((pi_f & bit_mask) ? '1' : '0');
    }
    cout << endl;
///Задание 4
    cout << endl;
    cout << "Задание 4" << endl;
    union {
    double d = -219.6;
    unsigned long long pi_d;
    };
    cout << "double: " << d << " &double: " << &d << endl;
    cout <<endl;

    int order_d = sizeof(double) * 8;
    unsigned long long mask_d = 1ULL << (order_d - 1);

    cout << '[';

    int sign_bit_d = (pi_d & mask_d) ? 1 : 0;
    cout << sign_bit_d;

    cout << "] ";
    
    for (int i = 62; i >= 52; --i) {
        unsigned long long bit_mask = 1ULL << i;
        cout << ((pi_d & bit_mask) ? '1' : '0');
    }

    cout << " ";

    for (int i = 51; i >= 0; --i) {
        unsigned long long bit_mask = 1ULL << i;
        cout << ((pi_d & bit_mask) ? '1' : '0');
    }
    cout << endl;
///Задание 5
    cout << endl;
    cout << "Задание 5" << endl;
    int x = 10;
    cout << "int before: " << x << endl;
    flip_bit(&x, sizeof(x) * 8, 1, 't');
    cout << "int after: " << x << endl << endl;

    long long y = -5;
    cout << "long long before: " << y << endl;
    flip_bit(&y, sizeof(y) * 8, 63, 'c');
    cout << "long long after: " << y << endl << endl;

    float z = 9.99;
    cout << "float  before: " << z << endl;
    flip_bit(&z, sizeof(z) * 8, 0, 't');
    cout << "float after: " << z << endl;

    
///Задание 6
    cout << endl;
    cout << "Задание 6" << endl;
    cout << "Программа, делающая число нечетным" << endl;
    cout << "Введите число:";
    int num;
    cin >> num;
    num |= 1;          
    cout << num << endl;
    return 0;

}




