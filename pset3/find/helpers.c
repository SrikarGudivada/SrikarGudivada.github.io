/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <string.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int min = 0, max = n, key;
    int mid;
    key = value;
    while(min <= max)
    {
        mid = (min + max)/2;
        if (values[mid] > key)
        {
            max = mid - 1;
        }
        else if (values[mid] < key)
        {
            min = mid + 1;
        }
        else
        {
            if(values[mid] == key)
                return true;
        }
    }
     return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int i,j,temp;
     for(i=0;i<n;i++)
     {
      for(j=i+1;j<n;j++)
      {
           if(values[i]>values[j])
           {
               temp = values[i];
              values[i] = values[j];
              values[j] = temp;
           }
      }
  }
    return;
}