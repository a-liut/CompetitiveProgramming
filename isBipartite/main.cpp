#include <iostream>
#include <queue>

#define MAX 50

bool isBipartite(int G[][MAX],int V)
{
	int colors[V], currentColor, i, node = 0;

	// Init
	for(i = 0; i < V; ++i)
	{
		colors[i] = 0;
	}

	colors[node] = 1;

	while(node < V)
	{
		currentColor = colors[node] == 1 ? 2 : 1;

		if(G[node][node] == 1)
		{
			return false; // Self loop
		}

		for(i = 0; i < V; ++i)
		{
			if(G[node][i] == 1)
			{
				// Already colored but with a different color
				if(colors[i] != 0 && colors[i] != currentColor)
				{
					return false;
				} else {
					// Color the node
					colors[i] = currentColor;
				}
			}
		}

		node++;
	}

	return true;
}