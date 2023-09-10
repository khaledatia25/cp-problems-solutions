#include <bits/stdc++.h>
using namespace std;


string actions[] = { "fill B", "fill A", "empty B", "empty A", "pour B A", "pour A B", "Start" };
enum list		   {  FILL_B ,  FILL_A ,  EMPTY_B ,  EMPTY_A ,  POUR_B_A ,  POUR_A_B  , Start};

struct state 	   {	int a, b, action;	};

const int MAX = 1000+9;
bool reached[MAX][MAX];
state prev_state[MAX][MAX];
queue<state> qu;

int ca, cb, required;

void backtrace(state cur)
{
	if(cur.a == 0 && cur.b == 0)
		return;

	backtrace(prev_state[cur.a][cur.b]);
	cout<<actions[cur.action]<<"\n";
}

void add_state(int a, int b, int action, state parent)
{
	if(reached[a][b])
		return;

	state cur = {a, b, action};
	qu.push(cur);
	prev_state[a][b] = parent;
	reached[a][b] = true;
}

void BFS(int a, int b)
{
	qu = queue<state>();
	memset(reached, 0, sizeof(reached) );

	add_state(0, 0, Start, state());

	while(!qu.empty())
	{
		state cur = qu.front();
		qu.pop();
		int a  = cur.a, b = cur.b, aa, bb;

		if(b == required)	// Improvement: Catch it before adding to queue
		{
			backtrace(cur);
			cout<<"success\n";
			return;
		}

		add_state(a, cb, FILL_B, cur);
		add_state(ca, b, FILL_A, cur);
		add_state(a, 0, EMPTY_B, cur);
		add_state(0, b, EMPTY_A, cur);

		aa = (a+b)>ca ? ca:a+b;
		bb = (a+b)>ca ? (a+b)-ca:0;
		add_state(aa, bb, POUR_B_A, cur);
		
		aa = (a+b)>cb ? (a+b)-cb:0;
		bb = (a+b)>cb ? cb:a+b;
		add_state(aa, bb, POUR_A_B, cur);
	}
}
// Your turn: Write Dijkstra version. Write DFS version

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif

	while(cin>>ca>>cb>>required)
		BFS(0, 0);

	return 0;
}
