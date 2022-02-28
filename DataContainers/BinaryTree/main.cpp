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
    } * root;

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
    }
    ~Tree()
    {
        deleteNode(root);
        cout << "Bdesctructor\t" << endl;
    }

    void insert(int data, Element *Root);
    void insert(int data);

    void print(Element *Root) const;
    void print() const;

    int maxValue(Element *Root);
    int maxValue();

    int minValue(Element *Root);
    int minValue();
    int size(Element *Root);
    int size();

    int sum(Element *Root);
    int sum();

    double avg();

    /// https://www.algolist.net/Data_structures/Binary_search_tree/Removal
    // not done
    //  void erase(Element *Temp,int Data) {
    //      if(Temp == nullptr) {
    //          return;
    //      }

    //     if(Data < Temp->data) {
    //         //left if
    //         if(Temp->data == Data) {
    //             //delete element
    //             if(Temp->left == nullptr && Temp->right == nullptr) {
    //                 delete Temp;
    //              }else if(Temp->right != nullptr) {

    //              }
    //         }else{
    //                 erase(Temp->left,Data);
    //         }
    //     }else{
    //         //right
    //         if(Temp->data == Data) {
    //             //delete element
    //              if(Temp->right == nullptr && Temp->left == nullptr) {
    //                 delete Temp;
    //              }
    //         }else{
    //                 erase(Temp->right,Data);
    //         }
    //     }

    // }
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
    if (Root == nullptr)
    {
        return 0;
    }
    return size(Root->left) + 1 + size(Root->right);
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

int main()
{
    srand(time(0));
    Tree tree = {2, 3, 5, 5, 7, 8};
    // for (int i = 0; i < n; i++)
    // {
    //     tree.insert(rand() % 20 + 1, tree.getRoot());
    // }

    // tree.insert(44,tree.getRoot());
    //  tree.insert(33,tree.getRoot());
    //   tree.insert(22,tree.getRoot());
    //   tree.insert(99,tree.getRoot());
    //     tree.insert(21,tree.getRoot());
    //      tree.insert(88,tree.getRoot());
    //       tree.insert(35,tree.getRoot());

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

    return 0;
}