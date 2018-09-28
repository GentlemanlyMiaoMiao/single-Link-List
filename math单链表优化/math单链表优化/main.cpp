#include <iostream>
#include <stdlib.h>
#include <mm_malloc.h>
#include "stdlib.h"
using namespace std;
typedef struct Singly_Linked_List{
    int data;
    Singly_Linked_List *next;
}List;
void sort(int *arr,int n){
    for (int j = 0;j< n;j++){
        for(int k = 0;k<n - j-1;k++){
            if(arr[k]>arr[k+1]){
                int tmp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = tmp;
            }
        }
    }

}
int List_length(List *L){
    int n = 0;
    List *p =L;
    while (p!= NULL){
        n++;
        p = p->next;
    }
    return n;
}
void sort_list(List *&list1){
    List *head = list1;
    List *p  = list1;
    int n = List_length(list1),x;
    for(int j=0;j<n;j++){
        p = head;
        for(int k=0;k<n-j-1;k++){
            if(p->data > p->next->data){
                x =p->next->data;
                p->next->data = p->data;
                p->data = x;
            }
            p=p->next;
        }
   }
}
void insert(int elem,List *&list1,int n){
    int j = 0,b;
    List *p = list1,*s;
    while (p->data <=elem && j<n){
        j++;
        p = p->next;
    }
    s = (List *) malloc(sizeof(List));
    s->data = elem;
    s->next = p->next;
    p->next = s;

    b = s->data;
    s->data = p->data;
    p->data = b;
}
void reverse(List *&L){
        //定义三个指针
        List *prev = L;
        List *cur = L->next;
        List *next = NULL;//保存原链表中cur的下一个节点
        while (cur)
        {
            //因为要修改cur的next成员，先将next移到cur的下一个节点
            next = cur->next;//先将next移到cur的下一个节点
            cur->next = prev;//修改cur->next

            prev = cur;//prev前移到cur节点     让prev指向后面这一个，
            cur = next;//cur在原链表中递进一个节点
        }//此时prev移到了5节点，是新链表的首节点
        L->next = NULL;//原链表的first节点(新链表的尾节点)下一个节点为0
        L = prev;//让first移动到NULLprev(首节点)
}

void Creat_List(List *&list,int a[],int n){
    List *r , *s;
    int i;
    list = (List *)malloc(sizeof(List));
    r = list;
    for(i = 0;i < n;i++){
        s = (List *)malloc(sizeof(List));
        s ->data = a[i];
        r ->next = s;
        r = s;
    }
    r->next = NULL;
    printf("赋值的初始化ok！");
    printf("\n");
}
void DisplayList(List *list1){
    List *p = list1->next;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void mreg(List *list1,List *list2,List *&list3,int n,int m){

    List *r,*s;
    list3 = (List *) malloc(sizeof(List));
    r = list3;
    for(int i = 0;i < n-1;i++){   //特别注意循环次数,不能够超过这个链表的长度，链尾不能够->next
        s = (List *)malloc(sizeof(List));
        list1=list1->next;
        s ->data = list1->data;
        r ->next = s;
        r = s;
    }
    for(int i = 0;i < m-1;i++){
        s = (List *)malloc(sizeof(List));
        list2 = list2->next;
        s ->data = list2->data;
        r ->next = s;
        r = s;
    }
    r->next = NULL;
    DisplayList(list3);
}


class MyLisT{
public:
    MyLisT(List *&list,int *arr,int n);
    void reverse_list(List *&L);
    void insert_List(int elem,List *&list1);
    void sort_list_List(List *list1,List *list2,List *&list3);
};
void MyLisT::sort_list_List(List *list1,List *list2,List *&list3) {
    int n,m;
    printf("我们进行两个序列合并，并且递减\n");
    n = List_length(list1);
    m = List_length(list2);
    mreg(list1,list2,list3,n,m);
    sort_list(list3->next);
    printf("合并后的序列:\n");
    DisplayList(list3);
    printf("\n");
}
void MyLisT::insert_List(int elem, List *&list1) {
    int n;
    n = List_length(list1);
    insert(elem,list1,n);
    printf("我们插入的数字是%d\n",elem);
    printf("插入后的序列:\n");
    DisplayList(list1);
    printf("\n");
}
void MyLisT::reverse_list(List *&L) {
    printf("将序列进行反转:\n");
    reverse(L);
    DisplayList(L);
    printf("\n");
}
MyLisT::MyLisT(List *&list,int *arr,int n) {
    sort(arr,n);
    Creat_List(list,arr,n);
    DisplayList(list);
    printf("\n");
}

int main() {

    List *list1,*list2,*list3;
    int arr[] = {6,1,9,7,3};
    int num[] = {23,2,56,8,40};
    MyLisT *mylist1  = new MyLisT(list1,arr,sizeof(arr)/ sizeof(int));
    MyLisT *mylist2  = new MyLisT(list2,num,sizeof(num)/ sizeof(int));
    mylist1->insert_List(5, list2);
    mylist1->reverse_list(list1->next);
    mylist2->sort_list_List(list1,list2,list3);
}


