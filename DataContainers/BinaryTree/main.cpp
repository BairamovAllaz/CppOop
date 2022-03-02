#include <iostream>
#include <ctime>
using namespace std;

class Tree
{

    class Element
    {
    private:
        int data;
        Element *left;
        Element *right;

    public:
        Element(int data, Element *left = nullptr, Element *right = nullptr) : data(data), left(left), right(right) { cout << "Econstructor\t" << this << endl; }
        ~Element() { cout << "Edesctructor\t" << endl; }

        friend class Tree;
        friend class UniqueTree;
    } * root;

    void insert(int data, Element *Root);
    void print(Element *Root) const;
    int maxValue(Element *Root);
    int minValue(Element *Root);
    int size(Element *Root);
    int sum(Element *Root);
    void erase(Element *Temp, int Data);

public:
    Element *getRoot()
    {
        return root;
    }

    Tree()
    {
        root = nullptr;
        cout << "Bconstructor\t" << endl;
    }

    void copy(Element *Temp)
    {
        if (Temp == nullptr)
        {
            return;
        }
        insert(Temp->data);
        copy(Temp->left);
        copy(Temp->right);
    }

    Tree(Tree &other) : Tree()
    {
        if (&other == this)
        {
            return;
        }
        copy(other.getRoot());
        cout << "Copy constructor" << endl;
    }

    Tree &operator=(Tree &other)
    {
        if (&other == this)
        {
            return *this;
        }
        copy(other.getRoot());
        cout << "Copy Assigment" << endl;
        return *this;
    }

    Tree(const std::initializer_list<int> &datas) : Tree()
    {
        for (int i : datas)
        {
            insert(i);
        }
    }

    void deleteNode(Element *Temp)
    {
        if (Temp == nullptr)
        {
            return;
        }
        deleteNode(Temp->left);
        deleteNode(Temp->right);
        delete Temp;
        // delete root; error!
    }
    ~Tree()
    {
        deleteNode(root);
        cout << "Bdesctructor\t" << endl;
    }
    void insert(int data);
    void print() const;
    int maxValue();
    int minValue();
    int size();
    int sum();
    double avg();
    void erase(int Data);
    friend class UniqueTree;
};

/// https://www.algolist.net/Data_structures/Binary_search_tree/Removal
void Tree::erase(Element *Temp, int Data)
{
    if (Temp == nullptr)
    {
        return;
    }

    if (Temp->data == Data)
    {
        if (Temp->left == nullptr && Temp->right == nullptr) // NO CHILD
        {
            delete Temp;
            return;
        }
        /// left side
        // TWO CHILD IN LEFT SIDE
        else if (Temp->left != nullptr && Temp->right != nullptr && Temp->data > root->data)
        {                                           // (Temp->data > root->data)To check is right or left side
            int minElement = minValue(Temp->right); // find min value
            Temp->data = minElement;
            erase(Temp->right, minElement); // to delete element
        }

        // right side
        // TWO CHILD IN RIGHT SIDE
        else if (Temp->left != nullptr && Temp->right != nullptr && Temp->data < root->data)
        {                                          // (Temp->data > root->data)To check is right or left side
            int maxElement = maxValue(Temp->left); // find max value
            Temp->data = maxElement;
            erase(Temp->right, maxElement); // to delete element
        }
        // ONE RIGHT CHILD
        else if (Temp->right != nullptr && Temp->left == nullptr)
        {
            // TODO:DONE DELETE ONE CHILD
            /// one child is not done in progress...
        }
        // ONE LEFT CHILD
        else if (Temp->left != nullptr && Temp->right == nullptr)
        {
            // TODO:DONE DELETE ONE CHILD
            /// one child is not done in progress...
        }
    }
    else if (Data < Temp->data)
    {
        erase(Temp->left, Data);
    }
    else
    {
        erase(Temp->right, Data);
    }
}

void Tree::erase(int Data)
{
    Element *Temp = this->root;
    erase(Temp, Data);
}

void Tree::insert(int data, Element *Root)
{
    if (this->root == nullptr)
    {
        this->root = new Element(data);
        return;
    }
    if (Root == nullptr)
    {
        return;
    }
    if (data < Root->data)
    {
        if (Root->left == nullptr)
        {
            Root->left = new Element(data);
        }
        else
        {
            insert(data, Root->left);
        }
    }
    else
    {
        if (Root->right == nullptr)
        {
            Root->right = new Element(data);
        }
        else
        {
            insert(data, Root->right);
        }
    }
}

