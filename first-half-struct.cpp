#include <stdio.h>
#include <iostream>
#include <cstdlib>
#define MAX_LEN 80   
#define END_CHAR '.'

using std::cout;
using std::cin;

char ReadTop(char stack[]){
    char top = stack[1];
    return top;
}

void DelElem(char stack[], int top, int *len){
    for (int i = 0; i < *len; ++i){
        stack[i] = stack[i + 1];
    }     
    (*len)--;
    top = stack[0];
}

// int InputStack(char stack[], int top, int len){
//     char inChar;
//     int tmp = 0;
//     cout << "\n Введите элементы:  ";
//     for (int i = 1; i < len; ++i) {
//         cin >> inChar
//         if (inChar == '.'){
//             cout << "Ping\n";
//             break;
//         }
//         if (top < MAX_LEN){
//             stack[0] = inChar;
//             stack[i]
//             len++;
//         } else{
//             cout << "\n Cтек Переполнен \n";
//             break;
//         }
//     }
// }

int InputStack(char stack[], int top, int len){
    char inChar;
    cout << "\n Введите элементы:  ";
    while (cin >> inChar){
        if (inChar == '.'){
            break;
        }
        if (top < MAX_LEN){
            stack[len++] = inChar;
        } else{
            cout << "\n Cтек Переполнен \n";
            break;
        }
    }
    return len;
}

bool StackIsOverflow(int len){
    return(len >= MAX_LEN - 1 ? 1 : 0);
}

void OutputStack(char stack[], int len){
    cout << "\n Вывод: \n";
    if (len > 0){
        for (int i = len; i >= 0; --i){
            cout << stack[i] << '\n';
        }
    }
    else
        cout << "Cтек пуст!";
    cout << "\n";
}

void AddInCenter(char stack[], int *len){
    int ind = *len / 2;
    (*len)++;
    for (int i = *len; i > ind; --i) {
        stack[i] = stack[i - 1];
    }
    stack[ind] = '*';
}

bool EmptyStack(int len) {
	if (len == 0)
		return 1;
	return 0;
}

void CleanStack(char stack[], int len){
    int i = 0;
    while (i < len){
        stack[i] = 0;
        ++i;
    }
    len = 0;
}

void ViewMenu(){
    cout << "   Меню:\n";
    cout << "1 - Печать стека\n";
    cout << "2 - Добавление элемента в стек\n";
    cout << "3 - Удаление элемента из стека\n";
    cout << "4 - Считывание элемента из стека без удаления\n";
    cout << "5 - Проверка стека на пустоту\n";
    cout << "6 - Проверка стека на переполнение\n";
    cout << "7 - Очистка стека\n";
    cout << "8 - Вставить * в середину стека\n";
    cout << "9 - Вывести меню\n";
    cout << "10 - Выход\n";
}
void Menu(){
    int value = 0;
    int top = 0;
    int len = 0;
    char stack[MAX_LEN];
    ViewMenu();
    while (value != 10){
        cout << ">   ";
        cin >> value;
        switch (value){
            case 1:
                /* print st */       
                OutputStack(stack, len);
            break;
            
            case 2:
                /* add elem */
                len = InputStack(stack, top, len);
            break;
            
            case 3:
                /* del elem */
                DelElem(stack, top, &len);
            break;
            
            case 4:
                /* read top */
                cout << stack[len - 1] << "\n";
            break;
            
            case 5:
                /* empty */
                cout << (EmptyStack(len) ? "Стeк пуст" : "Стeк не пуст") << "\n";
            break;
            
            case 6:
                /* overflow */
                cout << (StackIsOverflow(len) ? "Стек переполнен" : "Стек не переполнен" ) << "\n";
            break;
            
            case 7:
                /* clean stack */
                len = 0;
                // CleanStack(stack, len);
            break;
            
            case 8:
                /* add * in center */
                AddInCenter(stack, &len);
            break;
            
            case 9:
                /* output */
                ViewMenu();
            break;
            
            case 10:
                cout << "Завершение работы программы...\n";
            break;
            
            default:
                cout << "Неизвестная команда\n";
            break;
        }
    }
}

int main(){
    system("clear");
    Menu();
    return 0;
}