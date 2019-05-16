#include <iostream>
#include <map>

using namespace std;

struct tree {
    tree() {
        this->name = "";
        this->child = {};
    }

    tree(string name) {
        this->name = name;
        this->child = {};
    }

    tree(string name, map< string, tree *> child) {
        this->name = name;
        this->child = child;
    }

    string name;
    map< string, tree *> child;
};

void print_tr(tree *tr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        cout << " ";
    }
    if (tr->name != "") {
        cout << tr->name << endl;
    }
    ++n;
    for (auto &j : tr->child) {
        print_tr(j.second, n);
    }
}

int main() {
    int n;
    cin >> n;

    tree *tr_root = new tree();

    for (int i = 0; i < n; ++i) {
        string patch;
        cin >> patch;
        string dir = "";

        tree *tr = tr_root;
        for (int j = 0; j <= patch.size(); ++j) {
            if (patch[j] == '\\' || patch[j] == '\0') {
                auto dir_tr = tr->child.find(dir);
                if (dir_tr == tr->child.end()){
                    tree *new_tree = new tree(dir);
                    tr->child[dir] = new_tree;
                    tr = tr->child.find(dir)->second;
                } else {
                    tr = dir_tr->second;
                }
                dir = "";
            } else {
                dir += patch[j];
            }
        }

    }
    print_tr(tr_root, 0);
    return 0;
}
