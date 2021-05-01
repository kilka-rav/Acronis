#include "algo.h"

int* prefix_function(std::string substring, int* pi) {
    pi[0] = 0;
    int index = 0;
    int size = substring.length();
    for(int i = 1; i < size; ++i) {
        int k = pi[i - 1];
        while( ( k > 0) && ( substring[i] != substring[k] ) ) {
            k = pi[k - 1];
        }
        if ( substring[i] == substring[k] ) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}
        
int find_indexs(std::string string, std::string substring, int* pi) {
    int size_string = string.length();
    int size_substring = substring.length();
    for(int k = 0, i = 0; i < size_string; ++i) {
        while ( ( k > 0 ) && (substring[k] != string[i] ) ) {
            k = pi[k - 1];
        }
        if ( substring[k] == string[i] ) {
            k++;
        }
        if ( k == size_substring) {
            return i - size_substring + 1;
        }
    }
    return -1;
}



int KMP(std::string string, std::string substring) {
    int len = string.length();
    int mini_len = substring.length();
    if ( len < mini_len ) {
        return -2;        
    }
    int* pi = nullptr;
    pi = new int[substring.length()];
    pi = prefix_function(substring, pi);
    int num = find_indexs(string, substring, pi);
    delete pi; 
    return num;
}
