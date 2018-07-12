//
//  main.c
//  C prac
//
//  Created by MacBookPro on 2018. 7. 1..
//  Copyright © 2018년 MacBookPro. All rights reserved.
//

#include <stdio.h>

int temp[8];
int idx;

typedef struct _node{
    int key;
    struct _node *left;
    struct _node *right;
} node;
node *treesort(int arr[], int leng) {
    int i;
    node *cursor, *prev;
    node *root = (node *)malloc(sizeof(node));
    root->key = arr[0];
    for(i=1; i<leng; i++) {
        cursor = root;
        while(cursor != NULL) {
            if(arr[i]>cursor->key) {
                prev =cursor;
                cursor = cursor-> right;
            }
            else if(arr[i]<cursor->key) {
                prev = cursor;
                cursor = cursor->left;
            }
        }
        if(arr[i]>prev->key) {
            prev->right = (node *)malloc(sizeof(node));
            prev->right->key = arr[i];
        }
        if(arr[i]<prev->key) {
            prev->left = (node *)malloc(sizeof(node));
            prev->left->key = arr[i];
        }
        printf("%d\n", i );
    }
    return root;
}

void inorderTrav(node *ans) {
    if( ans != NULL) {
        inorderTrav(ans->left);
        printf("%d\n",ans->key);
        temp[idx++] = ans->key;
        inorderTrav(ans->right);
    }
}

node *balance(int n) {
    int ln, rn;
    node *r;
    ln = (n-1)/2;
    rn = n-ln-1;
    if(n>0) {
        r=(node *)malloc(sizeof(node));
        r->left = balance(ln);
        r->key = temp[idx++];
        r->right = balance(rn);
        return r;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i[8] = {26,4,51,42,19,13,7,8};
    node *ans = treesort(i, 8);
    inorderTrav(ans);
    printf("mid\n\n");
    idx = 0;
    balance(8);
    
    idx = 0;
    inorderTrav(ans);
    printf("end\n");
    return 0;
}
