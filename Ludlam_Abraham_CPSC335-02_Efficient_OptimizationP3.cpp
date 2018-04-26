#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
using namespace std;

struct node {

  float x; // x coordinate
  float y; // y coordinate
};
void generate_perm(int n, int *A, int sizeA, node *P, float *smallest, node *ans) {
  int i;
  if (n == 1)
  {

    float sum=0;
   	for(i=0;i<sizeA-1; i++)
   	{
	        float xv= P[A[i]].x-P[A[i+1]].x  ;
	        float yv= P[A[i]].y-P[A[i+1]].y    ;
	        sum+= sqrt((xv*xv)+(yv*yv))	;
	}

	if(sum<*smallest || *smallest == -1)
	{
	        for(i=0;i<sizeA; i++)
	        {
		    ans[i].x= P[A[i]].x ;
			ans[i].y= P[A[i]].y ;
	        }
			*smallest = sum;
	}

  }
  else {
    for(i = 0 ; i< n-1; i++) {

      generate_perm(n-1,A, sizeA, P, smallest, ans);
      if (n%2 == 0) {
        // swap(A[i], A[n-1])
        int temp = A[i];
        A[i] = A[n-1];
        A[n-1]=temp;
      }
      else {
          // swap(A[0], A[n-1])
          int temp = A[0];
          A[0] = A[n-1];
          A[n-1]=temp;
        }
    }
    generate_perm(n-1,A, sizeA, P, smallest, ans);
  }
}
int main() {
  int i, n;
  int *A;
  node *Bhamil;
  node *Answer;
  float smallest = -1.0;
  float *smaller  = &smallest;
  cout << "Enter the range of the values to be permuted (n > 0)" << endl;
  cin >> n;
  Bhamil= new node[n];
  A = new int[n];
  Answer = new node[n+1];
  // populate the array A with the values in the range 0 .. n-1
  cout << "Enter the x and y values" << endl;
  for(i=0; i<n; i++)
  {
    A[i] = i;
	 cout << "x=";
	cin >> Bhamil[i].x;
	cout << "y=";
	cin >> Bhamil[i].y;
  }
  generate_perm(n,A, n, Bhamil, smaller, Answer);
  Answer[n].x=Answer[0].x;
  Answer[n].y=Answer[0].y;
  cout << "Answer\n";
  for(int z=0;z<=n;z++)
  {

	  cout << "Node " << z+1 << ":  x=" << Answer[z].x << "  y=" << Answer[z].y <<"\n";
  }
  cout << "Sum = " << smallest << "\n";

  delete [] A;

  delete [] Bhamil;

   delete [] Answer;
  system("pause");


}
