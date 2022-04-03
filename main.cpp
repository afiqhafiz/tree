#include <iostream>
using namespace std;

class Tree{

struct TreeNode{
    string studID;
    int scorun;
    TreeNode *left, *right;
};

public:
int menu(){
    int choice;
    cout << "1. add new score" << endl;
    cout << "2. Display lowest score" << endl;
    cout << "3. Display highest score" << endl;
    cout << "4. Display score" << endl;
    cout << "5. Search student" << endl;
    cout << "6. Exit" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;
    
    return choice;
}
void insertScore(TreeNode *n, TreeNode *parent){
    if (root == NULL)
             root = n;
    else if(n->scorun < parent->scorun){
        if (parent->left!=NULL)
            insertScore (n, parent->left);
        else
            parent->left = n;        }
    else{
        if (parent->right!=NULL)
            insertScore (n, parent->right);
        else
            parent->right = n;
        }
}
void newScore(){
    TreeNode *n = new TreeNode();

    cout << "Enter student ID No: ";
    cin >> n->studID;
    cout << "Enter scorun point: ";
    cin >> n->scorun;
    n->left = n->right = NULL;
    
    insertScore(n, root);
}
    
    void display() {
        TreeNode* p = root;
        inorder(p);
    }
    void inorder(TreeNode* p) {
        if (p != NULL) {
            inorder(p->left);
            cout << "Student ID :" << p->studID << "  ";
            cout << "Scorun points :" << p->scorun << " " << endl;
            inorder(p->right);
        }
    }
    void search() {
        string id_search;
        int flag = 0;
        TreeNode* s = root;
        cout << "\nEnter student ID : ";
        cin >> id_search;
        if (root == NULL)
            cout << "\nTree is empty.";
        else {
            while (s != NULL) {
                if (s->studID == id_search) {
                    cout << "Data is exist" << endl;
                    cout << "Student ID: " << s->studID << endl;
                    cout << "Student scorun: " << s->scorun << endl;
                    flag = 1;
                }
                if (s->studID > id_search) {
                    s = s->left;
                }
                else {
                    s = s->right;
                }
            }
        }
        if (flag == 0)
            cout << "Data is not exist" << endl;
    }
    void lowestScore() {
        TreeNode* n = root;
        while (n->left != NULL) {
            n = n->left;
        }
        cout << "Lowest Score" << endl;
        cout << "Student Id : " << n->studID << endl;
        cout << "Score : " << n->scorun << endl;
    }
    void highestScore() {
        TreeNode* n = root;
        while (n->right != NULL) {
            n = n->right;
        }
        cout << "Highest Score" << endl;
        cout << "Student Id : " << n->studID << endl;
        cout << " Score : " << n->scorun << endl;
    }
private:
TreeNode *root = NULL;
};

int main(int argc, const char * argv[]) {
    Tree tree;
    int userchoice;
    do {
        userchoice = tree.menu();
        if (userchoice == 1) {
            tree.newScore();
        }
        else if (userchoice == 2){
            tree.lowestScore();        }
        else if (userchoice == 3){
            tree.highestScore();        }
        else if (userchoice == 4){
            tree.display();
        }
        else if (userchoice == 5){
            tree.search();
        }
    } while (userchoice != 6);
    return 0;
}
