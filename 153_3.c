#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct prolific_potion
{
    char ing[30];
    int qnt;
    struct prolific_potion *prev;
    struct prolific_potion *next;
} prolific_potion;


typedef struct requiredItems
{
    char ing[30];
    int qnt;
} required_items;
required_items requirement[5];
int pointer_in_beginning = 0;
int inspect_requirement(prolific_potion *potion)
{
    int flag_item_found = 0;
    int flag_item_qnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(requirement[i].ing, potion->ing) == 0)
        {
            flag_item_found = 1;
            if (potion->qnt >= requirement[i].qnt)
            {
                flag_item_qnt = 1;
            }
        }
    }
    if (flag_item_found == 1 && flag_item_qnt == 1)
        return 1;
    else if (flag_item_found == 0)
        return 1;
    else
        return 0;
}

prolific_potion *insert_at_end(prolific_potion *potion)
{
    char ing[30];
    int qnt;
    printf("\nEnter the ing : ");
    fflush(stdin);
    gets(ing);
    fflush(stdin);
    printf("\nEnter the qnt of the ing : ");
    scanf("%d", &qnt);
    prolific_potion *temp = (prolific_potion *)malloc(sizeof(prolific_potion));
    strcpy(temp->ing, ing);
    temp->qnt = qnt;
    temp->prev = NULL;
    temp->next = NULL;
    if (potion == NULL)
    {
        if (inspect_requirement(temp))
        {
            potion = temp;
            return potion;
        }
    }
    else
    {
        if (inspect_requirement(temp))
        {
            prolific_potion *curr = potion;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
            temp->prev = curr;
        }
    }
    return potion;
}

int inspect_items_gather(prolific_potion *potion)
{
    if (potion == NULL)
        return 0;
    prolific_potion *curr = potion;
    int count = 0;
    while (curr != NULL)
    {
        char ing[30];
        int qnt;
        strcpy(ing, curr->ing);
        qnt = curr->qnt;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(ing, requirement[i].ing) == 0 && qnt >= requirement[i].qnt)
                count++;
        }
        curr = curr->next;
    }
    if (count >= 5)
        return 1;
    else
        return 0;
}

void generatelist()
{
    strcpy(requirement[0].ing, "cups of fluxweed");
    requirement[0].qnt = 30;
    strcpy(requirement[1].ing, "bundles of knotgrass");
    requirement[1].qnt = 20;
    strcpy(requirement[2].ing, "leeches");
    requirement[2].qnt = 42;
    strcpy(requirement[3].ing, "Lacewing flies");
    requirement[3].qnt = 50;
    strcpy(requirement[4].ing, "Bicorn horn");
    requirement[4].qnt = 9;
}
prolific_potion *brew_the_potion(prolific_potion *potion)
{
    printf("\n");
    while (pointer_in_beginning < 5)
    {
        char ing[30];
        strcpy(ing, requirement[pointer_in_beginning].ing);
        int qnt = requirement[pointer_in_beginning].qnt;
        if (strcmp(ing, potion->ing) == 0)
        {
            printf("\nItem added for brewing : %s .", ing);
            printf("\nqnt left : %d .", potion->qnt - qnt);
            if (qnt == potion->qnt && potion->next != NULL)
            {
                printf("(So the node was deleted.)\n");
                prolific_potion *temp = potion;
                potion = potion->next;
                potion->prev = NULL;
                free(temp);
                temp = NULL;
            }
            else if (qnt == potion->qnt && potion->next == NULL)
            {
                prolific_potion *temp = potion;
                potion = NULL;
                free(temp);
                temp = NULL;
                printf("(So the node was deleted.)");
            }
            else
            {
                potion->qnt = (potion->qnt) - qnt;
                printf("(So the node was updated.)\n");
            }
        }
        else
        {
            prolific_potion *current = potion;
            prolific_potion *previous = NULL;
            while (current != NULL)
            {
                if (strcmp(ing, current->ing) == 0)
                {
                    printf("\nItem added for brewing : %s .", ing);
                    printf("\nqnt left : %d .", current->qnt - qnt);
                    if (qnt == current->qnt)
                    {
                        printf("(So the node was deleted.)\n");
                        prolific_potion *temp = current;
                        if (current->next != NULL)
                        {
                            previous->next = current->next;
                            current->next->prev = previous;
                            free(temp);
                            temp = NULL;
                        }
                        else
                        {
                            previous->next = NULL;
                            free(current);
                            current = NULL;
                            break;
                        }
                    }
                    else
                    {
                        current->qnt = (current->qnt) - qnt;
                        printf("(So the node was updated.)\n");
                    }
                }
                previous = current;
                current = current->next;
            }
        }
        pointer_in_beginning = pointer_in_beginning + 1;
    }
    return potion;
}
int main()
{
    generatelist();
    prolific_potion *potion = NULL;
    while (1)
    {

        if (inspect_items_gather(potion))
            break;
        else
            potion = insert_at_end(potion);
    }
    potion = brew_the_potion(potion);
    printf("\nThe POTION is ready, The dark army can now be defeated again!\n");
}
