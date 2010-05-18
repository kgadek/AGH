#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void fill(int tab[], int size){
    int i;
    srand(time(0));
    for(i=0;i<size;i++){
        tab[i]=rand()%50;
    }
}
 
int parent(int i){
    i++;
    i/=2;
    i--;
    return i;
}
 
int left(int i){
    i++;
    i*=2;
    i--;
    return i;
}
 
int right(int i){
    i++;
    i*=2;
    return i;
}
 
void heapify(int a[], int i, int heapsize){
    int max,temp;
    int l=left(i);
    int r=right(i);
    if(l<=(heapsize-1) && a[l]>a[i]){
        max=l;
    }
    else{
        max=i;
    }
    if(r<=(heapsize-1) && a[r]>a[max]){
        max=r;
    }
    if(max!=i){
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
        heapify(a,max,heapsize);
    }
}
 
void buildheap(int a[], int size){
    int i;
    for(i=(size/2)-1;i>=0;i--){
        heapify(a,i,size);
    }
}
 
void heapsort(int a[], int size){
    buildheap(a,size);
    int i,temp;
    for(i=(size-1);i>=1;i--){
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        size--;
        heapify(a,0,size);
    }
}
 
void writy(int tab[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%i ", tab[i]);
    }
}
 
int main(){
    int t[20];
    fill(t,20);
    heapsort(t,20);
    writy(t,20);
}