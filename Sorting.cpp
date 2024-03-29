#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <fstream>

#include "MaxHeap.h"
#include "SortAlgorithms.h"


using namespace std;
void data_set (int a[],int data_set_size);
void Unsorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end);
void Half_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end);
void Fully_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end);
void fill_struct(Astruct arr[],int size, int data[],int size_2);
void test_Struct(Astruct arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end,int data_set[],int size);

int main () {
    static int * array = new int [1000000000];

    Astruct * key_array = new Astruct [50000000];
    long int data_Set_Size=10000,size=100;
    int data[100];
    data_set(data,size);
    double elapsed=0;
    clock_t start, end;



    Unsorted_Data_Test(array,data_Set_Size,elapsed,start,end);
    Half_Sorted_Data_Test(array,data_Set_Size,elapsed,start,end);
    Fully_Sorted_Data_Test(array,data_Set_Size,elapsed,start,end);
    test_Struct(key_array,data_Set_Size,elapsed,start,end,data,size);
    // write code here to perform experiments with the sort algorithms

    return 0;
}

void data_set (int a[],int data_set_size){
    mt19937_64 generator(time(0));
    uniform_int_distribution<long long unsigned>distribution(0,1000000000);
    long long int i=0;
    for (  i=1; i < data_set_size; i++){
        a[i]= distribution(generator);
    }
}

void Unsorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end) {
    cout<<"Unsorted Data"<<endl<<endl;
    ofstream out;
    out.open("Unsorted Statistics.csv");

    out << "Unsorted Data Test" << endl;

    int i = 1;
     elapsed = 0;
    cout << "***Selection Sort***" << endl;
    out << "Selection Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed <= 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = (Data_Set_Size / 4);
    float quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***Bubble Sort***" << endl;
    out << "Bubble Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
        out << "" << endl;
    }
    i = 1;
    elapsed = 0;
    cout << "***Insertion Sort***" << endl;
    out << "Insertion Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    out << i << "," << elapsed << "," << Data_Set_Size << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***MergeSort***" << endl;
    out << "MergeSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***QuickSort***" << endl;
    out << "QuickSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        quickSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        quickSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***Maxheap***" << endl;
    out << "Maxheap" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***RadixSort***" << endl;
    out << "RadixSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;

        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
}

void Half_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end){
    cout<<"Half Sorted Data"<<endl<<endl;
    ofstream out;
    out.open("Sorted Statistics.csv");

    out<<"Sorted Data Test"<<endl;

    int i=1,full=1000000000;
    elapsed=0;
    data_set(arr, full);
    cout<<"***Selection Sort***"<<endl;
    out<<"Selection Sort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<=180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        selectionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }

    out<<""<<endl;

    i=1;
    elapsed=0;
    data_set(arr, full);
    cout<<"***Bubble Sort***"<<endl;
    out<<"Bubble Sort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        bubbleSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    elapsed=0;
    data_set(arr, full);
    cout<<endl<<"***Insertion In Place***"<<endl;
    out<<endl<<"Insertion In Place"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        insertionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<"***MergeSort***"<<endl;
    out<<"MergeSort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        mergeSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<"***QuickSort***"<<endl;
    out<<"QuickSort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        quickSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<"***Maxheap***"<<endl;
    out<<"Maxheap"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        heapSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<endl<<"RadixSort"<<endl;
    out<<endl<<"RadixSort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        radixsort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
}

