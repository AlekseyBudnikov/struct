#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10//количество элементов

typedef unsigned char UC;
typedef unsigned short US;

struct event
{
    char name[80];
    UC day;
    char mon[10];
    US year;
    char descr[256];
} event_list[N];

void init_list(),add(),del(),list();
int menu_select(),find_free();

int main()
{
    char choise;

    init_list();

    for(;;)
    {
        choise=menu_select();
        switch(choise)
        {
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                list();
                break;
            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}

void init_list()//объявление списка
{
    register int t;

    for(t=0;t<N;++t)
        event_list[t].name[0]='\0';
}

int menu_select()//выбор что нужно сделать
{
    char s[80];
    int c;

    printf("1. Add new event\n");
    printf("2. Delete event\n");
    printf("3. Display all events\n");
    printf("4. Exit\n");

    do
    {
        printf("\nEnter number: ");
        gets(s);
        printf("\n");
        c=atoi(s);
    }
    while(c<0 || c>4);

    return c;
}

void add()//добавить новый элемент
{
    int slot;
    char s[80];

    slot=find_free();
    if(slot==-1)
    {
        printf("\nNo free areas\n\n");
        return;
    }

    printf("Enter name: ");
    gets(event_list[slot].name);

    printf("Enter day: ");
    gets(s);
    event_list[slot].day=atoi(s);

    printf("Enter month: ");
    gets(event_list[slot].mon);

    printf("Enter year: ");
    gets(s);
    event_list[slot].year=atoi(s);

    printf("Enter description: ");
    gets(event_list[slot].descr);

    printf("\n");
}

int find_free()//поиск свободных элементов
{
    register int t;

    for(t=0;event_list[t].name[0] && t<N;++t);

    if(t==N)
        return -1;

    return t;
}

void del()//удаление элемента
{
    register int slot;
    char s[80];

    printf("Enter number of event: ");
    gets(s);
    slot=atoi(s);
    if(slot>=0 && slot<N)
        event_list[slot].name[0]='\0';
    else
        printf("\nNo such event\n\n");
}

void list()//отображение всех существующих элементов
{
    register int t;

    for(t=0;t<N;++t)
    {
        if(event_list[t].name[0])
        {
            printf("Name: %s\n",event_list[t].name);
            printf("Day: %1u\n",event_list[t].day);
            printf("Month: %s\n",event_list[t].mon);
            printf("Year: %1u\n",event_list[t].year);
            printf("Description: %s\n\n",event_list[t].descr);
        }
    }
}
