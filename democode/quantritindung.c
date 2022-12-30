#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer
{
	char name[30];
	char address[50];
	int id;
	int pass;
	float money;
	struct customer *next_customer;
} cus_t;

void Nhap(int n, cus_t** p_cus);

void In(int n, cus_t *p_cus);

void Rut(int n, cus_t *p_cus);

void Chuyen(int n, cus_t *p_cus);

int Tim(int x, int y, int n, cus_t *p_cus);

int TimID(int x, int n, cus_t *p_cus);

void SuaDiaChi(int n, cus_t *p_cus);

void SuaTen(int n, cus_t *p_cus);

void SuaID(int n, cus_t *p_cus);

void SuaPass(int n, cus_t *p_cus);

void SuaSoDu(int n, cus_t *p_cus);
void Save(int n, cus_t *p_cus);

int main()
{
	cus_t *p_head = NULL;
	int choose, n, key;

	do
	{
		printf("Nháº­p sá»‘ lÆ°á»£ng khÃ¡ch hÃ ng : ");
		fflush(stdout);
		scanf("%d", &n);
	} while (n < 1);
	Nhap(n, &p_head);
	if (p_head == NULL)
	{
		printf("CÃ³ lá»—i ! khÃ´ng thá»ƒ cáº­p phÃ¡t bá»™ nhá»›.");
		exit(0);
	}
	while (choose != 6)
	{
		printf("\nNháº­p 1: Hiá»‡n thá»‹ danh sÃ¡ch khÃ¡ch hÃ ng");
		fflush(stdout);
		printf("\nNháº­p 2: RÃºt tiá»n tá»« tÃ i khoáº£n");
		fflush(stdout);
		printf("\nNháº­p 3: Chuyá»ƒn tiá»n");
		fflush(stdout);
		printf("\nNháº­p 4: Sá»­a thÃ´ng tin khÃ¡ch hÃ ng");
		fflush(stdout);
		printf("\nNháº­p 5: LÆ°u dá»¯ liá»‡u khÃ¡ch hÃ ng");
		fflush(stdout);
		printf("\nNháº­p 6: ThoÃ¡t");
		fflush(stdout);
		printf("\nMá»i báº¡n nháº­p : ");
		fflush(stdout);
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			In(n, p_head);
			break;
		case 2:
			Rut(n, p_head);
			break;
		case 3:
			Chuyen(n, p_head);
			break;
		case 4:
			while (key != 6)
			{
				printf("\nNháº­p 1: Sá»­a tÃªn");
				fflush(stdout);
				printf("\nNháº­p 2: Sá»­a Ä‘á»‹a chá»‰");
				fflush(stdout);
				printf("\nNháº­p 3: Sá»­a ID");
				fflush(stdout);
				printf("\nNháº­p 4: Sá»­a pass");
				fflush(stdout);
				printf("\nNháº­p 5: Sá»­a sá»‘ dÆ° tÃ i khoáº£n");
				fflush(stdout);
				printf("\nNháº­p 6: ThoÃ¡t");
				fflush(stdout);
				printf("\nMá»i báº¡n chá»n : ");
				fflush(stdout);
				scanf("%d", &key);
				switch (key)
				{
				case 1:
					SuaTen(n, p_head);
					break;
				case 2:
					SuaDiaChi(n, p_head);
					break;
				case 3:
					SuaID(n, p_head);
					break;
				case 4:
					SuaPass(n, p_head);
					break;
				case 5:
					SuaSoDu(n, p_head);
					break;
				case 6:
					printf("ÄÃ£ thoÃ¡t!");
					break;
				default:
					printf("\nNháº­p láº¡i");
					break;
				}
			}
			break;
		case 5:
			Save(n, p_head);
			break;
		case 6:
			printf(" Háº¹n gáº·p láº¡i quÃ½ khÃ¡ch !");
			break;
		default:
			printf("\nNháº­p láº¡i");
			break;
		}
	}
	free(p_head);
	return 0;
}

int Tim(int x, int y, int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	for (int i = 0; i < n; i++)
	{
		if (temp->id == x && temp->pass == y)
		{
			return 1;
		}
		temp = temp->next_customer;
	}
	return 0;
}

int TimID(int x, int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	for (int i = 0; i < n; i++)
	{
		if (temp->id == x)
		{
			return 1;
		}
		temp = temp->next_customer;
	}
	return 0;
}

