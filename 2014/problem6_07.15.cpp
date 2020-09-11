#include <limits.h>

// Едносвързан цикличен списък от цели числа се описва с референция (указател)
// към циклична верига от двойни клетки, представени по следния начин:
struct Node {
    Node(int data) : data(data), next(nullptr) {}

    Node(int data, Node *next) : data(data), next(next) {}

    Node *next;
    int data;
};

// А) За даден цикличен списък L казваме, че числото M предхожда числото N,
// ако в списъка L има кутия A, която съдържа M, а A.next сочи към кутия, която съдържа N.
// Да се реализира (статична) функция precedes, която по даден списък L и две числа M и N проверява дали M
// предхожда N в L и ако е така, връща референция (указател) към кутията A, която съдържа M.
bool precedes(Node *l, int m, int n) {
    Node *node = l;
    do {
        if (node->data == m && node->next->data == n) {
            return true;
        }
        node = node->next;
    } while (node->next != l);
    return false;
}

// Б) Ако са дадени два списъка L1 и L2, така че M предхожда N в L1 и N предхожда M в L2,
// тогава двата списъка могат да се слеят в един списък L, както е показано на диаграмата долу,
// така че в L остава само по един екземпляр на числата M и N.
// L1: (1) -> (2) -> [(3) -> (4)] -> (5) -> (6) -> (1)
// L2: (7) -> (8) -> [(4) -> (3)] -> (9) -> (7)
// L:  (1) -> (2) -> [(3)] -> (9) -> (7) -> (8) -> [(4)] -> (5) -> (6) -> (1)

// Да се реализира (статична) функция merge, която слива два списъка L1 и L2, ако това е възможно.
// В случай, че сливането може да стане по няколко различни начина, да се избере такъв,
// за който сумата на числата M и N е максимална.
Node *getRef(Node *l, int n, int m) {
    while (l->data != n && l->next->data != m) {
        l = l->next;
    }
    return l;
}

void merge(Node *l1, Node *l2) {
    Node *iter = l1;
    int n = INT_MIN;
    int m = INT_MIN;
    do {
        int a = iter->data;
        int b = iter->next->data;
        if (precedes(l2, b, a) && (a + b) > (m + n)) {
            n = a;
            m = b;
        }
        iter = iter->next;
    } while (iter != l1);

    if (n == INT_MIN && m == INT_MIN) {
        // Не сме намерили точки m и n, невъзможно сливане
        return;
    }

    Node *nNode = getRef(l1, n, m);
    Node *mNode = getRef(l2, m, n);
    Node *l1Next = nNode->next->next;
    Node *l2Next = mNode->next->next;
    // TODO: the duplicate nodes can be deleted here.
    nNode->next = l2Next;
    mNode->next = l1Next;
}

// В) Да се реализира (статична) функция split, която по даден списък L и числа M и N, ако е възможно,
// разделя списъка L на два списъка L1 и L2, така че M предхожда N в L1 и N предхожда M в L2, както е показано на диаграмата горе.
// Ако разделянето може да стане по повече от един начин, да се избере такъв,
// при който разликата между дължините на получените списъци L1 и L2 е минимална.
int dist(Node *l, Node *x) {
    int n = 0;
    while(l != x) {
        l = l->next;
        n++;
    }
    return n;
}

void split(Node *l, int n, int m) {
    Node *nNode = nullptr, *mNode = nullptr, *iter = l;
    int diff = INT_MAX;
    // Some govnokod below, to find the most distant pairs m and n in the cycle
    do {
        int a = iter->data;
        if (a == n) {
            Node *s = iter->next;
            do {
                int b = s->data;
                if(b == m) {
                    int newDiff = dist(s, iter) - dist(iter, s);
                    newDiff = newDiff < 0 ? -newDiff : newDiff;

                    if (newDiff < diff) {
                        diff = newDiff;
                        nNode = iter;
                        mNode = s;
                    }

                }
                s = s->next;
            } while(s != iter);
        }

        iter = iter->next;
    } while (iter != l);

    if (nNode == nullptr || mNode == nullptr) {
        // няма такава двойка, невъзможно разделяне
        return;
    }

    Node *firstStart = mNode->next;
    Node *secondStart = nNode->next;
    Node *mNodeNew = new Node(mNode->data, nNode->next);
    Node *nNodeNew = new Node(nNode->data, mNode->next);
    nNode->next = mNodeNew;
    mNode->next = nNodeNew;
}


// helper for testing
void makeCyclic(Node *l) {
    Node *node = l;
    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = l;
}
