
// Следната задача да се реши на един от езиците за програмиране C++ илиJava. 
// Да се обозначи явно на кой от двата езика е решавана задачата. 
// При решението назадачата да не се използват библиотеки за работа със структури от данни.

// а) Да се дефинира подходяща структура от данни, позволяваща представянето в паметта на програмата на 
// ориентиран граф от типа ​​G=<V,E>​, ​където 
// ​V​​ е множеството на целите положителни числа, не по­големи от​​ 1000 ​(представено чрез типа данни int)​, ​
// а ​E=V×V​.

struct Graph {
    int n;
    int E[1000][1000];

    bool hasPath(int from, int to, bool *visited) {
        if (from == to) {
            return true;
        }
        visited[from] = true;

        for (int i = 0; i < n; i++) {
            if (E[from][i] != -1 && !visited[E[from][i]]) {
                if (hasPath(E[from][i], to, visited)) {
                    return true;
                }
            }
        }

        visited[from] = false;
        return false;
    }
};

// б) За така дефинираната структура от данни да се дефинира функция (или статичен метод)
// [булев тип] isConnected ([подходящ тип] g) чиято стойност е истина точно за тези графи​​ g​, ​които са свързани. 
// За един граф​​ G=<V,Е>казваме, че е свързан, ако за всяка двойка​​ u ∈ V,​ ​v ∈ V​ ​има път от​​ u ​​до ​v ​​или от ​v​​ до ​u​.
// ​На примера са показани два графа, първият от които е свързан, а вторият – не.

bool hasPath(Graph &g, int from, int to) {
    bool *visited = new bool[g.n] {false};
    bool hasPath = g.hasPath(from, to, visited);
    delete visited;
    return hasPath;
}

bool isConnected(Graph &g) {
    for(int i = 0; i < g.n; i++) {
        for(int j = 0; j < g.n; j++) {
            if (!hasPath(g, i, j) && !hasPath(g, j, i)) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    // TODO: test
    return 0;
}