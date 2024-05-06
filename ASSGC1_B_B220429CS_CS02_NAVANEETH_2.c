#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *tree(char *arr, int *index)
{
    if (arr[*index] == '\0')
        return NULL;

    char new_arr[10];
    int arrin = 0;
    while (arr[*index] != '(' && arr[*index] != ')' && arr[*index] != '\0')
    {
        new_arr[arrin] = arr[(*index)];
        arrin++;
        (*index)++;
    }
    new_arr[arrin] = '\0';
    if(arrin!=0){
    struct node *el = createnode(atoi(new_arr));
    if (arr[*index] == '(')
    {
        (*index)++;
        el->left = tree(arr, index);
        (*index)++;

        if (arr[*index] == '(')
        {
            (*index)++;
            el->right = tree(arr, index);
            (*index)++;
        }
    }

    return el;}
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {

        int lefth = height(root->left);
        int righth = height(root->right);

        if (lefth > righth)
            return (lefth + 1);
        else
            return (righth + 1);
    }
}

void travel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {

        travel(root->left, level - 1);
        travel(root->right, level - 1);
    }
}

void level(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        travel(root, i);
}

void check_bst(struct node *root, int *sum)
{
    if (root != NULL)
    {
        if ((root->left == NULL || root->left->key < root->key) &&
            (root->right == NULL || root->right->key > root->key))
        {
            *sum += root->key;
            check_bst(root->left, sum);
            check_bst(root->right, sum);
        }
        else
        {
            *sum = 0;
        }
    }
}
void bst(struct node *root, int arr[], int *i)
{
    if (root != NULL)
    {
        int sum = 0;
        check_bst(root, &sum);
        arr[(*i)++] = sum;
        bst(root->left, arr, i);
        bst(root->right, arr, i);
    }
    else
        return;
}

void rightview(struct node *root, int *l, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (*l < level)
    {
        printf("%d ", root->key);
        *l = level;
    }
    rightview(root->right, l, level + 1);
    rightview(root->left, l, level + 1);
}

int main()
{
    char arr[100];
    scanf("%s", arr);
    arr[strlen(arr)] = '\0';
    int index = 0;
    struct node *root = tree(arr, &index);
    char c[2];
    c[2] = '\0';
    while (1)
    {
        scanf("%s", c);
        if (strcmp("e", c) == 0)
        {
            break;
        }
        else if (strcmp("l", c) == 0)
        {
            level(root);
            printf("\n");
        }
        else if (strcmp("m", c) == 0)
        {
            int arr[100];
            int i = 0;
            bst(root, arr, &i);
            int max = arr[0];
            for (int j = 1; j < i; j++)
            {
                if (max < arr[j])
                {
                    max = arr[j];
                }
            }
            printf("%d\n", max);
        }
        else if (strcmp("r", c) == 0)
        {
            int l = 0;
            rightview(root, &l, 1);
            printf("\n");
        }
    }

    return 0;
}