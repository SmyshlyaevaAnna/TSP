#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <map> 


using namespace std;


int main()
{
    int N;
    double x, y;
    cin >> N;
    vector<vector<double>> Koord(N, vector<double>(2));
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        Koord[i][0] = x;
        Koord[i][1] = y;
    }
    vector<vector<double>> Adj(N, vector<double>(N));
    for (int i = 0; i < N - 1; i++)
    {
        Adj[i][i] = -1;
        for (int j = i + 1; j < N; j++)
        {
            Adj[i][j] = hypot((Koord[i][0] - Koord[j][0]), (Koord[i][1] - Koord[j][1]));
            Adj[j][i] = Adj[i][j];
        }

    }
    Adj[N - 1][N - 1] = -1;


	double sum = 0;
	int counter = 0;
	int j = 0, i = 0;
	double min = INT_MAX;
	map<double, double> mark;

	mark[0] = 1;
	vector <double> track(N);
    for (j = 0; j < N; j++)
    {
        if (counter >= N - 1)
        {
            break;
        }
        if (j != 0 && (mark[j] == 0))
        {
            if (Adj[0][j] < min)
            {
                min = Adj[0][j];
                track[counter] = j + 1;
            }
        }
    }
    for ( i = 1; i < N; i++)
    {
        sum += min;
        min = INT_MAX;
        mark[i] = 1;
        counter++;
        for (j = 0; j < N; j++)
        {
            if (counter >= N - 1)
            {
                break;
            }
            if (j != i && (mark[j] == 0))
            {
                if (Adj[i][j] < min)
                {
                    min = Adj[i][j];
                    track[counter] = j + 1;
                }
            }
        }
    }
	i = track[counter - 1] - 1;
	for (j = 0; j < N; j++)
	{

		if ((i != j) && Adj[i][j] < min)
		{
			min = Adj[i][j];
			track[counter] = j + 1;
		}
	}
	cout << sum+min;


 //   cout << min << " " << imin << " " << jmin;
 //   for (int i = 0; i < N; i++)
 //   {
 //       cout << endl;
 //       for (int j = 0; j < N; j++)
 //       {
 //          cout << Adj[i][j] << " ";
 //       }
 //   }
        
 //   for (int i = 0; i < N; i++)
 //  {
 //       cout << Koord[i][0] << " " << Koord[i][1] << endl;
 //   }
}
