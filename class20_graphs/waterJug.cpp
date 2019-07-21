#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Jug
{
public:
	int j1;
	int j2;
	string asf;

	Jug(int a, int b, string asf = "") : j1(a), j2(b), asf(asf) {}
};

void jugs(int jug1, int jug2)
{
	queue<Jug> q;
	Jug *tempJug = new Jug(0, 0);
	q.push(*tempJug);
	vector<vector<bool>> visited(jug1 + 1, vector<bool>(jug2 + 1, false));
	while (!q.empty())
	{
		Jug rem = q.front();
		q.pop();

		if(rem.j1 == 4 || rem.j2 == 4) {
			rem.asf += (rem.j1 == 4)? " 4@": " @4";
			cout << rem.asf << endl;
			break;
		}

		if (visited[rem.j1][rem.j2] == true)
			continue;
		visited[rem.j1][rem.j2] == true;

		if (rem.j1 < jug1)
		{
			Jug *addedJug = new Jug(jug1, rem.j2, rem.asf + " f1 ");
			if (visited[jug1][rem.j2] == false)
			{
				q.push(*addedJug);
			}
		}
		if (rem.j2 < jug2)
		{
			Jug *addedJug = new Jug(rem.j1, jug2, rem.asf + " f2 ");
			if (visited[rem.j1][jug2] == false)
			{
				q.push(*addedJug);
			}
		}
		if (rem.j1 > 0)
		{
			Jug *addedJug = new Jug(0, rem.j2, rem.asf + " e1 ");
			if (visited[0][rem.j2] == false)
			{
				q.push(*addedJug);
			}
		}
		if (rem.j2 > 0)
		{
			Jug *addedJug = new Jug(rem.j1, 0, rem.asf + " e2 ");
			if (visited[rem.j1][0] == false)
			{
				q.push(*addedJug);
			}
		}
		if (rem.j1 > 0 && rem.j2 < jug2)
		{
			int empty2 = jug2 - rem.j2;
			if (empty2 > rem.j1)
			{
				Jug *addedJug = new Jug(0, rem.j2 + rem.j1, rem.asf + " m35 ");
				if (visited[0][rem.j1 + rem.j2] == false)
				{
					visited[0][rem.j1 + rem.j2] = 1;
					q.push(*addedJug);
				}
			}
			else
			{
				Jug *addedJug = new Jug(rem.j1 - empty2, jug2, rem.asf + " m35 ");
				if (visited[rem.j1 - empty2][jug2] == false)
				{
					q.push(*addedJug);
				}
			}
		}
		if (rem.j1 < jug1 && rem.j2 > 0)
		{
			int empty1 = jug1 - rem.j1;
			if (empty1 > rem.j2)
			{
				Jug *addedJug = new Jug(rem.j1 + rem.j2, 0, rem.asf + " m53 ");
				if (visited[rem.j1 + rem.j2][0] == false)
				{
					q.push(*addedJug);
				}
			}
			else
			{
				Jug *addedJug = new Jug(jug1, rem.j2 - empty1, rem.asf + " m53 ");
				if (visited[jug1][rem.j2 - empty1] == false)
				{
					q.push(*addedJug);
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	int jug1;
	int jug2;
	cin >> jug1 >> jug2;
	jugs(jug1, jug2);
}