#include<iostream>
#include<windows.h>
#include<stack>
using namespace std;
#define ElemType int
typedef struct node{
    ElemType data;
    int p;
    struct node *lchild;
    struct node *rchild;
}BSTNode;

void DispBTree(BSTNode *x){
    if(x!=NULL){
        printf("%d",x->data);
    
    if(x->lchild!=NULL||x->rchild!=NULL){
        printf("(");
        DispBTree(x->lchild);
        if(x->rchild!=NULL){
            printf(",");
            
        }
        DispBTree(x->rchild);
        printf(")");
    }
 }
 }

BSTNode *InsertBST(BSTNode *bt,int k){
    if(bt==NULL){
        bt = (BSTNode*)malloc(sizeof(BSTNode));
        bt->data=k;bt->lchild=NULL;bt->rchild=NULL;
        return bt;
    }
    else if(k<bt->data){
        bt->lchild = InsertBST(bt->lchild,k);
    }
    else if(k>bt->data){
        bt->rchild = InsertBST(bt->rchild,k);
    }
    return bt;
}

BSTNode *CreatBST(int a[],int n){
    BSTNode *bt = NULL;
    int i = 0;
    while(i<n){
        bt = InsertBST(bt,a[i]);
        i++;
    }
    return bt;
}
int pre = -1;
bool JudgeBST(BSTNode *bt){
    if(bt==NULL){
        return true;
    }
    bool jdgl = JudgeBST(bt->lchild);
    if(!jdgl){return false;}
    if(bt->data<=pre){
        return false;
    }
    else{
        pre = bt->data;
    }
    return JudgeBST(bt->rchild);
}

bool findnum(BSTNode *bt,int k,int path){
    if(bt==NULL){
        return false;
    }
    if(bt->data==k){
        path = path*10+bt->data;
        printf("%d\n",path);
        return true;
    }
    return (findnum(bt->lchild,k,path*10+bt->data)||findnum(bt->rchild,k,path*10+bt->data));
}
void zhiling(BSTNode *&bt){
    
    if(bt!=NULL){
        if(bt->lchild!=NULL){
            bt->p = 0;
        }
        else if(bt->rchild!=NULL){
            bt->p = 1;
        }
        else if(bt->lchild==NULL&&bt->rchild==NULL){
            bt->p = 2;
        }
        zhiling(bt->lchild);
        zhiling(bt->rchild);
    }
    else{return;}
}

bool findnumfei(BSTNode *bt,int k){
    zhiling(bt);
    stack<BSTNode*> q;
    int path = 0;int u = 1;
    q.push(bt);
    while(!q.empty()){
        BSTNode *p = q.top();
        if((p->data) == k){
            
            while(!q.empty()){
                path += u*q.top()->data;
                u*=10;
                q.pop();
            }
            printf("%d",path);
            return true;
        } 
        if(p->p==0){//4
            p->p = 1;
            q.push(p->lchild);
        }
        else if(p->p==1&&p->rchild!=NULL){
            p->p = 2;
            q.push(p->rchild);
        }
        else if(p->p==1&&p->rchild==NULL){
            p->p=0;q.pop();
        }
        else{
            p->p = 0;
            q.pop();
        }
            
        }
        printf("dfghj");
        return false;
    }


BSTNode *DeleteBST(BSTNode *bt,int k){
    if(bt==NULL){
        return bt;
    }
    BSTNode *p = bt,*f = NULL;
    while(p!=NULL){
        if(p->data==k)break;
        f=p;
        if(k<p->data){
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
        if(p==NULL)return bt;
        if(p->lchild==NULL&&p->rchild==NULL){
            if(p==bt){bt=NULL;}
            else{
                if(f->lchild==p){
                    f->lchild=NULL;
                }
                else{
                    f->rchild=NULL;
                }
            }
            free(p);
        }
        else if(p->rchild==NULL){
            if(f==NULL)
            {
                bt=bt->lchild;
            }
            else{
                if(f->lchild==p){
                    f->lchild=p->lchild;
                }
                else{
                    f->lchild=p->lchild;
                }
            }
            free(p);
        }
        else if(p->lchild==NULL){
            if(f==NULL){
                bt=bt->rchild;
            }
            else{
                if(f->lchild==p){
                    bt=bt->rchild;
                }
                else{
                    f->rchild=p->rchild;
                }
            }
            free(p);
        }
        else{
            BSTNode *q = p->lchild;
            f=p;
            while(q->rchild!=NULL){
                f=q;
                q=q->rchild;
            }
            p->data=q->data;
            if(q==f->lchild){
                f->lchild=q->lchild;
            }
            else{
                f->rchild=q->lchild;
            }
            free(q);
        }
        return bt;
    }



int main(void){
    int a[10]={4,9,0,1,8,6,3,5,2,7};
    BSTNode *bt = CreatBST(a,10);
    DispBTree(bt);
    printf("\n");
    if(JudgeBST(bt)){
        printf("是排序二叉树\n");
    }

    printf("到6路径递归:");findnum(bt,6,0);
    printf("到3路径非递归:");findnumfei(bt,3);
    printf("\n");
    bt = DeleteBST(bt,4);
    bt = DeleteBST(bt,5);
    printf("删除45后：");
    DispBTree(bt);
    system("pause");
    return 0;
}