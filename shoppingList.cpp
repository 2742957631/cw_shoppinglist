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
	printf("购物清单:\n");
	while(current != NULL)
	{
		printf("%s - 数量: %d\n",current->name,current->quantity);
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
	printf("查找商品 \"%s\" ：\n", itemName);
	while(current != NULL)
	{
		if(strcmp(current->name,itemName) == 0)
		{
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
		}
		current=current->next;
	}
	if(current == NULL)
	printf("未找到商品 \"%s\"。\n", itemName);
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
	cout<<"购物清单的功能如下："<<endl;
	cout<<"【1】添加商品到购物清单 "<<endl;
	cout<<"【2】从购物清单中移除商品 "<<endl;
	cout<<"【3】查看购物清单 "<<endl;
	cout<<"【4】修改购物清单中商品的数量 "<<endl;
	cout<<"【5】清空购物清单 "<<endl;
	cout<<"【6】计算购物清单中上坪的总数量 "<<endl;
	cout<<"【7】查找购物清单中的商品 "<<endl;
	cout<<"【8】排序购物清单 "<<endl;
	cout<<"【9】合并购物清单 "<<endl;
	cout<<"【10】删除购物清单中的商品 "<<endl;
	cout<<"please enter the number : "<<endl; 
	int option;
	while(cin>>option)
	{
		char itemname[50];
		int itemQuantity;
		if(option == 1)
		{
			cout<<"请输入添加的商品名和对应数量（输入0结束） :"<<endl; 
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
			cout<<"输入商品名 :"<<endl;
			scanf("%s",&itemname);
			removeItem(itemname);
		}
		else if(option == 3)
		{
			displayList();
		}
		else if(option == 4)
		{
			cout<<"请输入商品名 :"<<endl;
			scanf("%s",&itemname);
			cout<<"请输入商品数量 :"<<endl;
			cin>>itemQuantity;
			updateQuantity(itemname,itemQuantity);
		}
		else if(option == 5)
		{
			clearList();
		}
		else if(option == 6)
		{
			cout<<"该商品的总数为："<<endl; 
			cout<< totalQuantity() <<endl;
		}
		else if(option == 7)
		{
			cout<<"请输入待查找的商品名"<<endl;
			scanf("%s",&itemname);
			findItem(itemname);
		}
		else if(option == 8)
		{
			sortList();
		}
		else if(option == 9)
		{ 
			cout<<"请输入待合并的购物清单： "<<endl;
			SS *list2 =read();
			mergeLists(&shoppingList,&list2);
		}
		else if(option == 10)
		{
			cout<<"please enter the name of goods :"<<endl;
			scanf("%s",&itemname);
			cout<<"输入数字1删除所有该名商品 输入数字0则删除其一 :"<<endl;
			int deleteAll;
			cin>>deleteAll;
			deleteItem(itemname,deleteAll);
		}
		else if(option == 0) break;
	}
	return 0;
}
