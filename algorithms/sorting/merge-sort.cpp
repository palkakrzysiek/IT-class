#include <ctime>
#include <cstdio>
#include <cstdlib>

/* Merge (uses a local array, tempArray)
 * Set saveFirst to leftFirst // To know where to copy back
 * while more items in left half AND more items in right half
     * if values[leftFirst] < values[rightFirst]
         * Set tempArray[index] to values[leftFirst]
         * Increment leftFirst
     * else
         * Set tempArray[index] to values[rightFirst]
         * Increment rightFirst
     * Increment index
 * Copy any remaining items from left half to tempArray
 * Copy any remaining items from right half to tempArray
 * Copy the sorted elements from tempArray back into values
 */

void merge(int values[], int N, int leftFirst, int leftLast, int rightFirst, int rightLast){

    /*
     * Pre: values[leftFirst]..values[leftLast] are sorted; values[rightFirst]..values[rightLast] are sorted.
     * Post: values[leftFirst]..values[leftLast] and values[rightFirst]..values[rightLast]
     * have been merged. values[leftFirst]..values[rightLast] are now sorted.
     */

    int tempArray[N];
    int index = leftFirst;
    int saveFirst = leftFirst;


    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)){
        if (values[leftFirst] < values[rightFirst]){
            tempArray[index++] = values[leftFirst++];
        }
        else{
            tempArray[index++] = values[rightFirst++];
        }
    }


    while (leftFirst <= leftLast){
        // Copy remaining items from left half.
        tempArray[index++] = values[leftFirst++];
    }


    while (rightFirst <= rightLast){
        // Copy remaining items from right half.
        tempArray[index++] = values[rightFirst++];
    }


    for (index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];

}

void mergeSort(int values[], int N,  int first, int last){
    // Post: The elements in values are sorted by key.
    
    if(first<last){
        int middle = (first+last)/2;
        mergeSort(values, N, first, middle);
        mergeSort(values, N,  middle+1, last);
        merge(values, N, first, middle, middle+1, last);
    }
}


int* getRandomArray(int n, int min, int max){
    // require ctime and cstdlib 
    srandom(time(0));
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = random() % (max - min + 1) + min;
    }
    return arr;
}

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    putchar('\n');
}

int main(int argc, char const* argv[])
{

    for(int i = 1; i <= 41; i += 5){
        int *temp = getRandomArray(i, -25, 25);
        printarray(temp, i);
        mergeSort(temp, i, 0, i - 1);
        printarray(temp, i);
        delete [] temp;
    }


    return 0;
}

            //printf("index: %d; leftFirst: %d; leftLast: %d; rightFirst: %d; rightLast: %d\n", index, leftFirst, leftLast, rightFirst, rightLast);
