#include<bits/stdc++.h>
using namespace std;

typedef struct ShoppingItem
{
	char name[50];
	int quantity;
	struct ShoppingItem *next;
}SS;

SS *shoppingList = NULL; // head point 

void addItem(char itemName[],int itemQuantity)
{
	SS *newItem = (SS *)malloc(sizeof(SS));
	newItem->next=NULL;
	strcpy(newItem->name,itemName);
	newItem->quantity=itemQuantity;
	newItem->next=shoppingList;
	shoppingList=newItem;// head insert//
}

void removeItem(char itemName[])
{
	SS *current=shoppingList;
	SS *previous=NULL;
	while(current != NULL)
	{
		if(strcmp(current->name,itemName) == 0)
		{
			if(previous != NULL)
			{
				previous->next=current->next;
			}
			else
			{
				shoppingList=current->next;
			}
			free(current);
			break;
		}
		previous=current;
		current=previous->next;
	}
}

void displayList()
{
	SS *current=shoppingList;
	printf("�����嵥:\n");
	while(current != NULL)
	{
		printf("%s - ����: %d\n",current->name,current->quantity);
		current=current->next;
	}
}

void updateQuantity(char itemName[],int newItemQuantity)
{
	SS *current=shoppingList;
	
	while(current != NULL)
	{
		if(strcmp(current->name,itemName) == 0)
		{
			current->quantity=newItemQuantity;
			break;
		}
		current=current->next;
	}
}

void clearList()
{
	while(shoppingList != NULL)
	{
		SS *temp = shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}

int totalQuantity()
{
	SS *current=shoppingList;
	int total=0;
	while(current != NULL)
	{
		total++;
		current=current->next;
	}
	return total;
}

void findItem(char itemName[])
{
	SS *current=shoppingList;
	printf("������Ʒ \"%s\" ��\n", itemName);
	while(current != NULL)
	{
		if(strcmp(current->name,itemName) == 0)
		{
			printf("%s - ������%d\n", current->name, current->quantity);
			return;
		}
		current=current->next;
	}
	if(current == NULL)
	printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}
void sortList()
{
	SS *current=shoppingList;
	SS *nextItem=NULL;
	char tempName[50];
	int tempQuantity;
	
	while(current != NULL)
	{
		nextItem=current->next;
		while(nextItem != NULL)
		{
			if(strcmp(current->name,nextItem->name) > 0)
			{
				strcpy(tempName,current->name);
				strcpy(current->name,nextItem->name);
				strcpy(nextItem->name,tempName);
				tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem=nextItem->next;
		}
		current=current->next;
	}
}

void mergeLists(SS **list1,SS **list2)
{
	SS *current=*list1;
	while(current->next != NULL)
	{
		current=current->next;
	}
	current->next=*list2;
	*list2=NULL;
}

void deleteItem(char itemName[],int deleteAll)
{
	SS *current=shoppingList;
	SS *prev=NULL;
	
	while(current != NULL)
	{
		if(strcmp(current->name,itemName) == 0)
		{
			if(prev == NULL)
			{
				SS *temp=shoppingList;
				shoppingList=shoppingList->next;
				free(temp);
				if(!deleteAll) break;
			}
			else
			{
				prev->next=current->next;
				free(current);
				current=prev->next;
				if(!deleteAll) break;
			}
		}
		else
		{
			prev = current;
			current=current->next;
		}
	}
}

SS* read()
{
	SS *head,*p;
	head=NULL;
	char itemname[50];
	int itemquantity;
	while(1)
	{
		scanf("%s",&itemname);
		if(strcmp(itemname,"0") == 0) break;
		cin>>itemquantity;
		p = (SS *)malloc(sizeof(SS));
		p->next=NULL;
		strcpy(p->name,itemname);
		p->quantity=itemquantity;
		p->next=head;
		head=p; 
	}
	return head;
}
int main()
{
	cout<<"�����嵥�Ĺ������£�"<<endl;
	cout<<"��1�������Ʒ�������嵥 "<<endl;
	cout<<"��2���ӹ����嵥���Ƴ���Ʒ "<<endl;
	cout<<"��3���鿴�����嵥 "<<endl;
	cout<<"��4���޸Ĺ����嵥����Ʒ������ "<<endl;
	cout<<"��5����չ����嵥 "<<endl;
	cout<<"��6�����㹺���嵥����ƺ�������� "<<endl;
	cout<<"��7�����ҹ����嵥�е���Ʒ "<<endl;
	cout<<"��8���������嵥 "<<endl;
	cout<<"��9���ϲ������嵥 "<<endl;
	cout<<"��10��ɾ�������嵥�е���Ʒ "<<endl;
	cout<<"please enter the number : "<<endl; 
	int option;
	while(cin>>option)
	{
		char itemname[50];
		int itemQuantity;
		if(option == 1)
		{
			cout<<"��������ӵ���Ʒ���Ͷ�Ӧ����������0������ :"<<endl; 
			while(1)
			{
				scanf("%s",&itemname);
				if(itemname[0] == '0') break;
				cin>>itemQuantity;
				addItem(itemname,itemQuantity);
			}
		}
		else if(option == 2)
		{
			cout<<"������Ʒ�� :"<<endl;
			scanf("%s",&itemname);
			removeItem(itemname);
		}
		else if(option == 3)
		{
			displayList();
		}
		else if(option == 4)
		{
			cout<<"��������Ʒ�� :"<<endl;
			scanf("%s",&itemname);
			cout<<"��������Ʒ���� :"<<endl;
			cin>>itemQuantity;
			updateQuantity(itemname,itemQuantity);
		}
		else if(option == 5)
		{
			clearList();
		}
		else if(option == 6)
		{
			cout<<"����Ʒ������Ϊ��"<<endl; 
			cout<< totalQuantity() <<endl;
		}
		else if(option == 7)
		{
			cout<<"����������ҵ���Ʒ��"<<endl;
			scanf("%s",&itemname);
			findItem(itemname);
		}
		else if(option == 8)
		{
			sortList();
		}
		else if(option == 9)
		{ 
			cout<<"��������ϲ��Ĺ����嵥�� "<<endl;
			SS *list2 =read();
			mergeLists(&shoppingList,&list2);
		}
		else if(option == 10)
		{
			cout<<"please enter the name of goods :"<<endl;
			scanf("%s",&itemname);
			cout<<"��������1ɾ�����и�����Ʒ ��������0��ɾ����һ :"<<endl;
			int deleteAll;
			cin>>deleteAll;
			deleteItem(itemname,deleteAll);
		}
		else if(option == 0) break;
	}
	return 0;
}
