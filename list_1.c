#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Student
{
    char name[10];
    struct Student *pnext;
}STU,*LINK;

STU *create()
{
    char str[10];
    char flag;
    LINK p,h;
    h = (LINK)malloc(sizeof(STU));
    h->pnext = NULL;
    printf("请输入姓名：");
    scanf("%s",&h->name);
    getchar();
    while(1)
    {
        printf("是否继续输入？");
        scanf("%c",&flag);
        getchar();
        if(flag == 'y')
        {
            p=(LINK)malloc(sizeof(STU));
            printf("请输入姓名：");
            scanf("%s",&p->name);
            getchar();
            p->pnext=h->pnext;
            h->pnext=p;
        }else
        {
            break;
        }
    }
    return h;
}

int main()
{
    LINK p;
    p = create();
    while (1)
    {
        printf("%s\n",p->name);
        if(p!=NULL){
            p = p->pnext;   //遍历
        }else{
            break;
        }
    }
    getchar();
}