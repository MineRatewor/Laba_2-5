#include<iostream> 
#include<iomanip>
using namespace std;

struct Node
{
    int* data;
    int* index;
    int end = 0;
};

void input(Node*, int, int);
void print(Node*, int);
int getSize(Node*, int, Node*, int);
int* getList(Node*, int, Node*, int, int);
void main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Пожалуйста, введите размер списка L1:" << endl; cin >> n;
    Node* l1 = new Node;

    l1->data = new int[n];
    l1->index = new int[n];
    
    for (int i = 0; i < n; i++) {
        int num, index;
        cout << "Введите элемент и индекс следующего элемента:" << endl; cin >> num; cin >> index;
        input(l1, num, index);
        
    }

    print(l1, n); cout << endl;

    int k;
    cout << "Пожалуйста, введите размер списка L2:" << endl; cin >> k;
    Node* l2 = new Node;
    l2->data = new int[k];
    l2->index = new int[k];
   
    for (int i = 0; i < k; i++) {
        int num, index;
        cout << "Введите элемент и индекс следующего элемента:" << endl; cin >> num; cin >> index;
        input(l2, num, index);
      
    }

    print(l2, k); cout << endl;

    int size = getSize(l1, n, l2, k); 

    Node* l = new Node;
    l->data = getList(l1, n, l2, k, size);
    cout << "Список L:" << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(3) << l->data[i];
    }
}
void input(Node* list, int d, int ind) {
   list->data[list->end] = d;
   list->index[list->end] = ind;
   list->end++;
}
void print(Node* list, int n) {
    int k = 0; int begin = 0;
    while (k != n ) {
        for (int i = 0; i < n; i++) {
            if (k == list->index[i]) {
                if (i == n - 1) {
                    cout << setw(3) << list->data[begin];
                }
                else {
                    cout << setw(3) << list->data[i + 1];
                }
           }
        }
        k++;
    }
}
int getSize(Node* l1, int n, Node* l2, int k) {
    int size = 0;

    for (int i = 0; i < n; i++) {
        int flot = 0;
        for (int j = 0; j < k; j++) {
            if (l1->data[l1->index[i]] == l2->data[l2->index[j]]) {
                flot++;
            }
        }
        if (flot == 0) {
            size++;
        }
    }

    for (int i = 0; i < k; i++) {
        int flot = 0;
        for (int j = 0; j < n; j++) {
            if (l2->data[l2->index[i]] == l1->data[l1->index[j]]) {
                flot++;
            }
        }
        if (flot == 0) {
            size++;
        }
    }
    return size;
}

int* getList(Node*l1, int n, Node* l2, int k, int size) {
    int* arr = new int[size]; int l = 0;

    for (int i = 0; i < n; i++) {
        int flot = 0;
        for (int j = 0; j < k; j++) {
            if (l1->data[l1->index[i]] == l2->data[l2->index[j]]) {
                flot++;
            }
        }
        if (flot == 0) {
            int a = 0;
            for (int j = 0; j < l; j++) {
                if (l1->data[l1->index[i]] == arr[j]) {
                    a++;
                }
            }
            if (a == 0) {
                arr[l] = l1->data[l1->index[i]]; l++;
            }
           
        }
    }

    for (int i = 0; i < k; i++) {
        int flot = 0;
        for (int j = 0; j < n; j++) {
            if (l2->data[l2->index[i]] == l1->data[l1->index[j]]) {
                flot++;
            }
        }
        if (flot == 0) {
            int a = 0;
            for (int j = 0; j < l; j++) {
                if (l2->data[l2->index[i]] == arr[j]) {
                    a++;
                }
            }
            if (a == 0) {
                arr[l] = l2->data[l2->index[i]]; l++;
            }
        }
    }
    
    return arr;
}