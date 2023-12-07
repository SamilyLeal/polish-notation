#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}

int calculateExpression(struct Node* root) {

    if (isdigit(root->value)) {
        return root->value - '0';
    }

    int leftValue = calculateExpression(root->left);
    int rightValue = calculateExpression(root->right);

    switch (root->value) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }
    
}

void printTreeExpression(struct Node *root) {
	
	if (root->value >= '0' && root->value <= '9') {
        printf("%c", root->value);
    } else {
        printf("(");
        printTreeExpression(root->left);
        printf(" %c ", root->value);
        printTreeExpression(root->right);
    	printf(")");
    }
	
}

int main() {
    //as arvores precisam ser montadas manualmente :(
	
	//(+ (+ 5 3) (* 2 4)) -> Resultado 16
    struct Node* expression1 = createNode('+');
    expression1->left = createNode('+');
    expression1->left->left = createNode('5');
    expression1->left->right = createNode('3');
    expression1->right = createNode('*');
    expression1->right->left = createNode('2');
    expression1->right->right = createNode('4');
    
    //(+ 3 4) -> Resultado 7
    struct Node* expression2 = createNode('+');
    expression2->left = createNode('3');
    expression2->right = createNode('4');
    
    //(- (* 5 2) 3) -> Resultado 7
    struct Node* expression3 = createNode('-');
    expression3->left = createNode('*');
    expression3->left->left = createNode('5');
    expression3->left->right = createNode('2');
    expression3->right = createNode('3');
    
    //(/ (* (+ 2 3) 4) 2) -> Resultado 10
    struct Node* expression4 = createNode('/');
    expression4->left = createNode('*');
    expression4->left->left = createNode('+');
    expression4->left->left->left = createNode('2');
    expression4->left->left->right = createNode('3');
    expression4->left->right = createNode('4');
    expression4->right = createNode('2');
    
    //(+ (+ (+ 1 2) 3) 4) -> Resultado 10
    struct Node* expression5 = createNode('+');
    expression5->left = createNode('+');
    expression5->left->left = createNode('+');
    expression5->left->left->left = createNode('1');
    expression5->left->left->right = createNode('2');
    expression5->left->right = createNode('3');
    expression5->right = createNode('4');
    
    //(- (* 2 (+ 3 5)) (/ 8 2)) -> Resultado 12
    struct Node* expression6 = createNode('-');
    expression6->left = createNode('*');
    expression6->left->left = createNode('2');
    expression6->left->right = createNode('+');
    expression6->left->right->left = createNode('3');
    expression6->left->right->right = createNode('5');
    expression6->right = createNode('/');
    expression6->right->left = createNode('8');
    expression6->right->right = createNode('2');



	printf("Expressao: ");
	printTreeExpression(expression1);
    printf("\nResultado: %d\n\n", calculateExpression(expression1));
    
    printf("Expressao: ");
	printTreeExpression(expression2);
    printf("\nResultado: %d\n\n", calculateExpression(expression2));
    
    printf("Expressao: ");
	printTreeExpression(expression3);
    printf("\nResultado: %d\n\n", calculateExpression(expression3));
    
    printf("Expressao: ");
	printTreeExpression(expression4);
    printf("\nResultado: %d\n\n", calculateExpression(expression4));
    
    printf("Expressao: ");
	printTreeExpression(expression5);
    printf("\nResultado: %d\n\n", calculateExpression(expression5));
    
    printf("Expressao: ");
	printTreeExpression(expression6);
    printf("\nResultado: %d\n\n", calculateExpression(expression6));
	
    return 0;
}

