#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

typedef enum {
	STACK_OK = 0,
	STACK_EMPTY = 1,
	STACK_OVERFLOW = 2
} Error_t;

typedef struct Stack {
	int value;
	int max_size;
	int ind;
	struct Stack *next;
} Stack;

Stack* StackInit(int size) {
	Stack *st = (Stack*)malloc(sizeof(Stack));
	st->next = NULL;
	st->ind = -1;
	st->max_size = size;
	return st;
}

bool StackIsOverflow(Stack *st) {
	if (st->ind + 1 < st->max_size)
		return 0;
	return 1;
}

bool StackIsEmpty(Stack *st) {
	if (st->next == NULL)
		return 1;
	return 0;
}

void StackRemove(Stack **st) {
	if (*st)
		StackRemove(&((*st)->next));
	free(*st);
	*st = NULL;
}

Error_t StackPrint(Stack *st) {
	if (StackIsEmpty(st)) 
		return STACK_EMPTY;
	printf("stack > ");
	while (st->next) {
		printf("%d ", st->value);
		st = st->next;
	}
	printf("\n");
	return STACK_OK;
}

Error_t StackPush(Stack **st, int val) {
	if (StackIsOverflow(*st)) 
		return STACK_OVERFLOW;
	Stack *tmp = (Stack*)malloc(sizeof(Stack));
	tmp->value = val;
	tmp->ind = (*st)->ind + 1;
	tmp->max_size = (*st)->max_size;
	tmp->next = *st;
	*st = tmp;
	return STACK_OK;
}

Error_t StackPop(Stack **st, int* val) {
	if (StackIsEmpty(*st)) 
		return STACK_EMPTY;
	Stack *tmp = *st;
	*val = (*st)->value;
	*st = (*st)->next;
	free(tmp);
	return STACK_OK;
}

Error_t StackSize(Stack *st, int* size) {
	if (StackIsEmpty(st)) 
		return STACK_EMPTY;
	while (st->next) {
		++(*size);
		st = st->next;
	}
	return STACK_OK;
}

Error_t StackPeek(Stack *st, int* value) {
	if (StackIsEmpty(st)) 
		return STACK_EMPTY;
	*value = st->value;
	return STACK_OK;
}

Error_t StackSwap(Stack **st, int ind1, int ind2) {
	if (StackIsEmpty(*st)) 
		return STACK_EMPTY;
	int size = 0;
	StackSize(*st, &size);
	int* arr = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i)
		StackPop(st, &arr[i]);
	int tmp = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = tmp;
	for (int i = size - 1; i >= 0; --i)
		StackPush(st, arr[i]);
	free(arr);
	return STACK_OK;
}

void ErrorHandler(Error_t err) {
	switch (err) {
		case STACK_EMPTY:
			printf("ERROR: Стэк пуст...\n");
		break;

		case STACK_OVERFLOW:
			printf("ERROR: Стэк переплонен...\n");
		break;
	}
}

void MenuPrint() {
	printf("   Меню:\n");
	printf("1: Печать стека\n");
	printf("2: Добавление элемента в стек\n");
	printf("3: Удаление элемента из стека\n");
	printf("4: Считывание элемента из стека без удаления\n");
	printf("5: Проверка стека на пустоту\n");
	printf("6: Очистка стека\n");
	printf("7: Поменять местам элементы стека\n");
	printf("8: Проверка стека на переполнение\n");
	printf("9: Вывести меню\n");
	printf("10: Выход\n");
}

void StateMachine() {
	int state = 0;
	int size = 10;
	int val;
	Stack* stack = StackInit(size);
	MenuPrint();
	while (state != 10) {
		Error_t err = STACK_OK;
		printf(">>> ");
		scanf("%d", &state);
		switch (state) {
			case 1:
				err = StackPrint(stack);
				ErrorHandler(err);
			break;

			case 2:
				printf("Введите значение: ");
				scanf("%d", &val);
				err = StackPush(&stack, val);
				ErrorHandler(err);
			break;

			case 3:
				err = StackPop(&stack, &val);
				if (!err)
					printf("%d\n", val);
				ErrorHandler(err);
			break;

			case 4:
				err = StackPeek(stack, &val);
				if (!err) 
					printf("%d\n", val);
				ErrorHandler(err);
			break;

			case 5:
				printf("%s\n", (StackIsEmpty(stack) ? "Стэк пуст" : "Стэк не пуст"));
			break;

			case 6:
				StackRemove(&stack);
				stack = StackInit(size);
			break;

			case 7:
				printf("Введите номера: ");
				int ind1, ind2;
				scanf("%d%d", &ind1, &ind2);
				err = StackSwap(&stack, ind1 - 1, ind2 - 1);
				ErrorHandler(err);
			break;

			case 8:
				printf("%s\n", (StackIsOverflow(stack) ? "Стэк переполнен" : "Стэк не переполнен"));
			break;

			case 9:
				MenuPrint();
			break;

			case 10:
				printf("Завершение работы...\n");
			break;

			default:
				printf("Неизвестная команда\n");
			break;				
		}
	}
	if (stack != NULL)
		StackRemove(&stack);
}

int main() {
	system("clear");
	StateMachine();
	return 0;
}