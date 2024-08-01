#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const int LOG = 21;

int padre[MAXN];
int ancestros[MAXN][LOG];
int n;

void preprocesar()
{
    for (int j = 0; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (j == 0)
                ancestros[i][j] = padre[i];
            else
            {
                if (ancestros[i][j - 1] != -1)
                    ancestros[i][j] = ancestros[ancestros[i][j - 1]][j - 1];
                else
                    ancestros[i][j] = -1;
            }
        }
    }
}

int obtenerKEsimoPadre(int nodo, int k)
{
    for (int i = 0; i < LOG; i++)
    {if (k & (1 << i))
        { nodo = ancestros[nodo][i];
            if (nodo == -1)
                return -1;
        }
    }
    return nodo;
}

int main()
{
    int q, a, b;
    cin >> n >> q;
    vector<int> nuevo;

    for (int i = 1; i <= n; i++)
        padre[i] = -1;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        padre[i] = a;
    }
    preprocesar();

    while (q--)
    {
        cin >> a >> b;
        nuevo.push_back( obtenerKEsimoPadre(a, b));
    }
    for (int n : nuevo)
    {
    	cout << n << endl; }
}