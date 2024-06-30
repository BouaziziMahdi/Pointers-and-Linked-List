/*
Initialisation du DSU:
parent est un tableau li fih le parent de chaque sommet. Kol sommet au début houwa parent t3ou.
rank est un tableau li fih la profondeur de chaque ensemble. Kol ensemble au début la profondeur t3ou 0.
La fonction find(x) t9aleb 3ala racine de l'ensemble fiha x et treturni le parent t3ou.
La fonction unionSet(x, y) tzid zetli ensemble fiha x m3a ensemble fiha y et ta3refi l'ensemble wa7id.
maxNumEdgesToRemove:
aliceDSU et bobDSU ce sont des DSU pour Alice et Bob.
edgesUsed c'est un compteur des arêtes mstawrfinhom.
Nous avons trié les arêtes bch les arêtes de type 3 yjiw loulin, bch nst3mlohom loul khater houma y9edou yest3mouhoum el deux.
Na3mel for loop pour les arêtes, w 3la hasb type de l'arête (1, 2, ou 3) nwasel les DSU mta3 Alice w Bob.
Si c'est une arête de type 3, nwasel l'arête fil deux DSU (Alice et Bob).
Si c'est une arête de type 1, nwaselha fel DSU mta3 Alice.
Si c'est une arête de type 2, nwaselha fel DSU mta3 Bob.
B3d manajem kol arête, nverifiw si Alice w Bob y9edou yest3mou kol node. Chna3mel hadha bch nchoufou 9adeh mset d'ensembles fama fi kol DSU.
Si Alice ou Bob 3andhom plus d'un ensemble, hadha ma3neha may9edouch ywaslou kol node, donc nerje3 -1.
Finalement, nerje3 9adeh m arêtes n7ina en soustrayant le nombre d'arêtes est1emlina men le nombre total d'arêtes.
*/
class Solution {
public:
  class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};
int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    DSU aliceDSU(n), bobDSU(n);
    int edgesUsed = 0;
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return b[0] < a[0];
    });
    
    // Parcourir les arêtes
    for (const auto& edge : edges) {
        int type = edge[0], u = edge[1], v = edge[2];
        if (type == 3) {
            if (aliceDSU.unionSet(u, v) | bobDSU.unionSet(u, v)) {
                edgesUsed++;
            }
        } else if (type == 1) {
            if (aliceDSU.unionSet(u, v)) {
                edgesUsed++;
            }
        } else if (type == 2) {
            if (bobDSU.unionSet(u, v)) {
                edgesUsed++;
            }
        }
    }
        int aliceComponents = 0, bobComponents = 0;
    for (int i = 1; i <= n; ++i) {
        if (aliceDSU.find(i) == i) {
            aliceComponents++;
        }
        if (bobDSU.find(i) == i) {
            bobComponents++;
        }
    }
    
    if (aliceComponents > 1 || bobComponents > 1) {
        return -1;
    }
    
    return edges.size() - edgesUsed;
}
};