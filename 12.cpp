#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char code[8];
    char name[65];
    char price[17];
} product;

typedef struct list {
    product value;
    struct list* next;
} list;

void push(list **lst, product value) {
    list *tmp = (list*) malloc(sizeof(list));
    tmp->value = value;
    tmp->next = *lst;
    *lst = tmp;
}

void pushBack(list** lst, product value) {
    list *tmp = (list*)malloc(sizeof(list));
    tmp->value = value;
    tmp->next = NULL;
    if (*lst == NULL) *lst = tmp;
    else {
        list* last = *lst;
        while (last->next) last = last->next;
        last->next = tmp;
    }
}

void pop(list** lst) {
	list* tmp = *lst;
	*lst = tmp->next;
	free(tmp);
}

void welcomeMessage() {
    printf("СИСТЕМА УПРАВЛЕНИЯ КАТАЛОГОМ v1.2\n\
    1. Создание нового файла каталога\n\
    2. Импорт существующего каталога из файла\n\
    3. Просмотр текущего каталога\n\
    4. Сохранение каталога в файл\n\
    5. Добавление товара\n\
    6. Удаление товара\n\
    7. Поиск товара по коду\n\
    8. Изменение данных о товаре\n\
    0. Выход из системы\n");
}

void clearBuf() {
    while (getchar() != '\n');
}

char* cut(char* str) {
    if (*str == ' ') str = str+1;
    if (str[strlen(str)-1] == ' ') str[strlen(str)-1] = '\0';
    return str;
}

list* createCatalog(list* lst) {
	FILE* cat = fopen("catalog.txt", "w");
    if (cat == NULL) {
        printf("Ошибка создания файла!\n");
        return NULL;
    }
	fclose(cat);
	while (lst != NULL)
		pop(&lst);
    printf("Файл каталога создан\n");
	return lst;
}

list* importCatalog(list* lst) {
    FILE* cat = fopen("catalog.txt", "r");
    if (cat == NULL) {
        printf("Ошибка открытия файла!\n");
        return NULL;
    }
    product product;
    while (lst != NULL)
		pop(&lst);
    while (!feof(cat)) {
        char str[256];
        fgets(str, 256, cat);
        strcpy(product.code, cut(strtok(str, "|\n")));
        strcpy(product.name, cut(strtok(NULL, "|\n")));
        strcpy(product.price, cut(strtok(NULL, "|\n")));
        pushBack(&lst, product);
    }
    fclose(cat);
    if (lst == NULL) printf("Внимание! На данный момент каталог пуст\n");
    else printf("Каталог успешно импортирован\n");
    return lst;
}

void printCatalog(list* lst) {
    if (lst == NULL) {
        printf("Каталог пуст\n");
    }
    else {
        while (lst) {
            product tmp = lst->value;
            printf("Код: %s | Наименование: %-30s | Цена: %s р.\n", tmp.code, tmp.name, tmp.price);
            lst = lst->next;
        }
    }
}

void saveCatalog(list* lst) {
    FILE* cat = fopen("catalog.txt", "w");
    if (cat == NULL) printf("Ошибка открытия файла!\n");
    else if (lst == NULL) printf("Каталог пуст, сохранять нечего\n");
    else {
        while (lst) {
            product tmp = lst->value;
            fprintf(cat, "%s | %s | %s", tmp.code, tmp.name, tmp.price);
            if (lst->next != NULL) fprintf(cat, "\n");
            lst = lst->next;
        }
        printf("Каталог успешно сохранен\n");
    }
    fclose(cat);
}

int deleteProduct(list** lst, char* code) {
    if (*lst == NULL) {
        printf("Каталог пуст\n");
        return 0;
    }
    if (!strcmp((*lst)->value.code, code)) {
        if ((*lst)->next == NULL) {
            free(*lst);
            *lst = NULL;
        }
        else *lst = (*lst)->next;
        printf("Товар удален\n");
        return 0;
    }
    else {
        list* tmp = *lst;
        while (tmp->next) {
            if (!strcmp(tmp->next->value.code, code)) {
                list* elem = tmp->next;
                tmp->next = elem->next;
                free(elem);
                printf("Товар удален\n");
                return 0;
            }
            tmp = tmp->next;
        }
    }
    printf("Товар с таким кодом не найден\n");
}

int foundProduct(list* lst, char* code) {
    if (lst == NULL) {
        printf("Каталог пуст\n");
        return 0;
    }
    while (lst) {
        if (!strcmp(lst->value.code, code)) {
            printf("Код: %s | Наименование: %-30s | Цена: %s р.\n", lst->value.code, lst->value.name, lst->value.price);
            return 0;
        }
        lst = lst->next;
    }
    printf("Товар с таким кодом не найден\n");
}

int changeProduct(list* lst, char* code) {
    if (lst == NULL) {
        printf("Каталог пуст\n");
        return 0;
    }
    while (lst) {
        if (!strcmp(lst->value.code, code)) {
            printf("Новое название товара: ");
            gets(lst->value.name);
            printf("Новая цена товара: ");
            gets(lst->value.price);
            printf("Данные о товаре изменены\n");
            return 0;
        }
        lst = lst->next;
    }
    printf("Товар с таким кодом не найден\n");
}

int isExists(list* lst, char* value) {
    while (lst) {
        if (!strcmp(lst->value.code, value) || !strcmp(lst->value.name, value))
            return 1;
        lst = lst->next;
    }
    return 0;
}

int main() {
    list* catalog = NULL;
    char choice;
    char code[8];
    welcomeMessage();
    while (choice != '0') {
        printf("Опция: ");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            clearBuf();
            FILE* cat = fopen("catalog.txt", "r");
            if (cat != NULL) {
                fclose(cat);
                char ans;
                printf("Это действие перезапишет существующий файл каталога\nПродолжить (y - да, other - нет)? ");
                clearBuf();
                scanf("%c", &ans);
                if (ans != 'y') {
                    printf("Действие отменено\n");
                    break;
                }
            }
            catalog = createCatalog(catalog);
            break;
        case '2':
            clearBuf();
            catalog = importCatalog(catalog);
            break;
        case '3':
            clearBuf();
            printCatalog(catalog);
            break;
        case '4':
            clearBuf();
            saveCatalog(catalog);
            break;
        case '5':
            clearBuf();
            product tmp;
            int amount;
            printf("Количество добавляемых товаров: ");
            scanf("%d", &amount);
            clearBuf();
            for (int i = 0; i < amount; i++) {
                printf("Товар %d\n", i+1);
                int exist = 0;
                printf("Код товара: ");
                gets(tmp.code);
                while (strlen(tmp.code) != 7) {
                    printf("В коде товара должно быть 7 символов: ");
                    gets(tmp.code);
                }
                if (isExists(catalog, tmp.code)) {
                    printf("Товар с таким кодом уже существует!\n");
                    i--;
                    continue;
                }
                printf("Название товара: ");
                gets(tmp.name);
                if (isExists(catalog, tmp.name)) {
                    printf("Товар с таким названием уже существует!\n");
                    i--;
                    continue;
                }
                printf("Цена товара: ");
                gets(tmp.price);
                pushBack(&catalog, tmp);
            }
            break;
        case '6':
            clearBuf();
            printf("Введите код удаляемого товара: ");
            gets(code);
            deleteProduct(&catalog, code);
            break;
        case '7':
            clearBuf();
            printf("Введите код искомого товара: ");
            gets(code);
            foundProduct(catalog, code);
            break;
        case '8':
            clearBuf();
            printf("Введите код товара для изменения данных: ");
            gets(code);
            changeProduct(catalog, code);
        }
    }
}
