#include<stdio.h>
void main(){
    int i, j,temp, n=5, array[5]={3,1,4,7,2};
    for(i=1;i<n;i++){
        temp = array[i];
        j = i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1] = temp;
/*    	if(array[i]>array[i+1]){
    		for (j=i; j>=0; j--)
    		{
    			if (array[j]>array[j+1])
    			{
    				temp = array[j+1];
    				array[j+1] = array[j];
    				array[j] = temp;
    			}
    		}
    	}
*/
    }
    for(i=0;i<n;i++){
        printf("%d \t", array[i]);
    }
}
