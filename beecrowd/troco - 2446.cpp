#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// 1 -> Calculei e dá pra pagar
// 0 -> Não calculado
// -1 -> Calculei e não da pra pagar
int troco(int v, int m, vector<int> &coins, vector<vector<int>> &tab) {

    if(tab[v][m] != 0 || v == 0) return tab[v][m-1];


    for(int i = 0; i < m; i++) {
        
        if(v - coins[i] < 0) {
            tab[v][i] = -1;
        } 
        
        else if(troco(v-coins[i],m, coins, tab) == 1) {
            tab[v][i] = 1;
        } 
        
    }

    return tab[v][m-1];    
}


int main() {

    int v,m;
    cin >> v >> m;

    vector<vector<int>> tab = vector<vector<int>>(v,vector<int>(m, 0));
    vector<int> coins(m+1, 0);

    for (int i = 0; i < m; i++)
    {
        tab[0][i] = 1;
        cin >> coins[i];
    }


    if(troco(v, m, coins, tab) == 1) {
        cout << "S";
    } else {
        cout << "N";
    }

}