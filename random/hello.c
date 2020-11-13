#include <stdlib.h>
#include <stdio.h>
int main()
{
    int user_input;
    int result = 0;
    int cnt;

    printf("\n入力した数値から1ずつ引いて足し算する処理です。\n\n");
    printf("数値をください：　");
    scanf("%d", &user_input);

    /* while (user_input != 0)
    {
        result = result + user_input; 
        user_input = user_input - 1;
    } */

    // 終わりました。どうぞ
    for (cnt = 1; cnt <= user_input; cnt++)
    {
        result += cnt;
        //    ここで、cntの数がuser_inputの数に達するまで
        // resultに１を加えてという形ですね。cnt;
    }
    // for のマイナス
    for (cnt = user_input; cnt > 0; cnt--)
    {
        result += cnt;
    }

    

    
    /* for (user_input >= 0; user_input--)
    {
        result = result + user_input;
    } */

    printf("答えは：　%d", result);
}
