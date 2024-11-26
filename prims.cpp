#include <iostream>

using namespace std;

int main()
{
    int strt;
    int mindist;
    int v;
    cout << "Enter number of vertex: ";
    cin >> v;
    int adj[v][v];
    int visited[v];
    int from[v];
    int distance[v];
    int nextnode;
    int totaldist = 0;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Enter the distance from " << i << " to " << j;
            cin >> adj[i][j];
        }
    }

    cout << "Entered adjcency matrix:\n";

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] == 0)
            {
                adj[i][j] = 999;
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        distance[i] = 999;
        from[i] = 0;
        visited[i] = 0;
    }

    cout << "Enter the starting vertex: ";
    cin >> strt;

    for (int i = 0; i < v; i++)
    {
        distance[i] = adj[strt][i];
        from[i] = strt;
    }
    visited[strt] = 1;
    distance[strt] = 0;
    cout << "1 Iteration:\n";

    cout << "\nvisited: ";
    for (int i = 0; i < v; i++)
    {
        cout << visited[i] << " ";
    }
    cout << "\ndistance: ";
    for (int i = 0; i < v; i++)
    {
        cout << distance[i] << " ";
    }
    cout << "\nfrom: ";
    for (int i = 0; i < v; i++)
    {
        cout << from[i] << " ";
    }
    cout << "\n-------------------------------------------------------" << endl;

    int count = 1;

    while (count < v - 1)
    {
        mindist = 999;

        for (int i = 0; i < v; i++)
        {
            if (mindist > distance[i] && !visited[i])
            {
                mindist = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;

        for (int i = 0; i < v; i++)
        
            if (!visited[i])
            {
                if (adj[nextnode][i] < distance[i])
                {
                    distance[i] = adj[nextnode][i];
                    from[i] = nextnode;
                }
            }
        
        count++;
        cout << count << " Iteration:\n";

        cout << "visited\n";
        for (int i = 0; i < v; i++)
        {
            cout << visited[i];
        }
        cout << "distance\n";
        for (int i = 0; i < v; i++)
        {
            cout << distance[i];
        }
        cout << "from\n";
        for (int i = 0; i < v; i++)
        {
            cout << from[i];
        }
        cout << "\n-------------------------------------------------------" << endl;
    }

    cout << "Path to follow:\n";

    for (int i = 0; i < v; i++)
    {
        if (i != from[i])
        {
            cout << "From: " << from[i] << " to " << i << "; where distance = " << distance[i]<<endl;
            totaldist += distance[i];
        }
    }
    cout<<"Total Distance = "<<totaldist;
    return 0;
}