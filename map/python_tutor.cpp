typedef int T;/* type of item to be stored */
#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

typedef enum { red, black, bnil } colors;

typedef struct t_node {
    typedef t_node node;

    struct t_node*    left;
    struct t_node*    right;
    struct t_node*    parent;
    colors    color;// bool мб
    T    data;

    t_node() : left(nullptr), right(nullptr), parent(nullptr), color(bnil) {}
    t_node(node* _left, node* _right, node* _parent, T _data)
        : left(_left), right(_right), parent(_parent), data(_data) {}

    t_node(node* _left, node* _right, node* _parent, colors c, T _data)
        : left(_left), right(_right), parent(_parent), color(c), data(_data) {
        }
}    node;

node *nil = new node();
node *root = nil;               /* root of Red-Black tree */
 

void insertNode(T _data) {
    node* current = root;
                node* x = new node(nil, nil, nullptr, red, _data);

                if (current->color == bnil){
                     root = x;
                     return;
                }
                
                node* parent = nullptr;
                while(current != nil){
                    parent = current;
                    if (_data < current->data)
                        current = current->left;
                    else
                        current = current->right;
                }

                x->parent = parent;        
                if (_data < parent->data)
                    parent->left = x;
                else 
                    parent->right = x;
}

void    leftRotate(node* x){
                node* rightTree = x->right;
                x->right = rightTree->left;
                rightTree->left->parent = x;
                rightTree->left = x;
                x->parent = rightTree;
                rightTree->parent = nullptr;
                x = rightTree;
            }

int main(){
  insertNode(1);
  insertNode(0);
  insertNode(5);
  insertNode(9);
  insertNode(3);
  leftRotate(root);
}