#include <stdio.h>

void file2array(FILE*, int*);
int get_arr_size(FILE*);

int main()
{
    FILE *fina;
    FILE *finb;
    FILE *fout;
    int *arra;
    int *arrb;

    fina = fopen("ina.txt","r");
    finb = fopen("inb.txt","r");
    fout = fopen("output.txt","w");

    file2array(fina, arra);
    file2array(finb, arrb);
    

    return 0;
}

void file2array(FILE* fin, int* arr)
{
    int size = get_arr_size(fin);
    printf("%d\n", size);
}

int get_arr_size(FILE* fin)
{
    return 0;
}
