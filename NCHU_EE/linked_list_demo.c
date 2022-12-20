#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

struct data{
	int num;
	struct data *nextPtr;
} ;
typedef struct data data;
typedef data *dataPtr;

void insert(dataPtr *sPtr,int value){
	dataPtr previousPtr;
	dataPtr currentPtr;
	dataPtr newPtr;
	newPtr = malloc(sizeof(data));
	if(newPtr != NULL){
		newPtr -> num = value;
		newPtr -> nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		
		while(currentPtr != NULL && value > currentPtr -> num ){
			previousPtr = currentPtr;
			currentPtr = currentPtr -> nextPtr;
		}
		
		if(previousPtr == NULL){
			newPtr -> nextPtr = *sPtr;
			*sPtr = newPtr;
		}else{
			previousPtr -> nextPtr = newPtr;
			newPtr->nextPtr =currentPtr;
		}
	}
	else{
		printf("無法插入 %d ，沒有額外空間。 \n",value);
	}
}

void DeleteValue(dataPtr *sPtr,int value){
	dataPtr previousPtr = NULL;
	dataPtr currentPtr = *sPtr;
	
	while(currentPtr != NULL && currentPtr -> num != value ){
		previousPtr = currentPtr;
		currentPtr = currentPtr -> nextPtr;
	}
	if(currentPtr != NULL){
		if(previousPtr != NULL){
			previousPtr -> nextPtr = currentPtr -> nextPtr;	
		}else{
			*sPtr = currentPtr ->nextPtr;
		}
		free(currentPtr);
	}else{
		printf("Link List 沒有 %d ，不須刪除。 \n",value);
	}
}

void edit(dataPtr *sPtr, int value, int value2){  //value想改的  value2後來的 
	dataPtr currentPtr = *sPtr;
	while(currentPtr != NULL && currentPtr -> num != value){
		currentPtr = currentPtr->nextPtr;
	}
	if(currentPtr != NULL){
		DeleteValue(sPtr , value);
		insert(sPtr , value2);
	}else{
		printf("Link List 沒有 %d ，不需要修改。\n",value);
	}
}

void printList(dataPtr currentPtr){
	printf("Link List內容如下 : \n");
	if(currentPtr == NULL){
		printf("沒有資料。");
	}
	
	while(currentPtr != NULL){
		printf("%d ",currentPtr -> num);
		currentPtr = currentPtr ->nextPtr;
	}
	printf("\n\n");
}

int main(void){
	dataPtr startPtr = NULL;
	int select,num,num2;
	while(1){
		printf("輸入模式 : (1)新增 (2)刪除 (3)修改 (4)顯示 (5)離開 \n");
		scanf("%d",&select);
		switch(select){
			case 1 :	//新增 
				while(1){
					printf("輸入欲新增數字(退出輸入$) : ");
					
					if(scanf("%d",&num) == 0){
					fflush(stdin);
					printf("結束新增\n");
					break;
					}
					insert(&startPtr, num);					
					printList(startPtr);
				}
				break;
				
			case 2 :	//刪除
				printList(startPtr);
				while(startPtr != NULL){
					printf("輸入欲刪除數字(退出輸入$) : ");
					
					if(scanf("%d",&num) == 0){
					fflush(stdin);
					printf("結束刪除\n");
					break;
					}
					DeleteValue(&startPtr ,num);
					printList(startPtr);
				}
				break;
				
			case 3 :	//修改 
				printList(startPtr);
				while(startPtr != NULL){
					printf("輸入欲改的數字(退出輸入$) : ");
					if(scanf("%d",&num) == 0){
						fflush(stdin);
						printf("結束刪除\n");
						break;
					}
					printf("輸入修改後的數字 : ");
					if(scanf("%d",&num2) == 0){
						fflush(stdin);
						printf("結束刪除\n");
						break;
					} 
					edit(&startPtr,num,num2);
					printList(startPtr);
				}
				break;
				
			case 4 :	//顯示 
				printList(startPtr);
				break;
			
			case 5 :	//離開 
				return 0;
				break;
		}
	}
}
