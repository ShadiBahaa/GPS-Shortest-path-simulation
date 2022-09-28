#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "SINGLE_LINKED_LIST.h"
s8 dx[4] = {-1,0,1,0};
s8 dy[4] = {0,1,0,-1};
s8 vis[5][5];
s32 mini = 10000000;
s8 arr[5][5];
s8 srci,srcj,desti,destj;
u32 cnt = 0;
Node *min = NULL;
s8 check(s8 i,s8 j)
{
    return i>=0 && i<=4 && j>=0 && j<=4;
}
void dfs(s8 dir, Node**tmp)
{
    if (!check(srci,srcj)||!check(desti,destj)||vis[srci][srcj] || arr[srci][srcj]==1)
    {
        return;
    }
    s8 tmpi = srci;
    s8 tmpj = srcj;
    vis[tmpi][tmpj] = 1;
    if (dir)insert_last(tmp,dir);
    if (srci==desti && srcj==destj)
    {
        cnt++;
        print(tmp);
        if (*tmp!= NULL && (*tmp)->len < mini)
        {
            mini = (*tmp)->len;
            if (min!=NULL)free(min);
            min = NULL;
            Node *tmptmp = *tmp;
            while (tmptmp!=NULL){
                insert_last(&min,tmptmp->data);
                tmptmp = tmptmp->next;
            }
        }
    }
    else
    {
        for (s8 i = 0; i<4; ++i)
        {
            srci = dx[i]+tmpi;
            srcj = dy[i]+tmpj;
            dfs(i+1,tmp);
        }
    }
    vis[tmpi][tmpj] = 0;
    delete_last(tmp);
}
s32 main(void)
{
    Node *tmp = NULL;
    for (s8 i = 0; i<5; ++i)
    {
        for (s8 j = 0; j<5; ++j)
        {
            scanf("%d",&arr[i][j]);
            vis[i][j] = 0;
        }
    }

    scanf("%d%d%d%d",&srci,&srcj,&desti,&destj);
    dfs(0,&tmp);
    printf("The number of paths is: %d\n",cnt);
    if (mini!=10000000)printf("The shortest path is: %d\n",mini);
    print(&min);
}
/*
0 1 1 1 1
0 1 1 1 1
0 1 1 1 1
0 1 1 1 1
0 0 0 0 0
0 0 4 4
*/
