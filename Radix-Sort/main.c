#include <stdio.h>


int get_max( int arr[], int n){

    int myMax = -1 ;
    for(int i=0; i<n; i++){
        if(arr[i] > myMax)myMax = arr[i] ;
    }

    return myMax ;
}

void count_sort(int arr[], int n, int digit){
    int count[10] = {0} ;
    int sorted[n] ;

    for(int i=0; i<n; i++){
        count[(arr[i]/digit)%10]++ ;
    }
    for(int i=1; i<10; i++){
        count[i] += count[i-1] ;
    }

    for(int i=n-1; i>=0; i--){
        sorted[--count[(arr[i]/digit)%10]] = arr[i] ;
    }

    for(int i=0; i<n; i++){
        arr[i] = sorted[i] ;
    }
}

void radix_sort(int arr[], int n){

    int myMax = get_max(arr,n) ;

    for(int digit=1; myMax/digit; digit*=10){
        count_sort(arr,n,digit) ;
    }
}

int main() {

    int arr[] = {374, 42, 6, 920,825} ;
    int n = sizeof(arr)/sizeof(int) ;

    printf("Before sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d",arr[i] );
        printf(" ") ;
    }

    radix_sort(arr, n) ;

    printf("\n\nAfter sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d",arr[i] );
        printf(" ") ;
    }
    return 0;
}
