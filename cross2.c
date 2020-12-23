#include <stdio.h>
#include <stdlib.h>


int file2array(FILE*, int**);
int get_arr_size(FILE*);
int f_min(int, int*);
int f_max(int, int*);
int cross(int, int, int, int*, int, int*);

int main()
{
    FILE *fina;
    FILE *finb;
    FILE *fout;
    int *arra;
    int *arrb;
    int s_arra;
    int s_arrb;

    fina = fopen("ina.txt","r");
    finb = fopen("inb.txt","r");
    fout = fopen("output.txt","w");

    s_arra = file2array(fina, &arra);
    s_arrb = file2array(finb, &arrb);

    int f_maxa = f_max(s_arra, arra);
    int f_minb = f_min(s_arrb, arrb);
    int cross_n = cross(f_maxa, f_minb, s_arra, arra, s_arrb, arrb);

    fprintf(fout, "%d\n",cross_n);

    fclose(fina);
    fclose(finb);
    fclose(fout);
    free(arra);
    free(arrb);

    return 0;
}

int file2array(FILE* fin, int** arr)
{
    int size = get_arr_size(fin);
    int* arr2 = malloc(sizeof(int)*size);
 
    fseek(fin, 0, SEEK_SET);

    for(int i=0; i<size; i++)
    {
        fscanf(fin, "%d", &arr2[i]);
        if(feof(fin))
            break;
        fgetc(fin);
    }

    *arr = arr2;

    return size;
}

int get_arr_size(FILE* fin)
{
    int buf;
    int count = 0;

    while(fscanf(fin, "%d", &buf))
    {
        if(feof(fin))
            break;

        count++;

        fgetc(fin);
    }

    return count;
}

int f_min(int size, int* arr)
{
    int f_minx = arr[0];

    for(int i=1 ; i< size; i++)
        if(f_minx > arr[i])
            f_minx = arr[i];

    return f_minx;
}

int f_max(int size, int* arr)
{
    int f_maxx = arr[0];

    for(int i=1 ; i< size; i++)
        if(f_maxx < arr[i])
            f_maxx = arr[i];

    return f_maxx;
}

int cross(int n_max, int n_min, int s1, int* arr1, int s2, int* arr2)
{
    int count = 0;

    for(int i=0 ; i< s1; i++)
        if(arr1[i] > n_min && arr1[i] < n_max)
        {
            printf("%d\n", arr1[i]);
            count++;
        }

    for(int i=0 ; i< s2; i++)
        if(arr2[i] > n_min && arr2[i] < n_max)
        {
            printf("%d\n", arr2[i]);
            count++;
        }

    return count;
}

