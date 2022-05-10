#include <bits/stdc++.h>
using namespace std;
void graphfread();   // Reads the graph from the file
void graphfwrite();  // Writes the graph to the file
void graphfdelete(); // Deletes the graph from the file
void addplaces();
void shortestpath();
void lowcostpath();
void pathfinder();
string nodes[100];
int noOfplaces = 0;

struct Graph
{
    string u, v;
    int cost, dist;
};
int main()
{
    addplaces();
    system("clear");
    int choice;
    while (1)
    {
        cout << "\n\n\n\n";
        printf("\t\t\t       Total number of places: %-4d\n", noOfplaces);
        cout << "\t\t\t*************************************\n";
        cout << "\t\t\t*             Path Finder           *\n";
        cout << "\t\t\t*************************************\n";
        cout << "\t\t\t*                Menu               *\n";
        cout << "\t\t\t* 1. Add Path                       *\n";
        cout << "\t\t\t* 2. Print Path                     *\n";
        cout << "\t\t\t* 3. Delete Path                    *\n";
        cout << "\t\t\t* 4. Path Finder                    *\n";
        cout << "\t\t\t* 5. Exit                           *\n";
        cout << "\t\t\t*************************************\n";
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            graphfwrite();
            break;
        case 2:
            graphfread();
            break;
        case 3:
            graphfdelete();
            break;
        case 4:
            pathfinder();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
            main();
        }
    }
}
void pathfinder()
{
    system("clear");
    cout << "\n\n\n\n";
    cout << "\t\t\t*************************************\n";
    cout << "\t\t\t*             Path Finder           *\n";
    cout << "\t\t\t*************************************\n";
    cout << "\t\t\t*                Menu               *\n";
    cout << "\t\t\t* 1. Shortest Path                  *\n";
    cout << "\t\t\t* 2. Lowest Cost Path               *\n";
    cout << "\t\t\t* 3. Back                           *\n";
    cout << "\t\t\t*************************************\n";
    cout << "\t\t\tEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        shortestpath();
        break;
    case 2:
        lowcostpath();
        break;
    case 3:
        main();
        break;
    default:
        printf("Invalid choice\n");
        pathfinder();
    }
}

void graphfwrite()
{
    system("clear");
    cout << "\n\n\n\n";
    cout << "\t\t\t*************************************\n";
    cout << "\t\t\t*             Path Finder           *\n";
    cout << "\t\t\t*************************************\n";
    ofstream fout;
    fout.open("graph.txt", ios_base::app);
    int ch = 1;
    while (ch != 0)
    {
        struct Graph obj;
        cout << "\t\t\tEnter the source : ";
        cin >> obj.u;
        cout << "\t\t\tEnter the destination : ";
        cin >> obj.v;
        cout << "\t\t\tEnter the cost : ";
        cin >> obj.cost;
        cout << "\t\t\tEnter the distance : ";
        cin >> obj.dist;
        cout << "\t\t\t*************************************\n";
        fout << obj.u << " " << obj.v << " " << obj.cost << " " << obj.dist << endl;
        cout << "\t\t\tDo you want to add more nodes? (1/0)";
        cin >> ch;
    }
    fout.close();
    int ch1;
    cout << "\n\n\t\t\tPress 1 for main menu or 0 for exit : ";
    cin >> ch1;
    switch (ch1)
    {
    case 0:
        exit(0);
        break;

    default:
        main();
        break;
    }
}

void graphfread()
{
    system("clear");
    ifstream fin("graph.txt");
    struct Graph obj;
    cout << "\n\n\n\n";
    cout << "\t\t\t************************************************************\n";
    cout << "\t\t\t*                        Path Finder                       *\n";
    cout << "\t\t\t************************************************************\n\n";
    cout << "\t\t\tStart               Destination         Cost      Distance  \n";
    cout << "\t\t\t------------------------------------------------------------\n";
    while (fin >> obj.u >> obj.v >> obj.cost >> obj.dist)
    {

        printf("\t\t\t%-20s%-20s%-10d%-10d\n", obj.u.c_str(), obj.v.c_str(), obj.cost, obj.dist);
    }
    fin.close();
    int ch;
    cout << "\n\n\t\t\tPress 1 for main menu or 0 for exit : ";
    cin >> ch;
    switch (ch)
    {
    case 0:
        exit(0);
        break;

    default:
        main();
        break;
    }
}

