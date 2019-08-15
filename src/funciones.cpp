#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> un_set;
    for(int i : s) {
        un_set.insert(i);
    }

    vector<int> res;
    for(int j : un_set) {
        res.push_back(j);
    }

    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> un_set;
    for(int i : s) {
        un_set.insert(i);
    }

    vector<int> res;
    for(int j : un_set) {
        res.push_back(j);
    }

    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> a_set;
    set<int> b_set;

    for(int i : a) {
        a_set.insert(i);
    }

    for(int i : b) {
        b_set.insert(i);
    }

    return a_set == b_set;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> a_set;
    set<int> b_set;

    for(int i : a) {
        a_set.insert(i);
    }

    for(int i : b) {
        b_set.insert(i);
    }

    return a_set == b_set;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> dict;

    for(int elem : s){
        if(dict.count(elem) == 1) {
            dict[elem] = dict[elem] + 1;
        }
        else {
            dict[elem] = 1;
        }
    }
    return dict;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int, int> apariciones = contar_apariciones(s);
    vector<int> res;
    for(int i : s) {
        if(apariciones.count(i) == 0 || apariciones[i] == 1) {
            res.push_back(i);
        }
    }

    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int i : a) {
        if(b.count(i) == 1) {
            res.insert(i);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> grupos;

    for(int i : s) {
        grupos[i % 10].insert(i);
    }

    return grupos;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> traduccion;
    map<char, char> dict;
    for(pair<char, char> tupla : tr) {
        dict[tupla.first] = tupla.second;
    }

    for(char elem : str) {
        char decode = elem;
        if(dict.count(elem)) {
            decode = dict[elem];
        }
        traduccion.push_back(decode);
    }
    return traduccion;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    set<set<LU>> set_libretas;
    for(Mail m : s) {
        set_libretas.insert(m.libretas());
    }
    return s.size() != set_libretas.size();
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
