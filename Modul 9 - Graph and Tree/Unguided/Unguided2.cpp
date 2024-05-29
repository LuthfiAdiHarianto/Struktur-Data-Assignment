#include <iostream>
#include <queue>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init_2311102172() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

void tampilkanChild(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nChild dari node " << node->data << ": ";
            if (node->left) {
                cout << "Kiri: " << node->left->data << " ";
            } else {
                cout << "Kiri: (tidak punya child kiri) ";
            }
            if (node->right) {
                cout << "Kanan: " << node->right->data << endl;
            } else {
                cout << "Kanan: (tidak punya child kanan) " << endl;
            }
        }
    }
}

void tampilkanDescendant(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nDescendant dari node " << node->data << ": ";
            queue<Pohon*> q;
            q.push(node);
            while (!q.empty()) {
                Pohon* temp = q.front();
                q.pop();
                if (temp->left) {
                    cout << temp->left->data << " ";
                    q.push(temp->left);
                }
                if (temp->right) {
                    cout << temp->right->data << " ";
                    q.push(temp->right);
                }
            }
            cout << endl;
        }
    }
}

int main() {
    init_2311102172();
    char pilihan, data, parent;
    Pohon *node = NULL, *parentNode = NULL;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Buat Root" << endl;
        cout << "2. Tambah Child Kiri" << endl;
        cout << "3. Tambah Child Kanan" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Tampilkan Child" << endl;
        cout << "6. Tampilkan Descendant" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Hapus Subtree" << endl;
        cout << "11. Hapus Tree" << endl;
        cout << "12. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case '1':
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case '2':
                cout << "Masukkan data child kiri: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> parent;
                parentNode = NULL;
                if (root) {
                    queue<Pohon*> q;
                    q.push(root);
                    while (!q.empty()) {
                        Pohon* temp = q.front();
                        q.pop();
                        if (temp->data == parent) {
                            parentNode = temp;
                            break;
                        }
                        if (temp->left) q.push(temp->left);
                        if (temp->right) q.push(temp->right);
                    }
                }
                if (parentNode) {
                    insertLeft(data, parentNode);
                } else {
                    cout << "Parent tidak ditemukan!" << endl;
                }
                break;
            case '3':
                cout << "Masukkan data child kanan: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> parent;
                parentNode = NULL;
                if (root) {
                    queue<Pohon*> q;
                    q.push(root);
                    while (!q.empty()) {
                        Pohon* temp = q.front();
                        q.pop();
                        if (temp->data == parent) {
                            parentNode = temp;
                            break;
                        }
                        if (temp->left) q.push(temp->left);
                        if (temp->right) q.push(temp->right);
                    }
                }
                if (parentNode) {
                    insertRight(data, parentNode);
                } else {
                    cout << "Parent tidak ditemukan!" << endl;
                }
                break;
            case '4':
                cout << "Masukkan data node baru: ";
                cin >> data;
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> parent;
                parentNode = NULL;
                if (root) {
                    queue<Pohon*> q;
                    q.push(root);
                    while (!q.empty()) {
                        Pohon* temp = q.front();
                        q.pop();
                        if (temp->data == parent) {
                            parentNode = temp;
                            break;
                        }
                        if (temp->left) q.push(temp->left);
                        if (temp->right) q.push(temp->right);
                    }
                }
                if (parentNode) {
                    update(data, parentNode);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case '5':
                cout << "Masukkan data node: ";
                cin >> data;
                node = NULL;
                if (root) {
                    queue<Pohon*> q;
                    q.push(root);
                    while (!q.empty()) {
                        Pohon* temp = q.front();
                        q.pop();
                        if (temp->data == data) {
                            node = temp;
                            break;
                        }
                        if (temp->left) q.push(temp->left);
                        if (temp->right) q.push(temp->right);
                    }
                }
                tampilkanChild(node);
                break;
            case '6':
                cout << "Masukkan data node: ";
                cin >> data;
                node = NULL;
                if (root) {
                    queue<Pohon*> q;
                    q.push(root);
                    while (!q.empty()) {
                        Pohon* temp = q.front();
                        q.pop();
                        if (temp->data == data) {
                            node = temp;
                            break;
                        }
                        if (temp->left) q.push(temp->left);
                        if (temp->right) q.push(temp->right);
                    }
                }
                tampilkanDescendant(node);
                break;
            case '7':
                cout << "\nPreOrder Traversal:" << endl;
                preOrder(root);
                cout << endl;
                break;
            case '8':
                cout << "\nInOrder Traversal:" << endl;
                inOrder(root);
                cout << endl;
                break;
            case '9':
                cout << "\nPostOrder Traversal:" << endl;
                postOrder(root);
                cout << endl;
                break;
            case '10':
                cout << "Masukkan data node subtree yang ingin dihapus: ";
                cin >> data;
                node = NULL;
                if (root) {
                    queue<Pohon*> q;
                    q.push(root);
                    while (!q.empty()) {
                        Pohon* temp = q.front();
                        q.pop();
                        if (temp->data == data) {
                            node = temp;
                            break;
                        }
                        if (temp->left) q.push(temp->left);
                        if (temp->right) q.push(temp->right);
                    }
                }
                deleteSub(node);
                break;
            case '11':
                clear();
                break;
            case '12':
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != '12');
    
    return 0;
}
