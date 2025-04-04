/**
*Sukurti dvejetainį medį, kurio elementai sveiki skaičiai. Realizuoti įterpimo, paieškos, spausdinimo ir šalinimo operacijas bei atlikti šiuos veiksmus:
a. Sukurti eilę, realizuotą kaip sąrašą, į kurią įrašyti visus medžio elementus iš intervalo [a;b].
b. Panaikinti iš medžio visus elementus iš intervalo [a;c] (čia c<b), įrašant juos į deką, realizuotą kaip sąrašas į pradžią .
c. Panaikinti iš medžio visus elementus iš intervalo [c;b], įrašant juos į deko pabaigą.
d. Spausdinti deką ir eilę
 * nenaudoti STL bibliotekų
 */

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>

using namespace std;

// ========== Medžio mazgas ==========
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ========== Sąrašo mazgas ==========
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// ========== Eilė ==========
struct Queue {
    ListNode* front;
    ListNode* rear;
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        ListNode* node = new ListNode(val);
        if (!rear) front = rear = node;
        else {
            rear->next = node;
            rear = node;
        }
    }

    void print() {
        cout << "Eilė: ";
        ListNode* current = front;
        if (!current) cout << "[tuščia]";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (front) {
            ListNode* tmp = front;
            front = front->next;
            delete tmp;
        }
        rear = nullptr;
    }
};

// ========== Dekas ==========
struct Deque {
    ListNode* head;
    ListNode* tail;
    Deque() : head(nullptr), tail(nullptr) {}

    void push_front(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        if (!tail) tail = node;
    }

    void push_back(int val) {
        ListNode* node = new ListNode(val);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void print() {
        cout << "Dekas: ";
        ListNode* current = head;
        if (!current) cout << "[tuščia]";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Deque() {
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
    }
};

// ========== Medžio funkcijos ==========
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void printTreeRecursive(TreeNode* root, int space = 0, int gap = 10) {
    if (!root) return;
    space += gap;
    printTreeRecursive(root->right, space, gap);
    cout << endl;
    for (int i = gap; i < space; i++) cout << " ";
    cout << root->data;
    printTreeRecursive(root->left, space, gap);
}

void printTree(TreeNode* root) {
    cout << "\nMedis (piramidės forma):\n";
    if (!root) cout << "[tuščias]\n";
    else printTreeRecursive(root);
    cout << "\n-----------------------------------\n";
}

bool search(TreeNode* root, int val, string& path) {
    if (!root) return false;
    path += to_string(root->data);
    if (val == root->data) return true;
    path += " -> ";
    if (val < root->data) return search(root->left, val, path);
    else return search(root->right, val, path);
}

TreeNode* findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

TreeNode* remove(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (val < root->data) root->left = remove(root->left, val);
    else if (val > root->data) root->right = remove(root->right, val);
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

// ========== 5.1 ==========
void collectInterval(TreeNode* root, int a, int b, Queue& q) {
    if (!root) return;
    if (root->data > a) collectInterval(root->left, a, b, q);
    if (root->data >= a && root->data <= b) q.enqueue(root->data);
    if (root->data < b) collectInterval(root->right, a, b, q);
}

// ========== 5.2 & 5.3 ==========
void removeInterval(TreeNode*& root, int from, int to, Deque& d, bool to_front) {
    if (!root) return;
    removeInterval(root->left, from, to, d, to_front);
    removeInterval(root->right, from, to, d, to_front);
    if (root && root->data >= from && root->data <= to) {
        int val = root->data;
        if (to_front) d.push_front(val);
        else d.push_back(val);
        root = remove(root, val);
    }
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ========== Main ==========
int main() {
    SetConsoleOutputCP(CP_UTF8);
    TreeNode* root = nullptr;
    int option;

    do {
        cout << "\n======= Meniu =======\n"
             << "1. Įterpti skaičius\n"
             << "2. Spausdinti medį\n"
             << "3. Paieška medyje\n"
             << "4. Pašalinti skaičių\n"
             << "5. Intervalų operacijos\n"
             << "6. Išeiti\n"
             << "Pasirinkite: ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida: įveskite skaičių.\n";
            continue;
        }

        if (option == 1) {
            int n;
            cout << "Kiek skaičių įterpti? ";
            cin >> n;
            if (cin.fail() || n <= 0) {
                cout << "Klaida: įveskite teigiamą skaičių.\n";
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            for (int i = 0; i < n; i++) {
                int x;
                cout << i + 1 << ": ";
                cin >> x;
                if (cin.fail()) {
                    cout << "Klaida: netinkama reikšmė.\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    i--;
                    continue;
                }
                root = insert(root, x);
            }
        } else if (option == 2) {
            printTree(root);
        } else if (option == 3) {
            int val;
            cout << "Ieškomas skaičius: ";
            cin >> val;
            string path = "Kelias: ";
            bool found = search(root, val, path);
            cout << path << endl;
            cout << (found ? "Rasta!" : "Nerasta.") << endl;
        } else if (option == 4) {
            int val;
            cout << "Šalinamas skaičius: ";
            cin >> val;
            root = remove(root, val);
            cout << "Po šalinimo:\n";
            printTree(root);
        } else if (option == 5) {
            int a, c, b;
            cin.ignore();
            cout << "Įveskite intervalo ribas su tarpais (pvz.: 10 15 20):\n";
            cout << "[a; c; b], kur a ≤ c < b: ";
            string line;
            getline(cin, line);
            istringstream iss(line);
            if (!(iss >> a >> c >> b) || !(a <= c && c < b)) {
                cout << "Klaida: netinkamai įvestos ribos. a ≤ c < b.\n";
                continue;
            }

            Queue q;
            Deque d;

            cout << "5.1. Renkami elementai iš [" << a << "; " << b << "] į eilę...\n";
            collectInterval(root, a, b, q);

            cout << "5.2. Pašalinami iš [" << a << "; " << c << "] → į deko pradžią\n";
            removeInterval(root, a, c, d, true);

            cout << "5.3. Pašalinami iš [" << c << "; " << b << "] → į deko pabaigą\n";
            removeInterval(root, c, b, d, false);

            cout << "5.4. Galutinės struktūros:\n";
            q.print();
            d.print();
            printTree(root);
        }

    } while (option != 6);

    deleteTree(root);
    return 0;
}
