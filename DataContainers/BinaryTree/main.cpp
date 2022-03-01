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
    /// https://www.algolist.net/Data_structures/Binary_search_tree/Removal
    // not done
    // void DeleteElement(Element *Temp, int Data)
    // {
    //     if (Temp == nullptr)
    //     {
    //         return;
    //     }

    //     if (Data < Temp->data)
    //     {
    //         if (Temp->data == Data && Temp->right != nullptr && Temp->left != nullptr)
    //         {
    //             delete Temp;
    //         }
    //         else
    //         {
    //             DeleteElement(Temp->left, Data);
    //         }
    //     }
    //     else
    //     {
    //         if (Temp->data == Data && Temp->right != nullptr && Temp->left != nullptr)
    //         {
    //             delete Temp;
    //         }
    //         else
    //         {
    //             DeleteElement(Temp->right, Data);
    //         }
    //     }
    // }
    void erase(Element *Temp, int Data)
    {
        if (Temp == nullptr)
        {
            return;
        }

        if (Temp->data == Data)
        {
            if (Temp->left == nullptr && Temp->right == nullptr)
            {
                delete Temp;
                return;
            }
            else if (Temp->left != nullptr && Temp->right != nullptr && Temp->data > root->data)
            {                                // (Temp->data > root->data)To check is right or left side
                int minElement = minValue(); // find max value
                Temp->data = minElement;
                erase(Temp->left, minElement); // to delete element
            }
            // else if(Temp->right != nullptr && Temp->left == nullptr) {
            //     Element *Erased = Temp;
            //     Temp = Temp->right;
            //     delete Erased;
            // }
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
    friend class UniqueTree;
};

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
    return sum(root) / size(root);
}

class UniqueTree : public Tree
{
private:
    void insert(int data, Element *Root);

public:
    UniqueTree(const std::initializer_list<int> &datas) : Tree::Tree(datas) {}

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

void UniqueTree::insert(int data)
{
    Element *Temp = this->root;
    insert(data, Temp);
}

#define CHECK
int main()
{
    srand(time(0));
#ifdef CHECK
    Tree tree = {50, 25, 80, 16, 32, 64, 85};
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

    tree.print();

    cout << endl;

    cout << "Max value: " << tree.maxValue() << endl;
    cout << "Min value : " << tree.minValue() << endl;
    cout << "Size of binary: " << tree.size() << endl;
    cout << "Sum of element: " << tree.sum() << endl;
    cout << "Average of numbers: " << tree.avg() << endl;

    tree.erase(tree.getRoot(), 80);

    cout << endl;

    tree.print();

#endif // DEBUG

    return 0;
}