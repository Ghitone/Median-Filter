#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

int main()
{
    FILE *f1, *f2;
    int i=0, k=0, j=0, o=0, temp_j, temp_i, l=0, m=0;
    int n, count;
    int width, height, val_maxima, width_nou, height_nou;
    char tip[2];
    int *arr;
    int **fereastra;
    char fisier_intrare[20], fisier_iesire[20];
    char metoda[10];
   	scanf("%s",metoda);
   	printf("%s",metoda);
	scanf("%d", &n);
   	scanf("%s", fisier_intrare);
    scanf("%s", fisier_iesire);
    arr = (int*)malloc(n*n*sizeof(int));
    fereastra = (int**)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
		fereastra[i] = (int*)malloc(n*sizeof(int));



    f1=fopen(fisier_intrare,"r");
    if (f1==NULL)
        printf("Fisierul nu a putut fi deschis!");
    fscanf(f1,"%s",tip);
    fscanf(f1,"%d",&height);
    fscanf(f1,"%d",&width);
    fscanf(f1,"%d",&val_maxima);

	width_nou = width + (n-1);
	height_nou = height + (n-1);

	int **poza;
	int **poza_buna;
    poza = (int**)malloc(height_nou*sizeof(int*));
    for (i=0;i<=height_nou;i++)
		poza[i] = (int*)malloc(width_nou*sizeof(int));
    poza_buna = (int**)malloc(height_nou*sizeof(int*));
    for (i=0;i<height_nou;i++)
		poza_buna[i] = (int*)malloc(width_nou*sizeof(int));

    printf("%d\n",val_maxima );

    for (i = (n-1)/2 ; i <= height + (n-1)/2 ; i++)
        for (j = (n-1)/2; j < width + (n-1)/2  ; j++)
    		fscanf(f1,"%d",&poza[i][j]);


//COLT 1
	for (i = 0; i < (n-1)/2; i++)
		for (j = 0; j < (n-1)/2; j++){
			poza[i][j] = poza[(n-1)/2][(n-1)/2];
		}
//COLT 2
	for (i = 0; i < (n-1)/2; i++)
		for (j =  width + (n-1)/2; j < width_nou; j++){
			poza[i][j] = poza[(n-1)/2][width + (n-1)/2 -1];
		}
//COLT 3
	for (i = height + (n-1)/2; i < height_nou; i++)
		for (j = 0; j < (n-1)/2; j++){
			poza[i][j] = poza[(height + (n-1)/2 -1)][(n-1)/2];
		}
//COLT 4
	for (i = height + (n-1)/2; i < height_nou; i++)
		for (j = width + (n-1)/2; j < width_nou; j++){
			poza[i][j] = poza[ height + (n-1)/2 -1][ width + (n-1)/2 -1];
		}


//MIJL 1

	k = (n-1)/2;
	o = (n-1)/2;
		for (i = 0; i < (n-1)/2; i++)
			for (j = (n-1)/2; j < width + (n-1)/2; j++){
				poza[i][j] = poza[k][o];
				o++;
		}
//MIJL 2
	k = (n-1)/2;
	o = (n-1)/2;
		for (i = (n-1)/2; i < height + (n-1)/2; i++){
			for (j = 0; j < (n-1)/2; j++){
				poza[i][j] = poza[k][o];
        }
		k++;
    }
//MIJL 3
	k = (n-1)/2;
	o = width + (n-1)/2 -1;
		for (i = (n-1)/2; i < height + (n-1)/2; i++){
			for (j = width + (n-1)/2; j < width_nou; j++){
				poza[i][j] = poza[k][o];
			}
		k++;
	}
//MIJL 4
	k = height + (n-1)/2 -1;
	o = (n-1)/2;
		for (i = height + (n-1)/2 -1; i < height_nou; i++){
			for (j = (n-1)/2; j < width + (n-1)/2; j++){
				poza[i][j] = poza[k][o];
				o++;
		}
	}
    for (i = (n-1)/2 ; i <= height + (n-1)/2 ; i++){
        for (j = (n-1)/2; j < width + (n-1)/2  ; j++){
		temp_i = i;
        temp_j = j;
		k=0;
		o=0;	
		while (k<n){
			o=0;
			temp_j = j;
			while (o<n){

				fereastra[k][o] = poza[temp_i-(n-1)/2][temp_j-(n-1)/2];
				o++;
				temp_j++;
				}
			k++;
			temp_i++;
		}
		k=0;
    	for (l = 0; l < n ; l++)
			for (m = 0 ;m < n ; m++){
				arr[k] = fereastra[l][m];
				k++;
			}
		if(strcmp(metoda,"merge") == 0){
		mergeSort(arr, 0,n*n-1);
		poza_buna[i][j] = arr[(n*n-1)/2];
		}
		else {
			bubbleSort(arr, n*n-1);
			poza_buna[i][j] = arr[(n*n-1)/2];
		}
		}
	}
    fclose(f1);
    f2=fopen(fisier_iesire,"w");
    if (f1==NULL)
        printf("Fisierul nu a putut fi deschis!");
    fprintf(f2,"%s\n",tip);
    fprintf(f2,"%d ",height);
    fprintf(f2,"%d\n",width);
    fprintf(f2,"%d\n",val_maxima);
    for (i = (n-1)/2 ; i <= height + (n-1)/2 ; i++){
        for (j = (n-1)/2; j < width + (n-1)/2 ; j++)
            fprintf(f2,"%d ",poza_buna[i][j]);
        fprintf(f2, "\n");
    }

    return 0;
}