void Tree::insert(int data)
{
    Element *Temp = this->root;
    insert(data, Temp);
}

void Tree::print(Element *Root) const
{
    if (Root == nullptr)
    {
        return;
    }

    print(Root->left);
    cout << Root->data << '\t';
    print(Root->right);
    cout << endl;
}

void Tree::print() const
{
    Element *Temp = this->root;
    print(Temp);
}

int factorial(int num)
{
    if (num < 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

int Tree::maxValue(Element *Root)
{
    if (Root->right == nullptr)
    {
        return Root->data;
    }
    return maxValue(Root->right);
}

int Tree::maxValue()
{
    Element *Temp = this->root;
    return maxValue(Temp);
}

int Tree::minValue(Element *Root)
{
    if (Root->left == nullptr)
    {
        return Root->data;
    }
    return minValue(Root->left);
}

int Tree::minValue()
{
    Element *Temp = this->root;
    return minValue(Temp);
}

int Tree::size(Element *Root)
{
    // if (Root == nullptr)
    // {
    //     return 0;
    // }
    // return size(Root->left) + 1 + size(Root->right);

    return Root == nullptr ? 0 : size(Root->left) + 1 + size(Root->right);
}

int Tree::size()
{
    Element *Temp = this->root;
    return size(Temp);
}

int Tree::sum(Element *Root)
{
    if (Root == nullptr)
    {
        return 0;
    }
    return sum(Root->left) + sum(Root->right) + Root->data;
}
int Tree::sum()
{
    Element *Temp = this->root;
    return sum(Temp);
}

double Tree::avg()
{
    return (double)sum(root) / size(root);
}

class UniqueTree : public Tree
{
private:
    void insert(int data, Element *Root);

public:
    UniqueTree(const std::initializer_list<int> &datas) : Tree::Tree(datas) {}
    UniqueTree() : Tree() {}
    void insert(int data);
};

//! unique tree

void UniqueTree::insert(int data, Element *Root)
{
    if (this->root == nullptr)
    {
        this->root = new Element(data);
        return;
    }
    if (Root == nullptr)
    {
        return;
    }
    if (data < Root->data)
    {
        if (Root->left == nullptr)
        {
            Root->left = new Element(data);
        }
        else
        {
            insert(data, Root->left);
        }
    }
    else if (data > Root->data)
    {
        if (Root->right == nullptr)
        {
            Root->right = new Element(data);
        }
        else
        {
            insert(data, Root->right);
        }
    }
}

void UniqueTree::insert(int data)
{
    Element *Temp = this->root;
    insert(data, Temp);
}

// #define CHECK
int main()
{
    srand(time(0));
#ifdef CHECK
    UniqueTree tree;
    tree.insert(99);
    tree.insert(33);
    tree.insert(23);
    tree.insert(65);
    tree.insert(65);
    tree.print();
    // for (int i = 0; i < n; i++)
    // {
    //     tree.insert(rand() % 20 + 1, tree.getRoot());
    // }

    // tree.insert(44,tree.getRoot());
    // tree.insert(33,tree.getRoot());
    // tree.insert(22,tree.getRoot());
    // tree.insert(99,tree.getRoot());
    // tree.insert(21,tree.getRoot());
    // tree.insert(88,tree.getRoot());
    // tree.insert(35,tree.getRoot());

    // tree.insert(40);
    // tree.insert(25);
    // tree.insert(50);
    // tree.insert(30);

    cout << endl;

    // cout << "Max value: " << tree2.maxValue() << endl;
    // cout << "Min value : " << tree2.minValue() << endl;
    // cout << "Size of binary: " << tree2.size() << endl;
    // cout << "Sum of element: " << tree2.sum() << endl;
    // cout << "Average of numbers: " << tree2.avg() << endl;

    // tree2.erase(tree.getRoot(), 70);

    cout << endl;

    // tree2.print();

#endif // DEBUG

    Tree tree = {3, 5, 6, 34, 56, 7, 5, 44};
    tree.print();
    Tree tree2 = tree;
    tree2.print();

    return 0;
}