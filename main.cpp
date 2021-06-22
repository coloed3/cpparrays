#include <iostream>


void printArray(int a[], int n);
void sortArray(int a[], int n);
int getHighestValue(int a[], int n);
int getLowestValue(int a[], int n);
int getMean(int a[], int n);
int getMedian(int a[], int n);
void swapElements(int a[], int i, int j);
int main() {

    int a[11] = {87,59,55,22,17,12,9,4,3,123,12943};
//  std:: cout << getHighestValue(a, 10);
//  std:: cout << getLowestValue(a, 11);
//  std:: cout << getMean(a, 11);
  std:: cout << getMedian(a, 10);
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        std:: cout << a[i] << ", ";
    }
}

void sortArray(int a[], int n){
    bool swapped = true;
    while(swapped){
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                swapElements(a, i, i + 1);
                swapped = true;
            }
        }
    }
}

void swapElements(int a[], int i, int j){
    int tempValue = a[i];
    a[i] = a[j];
    a[j] = tempValue;
}



int getHighestValue(int a[], int n) {
    // we will use this  as the start for the array
    int max = a[0];

    for (int i = 0; i < n ; i++){
    //n will be the total number in the array 10
        if(a[i] > max){
            // we need  1 traverse the given array which is a[i] compare it to max= a[0] if it is greater than max then we
            //update max
            max = a[i];
        }
    }

    return max;
}

int getLowestValue( int a[], int n){
    //we need to be able to change a[] to min when updating
    int min =  a[0];
    /* we will be following the same logic, only thing we will be doing now is saying if
     * min < i give me min
     *
     */
    for(int i = 0; i < n; i++){
        if (a[i]  < min){
            min = a[i];
        }
    }
    return min;
}


/* find the meeam of an array
 * sum will be our variable we will use ot traversay sum += a[i]
 * return (double)sum / (double)n ;
 *
 */

 int getMean(int a[], int n){

     int sum = 0;

    for (int i = 1; i < n; i++)
        sum += a[i];

     return (double) sum / (double)n;
 }

 int getMedian(int a[], int n){
    /*
     * in the array median is the middle number after a sort,
     * since we havent sorted it yet we willned to sort then loop
     * through to grab the median
     * Median = 1/2 (n+1)the value
     * if n%2 !=0 we will then return the a[n divided by 2]
     * std :: sort will sort the  elements in the range ( first to last) desending order
     */
     std::sort(a, a+n);

     if( n % 2 !=0){
         return (double)a[n / 2];
     }
     return (double)(a[(n - 1)/2] + a[n/2]) / 2;
 }