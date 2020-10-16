#include <stdio.h>
#define max 12
int a[max] = {22, 19, 24, 1, 0, -2, 18, 91, 6, -100, -15, -26, 8, 19};
int b[max];

void array_spliting(int low, int mid, int high){
   int x, y, i;

   for(x = low, y = mid + 1, i = low; x <= mid && y <= high; i++){
      if(a[x] <= a[y])
         b[i] = a[x++];
      else
         b[i] = a[y++];
   }
   while(x <= mid)
      b[i++] = a[x++];

   while(y <= high)
      b[i++] = a[y++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void merge(int low, int high){
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      merge(low, mid);
      merge(mid+1, high);
      array_spliting(low, mid, high);
   } else {
      return;
   }
}

int main(){
   int i;
   printf("List:\t");
   for(i = 0; i < max; i++)
      printf("%d ", a[i]);

   merge(0, max);
   printf("\n\nmerge:\t");
   for(i = 0; i < max; i++)
      printf("%d ", a[i]);
}