void Fully_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end){
    cout<<"Fully sorted DAta"<<endl<<endl;
    ofstream out;
    out.open("Fully Sorted Statistics.csv");

    out << "Fully Sorted Data Test" << endl;
    cout<<"Array is being loaded"<<endl<<endl;
    data_set(arr,1000000000);
    cout<<"Array is being sorted test will start shortly...."<<endl<<endl;
    radixsort(arr,1000000000);

    int i = 1;
    elapsed = 0;

    cout << "***Selection Sort***" << endl;
    out << "Selection Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed <= 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = (Data_Set_Size / 4);
    float quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }


    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***Bubble Sort***" << endl;
    out << "Bubble Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
        out << "" << endl;
    }
    i = 1;
    elapsed = 0;
    cout << "***Insertion Sort***" << endl;
    out << "Insertion Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    out << i << "," << elapsed << "," << Data_Set_Size << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***MergeSort***" << endl;
    out << "MergeSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;


    i = 1;
    elapsed = 0;
    cout << "***QuickSort***" << endl<<endl;
    out << "QuickSort Will Crash with sorted data" << endl;
    out << "" << endl;


    cout << "***Maxheap***" << endl;
    out << "Maxheap" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***RadixSort***" << endl;
    out << "RadixSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;

        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

}

void test_Struct(Astruct arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end,int data_set1[],int size){
    cout<<"Unsorted Data Struct"<<endl<<endl;
    ofstream out;
    out.open("Struct Unsorted Statistics.csv");

    out << "Unsorted Data Test struct" << endl;
    int j=0;
    int i = 1;
    elapsed = 0;
    cout << "***Quick Sort***" << endl;
    out << "Quick Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 60000000) {
            break;
        }

        fill_struct(arr, Data_Set_Size,data_set1,size);

        start = clock();
        SquickSort(arr,0, Data_Set_Size);

        while(j<Data_Set_Size){
            quickSort(arr[j].data,0,size);
            j++;
        }

        end = clock();
        j=0;
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = (Data_Set_Size / 4);
    float quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 60000000) {
            break;
        }
        fill_struct(arr, Data_Set_Size,data_set1,size);
        start = clock();
        SquickSort(arr,0, Data_Set_Size);
        while(j<Data_Set_Size){
            quickSort(arr[j].data,0,size);
            j++;
        }
        end = clock();
        j=0;
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    out << "" << endl;

    elapsed = 0;
    i = 1;
    cout << "***Radix Sort***" << endl;
    out << "Radix Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 50000000) {
            break;
        }
        fill_struct(arr, Data_Set_Size,data_set1,size);
        start = clock();
        Sradixsort(arr, Data_Set_Size);
        while(j<Data_Set_Size){
            radixsort(arr[j].data,size);
            j++;
        }
        end = clock();
        j=0;
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = (Data_Set_Size / 4);
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 50000000) {
            break;
        }
        fill_struct(arr, Data_Set_Size,data_set1,size);
        start = clock();
        Sradixsort(arr, Data_Set_Size);
        while(j<Data_Set_Size){
            radixsort(arr[j].data,size);
            j++;
        }
        end = clock();
        j=0;
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    out << "" << endl;*/

    elapsed = 0;
    i = 1;
    cout << "***Merge Sort***" << endl;
    out << "Merge Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed <= 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 50000000) {
            break;
        }
        fill_struct(arr, Data_Set_Size,data_set1,size);
        start = clock();
        SmergeSort(arr,0, Data_Set_Size);
        /*while(j<Data_Set_Size){
            mergeSort(arr[j].data,0,size);
            j++;
        }*/
        end = clock();
        j=0;
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = (Data_Set_Size / 4);
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 50000000) {
            break;
        }
        fill_struct(arr, Data_Set_Size,data_set1,size);
        start = clock();
        SmergeSort(arr,0, Data_Set_Size);
        /*while(j<Data_Set_Size){
            mergeSort(arr[j].data,0,size);
            j++;
        }*/
        end = clock();
        j=0;
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    out << "" << endl;

    i = 1;

}

void fill_struct(Astruct arr[],int size,int data[],int size_2){
    mt19937_64 generator(time(0));
    uniform_int_distribution<long long unsigned>distribution(0,1000000000);
    long long int i=0;
    for (  i=1; i < size; i++){
        arr[i].key= distribution(generator);
        for(int j=0;j<size_2;j++){
            arr[i].data[j]=data[j];
        }
    }
}
