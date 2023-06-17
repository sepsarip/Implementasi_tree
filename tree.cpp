#include <iostream>
using namespace std;

//create struk node
struct Node{
    char label;
    Node *left, *right, *parent;

};

//pointer global
Node *root, *nodeBaru;

//cek kondisi root
bool rootEmpty() {
    return (root == nullptr);
}

//create tree or root
void newTree(char label){
    if(root != nullptr){
        cout <<"udh ada tree" << endl;
    }else{
        root = new Node();
        root->label = label;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        cout << "\nNode " << label << " adalah root" << endl;
    }
}



//add node kiri
Node *addLeft(char label, Node *node){
    //cek root kosong atau tidak
    if(rootEmpty()){
        cout << "buat tree dlu" << endl;
    }else{
        //cek ada anak kiri atau tidak
        if(node->left!=nullptr){
            cout << "\nNode "<< node->label << " sudah ada anak kiri" << endl;
            return nullptr;
        }else{
            nodeBaru = new Node();
            nodeBaru->label = label;
            nodeBaru->left = nullptr;
            nodeBaru->right = nullptr;
            nodeBaru->parent = node;
            node->left = nodeBaru;
            cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << nodeBaru->parent->label << endl;
            return nodeBaru;

        }
    }
}

//add node kanan
Node *addRight(char label, Node *node){
    //cek root kosong atau tidak
    if(rootEmpty()){
        cout << "buat tree dlu" << endl;
    }else{
        //cek ada anak kanan atau tidak
        if(node->right!=nullptr){
            cout << "Node "<< node->label << " sudah ada anak kanan" << endl;
            return nullptr;
        }else{
            nodeBaru = new Node();
            nodeBaru->label = label;
            nodeBaru->left = nullptr;
            nodeBaru->right = nullptr;
            nodeBaru->parent = node;
            node->right = nodeBaru;
            cout << "Node " << label << " berhasil ditambahkan ke anak kanan " << nodeBaru->parent->label << endl;
            return nodeBaru;

        }
    }
}

//find
void find(Node *node){
    if(rootEmpty()){
        cout << "buat tree dlu" << endl;
    }else{
        if(node == nullptr){
            cout << "Node yang ditunjuk tidak ada" << endl;
        }else{
            cout << "\nNode ditemukan : " << node->label << endl;
        }
    }
}

//traverse
// preOrder
void preOrder( Node *node = root ){
  if(rootEmpty()){
    cout << "\nBuat tree dlu" << endl;
  }else{
    if( node != nullptr ){
      cout << node->label << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
}

// inOrder
void inOrder( Node *node = root ){
  if(rootEmpty()){
    cout << "\nBuat tree dlu" << endl;
  }else{
    if( node != nullptr ){
      inOrder(node->left);
      cout << node->label << ", ";
      inOrder(node->right);
    }
  }
}

// postOrder
void postOrder( Node *node = root ){
  if(rootEmpty()){
    cout << "\nBuat tree dlu" << endl;
  }else{
    if( node != nullptr ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->label << ", ";
    }
  }
}

// fungsi delete tree
void deleteTree( Node *node ){
  if(rootEmpty()){
    cout << "\nBuat tree dlu" << endl;
  }else{
    if( node != nullptr ){
      if( node != root ){
        node->parent->left = nullptr;
        node->parent->right = nullptr;
      }
      deleteTree(node->left);
      deleteTree(node->right);
      
      if( node == root ){
        delete root;
        root = nullptr;
      }else{
        delete node;
      }
    }
  }
}

// clear
void clear(){
  if(rootEmpty()){
    cout << "\nBuat tree dlu" << endl;
  }else{
    deleteTree(root);
    cout << "\nTree sudah dihapus."  << endl;
  }
}

// retrieve
void retrieve( Node *node ){
  if(rootEmpty()){
    cout << "\nBuat tree dlu" << endl;
  }else{
    if(node==nullptr)
      cout << "\nNode yang ditunjuk tidak ada" << endl;
    else{
      cout << "\n\nRetrieve node : " << node->label << endl;
    }
  }
}

//mengetahui height dari tree
int height( Node *node = root ){
  if(rootEmpty()){
      cout << "\nBuat tree dlu" << endl;
      return 0;
    }else{
      if(node==nullptr){
        return 0;
      }else{
        int heightKiri = height( node->left );
        int heightKanan = height( node->right );

        if( heightKiri >= heightKanan ){
          return heightKiri + 1;
        }else{
          return heightKanan + 1;
        }
      }
    }
}

//mengetahui size atau banyak node pada tree
int size(Node *node = root){
  if(rootEmpty()){
    cout << "\nBuat tree dlu" << endl;
    return 0;
  }else{
    if(node == nullptr){
      return 0;
    }else{
      return 1 + size( node->left ) + size(node->right);
    }
  }
}

int main(){
    newTree('A');
    Node *nB, *nC, *nD, *nE, *nF, *nG, *nH, *nI, *nJ;

    nB = addLeft('B',root);
    nC = addRight('C',root);
    nD = addLeft('D', nB);
    nE = addLeft('E',nC);
    nF = addRight('F', nC);
    nG = addRight('G', nD);
    nH = addLeft('H', nE);
    nI = addRight('I', nE);
    
    //clear();

    find(nH);

    cout << "\nPreOrder  :";
    preOrder(nE);
    cout << "\nInOrder   :";
    inOrder(nE);
    cout << "\nPostOrder :";
    postOrder(nE);

    retrieve(nC);

    cout << "\nHeight tree : " << height();
    cout << "\nSize tree   : " << size();
}