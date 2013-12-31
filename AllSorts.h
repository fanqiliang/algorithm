#ifndef  ALLSORTS_H
#define  ALLSORTS_H
#include <stdio.h>
#include <string.h>

extern void BullbeSort(int Array[], int low, int high);

extern void InsertSort(int Array[], int low, int high);

extern int  Partition(int Array[], int low, int high);
extern void QuickSort(int Array[], int low, int high);

extern void ShellSort(int Array[], int low, int high);

extern void MergeSort(int Array[], int low, int high);
extern void Merge(int Array[], int low, int mid, int high);

extern void BucketSort(int Array[], int low, int high);
#endif
