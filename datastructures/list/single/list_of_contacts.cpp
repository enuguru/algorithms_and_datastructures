
/*

Find same contacts in a list of contacts

Given a list of contacts containing username, email and phone number in any order. Identify the same contacts (i.e., same person having many different contacts) and output the same contacts together.

Notes:
1) A contact can store its three fields in any order, i.e., phone number can appear before username or username can appear before phone number.

2) Two contacts are same if they have either same username or email or phone number.

Example:

Input: contact[] = 
     { {"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
       { "Lucky", "lucky@gmail.com", "+1234567"},
       { "gaurav123", "+5412312", "gaurav123@skype.com"}.
       { "gaurav1993", "+5412312", "gaurav@gfgQA.com"}
     }
Output:
   0 2 3
   1 
contact[2] is same as contact[3] because they both have same
contact number.
contact[0] is same as contact[3] because they both have same
e-mail address.
Therefore, contact[0] and contact[2] are also same.

We strongly recommend you to minimize your browser and try this yourself first.
Input is basically an array of structures. A structure contains three fields such that any field can represent any detail about a contact.

The idea is to first create a graph of contacts using given array. In the graph, there is an edge between vertex i to vertex j if they both have either same username or same email or same phone number. Once the graph is constructed, the task reduces to finding connected components in an undirected graph. We can find connected components either by doing DFS or BFS starting from every unvisited vertex. In below code, DFS is used.

*/
//Below is C++ implementation of this idea.
// A C++ program to find same contacts in a list of contacts
#include<bits/stdc++.h>
using namespace std;
 
// Structure for storing contact details.
struct contact
{
    string field1, field2, field3;
};
 
// A utility function to fill entries in adjacency matrix
// representation of graph
void buildGraph(contact arr[], int n, int *mat[])
{
    // Initialize the adjacency matrix
    for (int i=0; i<n; i++)
       for (int j=0; j<n; j++)
           mat[i][j] = 0;
 
    // Traverse through all contacts
    for (int i = 0; i < n; i++) {
 
        // Add mat from i to j and vice versa, if possible.
        // Since length of each contact field is at max some
        // constant. (say 30) so body execution of this for
        // loop takes constant time.
        for (int j = i+1; j < n; j++)
            if (arr[i].field1 == arr[j].field1 ||
                arr[i].field1 == arr[j].field2 ||
                arr[i].field1 == arr[j].field3 ||
                arr[i].field2 == arr[j].field1 ||
                arr[i].field2 == arr[j].field2 ||
                arr[i].field2 == arr[j].field3 ||
                arr[i].field3 == arr[j].field1 ||
                arr[i].field3 == arr[j].field2 ||
                arr[i].field3 == arr[j].field3)
            {
                mat[i][j] = 1;
                mat[j][i] = 1;
                break;
            }
    }
}
 
// A recuesive function to perform DFS with vertex i as source
void DFSvisit(int i, int *mat[], bool visited[], vector<int>& sol, int n)
{
    visited[i] = true;
    sol.push_back(i);
 
    for (int j = 0; j < n; j++)
        if (mat[i][j] && !visited[j])
            DFSvisit(j, mat, visited, sol, n);
}
 
// Finds similar contacrs in an array of contacts
void findSameContacts(contact arr[], int n)
{
    // vector for storing the solution
    vector<int> sol;
 
    // Declare 2D adjaceny matrix for mats
    int **mat = new int*[n];
 
    for (int i = 0; i < n; i++)
        mat[i] = new int[n];
 
    // visited array to keep track of visited nodes
    bool visited[n];
    memset(visited, 0, sizeof(visited));
 
    // Fill adjacency matrix
    buildGraph(arr, n, mat);
 
    // Since, we made a graph with contacts as nodes with fields as links.
    // two nodes are linked if they represent the same person.
    // so, total number of connected components and nodes in each component
    // will be our answer.
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFSvisit(i, mat, visited, sol, n);
 
            // Add delimeter to separate nodes of one component from other.
            sol.push_back(-1);
        }
    }
 
    // Print the solution
    for (int i = 0; i < sol.size(); i++)
        if (sol[i] == -1) cout << endl;
        else cout << sol[i] << " ";
}
 
// Drive program
int main()
{
    contact arr[] = {{"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
                     {"Lucky", "lucky@gmail.com", "+1234567"},
                     {"gaurav123", "+5412312", "gaurav123@skype.com"},
                     {"gaurav1993", "+5412312", "gaurav@gfgQA.com"},
                     {"raja", "+2231210", "raja@gfg.com"},
                     {"bahubali", "+878312", "raja"}
                    };
 
    int n = sizeof arr / sizeof arr[0];
    findSameContacts(arr, n);
    return 0;
}