void addplaces()
{
    ifstream fin("graph.txt"); // opens the code.txt file
    struct Graph obj;          // creates a structure object
    set<string> places;        // set unique elements
    while (fin >> obj.u >> obj.v >> obj.cost >> obj.dist)
    {
        places.insert(obj.u);
        places.insert(obj.v);
    }
    // ishwardi --- kustia, ishwardi --- khulna, ishwardi -- rajshahi, kulna -- borisal
    // ishwardi, kustia, khulna,rajshahi,borisal //set of unique elements 5
    //   0,   --- 1,   -- 2,  ---    3,   ----   4
    fin.close();
    set<string>::iterator it;

    noOfplaces = 0;
    for (it = places.begin(); it != places.end(); it++) // 0 the end porjonto
    {
        nodes[noOfplaces] = *it;
        noOfplaces++;
    }
    for (int i = 0; i < noOfplaces; i++)
    {
        cout << "No " << i << " : " << nodes[i] << endl;
    }
}

void graphfdelete()
{
    system("clear");
    string u, v;
    ifstream fin("graph.txt");
    ofstream fout("temp.txt");
    struct Graph obj;
    cout << "\n\n\n\n";
    cout << "\t\t\t************************************************************\n";
    cout << "\t\t\t*                        Path Finder                       *\n";
    cout << "\t\t\t************************************************************\n\n";
    cout << "\t\t\tEnter the source that you want to delete: ";
    cin >> u;
    cout << "\t\t\tEnter the destination that you want to delete: ";
    cin >> v;
    while (fin >> obj.u >> obj.v >> obj.cost >> obj.dist)
    {
        if (obj.u == u && obj.v == v)
        {
            //fout << obj.u << " " << obj.v << " " << obj.cost << " " << obj.dist << endl;
        }
        else{
            fout << obj.u << " " << obj.v << " " << obj.cost << " " << obj.dist << endl;
        }
    }
    fout.close();
    fin.close();
    remove("graph.txt");
    rename("temp.txt", "graph.txt");
    cout << "\t\t\tPath deleted successfully\n";
    int ch1;
    cout << "\n\n\t\t\tPress 1 for main menu or 0 for exit : ";
    cin >> ch1;
    switch (ch1)
    {
    case 0:
        exit(0);
        break;

    default:
        main();
        break;
    }
}
void shortestpath()
{
    system("clear");
    ifstream fin("graph.txt");
    struct Graph obj;
    int u, v;

    list<pair<int, int>> graphdist[100]; // dist er graph er ekta list

    list<pair<int, int>> graphcost[100]; // cost er graph er ekta list

    set<string> s1;                                       // source set
    set<string> s2;                                       // destination set
    set<string>::iterator itx;                            // print pointer
    while (fin >> obj.u >> obj.v >> obj.cost >> obj.dist) //
    {

        s1.insert(obj.u);                    // s1 insert
        s2.insert(obj.v);                    /// s2 insert
        for (int j = 0; j < noOfplaces; j++) // 0 the all nuique elements
        {
            if (nodes[j] == obj.u) // obj.u file er source ar nodes holo unique elements
            {
                u = j;
                break;
            }
        }
        for (int j = 0; j < noOfplaces; j++)
        {
            if (nodes[j] == obj.v)
            {
                v = j;
                break;
            }
        }
        graphdist[u].push_back(make_pair(v, obj.dist)); // u, v , dist

        graphcost[u].push_back(make_pair(v, obj.cost));
    }
    string source, destination;
    cout << "\n\n\n\n";
    cout << "\t\t\t************************************************************\n";
    cout << "\t\t\t*                        Path Finder                       *\n";
    cout << "\t\t\t************************************************************\n\n";
    cout << "\t\t\tAvailable Sources are :\n";
    for (itx = s1.begin(); itx != s1.end(); itx++)
    {
        cout << "\t\t\t" << *itx << endl;
    }
    cout << "\t\t\tEnter the source : ";
    cin >> source;
    cout << "\n\n\t\t\tAvailable Destinations are :\n";
    for (itx = s2.begin(); itx != s2.end(); itx++)
    {
        cout << "\t\t\t" << *itx << endl;
    }
    cout << "\t\t\tEnter the destination : ";
    cin >> destination;
    int src, dest;

    for (int i = 0; i < noOfplaces; i++)
    {
        if (nodes[i] == source)
        {
            src = i;
            break;
        }
    }
    for (int i = 0; i < noOfplaces; i++)
    {
        if (nodes[i] == destination)
        {
            dest = i;
            break;
        }
    }

    int node = noOfplaces;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(node, INT_MAX);
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    int parent[node];
    parent[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = graphdist[u].begin(); i != graphdist[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
    vector<int> path;
    vector<int>::iterator ipath;
    while (dest != src)
    {
        path.push_back(dest);
        dest = parent[dest];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    cout << "\n\t\t\tThe shortest path is : ";
    for (ipath = path.begin(); ipath < path.end(); ipath++)
    {
        cout << nodes[*ipath];
        if (ipath != path.end() - 1)
        {
            cout << "->";
        }
    }
    void lowcostpath();
    int ch1;
    cout << "\n\n\t\t\tPress 1 for main menu or 0 for exit : ";
    cin >> ch1;
    switch (ch1)
    {
    case 0:
        exit(0);
        break;

    default:
        main();
        break;
    }
}
void lowcostpath()
{

    ifstream fin("graph.txt");
    struct Graph obj;
    int u, v;
    list<pair<int, int>> graphcost[100];                  // cost er graph er ekta list
    set<string> s1;                                       // source set
    set<string> s2;                                       // destination set
    set<string>::iterator itx;                            // print pointer
    while (fin >> obj.u >> obj.v >> obj.cost >> obj.dist) //
    {
        s1.insert(obj.u);                    // s1 insert
        s2.insert(obj.v);                    /// s2 insert
        for (int j = 0; j < noOfplaces; j++) // 0 the all nuique elements
        {
            if (nodes[j] == obj.u) // obj.u file er source ar nodes holo unique elements
            {
                u = j;
                break;
            }
        }
        for (int j = 0; j < noOfplaces; j++)
        {
            if (nodes[j] == obj.v)
            {
                v = j;
                break;
            }
        }
        graphcost[u].push_back(make_pair(v, obj.cost));
    }
    string source, destination;
    cout << "\n\n\n\n";
    cout << "\t\t\t************************************************************\n";
    cout << "\t\t\t*                        Path Finder                       *\n";
    cout << "\t\t\t************************************************************\n\n";
    cout << "\t\t\tAvailable Sources are :\n";
    for (itx = s1.begin(); itx != s1.end(); itx++)
    {
        cout << "\t\t\t" << *itx << endl;
    }
    cout << "\t\t\tEnter the source : ";
    cin >> source;
    cout << "\n\n\t\t\tAvailable Destinations are :\n";
    for (itx = s2.begin(); itx != s2.end(); itx++)
    {
        cout << "\t\t\t" << *itx << endl;
    }
    cout << "\t\t\tEnter the destination : ";
    cin >> destination;
    int src, dest;

    for (int i = 0; i < noOfplaces; i++)
    {
        if (nodes[i] == source)
        {
            src = i;
            break;
        }
    }
    for (int i = 0; i < noOfplaces; i++)
    {
        if (nodes[i] == destination)
        {
            dest = i;
            break;
        }
    }

    int node = noOfplaces;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(node, INT_MAX);
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    int parent[node];
    parent[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = graphcost[u].begin(); i != graphcost[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
    vector<int> path;
    vector<int>::iterator ipath;
    while (dest != src)
    {
        path.push_back(dest);
        dest = parent[dest];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    cout << "\n\t\t\tThe lowest cost path is : ";
    for (ipath = path.begin(); ipath < path.end(); ipath++)
    {
        cout << nodes[*ipath];
        if (ipath != path.end() - 1)
        {
            cout << "->";
        }
    }
    int ch1;
    cout << "\n\n\t\t\tPress 1 for main menu or 0 for exit : ";
    cin >> ch1;
    switch (ch1)
    {
    case 0:
        exit(0);
        break;

    default:
        main();
        break;
    }
}