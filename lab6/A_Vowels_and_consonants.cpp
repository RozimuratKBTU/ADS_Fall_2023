

#include<bits/stdc++.h>

using namespace std;

bool is_vowel(char z){
    switch (z)
    {
        case('a'):
        case('e'):
        case('i'):
        case('o'):
        case('u'):
            return true;
            break;

        default:
            return false;
    }
}
// abcde -> aebcd

int partition(char chars[], int low, int high){ // partition implementation -> abcde
    int pivot = chars[high]; //  piv = chars[4]
    int index = low - 1; // ind = -1
    for(int j = low; j < high; j++){ // (j = 0; j <= 4; j++)
        if(((is_vowel(chars[j]) && is_vowel(pivot) || !is_vowel(chars[j]) && !is_vowel(pivot)) && chars[j] < pivot) || is_vowel(chars[j]) && !is_vowel(pivot)){
            // 1 iteration: (((1 || 0) && 0) && a < e) || (1 && 0) = 0
            index++;
            swap(chars[index], chars[j]);
            // cout << pivot << chars[j] << endl;
        }
    }
    swap(chars[index + 1], chars[high]); // ebcda
    // cout << chars[index + 1] << chars[high] << endl;
    return index + 1; // index = 0
}

void quickSort(char chars[], int low, int high){ // quick sort implementation (chars[], 0, 5 - 1)
    if(low < high){ // if(0 < 4)
        int pi = partition(chars, low, high); // pi = partition(chars[], 0, 5)
        quickSort(chars, low, pi - 1);
        quickSort(chars, pi + 1, high);
    }
}

int main(){ // driver code
    int number; cin >> number; // 5
    char chars[number];
    int i = 0;;
    for(int i = 0; i < number; i++) cin >> chars[i];
    quickSort(chars, 0, number - 1);
    for(int i = 0; i < number; i++) cout << chars[i];
}
