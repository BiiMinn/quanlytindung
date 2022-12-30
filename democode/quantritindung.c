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

void Nhap(int n, cus_t** p_head)
{
	*p_head = (cus_t *)malloc(sizeof(cus_t));
	cus_t *temp = *p_head;
	for (int i = 0; i < n; i++)
	{
		getchar();
		printf("\nNhập tên khách hàng %d: ", i + 1);
		fflush(stdout);
		gets(temp->name);
		printf("Nhập địa chỉ: ");
		fflush(stdout);
		gets(temp->address);
		printf("Nhập ID ( Chỉ nhập số ): ");
		fflush(stdout);
		scanf("%d", &temp->id);
		getchar();
		printf("Nhập password ( Chỉ nhập số ): ");
		fflush(stdout);
		scanf("%d", &temp->pass);
		printf("Nhập số tiền ( Chỉ nhập số ): ");
		fflush(stdout);
		scanf("%f", &temp->money);
		if (i != n - 1)
		{
			temp->next_customer = (cus_t *)malloc(sizeof(cus_t));
			temp = temp->next_customer;
		}
	}
}

void In(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	printf("\n------------------------------------------------------------------------------------------------------");
	for (int i = 0; i < n; i++)
	{
		printf("\nSTT: %d", i + 1);
		printf("\nTen: %s", temp->name);
		printf("\nDiachi: %s", temp->address);
		printf("\nID: %d", temp->id);
		printf("\nTien: %.2f", temp->money);
		printf("\n------------------------------------------------------------------------------------------------------");
		temp = temp->next_customer;
	}
}

void Rut(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	int my_id, my_pass, i;

	printf("Nhập ID của bạn: ");
	fflush(stdout);
	scanf("%d", &my_id);
	printf("Nhập password của bạn: ");
	fflush(stdout);
	scanf("%d", &my_pass);

	if (Tim(my_id, my_pass, n, p_cus) == 1)
	{
		for (i = 0; i < n; i++)
		{
			if (temp->id == my_id)
			{
				float m;
				printf("Nhập số tiền cần rút :");
				fflush(stdout);
				scanf("%f", &m);
				if (m > temp->money)
				{
					printf("\n ==> Không đủ tiền !");
					break;
				}
				// them else
				else
				{
					temp->money = temp->money - m;
					printf("\n ==> Rút tiền thành công , Số tiền còn lại trong tài khoản là: %f", temp->money);
					break;
				}
			}
			temp = temp->next_customer;
		}
	}
	// them else
	else
	{
		printf("\n ==> sai id hoặc pass , vui lòng nhập lại ! ");
	}
}

void Chuyen(int n, cus_t *p_cus)
{
	cus_t *temp_1 = p_cus;
	cus_t *temp_2 = p_cus;
	int my_id, orther_id, my_pass, j;
	float m;
	char name1[30];

	printf("Nhập ID của bạn: ");
	fflush(stdout);
	scanf("%d", &my_id);
	printf("Nhập password của bạn: ");
	fflush(stdout);
	scanf("%d", &my_pass);

	if (Tim(my_id, my_pass, n, p_cus) == 1)
	{
		printf("Nhập số tiền cần chuyển:");
		fflush(stdout);
		scanf("%f", &m);
		for (int i = 0; i < n; i++)
		{
			if (temp_1->id == my_id)
			{
				strcpy(name1, temp_1->name);

				if (m > temp_1->money)
				{
					printf("==> Giao dịch không thành công , không đủ tiền!");
				}
				else if (m <= temp_1->money)
				{
					printf("\n Nhập ID tài khoản bạn muốn chuyển: ");
					fflush(stdout);
					scanf("%d", &orther_id);

					if (TimID(orther_id, n, p_cus) == 1)
					{
						for (j = 0; j <= n; j++)
						{
							if (temp_2->id == orther_id)
							{
								temp_2->money = temp_2->money + m;
								printf("\n ==> chuyển thành công ");
								printf("\n ==> Bạn vừa chuyển %f đến tài khoản %s", m, name1);
								temp_1->money = temp_1->money - m;
								printf("\n ==> Số tiền còn lại trong tài khoản của bạn là: %f", temp_1->money);
								break;
							}
							temp_2 = temp_2->next_customer;
						}
					}
					else
					{
						printf("\n ==> Người nhận không tồn tại !");
					}
				}
			}
			temp_1 = temp_1->next_customer;
		}
	}
	else // if ( (p_cus + i)->id == my_id || (p_cus + i)->pass == my_pass)
	{
		printf(" \n  ==> nhập sai , vui lòng nhập lại !");
	}
}

