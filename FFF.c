//
// Created by Вадим Герасимович on 3/19/23.
//
#include "FFF.H"
int input(int min, int max){
    int x;
    while (scanf("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void task1(FILE* f){
    char c[127];
    printf("Введите строку :\n");
    if(fgets(c, 127, stdin) != NULL){
        fputs(c,f);
    }
    printf("Your filled file : %s\n", c);
}

void task2(FILE* f,char* argv){
    freopen(argv,"rt+",f);
    fflush(stdin);
    rewind(f);
    int n,freq[256]={0};
    char str[BUFSIZ];
    fgets(str, BUFSIZ, f);
    fclose(f);
    n=strlen(str)-1;
    for (int i = 0; i < n; i++) {
        freq[(int)str[i]]++; // увеличиваем частоту символа
    }
    printf("Частота вхождения каждого символа:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("[%c]: %d\n", i, freq[i]);
        }
    }

}
void task3(FILE* f,char* argv){
    char w,chr;
    freopen(argv,"rt+",f);
    printf("Введите символ замены : \n");
    fflush(stdin);
    scanf("%c", &w);
    fflush(stdin);
    rewind(f);
    fseek(f,0,SEEK_SET);
    char str[BUFSIZ];
    fgets(str, BUFSIZ, f);
    fclose(f);
    for(int i=0; str[i]!='\0'; i++)
    {
        chr = str[i];
        if(chr == ' ')
            str[i] = w;
    }
    freopen(argv, "wt+",f);
    fputs(str,f);
    printf("Pasted file : \n%s",str);
}
