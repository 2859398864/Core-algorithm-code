#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Huffman���Ľڵ���
typedef struct Node
{
    char value;               //�����ַ�ֵ   
    int weight;               //����ַ����ֵ�Ƶ��
    Node *lchild,*rchild;     //�������Һ���
}Node;

//�Զ���������򣬼���vector��node���weightֵ��������
bool ComNode(Node *p,Node *q)
{
    return p->weight < q->weight;
}

//����Huffman�������ظ����ָ��
Node* BuildHuffmanTree(vector<Node*> vctNode)
{
    while(vctNode.size()>1) //vctNodeɭ��������������1ʱѭ�����кϲ�
    {
        sort(vctNode.begin(),vctNode.end(),ComNode);  //��Ƶ�ȸߵͶ�ɭ���е���������������

        Node *first=vctNode[0];    //ȡ�������vctNodeɭ����Ƶ����С������
        Node *second=vctNode[1];   //ȡ�������vctNodeɭ����Ƶ�ȵڶ�С������
        Node *merge=new Node;      //�ϲ�����������
        merge->weight = first->weight + second->weight;
        merge->lchild = first;
        merge->rchild = second;
        vector<Node*>::iterator iter;
        iter=vctNode.erase(vctNode.begin(),vctNode.begin()+2);    //��vctNodeɭ����ɾ������Ƶ����С�������ڵ�first��second
        vctNode.push_back(merge);                                 //��vctNodeɭ������Ӻϲ����merge��
    }
    return vctNode[0];            //���ع���õĸ��ڵ�
}

//�û��ݷ�����ӡ����
void PrintHuffman(Node *node,vector<int> vctchar)
{
    if(node->lchild==NULL && node->rchild==NULL)
    {//���ߵ�Ҷ�ӽڵ㣬�������ӡvctchar�д�ı���
        cout<<node->value<<": ";
        for(vector<int>::iterator iter=vctchar.begin();iter!=vctchar.end();iter++)
            cout<<*iter;
        cout<<endl;
        return;
    }
    else
    {
        vctchar.push_back(1);     //����������ʱ��vctchar�м�һ��1
        PrintHuffman(node->lchild,vctchar);
        vctchar.pop_back();       //���ݣ�ɾ���ոռӽ�ȥ��1
        vctchar.push_back(0);     //����������ʱ��vctchar�м�һ��0
        PrintHuffman(node->rchild,vctchar);
        vctchar.pop_back();       //���ݣ�ɾ���ոռӽ�ȥ��0

    }
}

int main()
{
	//a b c d e
	//12 34 56 6 73 
    cout<<"************ Huffman�������� ***************"<<endl;
    cout<<"������Ҫ������ַ�,���Կո�������������⣩��"<<endl;
    vector<Node*> vctNode;        //���Node����vector����vctNode
    char ch;                      //��ʱ��ſ���̨������ַ�
    while((ch=getchar())!='\n')
    {
        if(ch==' ')continue;      //�����ո�ʱ��������ûÿ��һ���ַ���һ��ո�
        Node *temp=new Node;
        temp->value=ch;
        temp->lchild=temp->rchild = NULL;
        vctNode.push_back(temp);  //���µĽڵ���뵽����vctNode��
    }

    cout<<endl<<"������ÿ���ַ���Ӧ��Ƶ�ȣ����Կո������"<<endl;
    for(int i=0;i<vctNode.size();i++)
        cin>>vctNode[i]->weight;
        
    Node *root = BuildHuffmanTree(vctNode);  //����Huffman���������ص���������root
    vector<int> vctchar;
    cout<<endl<<"��Ӧ��Huffman�������£�"<<endl;
    PrintHuffman(root,vctchar);
    
    system("pause");
}
