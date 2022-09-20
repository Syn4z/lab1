#include <stdio.h>
#include<stdlib.h>
#define limit 99

void insert();
void delete();
void display();
void reverse();
int queue_struct[limit];
int rear = - 1;
int front = - 1;

void check(int element)
{
	int i;
    for (i = 0; i <= rear; i++)
    {
        if (element >= queue_struct[i])
        {
            for (int j = rear+1; j > i; j--)
            {
                queue_struct[j] = queue_struct[j - 1];
            }
            queue_struct[i] = element;
            return;
        }
    }

    queue_struct[i] = element;
}

void insert(int element)
{
	if (rear >= limit - 1)
	{
		printf("\nQueue Overflow!");
		return;
	}

	if ((front == -1) && (rear == -1))
	{
		front++;
		rear++;
		queue_struct[rear] = element;
		return;
	}    
	else
		check(element);
	rear++;
}

void delete(int element)
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is Empty!");
        return;
    }

    for (int i = 0; i <= rear; i++)
    {
        if (element == queue_struct[i])
        {
            for (i; i < rear; i++)
			{
                queue_struct[i] = queue_struct[i + 1];
			}	

        rear--;

        if (rear == -1) 
            front = -1;
        return;
        }
    }

    printf("\n\t%d is not in queue!", element);
}

void reverse()
{
    int i, j, t;
	for (i = front, j = rear; i < j; i++,j--)
    {
		t = queue_struct[i];
		queue_struct[i] = queue_struct[j];
		queue_struct[j] = t;
	}

	display();
}

void sort()
{
			printf("\n\tSorted queue: ");
			reverse();
			printf("\n\tInitial queue: ");
			reverse();
}

void display()
{
	int i;
	if ((front == -1) && (rear == -1))
	{
		printf("\n\tQueue is empty!");
		return;
	}	
	else
	{
		printf("\n\tThe Queue: ");
		for (i = front; i <= rear; i++)
			printf("%d ", queue_struct[i]);
	}

	front = 0;
}

void load_file()
{
    int i = 0;
    front = 0;
    rear = -1;

    FILE *loaded_file  = fopen("load.txt", "r");

    if (loaded_file == NULL) 
	{   
        printf("\n\tFile cannon be accesed!"); 
        exit(0);
    }
    else
	{
        printf("\n\tFile loaded up");

        while(fscanf(loaded_file, "%d ", &queue_struct[i]) != EOF)
		{
            i++;
            rear++;
        }
    }

    fclose(loaded_file);
}

void save_file()
{
	FILE *fp;
	fp = fopen("queue.txt", "w+");
	for (int i = 0; i < limit; i++)
		{
			if (queue_struct[i] == 0)
				break;
			fprintf(fp, "%i ", queue_struct[i]);
		}
	fclose(fp);
	printf("\n\n\tQueue saved to file named 'queue.txt'");
}

int main()
{
	int choice, e;

	while (1)
	{
		printf("\n\n==========================================");
		printf("\nType '1' to insert an element to queue");
		printf("\nType '2' to delete an element from queue");
		printf("\nType '3' to display the elements of queue");
		printf("\nType '4' to reverse the queue");
        printf("\nType '5' to sort the queue");
		printf("\nType '6' to load queue from a file");
		printf("\nType '7' to save queue to a file");
        printf("\nType '8' to quit");
		printf("\n------------------------------------------");
		printf("\n\n\tType in your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Type the element to insert: ");
				scanf("%d", &e);
				insert(e);
				break;
			case 2:
				printf("Type the element to delete: ");
				scanf("%d", &e);
				delete(e);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\n\tReversed queue: ");
				reverse();
				printf("\n\tInitial queue: ");
				reverse();
                break;	
			case 5:
				sort();
				break;
			case 6:
				load_file();
				break;		
			case 7:
				save_file();
				break;	
			case 8:
				exit(0);	
			default:
				printf("\nTry again!");
		}
	}

	return 0;
}

