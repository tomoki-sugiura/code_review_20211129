#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

//#define SIZE_OF_ARRAY(array)    (sizeof(array)/sizeof(*array))

using namespace std;

//文字の桁数を返す
int GetDegit(int num){
    return (int)log10(num)+1;
}

//数値の先頭の桁の値を返す
int GetMaxDegitValue(int num){
    return (int)(num / pow(10, GetDegit(num) - 1));
}

//入力された自然数の配列から最大値を作る
void make_maxnum(int num[], int size){
    int output[size];

    int index = 0;
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < size; j++){
            if(GetMaxDegitValue(num[j]) == i){
                output[index] = num[j];
                index++;
            }
        }
    }

    cout << "[";
    for(int i = 0; i < size-1; i++)   cout << output[i] << ",";
    cout << output[size-1] << "]" << endl;
    return;
}

int main(void){
    int input[] = {1, 2, 3, 33, 54, 59, 82, 888, 9, 91};
    int size = sizeof(input) / sizeof(int);
    
    int i = 0;
    cout << "[";
    for(i = 0; i < size-1; i++)   cout << input[i] << ",";
    cout << input[i] << "]" << endl;

    make_maxnum(input, size);

    return 0;
}