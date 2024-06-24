#include<stdio.h>
int main(){
	int a[10][10],b[10][10],mul[10][10],rows,columns,i,j,k;
	printf("Enter number or rows: ");
	scanf("%d", &rows);
	printf("Enter number of columns: ");
	scanf("%d",&columns);
	printf("Elements of 1st matrix:\n");
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			scanf("%d", &a[i][j])
		}
	}
	printf("Elements of 2nd matrix:\n");
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			scanf("%d", &b[i][j]);
		}
	}
}
