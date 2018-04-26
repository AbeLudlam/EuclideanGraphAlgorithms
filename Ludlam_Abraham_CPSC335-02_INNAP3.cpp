#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
using namespace std;

struct node {

  float x; // x coordinate
  float y; // y coordinate
};
int main()
{
	int n;
	node * unseen;
	node * answer;
	int position;
	int apos=1;
	node start;
	node current;
	float hold;
	float sum= 0.0;
	float max = 0.0;
	cout << "Enter the range of the values to be permuted (n > 0)" << endl;
	cin >> n;
	unseen = new node[n];
	answer= new node[n+1];
	cout << "Enter the x and y values" << endl;
	for(int i=0; i<n; i++)
    {
		cout << "x=";
		cin >> unseen[i].x;
		cout << "y=";
		cin >> unseen[i].y;
    }
	for(int x=0; x<n-1; x++)
	{
		for(int y=x; y<n; y++)
		{
			float xv = unseen[x].x-unseen[y].x;
			float yv = unseen[x].y-unseen[y].y;
			hold= sqrt((xv*xv)+(yv*yv));
			if(hold>max)
			{
      			max=hold;
				start=unseen[x];
				position = x;

			}
		}

	}
	sum+= max;
	float min= max;
	answer[0]=start;
	answer[n]=start;
	for(int f=position; f<n-1; f++)
	{
		unseen[f]=unseen[f+1];
	}
	current = start;
	int usize = n-1;
	while(usize)
	{
		for(int z=0; z<usize; z++)
		{
			float xv = current.x-unseen[z].x;
			float yv = current.y-unseen[z].y;
			hold= sqrt((xv*xv)+(yv*yv));
			if(hold<min)
			{
      			min=hold;
				position = z;

			}

		}
		sum+= min;
		min = max;
		current = unseen[position];

		answer[apos++] = current;
		for(int f=position; f<usize-1; f++)
		{
			unseen[f]=unseen[f+1];
		}
		usize--;

	}
	for(int z=0;z<=n;z++)
  {

	  cout << "Node " << z+1 << ":  x=" << answer[z].x << "  y=" << answer[z].y <<"\n";
  }
	cout << "Sum = " << sum << "\n";
	delete [] unseen;
	delete [] answer;
	system("pause");
	return 1;
}
