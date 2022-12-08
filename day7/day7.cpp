#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int totalSize = 0;

struct Node
{
    int size;
    int height;
    string dir;
    Node* parent;
    vector <Node *> children;   
};

class Tree
{
    public:
    Node* root;
    Node* current;
    Tree()
    {
        this->root = new Node();
        this->root->dir ="/";
        this->root->size=0;
        this->root->parent=NULL;
        this->root->height=0;
        this->current = this->root;
    };
    void cdRoot(){
        this->current = this->root;
    }
    void cdBack(){
        this->current=this->current->parent;
    }
    void fixCurrent (string dir){
        for (int i= 0 ; i < current->children.size();i++){
            if(current->children[i]->dir==dir)
            {
                current = current->children[i];
                break;
            }
        }
    }
    void addChild (Node* child){
        Node* ptr = current;
        int h=0;
        while(ptr){
            h++;
            ptr=ptr->parent;
        }
        child->height=h;
        child->parent= current;
        current->children.push_back(child);
    }
    void updateSize(int size){
        Node* ptr = current;
        while(ptr){
            ptr->size+=size;
            ptr=ptr->parent;
        }
    }
    void printFileTree()
    {
        cout << "File Tree: " << endl;
        printFileTreeHelper(root);
    }
    void printFileTreeHelper(Node *node  )
    {
        for(int j=0; j<node->height;j++){
            cout<< "\t";
        }
        cout  <<node->dir << " " << node->size << " "<<node->height << endl;
        for (int i = 0; i < node->children.size(); i++)
        {
            printFileTreeHelper(node->children[i]);
        }
    }
    void callSolution1(){
        solution1(root);
    }
    void solution1(Node* node){
        if(node->size<=100000) totalSize+=node->size;
        for (int i = 0; i < node->children.size(); i++)
        {
            solution1(node->children[i]);
        }
    }
    void callSolution2(){
        int unused= 70000000 - this->root->size;
        vector <int> listDir;
        solution2(root,unused,listDir);
        int min= 70000000;
        for (int i= 0 ; i < listDir.size();i++){
            cout << listDir[i] << endl;
            if(listDir[i]<min) min = listDir[i];
        }
        cout << min ;
    }
    void solution2(Node* node,int unused,vector<int> &list){
        if(node->size+unused>=30000000) list.push_back(node->size);
        for (int i = 0; i < node->children.size(); i++)
        {
            solution2(node->children[i],unused,list);
        }
    }
};

Node* createNode(string name){
    Node* node = new Node();
    if(node!=NULL){
        node->dir =name;
        node->size=0;
    }
    return node;
}

bool isNumber(char num){
    if (num >=48 && num<= 57)
        return true;
    return false;
}
vector <string> parseInput(string input){
    vector<string> result;

    if (input[0]=='$' && input[2]=='c'){
        result.push_back(input.substr(2,2));
        result.push_back(input.substr(5));
    }else{
        if(input[0]=='d'){
            result.push_back(input.substr(0,3));
            result.push_back(input.substr(4));
        }else{
            string num="";
            int i=0;
            while (isNumber(input[i]))
            {
                num+=input[i];
                i++;
            }
            result.push_back(num);
        }
    }
    return result;
}
Tree FileSys ;
void input (){
    string str;
    char n[255];
    ifstream fileInput("D:/DEV/Project/AOC/day7/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        str = n;
        vector <string> input;
        input=parseInput(str);
        if(input[0]=="cd"){
            if(input[1]==".."){
                FileSys.cdBack();
            }else if(input[1]=="/"){
                FileSys.cdRoot();
            }else{
                FileSys.fixCurrent(input[1]);
            }
        }else if(input[0]=="dir"){
            Node* node = createNode(input[1]);
            FileSys.addChild(node);
        }else if(isNumber(input[0][0])){
            int size=stoi(input[0]);
            FileSys.updateSize(size);
        }
    }
}

int main (){
    input();
    FileSys.callSolution2();
    return 0;
}