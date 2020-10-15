#include<stdio.h>
void main(){
    int i, j,temp, n=5, array[5]={3,1,4,7,2};
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
            //printf("i, j = %d %d \n", i, j);
        }
    }
    for(i=0;i<n;i++){
        printf("%d \t", array[i]);
    }
}
