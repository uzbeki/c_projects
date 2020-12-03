/* [Yesterday 12:13 PM] 伊藤秀明

第二課題（自作関数で文字列をソートしよう）
制約：ポインタを使うこと。


流れとしては以下のイメージ

input string before sorting:fbdenakgcjlmih
string after sorting:abcdefghijklmn

-----
作る関数イメージ。
引数
 *before  ソート前の文字列
 *after  ソート後の文字列
戻り値
 なし

void sort_str(const char *before, char *after)
*/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// character sorting function
void char_sort(char* str) {
    char temporary_value;
    int str_size = strlen(str);
    for (int i = 0; i < str_size - 1; i++) {
        for (int j = i + 1; j < str_size; j++) {
            if (*(str + i) > *(str + j)) {
                temporary_value = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = temporary_value;
            }
        }
    }
    // printf("Sorted: %s\n", str);
}


int main() {
    char* string = malloc(sizeof(char) * 128);
    printf("Please enter a string: \nBefore: ");
    scanf(" %s", string);
    // pass the string to the sorting function
    char_sort(string);
    printf("After: %s\n", string);
    return 0;
}
