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
		printf("Nhập số lượng khách hàng : ");
		fflush(stdout);
		scanf("%d", &n);
	} while (n < 1);
	Nhap(n, &p_head);
	if (p_head == NULL)
	{
		printf("Có lỗi ! không thể cập phát bộ nhớ.");
		exit(0);
	}
	while (choose != 6)
	{
		printf("\nNhập 1: Hiện thị danh sách khách hàng");
		fflush(stdout);
		printf("\nNhập 2: Rút tiền từ tài khoản");
		fflush(stdout);
		printf("\nNhập 3: Chuyển tiền");
		fflush(stdout);
		printf("\nNhập 4: Sửa thông tin khách hàng");
		fflush(stdout);
		printf("\nNhập 5: Lưu dữ liệu khách hàng");
		fflush(stdout);
		printf("\nNhập 6: Thoát");
		fflush(stdout);
		printf("\nMời bạn nhập : ");
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
				printf("\nNhập 1: Sửa tên");
				fflush(stdout);
				printf("\nNhập 2: Sửa địa chỉ");
				fflush(stdout);
				printf("\nNhập 3: Sửa ID");
				fflush(stdout);
				printf("\nNhập 4: Sửa pass");
				fflush(stdout);
				printf("\nNhập 5: Sửa số dư tài khoản");
				fflush(stdout);
				printf("\nNhập 6: Thoát");
				fflush(stdout);
				printf("\nMời bạn chọn : ");
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
					printf("Đã thoát!");
					break;
				default:
					printf("\nNhập lại");
					break;
				}
			}
			break;
		case 5:
			Save(n, p_head);
			break;
		case 6:
			printf(" Hẹn gặp lại quý khách !");
			break;
		default:
			printf("\nNhập lại");
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

void SuaTen(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	char newName[20];
	int id;
	printf("Nhập ID khách hàng cần sửa tên: ");
	fflush(stdout);
	scanf("%d", &id);
	getchar();
	if (TimID(id, n, p_cus) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (temp->id == id)
			{
				printf("Nhập tên mới: ");
				fflush(stdout);
				fgets(newName, sizeof(newName), stdin);
				strcpy(temp->name, newName);
				break;
			}
			temp = temp->next_customer;
		}
	}
	else
	{
		printf("\nKhong tim thay khach hang can sua ten!!");
	}
}

void SuaDiaChi(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	char newAddress[20];
	int id;
	printf("Nhập ID khách hàng cần sửa địa chỉ: ");
	fflush(stdout);
	scanf("%d", &id);
	getchar();
	if (TimID(id, n, p_cus) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (temp->id == id)
			{
				printf("Nhập địa chỉ mới: ");
				fflush(stdout);
				fgets(newAddress, sizeof(newAddress), stdin);
				strcpy(temp->address, newAddress);
				break;
			}
			temp = temp->next_customer;
		}
	}
	else
	{
		printf("\nKhông tìm thấy khách hàng cần sửa địa chỉ!!");
	}
}

void SuaID(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	int newID;
	int id;
	printf("Nhập lại ID khách hàng cần sửa ID: ");
	fflush(stdout);
	scanf("%d", &id);
	if (TimID(id, n, p_cus) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (temp->id == id)
			{
				printf("Nhập ID mới: ");
				fflush(stdout);
				scanf("%d", &newID);
				temp->id = newID;
				break;
			}
			temp = temp->next_customer;
		}
	}
	else
	{
		printf("\nKhông tìm thấy khách hàng cần sửa ID!!");
	}
}

void SuaPass(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	int newPass;
	int id;
	printf("Nhập ID khách hàng cần sửa pass: ");
	fflush(stdout);
	scanf("%d", &id);
	if (TimID(id, n, p_cus) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (temp->id == id)
			{
				printf("Nhập pass mới: ");
				fflush(stdout);
				scanf("%d", &newPass);
				temp->pass = newPass;
				break;
			}
			temp = temp->next_customer;
		}
	}
	else
	{
		printf("\nKhông tìm thấy thông tin khách hang cần sửa pass!!");
	}
}

void SuaSoDu(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	int newSodu;
	int id;
	printf("Nhập ID khách hàng cần sửa số dư tài khoản: ");
	fflush(stdout);
	scanf("%d", &id);
	if (TimID(id, n, p_cus) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (temp->id == id)
			{
				printf("Nhập số dư tài khoản mới: ");
				fflush(stdout);
				scanf("%d", &newSodu);
				temp->money = newSodu;
				break;
			}
			temp = temp->next_customer;
		}
	}
	else
	{
		printf("\nKhông tìm thông tin thấy khách hàng cần sửa số dư tài khoản!!");
	}
}

void Save(int n, cus_t *p_cus)
{
	cus_t *temp = p_cus;
	char NgayLuu[20];
	char GioLuu[20];
	FILE *fptr;

	fptr = fopen("Thong_tin_khach hang.txt", "a+");
	getchar();
	printf("Nhập ngày lưu dữ liệu: ");
	fflush(stdout);
	gets(NgayLuu);
	printf("Nhập giờ lưu dữ liệu: ");
	fflush(stdout);
	gets(GioLuu);
	fprintf(fptr, "\n");
	fprintf(fptr, "Ngay luu: %s, gio luu: %s", NgayLuu, GioLuu);
	fprintf(fptr, "\nSTT\t\tName\t\t\tAddress\t\t\tID\t\t\tMoney\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(fptr, "%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", i + 1, temp->name, temp->address, temp->id, temp->money);
		temp = temp->next_customer;
	}
	fflush(fptr);
	fclose(fptr);
}
