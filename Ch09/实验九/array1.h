#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Array
{
public:
    vector<int> a;
    Array(){
        a.clear();
    }
    void add(int v) {
        a.push_back(v);
    }
    void insertSort() {
        int  j;
        vector<int> aa;
        aa.clear();
        for (int i = 0; i < (int)a.size(); i++)
        {
            int j;
            vector<int> b;
            b.clear();
            for (j = 0; j < (int)aa.size(); j++)
               if (aa[j] <= a[i])
                  b.push_back(aa[j]);
               else break;
               
            b.push_back(a[i]);
            for (; j < (int) aa.size(); j++)
                b.push_back(aa[j]);
            aa = b;
        }
        a = aa;
    }
    void selectSort() {
        int k,temp;
        for (int i = 0; i < (int) a.size(); i++)
        {
            k = i;
            for (int j = i; j < (int) a.size(); j++) 
               if (a[j] < a[k]) k = j;
            temp = a[i]; a[i] = a[k]; a[k] = temp;
        }
    }
    void BubbleSort()
    {
        int temp;
        for (int i = 0; i < (int)a.size(); i++)
        {
            for (int j = 0; j < ((int)a.size()) - 1; j ++)
            {
                if (a[j] > a[j + 1]) 
                {
                    temp = a[j]; a[j] = a[j+ 1]; a[j + 1] = temp;
                }
            }
        }
    }
    int seqSearch(int key)
    {
        for (int i = 0; i < (int)a.size(); i++)
            if (a[i] == key) return i;
        return -1;
    }
};