#include <map>
#include <vector>
#include <iostream>


/*Créé un "hashmap" feragh ou smi "degree" bach t7ot fih degré mta3 kol nœud.
Dourek 3al "edges" li fel liste "edges" ou, fi kol arête, zed degré mta3 nœuds li toseb bihom hedhi arête fel "hashmap" "degree".
Dourek fel "hashmap" "degree" ou a9leb degré ili ykoun yethla 3la N-1, ili yaani 9dah yethla "edges".
Rajja3 nœud ili ythela fi condition hedhi.
Rajja3 -1, ama hedhi partia mta3 code ma t7otlach mouch haka t7otch car l'input toujours valid.*/
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
           map<int, int> degree;

        for (vector<int> edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for (pair<int, int> nodes : degree) {
            int node = nodes.first;
            int nodeDegree = nodes.second;

            if (nodeDegree == edges.size()) {
                return node;
            }
        }

        return -1;
    }

};