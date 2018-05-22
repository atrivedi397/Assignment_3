#pragma once

///////////******Swapping**************///////////
template<typename T1>
void swap(T1 *a , T1 *b)
{
    T1 temp;
    temp = *b;
    *b = *a;
    *a = temp;
}


///partition of an array using last element as pivot
int partition_LOMUTO(int arr[] , int start , int last)
{
    int pivot = arr[last];  ///choosing last element as pivotal element
    int i = start-1;        /// initialising i

    for(int j = start; j <= last-1; j++)        ///loop to swap the elements
    {
        //for sorting in descending order we can swap only when arr[j] >= pivot

        if(arr[j] <= pivot)          ///travelling from right if element is smaller than last (pivot) then
        {
            i = i+1;                 ///incrementing in i
            swap(&arr[i] , &arr[j]); ///swapping
        }
    }
    swap(&arr[i+1] , &arr[last]);        /// putting the pivot at its position
    return i+1;                          ///returning pivot position
}


int partition_HOARE(int arr[], int start , int last)
{
    int pivot = arr[start];
    int i = start-1;
    int j = last+1;
    while(true)
    {
        do
            i++;
        while(arr[i] < pivot);
        do
            j--;
        while(arr[j] > pivot);
        if (i >= j)
            return j;
        else
            swap(&arr[i], &arr[j]);
    }
}


///QuickSort Definition
void Quick_sort(int arr[] , int start , int last)
{
    int pivot_position;
    if(start < last)
    {
        pivot_position = partition_LOMUTO(arr , start ,last);
        Quick_sort(arr ,start , pivot_position-1);
        Quick_sort(arr , pivot_position+1 , last);
    }
}

void Quick_sort2(int arr[] , int start , int last)
{
    int pivot_position;
    if(start < last)
    {
        pivot_position = partition_HOARE(arr , start ,last);
        Quick_sort2(arr ,start , pivot_position);
        Quick_sort2(arr , pivot_position+1 , last);
    }
}
// Created by atrivedi on 5/8/18.
//