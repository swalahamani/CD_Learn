#include <stdio.h>
#include <iostream>
using namespace std;

// C++ 98/03 do not contain Lambda , so we use a Functor to 
// Simulate Lambda 
template <class T>
struct functor { 
   bool operator()(T const &a, T const &b) {
       return a> b;
   }
};

template <class T>
class IComparitorStrategy{  
     public: 
         virtual int Execute(T a, T b) = 0;
};


template <class T>
class GenericComparitor : public IComparitorStrategy<T> {
        public:
	int Execute(T a, T b) { 
		T  pa  = a ;   T   pb  = b ; 
		return pa > pb ? 1 : (pb > pa ) ? -1 : 0; 
        	}

};
template <class T>
void BSort(T *arr, int len , functor<T>& test) {
            int n = len;
              for(int i = 0; i<n; ++i)
                for (int j = 0; j < n-i-1; j++)
                   if (test(arr[j],arr[j + 1])  == true ) {  
                              T  temp = arr[j]; arr[j] = arr[j + 1];  arr[j + 1] = temp; 
                  }
}

int main(int argc, char ** args){
         //---- Check whether there is any Command Line argument
        if ( argc  == 1 ) {  printf("No Command Line ARguments");    return 1; }
       //------ Allocate Array
        double *arr = new double[argc-1];
        for( int i=0; i< argc-1 ; ++i )
                 arr[i] = atof(args[i+1]);
              //---------- A Bubble Sort Routine
              functor<double> a;
              BSort(arr, argc-1 , a) ;
            
            //-------------------- Spit the Output
            for( int i=0; i<argc-1; ++i   )  { printf("%e\n",arr[i]); }
            delete [] arr;
            return 0;
    } // Main
