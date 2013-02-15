#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

const int n = 5;       /*Quantity of cities*/

int arr1[n];
int arr2[n];

short c;
					           //G Wars Krak Pozn Wr
int a[n][n] = /*G*/ {{0, 341, 584, 304, 486}, 
			       /*Wars*/{341, 0, 299, 304, 341},              /*Adjacency matrix of distances between cities*/
			       /*Krak*/{584, 299, 0, 403, 304},
			       /*Pozn*/{304, 304, 403, 0, 280},
			         /*Wr*/{486, 341, 304, 280, 0}};
  
list <int> list_1;	 /*from Krakow*/
list <int> list_2;   /*from Warszaw*/

void write_list(list <int> list_a)              /*Function, displaying elements of list*/
{
  list <int>::iterator pointer;
	for (pointer = list_a.begin(); pointer != list_a.end(); pointer++)
    		cout << *pointer << " ";
  cout << "\n";
	}

void swap(int &a, int &b)                     /*Swapping two elements*/
{
	if (&a == &b)
		return ;
	a^=b;
	b^=a;
	a^=b;
	}

void bubbleSort()                           /*Array sorting, using bubble sort algorithm*/                    
{
	for(int i = n - 2; i >= 0; i--)   
    	for(int j = 0; j <= i; j++)  
			 if (arr1[j] > arr1[j+1])
				swap(arr1[j], arr1[j+1]);
	}

void bubbleSort_lists()                   /*List sorting, using bubble sort algorithm*/
{
  list <int>::iterator iter;
  list <int>::iterator iter_temp;
  int tmp;
  for(int i = 0; i < n; i++)
  {
    for (iter = --list_1.end(); iter != list_1.begin(); iter--)
    {
      iter_temp = iter--;
      if(*iter_temp < *iter)
        swap(*iter_temp, *iter);
      iter++;
      }
    } 
  }

void convert_list_to_array_1()          /*Void function, which converting list to array*/
{
	copy(list_1.begin(), list_1.end(), arr1);
    }

void convert_list_to_array_2()         /*Do the same as previous for another array*/
{
  copy(list_2.begin(), list_2.end(), arr2);
    }

void convert_array_to_list_1()        /*Void function, which converting array to list*/
{
  for (int i = 0; i < n; i++)
    list_1.push_back(arr1[i]);
  }

void convert_array_to_list_2()      /*Do the same as previous for another list*/
{
  for (int i = 0; i < n; i++)
    list_2.push_back(arr2[i]);
  }

void matrix_to_list_1()       /*Transfer line from adjacency matrix(from Warszaw to another cities)*/
{
  for (int i = 0; i < n; i++)
    list_2.push_back(a[1][i]);
  }

void matrix_to_list_2()     /*Transfer line from adjacency matrix(from Krakow to another cities)*/
{
  for (int i = 0; i < n; i++)
    list_1.push_back(a[2][i]);
  }

void matrixes_to_list()    /*Merge two previous function*/
{
  matrix_to_list_1();
  matrix_to_list_2(); 
  }

void select()         /*Asking user, to which city he want to get*/
{
  cout << "To which city do you want to get?  (1 - Gdansk, 2 - Poznan, 3 - Wroclaw\n";
  cin >> c;
  }

void quickSort_basic(int arr[], int begin, int end)       /*Basic recursive function of quick sort on arrays*/
{
      int i = begin, j = end;
      int pivot = arr[begin + (end - begin)/2]; 

      while (i <= j)
      {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j)
            {
                  swap(arr[i], arr[j]);
                  i++;
                  j--;
              }
          }

      if (begin < j)
            quickSort_basic(arr, begin, j);
      if (i < end)
            quickSort_basic(arr, i, end);
      }

void from_city(list <int> list_a, short c, bool t)      /*Display distance from Krakow(or Warszaw) to other city, choosen by user*/ 
{
  int tmp;
  cout << "From ";
  if (t)
    cout << "Warszaw ";
  else
    cout << "Krakow ";
  cout << "to *your city* - ";
  switch (c) 
    {
      case 1 : 
        cout << list_a.front() << "\n";
        break;
      case 2 :
        tmp = list_a.back();
        list_a.pop_back();
        cout << list_a.back() << "\n";
        list_a.push_back(tmp);
        break;
      case 3 :
        cout << list_a.back() << "\n";
        break;
      }
    }

void sort_lists()                           /*Sorting lists with standart method quick sort*/
{
  list_1.sort();
  list_2.sort();
  }

void sort_bubble()                  /*Converting list to array, sorting it with bubble sort algorithm and unconvert it to list back*/
{
		convert_list_to_array_1();
		list_1.clear();
  	bubbleSort();
  	convert_array_to_list_1();
  	}

void sort_quick()               /*Converting list to array, sorting it with quick sort algorithm and unconvert it to list back*/
{
  convert_list_to_array_2();
  list_2.clear();
  quickSort_basic(arr2, 0, n - 1);
  convert_array_to_list_2();
  }

void solution()             /*Magic, don't touch!!!*/
{
  matrixes_to_list();
  select();
  from_city(list_1, c, 0);
  from_city(list_2, c, 1);

  sort_lists();
  cout << "Sorted first list with quick sort algorithm:\n";
  write_list(list_1);
  cout << "Sorted second list with quick sort algorithm:\n";
  write_list(list_2);

  bubbleSort_lists();
  cout << "Sorted first list with bubble sort algorithm:\n";
  write_list(list_1);

  sort_quick();
  cout << "Sorted second list with quick sort algorithm:\n";
  write_list(list_2);
  }
