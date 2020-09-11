
struct Node {
    Node(int data): data(data), next(nullptr), prev(nullptr) {}
    Node(int data, Node *next): data(data), next(next), prev(nullptr) {next->prev = this;}
    Node *next, *prev;
    int data;
};

// Казваме, че двусвързаният списък L1 може да бъде „снаден“ с двусвързания списък L2 в числото M,
// ако има кутия A в L1 и кутия B в L2, такива че:
// - A.data и B.data са равни на M;
// - A е на разстояние Y от края на L1;
// - B е на разстояние Y от началото на L2.
//
// Разстояние между две кутии е броят на връзките, през които се преминава от едната до другата кутия.
// Снаждането на списъците се осъществява както е показано на диаграмата по-долу, като получената структура наричаме „снаден списък”.
// (1) <-> (3) <-> (5) <-> (7) <-> (9) <-> (6)             <--- l1
//                  ^                       |
//                  |                       v
//                 (3) <-> (4) <-> (8) <-> (5) <-> (7)     <--- l2

// А) Да се реализира функция join, която „снажда“ два двусвързани списъка L1 и L2, ако това е възможно.
// В случай, че снаждането може да се получи по няколко различни начина, да се избере този, при който разстоянието Y е минимално.

Node *getLast(Node *l) {
    Node *last = l;

    while(last->next != nullptr) {
        last = last->next;
    }

    return last;
}

void join(Node *l1, Node *l2) {
    Node *l1Last = getLast(l1);

    Node *cl1 = l1Last, *cl2 = l2;
    while(cl1 != nullptr && cl2 != nullptr && cl1->data != cl2->data) {
        cl1 = cl1->prev;
        cl2 = cl2->next;
    }

    if (cl1 == nullptr || cl2 == nullptr) {
        // невъзможно да ги снадим
        return;
    }

    l1Last->next = cl2;
    l2->prev = cl1;
}

// Б) Да се реализира булева функция isJoined, която по двойка референции (указатели)
// към начало и края на двусвързана верига проверява дали веригата е снаден списък.
// Забележка: да се счита, че подадената верига е двусвързан или снаден списък,
// т.е. не е нужно функцията да може да обработва друг вид вериги.

bool isJoined(Node *l) {
    while (l->next != nullptr) {
        if (l->next->prev != l) {
            return true;
        }

        l = l->next;
    }
    return false;
}

// В) Да се реализира функция sum, която по даден снаден списък намира сумата на всичките му елементи
int sum(Node *l) {
    int s = 0;

    Node *joinPoint = nullptr;
    while(l != nullptr) {
        if (l->next != nullptr && l->next->prev != l) {
            joinPoint = l->next;
        };
        s += l->data;
        l = l->next;
    }

    if (joinPoint != nullptr) {
        while(joinPoint->prev->next == joinPoint) {
            s += joinPoint->prev->data;
            joinPoint = joinPoint->prev;
        }
    }

    return s;
}
