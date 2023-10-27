#include<bits/stdc++.h>
using namespace std;

struct edge {
	int source, dest, weight;
};
int V, E;

void bellmanFord(vector<edge>& Edges) {
	int parent[V];
	int cost_parent[V];
	vector<int> value(V, INT_MAX);
	
	parent[0] = -1;
	value[0] = 0;
	
	bool updated;
	for(int i = 0; i < V-1; i++) {
		updated = false;
		for(int j = 0; j < E; j++) {
			if(value[Edges[j].source]!=INT_MAX && value[Edges[j].source]+Edges[j].weight<value[Edges[j].dest]) {
				value[Edges[j].dest] = value[Edges[j].source]+Edges[j].weight;
				parent[Edges[j].dest] = Edges[j].source;
				cost_parent[Edges[j].dest] = value[V];
				updated = true;
			}
		}
		if(updated == false) break;
	}
	for(int j = 0; j < E && updated == true; j++) {
		if(value[Edges[j].source]!=INT_MAX && value[Edges[j].source]+Edges[j].weight<value[Edges[j].dest]) {
				cout<<"Negative edge cycle present"<<endl;
				return;
		}
	}
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<" from source 0 = "<<value[i]<<"\n";
}

int main() {
	cin>>V>>E;
	vector<edge> Edges(E);
	int src, dest, wt;
	for(int i = 0; i < E; i++) {
		cin>>src>>dest>>wt;
		Edges[i].source = src;
		Edges[i].dest = dest;
		Edges[i].weight = wt;
	}
	bellmanFord(Edges);
	return 0;
}
