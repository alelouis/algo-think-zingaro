#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int candy; // if the node is an house
    struct node *left; // left children
    struct node *right; // right children
} node;

// create a new house
node *new_house(int candy) {
    node *house = malloc(sizeof(node));
    if (house == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    house -> candy = candy;
    house -> left = NULL;
    house -> right = NULL;
    return house;
}

// create intersections
node *new_nonhouse(node *left, node *right) {
    node *nonhouse = malloc(sizeof(node));
    if (nonhouse == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    nonhouse -> left = left;
    nonhouse -> right = right;
    return nonhouse;
}

// implementing the stack
#define SIZE 255

typedef struct stack {
    node *values[SIZE];
    int highest_used;
} stack;

stack *new_stack(void) {
    stack *s = malloc(sizeof(stack));
    if (s == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    s -> highest_used = -1;
    return s;
}

void push_stack(stack *s, node *value) {
    s -> highest_used++;
    s -> values[s->highest_used] = value;
}

node *pop_stack(stack *s) {
    node *ret = s->values[s->highest_used];
    s->highest_used--;
    return ret;
}

int is_empty_stack(stack *s) {
    return s->highest_used==-1;
}

int tree_candy(node *tree) {
    int total = 0;
    stack *s = new_stack();
    while (tree != NULL) {
        // if is an intersection
        if (tree->left && tree->right) {
            // add left node to stack
            push_stack(s, tree->left);
            // go to right
            tree = tree->right;
        } else {
            // if an house
            total += tree->candy;
            // what next ?
            if (is_empty_stack(s)) {
                // we are done
                tree = NULL;
            } else {
                // go to last of stack
                tree = pop_stack(s);
            }
        }
    }
    return total;
}

// finding the number of streets in the tree
int tree_streets(node *tree) {
    if (!tree->left && !tree->right) {
        // if at leaf
        return 0;
    } else {
        // going on left and right subtrees + 2 back and forth
        return tree_streets(tree->left) + tree_streets(tree->right) + 4;
    }
}

// util max function
int max(int v1, int v2) {
    if (v1 > v2) {
        return v1;
    }else{
        return v2;
    }
}

// finding the height of a tree
int tree_height(node * tree) {
    if (!tree->right && !tree->left) {
        return 0;
    }
    return 1 + max(tree_height(tree->left), tree_height(tree->right));
}

// finding num of candies and optimal num of streets
void tree_solve(node *tree) {
    int candy = tree_candy(tree);
    int height = tree_height(tree);
    int num_streets = tree_streets(tree) - height;
    printf("%d %d\n", num_streets, candy);
}

